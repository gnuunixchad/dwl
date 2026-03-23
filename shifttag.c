// "arg->i" stores the number of tags to shift right (positive value)
//          or left (negative value)

static uint32_t
get_occupied_tags(Monitor *m)
{
	uint32_t occupied = 0;
	Client *c;
	wl_list_for_each(c, &clients, link) {
		if (c->mon == m)
			occupied |= c->tags;
	}
	return occupied & TAGMASK;
}

static uint32_t
find_next_tag(uint32_t current_tag, int direction, bool skip_unoccupied, bool skip_occupied)
{
	uint32_t occupied = get_occupied_tags(selmon);
	uint32_t result = 0;

	for (int i = 0; i < LENGTH(tags); i++) {
		uint32_t bit = 1 << i;

		if (current_tag & bit) {
			uint32_t new_bit = bit;

			if (!skip_unoccupied && !skip_occupied) {
				if (direction > 0) {
					if (bit << 1 && (bit << 1) <= TAGMASK)
						new_bit = bit << 1;
					else
						new_bit = 1;
				} else {
					if (bit >> 1)
						new_bit = bit >> 1;
					else
						new_bit = 1 << (LENGTH(tags) - 1);
				}
			} else {
				uint32_t test_bit = bit;
				uint32_t start_bit = bit;
				int count = 0;

				do {
					if (direction > 0) {
						if (test_bit << 1 && (test_bit << 1) <= TAGMASK)
							test_bit = test_bit << 1;
						else
							test_bit = 1;
					} else {
						if (test_bit >> 1)
							test_bit = test_bit >> 1;
						else
							test_bit = 1 << (LENGTH(tags) - 1);
					}

					int is_occupied = (occupied & test_bit) != 0;
					int should_select = (skip_unoccupied && is_occupied) ||
										(skip_occupied && !is_occupied);

					if (should_select) {
						new_bit = test_bit;
						break;
					}
					count++;
				} while (test_bit != start_bit && count < LENGTH(tags));
			}

			result |= new_bit;
		}
	}

	return result;
}

static void
shifttag_with_filter(const Arg *arg, bool skip_unoccupied, bool skip_occupied)
{
	Arg a;
	if (!selmon)
		return;

	uint32_t occupied = get_occupied_tags(selmon);
	if (skip_unoccupied && !skip_occupied && occupied == 0)
		return;
	if (skip_occupied && !skip_unoccupied && (occupied == TAGMASK))
		return;

	uint32_t curseltags = selmon->tagset[selmon->seltags];
	uint32_t nextseltags = find_next_tag(curseltags, arg->i, skip_unoccupied, skip_occupied);

	if (nextseltags != curseltags) {
		a.i = nextseltags;
		view(&a);
	}
}

void
shifttag(const Arg *arg)
{
	shifttag_with_filter(arg, false, false);
}

void
shifttag_occupied(const Arg *arg)
{
	shifttag_with_filter(arg, true, false);
}

void
shifttag_unoccupied(const Arg *arg)
{
	shifttag_with_filter(arg, false, true);
}
