# <img src="./misc/dwl-repo.png" width="24"/> My build of [dwl](https://codeberg.org/dwl/dwl) - dwm for Wayland


![](./misc/20251113_23h10m17s_grim.png)

### Running dwl
```sh
alias dl="exec ssh-agent ${HOME}/.local/bin/damblocks | /usr/local/bin/dwl"
```

### Status information
I'm using the bar patch with `damblocks`([codeberg](https://codeberg.org/unixchad/damblocks)/[github](https://github.com/gnuunixchad/damblocks)), my modular POSIX script with signaling support.

For a build without the `bar.patch`, checkout the `nobar` branch. You can use any compatible bar.

### Patches applied
1. [bar](https://codeberg.org/dwl/dwl-patches/patch/bar/bar-0.7.patch)
2. [autostart](https://codeberg.org/dwl/dwl-patches/patch/autostart/autostart-0.7.patch)
3. [sticky](https://codeberg.org/dwl/dwl-patches/patch/sticky/sticky.patch)
4. [swapandfocusdir](https://codeberg.org/dwl/dwl-patches/patch/swapandfocusdir/swapandfocusdir.patch)
5. [bottomstack](https://codeberg.org/dwl/dwl-patches/patch/bottomstack/bottomstack.patch)
6. [shiftview](https://codeberg.org/dwl/dwl-patches/patch/shiftview/shiftview.patch)(Modifed for bar-0.7.patch)
7. [pertag](https://codeberg.org/dwl/dwl-patches/patch/pertag/pertag.patch)(Modifed for bar-0.7.patch)
8. [genericgaps](https://codeberg.org/dwl/dwl-patches/patch/genericgaps/genericgaps-0.7.patch)
9. [alwayscenter](https://codeberg.org/dwl/dwl-patches/patch/alwayscenter/alwayscenter.patch)
10. [text-input](./patches/text-input/text-input-0.7.patch)

#### Changes I've made to [bar](https://codeberg.org/dwl/dwl-patches/patch/bar) patch:
- Reduce `lrpad` to 0.75, for paddings around tag names(commit f31b82b9db279c6f20689586e7ee1bc2615e2c11).
- Draw bar status on unfocused outputs, unlike the default `dwm` bar(commit 1a9dcebcee0b99c725fe4acfa1c7968f4cf7cbd4).

patch involes manual patch for some other patches, due to the changes:
```diff
--- TAGSCOUNT
+++ LENGTH(tags)
```


### Building dwl v0.7
dwl has the following dependencies:
- libinput
- wayland
- wlroots0.18 (compiled with the libinput backend)
- xkbcommon
- wayland-protocols (compile-time only)
- pkg-config (compile-time only)

dwl has the following additional dependencies if XWayland support is enabled:
- libxcb
- libxcb-wm
- wlroots0.18 (compiled with X11 support)
- Xwayland (runtime only)

To enable XWayland, you should uncomment its flags in `config.mk`.
