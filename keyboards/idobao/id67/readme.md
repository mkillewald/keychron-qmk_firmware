# IDOBAO ID67

<<<<<<< HEAD
=======
![id67](https://idobao.github.io/assets/img/idobao-id67.png)

>>>>>>> playground_new
A 65% hotswap keyboard from IDOBAO.

## ANSI support:

<<<<<<< HEAD
* Keyboard Maintainer: Tybera
* Hardware Supported: IDOBAO ID67
* Hardware Availability: [IDOBAO](https://www.idobao.net/products/idobao-id67-65-hot-swappable-mechanical-keyboard-kit-1)

## Variants

Currently there are two variants for the id67:
1. `rgb_default` which uses the `RGB Lightning` feature for the on-board LEDs.
2. `rgb` which uses the more advanced `RGB Matrix` feature for the per-key and underglow (bottom of PCB) LEDs.

Make examples for this keyboard (after setting up your build environment):

    make idobao/id67/default_rgb:default

    make idobao/id67/rgb:default

Flashing examples for this keyboard:

    make idobao/id67/default_rgb:default:flash

    make idobao/id67/rgb:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
=======
* Keyboard Maintainer: Tybera *(fmr.)*, [thewerther](https://github.com/thewerther) *(curr.)*
* Hardware Supported: IDOBAO ID67, ID67V2, ID67 Crystal & ID67 Bestype
* Hardware Availability: IDOBAO website: 
  * [ID67](https://www.idobao.net/products/idobao-id67-65-hot-swappable-mechanical-keyboard-kit-1)
  * [ID67V2](https://idobao.net/products/idobao-id67v2-65-hot-swappable-mechanical-keyboard-kit)
  * [ID67 Crystal](https://idobao.net/products/idobao-id67-crystal-keyboard-kit-gasket-mount-version)
  * [ID67 Bestype](https://idobao.net/products/idobao-id67-bestype-keyboard-kit-aluminum-with-brass-weight)

## Layout

![ID67 layout](https://idobao.github.io/kle/idobao-id67.png)


## Compiling and flashing

Make example for this keyboard (after setting up your build environment):

    make id67:default

Flashing example for this keyboard:

    make id67:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the `Escape` key and plug in the keyboard.
* **Physical reset button**: Briefly press the button on the back of the PCB.
* **Keycode in layout**: Press the key mapped to `RESET` (FN+Z).
>>>>>>> playground_new
