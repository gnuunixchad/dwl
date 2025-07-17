# <img src="./misc/dwl-repo.png" width="24"/> My build of [dwl](https://codeberg.org/dwl/dwl) - dwm for Wayland


![](./misc/20250709_22h31m01s_grim.png)

### Running dwl
```sh
alias dl="exec ssh-agent ${HOME}/.local/bin/damblocks | /usr/local/bin/dwl"
```

## Patches Applied:
1. [bottomstack](https://codeberg.org/dwl/dwl-patches/patches/bottomstack.patch)
2. [pertag](https://codeberg.org/dwl/dwl-patches/patches/pertag.patch)
3. [shiftview](https://codeberg.org/dwl/dwl-patches/patches/shiftview.patch)
4. [swapandfocusdir](https://codeberg.org/dwl/dwl-patches/patches/swapandfocusdir.patch)
5. [sticky](https://codeberg.org/dwl/dwl-patches/patches/sticky.patch)
6. [autostart](https://codeberg.org/dwl/dwl-patches/patches/autostart.patch)
7. [gaps](https://codeberg.org/dwl/dwl-patches/patches/gaps.patch)

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
