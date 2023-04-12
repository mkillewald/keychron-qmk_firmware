## Keychron Q1V2 ANSI STM32L432 ENC11 (with knob) Keymap v2.0.3

### Highly Recommended: You should clear your eeprom before or after flashing this firmware. Be aware that clearing the eeprom will erase any changes previously made in VIA. Please backup your VIA config before clearing your eeprom. If you place your keyboard in DFU mode by holding ESC and plugging in the USB cable, this should clear your eeprom even if you take it out of DFU mode at this point without flashing.

## Features:
- Retains Keychron factory keycodes for Mission Control, Launchpad, Siri, Cortana, Task View, File Explorer, and others.

- Retains Keychron factory reset (Fn+J+Z) and LED test (Fn+Right+Home)

- Separate RGB settings for Mac base and Win base layers. You can set different RGB animations, colors, brightness and speed for the Mac and Win base layers using the standard RGB keyboard shortcuts.

- Autocorrect is enabled. ([https://docs.qmk.fm/#/feature_autocorrect](https://docs.qmk.fm/#/feature_autocorrect))
    - Uses getreuer's 400 entry autocorrect dictionary.   
    [https://github.com/getreuer/qmk-keymap/blob/main/features/autocorrection_dict_extra.txt](https://github.com/getreuer/qmk-keymap/blob/main/features/autocorrection_dict_extra.txt)

- Caps Word enabled with RGB indicator. ([https://docs.qmk.fm/#/feature_caps_word](https://docs.qmk.fm/#/feature_caps_word))

- Caps Lock RGB indicator. Will light Caps Lock key with options to also light Tab key (useful for some keycap sets), and/or light all alpha keys.

- Dynamic Fn layer RGB indicator. When Fn key is held down, any keys defined on the Fn layers in this firmware or in VIA will be highlighted.

##### Notes:   

###### Toggling RGB mode off will disable RGB and indicators separately for each base layer (Mac or Win). RGB must be toggled on for all indicators to function. If you do not want an RGB mode active but still want the indicators, toggle RGB on and turn the brightness all the way off. The indicators will remain at full brightness.
###### Changing RGB settings with VIA lighting tab is unsupported at this time and may have undesired effects. Keymap changes with VIA is supported.

## Config.h options

Default options (these defaults will be applied whenever the eeprom is cleared):

```
    #define DEFAULT_CAPS_LOCK_LIGHT_TAB      0            // 1 = enable, 0 = disable
    #define DEFAULT_CAPS_LOCK_LIGHT_ALPHA    1            // 1 = enable, 0 = disable
    #define DEFAULT_FN_LAYER_TRANSPARENT_OFF 0            // 1 = enable, 0 = disable
    #define DEFAULT_FN_LAYER_SHOW_COLOR      1            // 1 = enable, 0 = disable
    #define DEFAULT_RGB_ENABLE_MAC_BASE      1            // 1 = enable, 0 = disable
    #define DEFAULT_RGB_ENABLE_WIN_BASE      1            // 1 = enable, 0 = disable
    #define DEFAULT_HUE_WIN_BASE             80           // HSV green hue (Win Base layer)
    #define RGB_MATRIX_DEFAULT_HUE           125          // HSV teal hue  (Mac Base layer)
    #define RGB_MATRIX_DEFAULT_SAT           255          // Both Win/Mac Base layers
    #define RGB_MATRIX_DEFAULT_VAL           255          // Both Win/Mac Base layers
    #define RGB_MATRIX_DEFAULT_SPD           127          // Both Win/Mac Base layers
    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BREATHING  // Both Win/Mac Base layers
```   

Autocorrect option:

```
    // Autocorrect is on at start up. If you want Autocorrect to be off at startup,
    // un-comment the following line
    //#define AUTOCORRECT_OFF_AT_STARTUP
```

Caps Lock RGB indicator option:

```
    #define CAPS_LOCK_INDICATOR_COLOR RGB_RED
```

Dynamic Fn Layer RGB indicator options:

```
    #define FN1_LAYER_COLOR RGB_ORANGE
```

Caps Word options:

```
    // Caps Word RGB indicator color
    #define CAPS_WORD_INDICATOR_COLOR RGB_RED

    // Caps Word is activated by double-tapping left Shift. Replace this with 
    // #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD if you want to activate Caps Word 
    // by single-tapping both left and right Shift togeter. 
    #define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

    // Caps Word will light left Shift, left Control and left Option (or left Windows
    // key) when acitvated. Remove this line if you want Caps Word to only light left
    // Shift when enabled.
    #define CAPS_WORD_LIGHT_LOWER_LEFT_CORNER
```

## This keymap makes the following layout changes over the factory firmware

- Fn+Left Shift toggles Autocorrect on/off
- Fn+Backspace enters DFU mode (but does not reset eeprom)
- Fn+Z (KC_LTTOG) Caps Lock Light Tab Toggle (default: off)
    - toggle lighting the Tab key when Caps Lock is enabled. This is useful with non backlit keycaps/legends. 
- Fn+X (KC_LATOG) Caps Lock Light Alpha Toggle (default: on)
    - toggle lighting all the alpha keys when Caps Lock is enabled. 
- Fn+C (KC_TKTOG) Fn layer Trasnparent Key Off Toggle (default: RGB on)
    - toggle turning off RGB for keys with no definition 
- Fn+V (KC_FCTOG) Fn layer Color Toggle (default: static color on)
    - toggle lighting the defined Fn layer keys with the static color set with FN1_LAYER_COLOR

- Mac mode only
    - Fn+Esc (KC_LBMAC) will lock and sleep display
    - Fn+< sets my secondary display to 0° rotation
    - Fn+> sets my secondary display to 90° rotation
    
    Note: display rotation requires additional software and changes made, see this link for more information:   
    [https://www.reddit.com/r/Keychron/comments/1254g36/howto_macos_rotate_screen_from_keyboard_shortcut/](https://www.reddit.com/r/Keychron/comments/1254g36/howto_macos_rotate_screen_from_keyboard_shortcut/)

All custom keycodes can be moved to different keys in VIA by using the following:
- CUSTOM(11) = KC_LTTOG (default: Fn+Z) Caps Lock Light Tab Toggle
- CUSTOM(12) = KC_LATOG (default: Fn+X) Caps Lock Light Alpha Toggle
- CUSTOM(13) = KC_TKTOG (default: Fn+C) Fn layer Trasnparent Key Off Toggle
- CUSTOM(14) = KC_FCTOG (default: Fn+V) Fn layer Color Toggle
- CUSTOM(15) = KC_LBMAC (default Mac Only: Fn+Esc) Lock and Blank Mac

## Keychron Factory Reset and LED Test

- Hold Fn+J+Z for 4 seconds to factory reset (will clear eeprom but will not remove this firmware)
    - All LEDs will flash red to show reset is occurring
    - NOTE: User must use VIA to remove KC_LTTOG custom keycode from Fn+Z (make Fn+Z transparent or Z) before doing factory reset. The KC_LTTOG custom keycode will automatically return after factory reset is complete. 

- Hold Fn+Right+Home for 4 seconds to enable factory LED test
    - All LEDs will turn bright white
    - Right arrow will cycle all LEDs between white, red, green, and blue.
    - Home exits LED test
    - NOTE: Upon exiting, the LED test may overwrite changes you've previously made to RGB brightness, hue or saturation


#### USE AT YOUR OWN RISK

## Changelog:
v2.0.3  April 11, 2023
- added different RGB settings for Mac Base and Win Base layers with separate RGB toggle for each base layer
- added Autocorrect

v2.0.2  February 21, 2023
- Added Caps Word with indicator

v2.0.1  February 19, 2023
- Added Keychron common code for factory keycodes and things like factory reset and LED test
- Moved DFU Mode shortcut to Fn+PgUp

v2.0.0  February 15, 2023 
- Carried over all features from my original Q1V1 keymap.
- Added Fn+Home shortcut for entering DFU Mode. 
