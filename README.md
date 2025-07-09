# My build of [dwl](https://codeberg.org/dwl/dwl) - dwm for Wayland

### Running dwl
```sh
alias dl="exec ssh-agent ${HOME}/.local/bin/damblocks | /usr/local/bin/dwl"
```

### Status information
I'm using bar patches with [damblocks](https://codeberg.org/unixchad/damblocks), my posix script with signaling support. It's also on [github](https://github.com/gnuunixchad/damblocks).

### Patches applied
- [bar](https://codeberg.org/dwl/dwl-patches/patch/bar)
- [autostart](https://codeberg.org/dwl/dwl-patches/patch/autostart)
- [movestack](https://codeberg.org/dwl/dwl-patches/patch/movestack)
- [sticky](https://codeberg.org/dwl/dwl-patches/patch/sticky)

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
- wlroots (compiled with X11 support)
- Xwayland (runtime only)

To enable XWayland, you should uncomment its flags in `config.mk`.
