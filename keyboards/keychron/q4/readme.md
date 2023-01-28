# Keychron Q4

A customizable 60% keyboard.

Q4 Version 1 uses only 2 ICs for CKLED2001 and Q4 Version 2 uses only one IC.

* Keyboard Maintainer: [Keychron](https://github.com/keychron)
* Hardware Supported: Keychron Q4
* Hardware Availability: [Keychron](https://www.keychron.com)

Make example for this keyboard (after setting up your build environment):

```bash
make keychron/q4/q4_rev2_ansi_stm32l432:default
```

Flashing example for this keyboard ([after setting up the bootloadHID flashing environment](https://docs.qmk.fm/#/flashing_bootloadhid))

```bash
make keychron/q4/q4_rev2_ansi_stm32l432:default:flash
```

**Reset Key**: Hold down the key located at *K00*, commonly programmed as *Esc* while plugging in the keyboard.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
