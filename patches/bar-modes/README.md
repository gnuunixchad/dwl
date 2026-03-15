![dwl bar-modes patch example](./example.png)

### Description

Add a mode indicator to bar that tells which mode you are in, just like
river-classic's [dam](https://codeberg.org/sewn/dam) bar.

The string from `modes_labels` defined in `config.h` is used, while normal mode
is ignored.

Another usage is to serve as a hint for each modes keybindings:

```c
enum {
    BROWSER,
};
const char *modes_labels[] = {
    "[f]irefox [b]rave [c]hromium [q]utebrowser",
};
```

### Dependencies
this patch depends on:
- [bar](https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/bar/) patch
- [modes](https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/modes/) patch

### Download
- [v0.8](https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches/bar-modes/bar-modes.patch)

### Authors
- [unixchad](https://codeberg.org/unixchad/)
