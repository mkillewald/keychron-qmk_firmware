# Keychron Q1

![Keychron Q1](https://i.imgur.com/BbJNGLY.jpg[/img])

A customizable 75% keyboard.

* Keyboard Maintainer: [Keychron](https://github.com/keychron)
* Hardware Supported: Keychron Q1
* Hardware Availability: [Keychron Q1 QMK Custom Mechanical Keyboard](https://www.keychron.com/products/keychron-q1)

Make example for this keyboard (after setting up your build environment):

    make keychron/q1/ansi_atmega32u4:default
    make keychron/q1/ansi_atmega32u4_encoder:default
    make keychron/q1/ansi_stm32l432:default
    make keychron/q1/ansi_stm32l432_encoder:default
    make keychron/q1/iso_atmega32u4:default
    make keychron/q1/iso_atmega32u4_encoder:default
    make keychron/q1/iso_stm32l432:default
    make keychron/q1/iso_stm32l432_encoder:default
    make keychron/q1/jis_stm32l432:default
    make keychron/q1/jis_stm32l432_encoder:default

Flashing example for this keyboard:

    make keychron/q1/ansi_atmega32u4:default:flash
    make keychron/q1/ansi_atmega32u4_encoder:default:flash
    make keychron/q1/ansi_stm32l432:default:flash
    make keychron/q1/ansi_stm32l432_encoder:default:flash
    make keychron/q1/iso_atmega32u4:default:flash
    make keychron/q1/iso_atmega32u4_encoder:default:flash
    make keychron/q1/iso_stm32l432:default:flash
    make keychron/q1/iso_stm32l432_encoder:default:flash
    make keychron/q1/jis_stm32l432:default:flash
    make keychron/q1/jis_stm32l432_encoder:default:flash

**Reset Key**: Hold down the key located at *K00*, commonly programmed as *Esc* while plugging in the keyboard.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
