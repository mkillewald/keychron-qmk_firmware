## Keychron Q1V2 ANSI STM32L432 ENC11 (with knob) Keymap v2.0.1

## Features:
- Retains Keychron factory keycodes for Mission Control, Launchpad, Siri, Cortana, Task View, File Explorer, and others. 

- Retains Keychron factory reset (Fn+J+Z) and LED test (Fn+Right+Home)
    - Hold Fn+J+Z for 4 seconds to factory reset (will clear eeprom but will not remove this firmware)
        - All LEDs will flash red to show reset is occurring
        - NOTE: User must use VIA to remove KC_LTTOG custom keycode from Fn+Z (make Fn+Z transparent or KC_Z) before doing factory reset. The KC_LTTOG custom keycode will automatically return after factory reset is complete. 
    - Hold Fn+Right+Home for 4 seconds to enable factory LED test
        - All LEDs will turn bright white
        - Right arrow will cycle all LEDs between white, red, green, and blue.
        - Home exits LED test
        - NOTE: Upon exiting, the LED test may overwrite changes you've previously made to LED brightness, hue or saturation

- Fn+PGUP enters DFU mode for flashing (saves you from removing the space bar and unplugging cable) 

- Caps Lock RGB indicator
    - the Caps Lock key will light when Caps Lock is enabled with the following options:
        - #define CAPS_LOCK_INDICATOR_COLOR [color] in config.h to set the backlight color used for the indicator when Caps Lock is enabled (default: red)
        - Fn+Z will toggle lighting the TAB key when Caps Lock is enabled. This is useful with non backlit keycaps/legends. (default: off)
        - Fn+X will toggle lighting all the alpha keys when Caps Lock is enabled. (default: off)

- Dynamic Fn layer RGB indicator
    - When the Fn key is held down, any keys defined on the Fn layer in this firmware or in VIA will be highlighted with the following options:
        - #define FN_LAYER_COLOR [color] in config.h to set a static color for defined keys (default: orange)
        - Fn+C will toggle turning off RGB for keys with no definition (default: RGB off)
        - Fn+V will toggle lighting the defined Fn layer keys with the static color set with FN_LAYER_COLOR (default: static color off)

- All custom keycodes can be moved to different keys in VIA by using the ANY key with the following keycodes:
    - CUSTOM(2) = Caps Lock light Tab toggle
        - default: Fn+Z
        - represented in source code as: KC_LTTOG
    - CUSTOM(3) = Caps Lock light alphas toggle
        - default: Fn+X
        - represented in source code as: KC_LATOG
    - CUSTOM(4) = Fn layer non-defined keys RGB toggle
        - default: Fn+C
        - represented in source code as: KC_TKTOG
    - CUSTOM(5) = Fn layer defined keys static color toggle
        - default: Fn+V
        - represented in source code as: KC_FCTOG

RGB must be toggled on for all indicators to function. If you do not want an RGB mode active but still want the indicators, toggle RGB on and turn the brightness all the way off. The indicators will remain at full brightness.

Please make sure to save any customizations you have made in VIA to a .json file before flashing the firmware. Sometimes it has been necessary to re-apply those changes in VIA after flashing the firmware. If that is the case, you will most likely need to manually add the CUSTOM(2) through CUSTOM(5) keycodes after loading your customizations from the saved .json file. Then re-save a new .json file which will have your previous customizations and the custom keycodes for future use as needed.
    
#### USE AT YOUR OWN RISK

## Changelog:

v2.0.1  February 19, 2023
- Added Keychron common code for factory keycodes and things like factory reset and LED test

v2.0.0  February 15, 2023 
- Carried over all features from my original Q1V1 keymap.
- Added Fn+Home shortcut for entering DFU Mode. 
