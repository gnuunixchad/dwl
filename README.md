# <img src="./misc/dwl-repo.png" width="24"/> My build of [dwl](https://codeberg.org/dwl/dwl) - dwm for Wayland


![](./misc/20250709_22h31m01s_grim.png)

### Running dwl
```sh
alias dl="exec ssh-agent /usr/local/bin/dwl"
```
### Status information
This `nobar` branch has no bar patched, you can use any compatible bar.
For a built-in bar build, checkout the `master` branch instead.

## Patches Applied:
1. [bottomstack](https://codeberg.org/dwl/dwl-patches/patches/bottomstack/bottomstack.patch)
2. [pertag](https://codeberg.org/dwl/dwl-patches/patches/pertag/pertag.patch)
3. [shiftview](https://codeberg.org/dwl/dwl-patches/patches/shiftview/shiftview.patch)
4. [swapandfocusdir](https://codeberg.org/dwl/dwl-patches/patches/swapandfocusdir/swapandfocusdir.patch)
5. [sticky](https://codeberg.org/dwl/dwl-patches/patches/sticky/sticky.patch)
6. [autostart](https://codeberg.org/dwl/dwl-patches/patches/autostart/autostart-0.7.patch)
7. [genericgaps](https://codeberg.org/dwl/dwl-patches/patches/genericgaps/genericgaps-0.7.patch)
8. [alwayscenter](https://codeberg.org/dwl/dwl-patches/patches/alwayscenter/alwayscenter.7.patch)

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
