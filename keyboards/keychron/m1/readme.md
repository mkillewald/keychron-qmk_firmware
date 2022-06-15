# Keychron M1

It's a DIY, QMK Powered Mouse!

* Keyboard Maintainer: [Keychron](https://github.com/keychron)
* Hardware Supported: Keychron M1
* Hardware Availability: [Keychron](https://www.keychron.com)

Make example for this keyboard (after setting up your build environment):

    make keychron/m1:default

Flashing example for this keyboard:

    make keychron/m1:flash

**Reset Key**: Hold down the independent key next to the mouse scroll wheel on the hardware while plugging in the keyboard.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

# Customizing your Keychron Mouse
## DPI
you can change the DPI/CPI by calling `pointing_device_set_cpi` at any time. Additionally, there is a `DPI_CONFIG` macro that will cycle through an array of options for the DPI. This is set to 1200, 2400, 3600 and 5000, but can be changed. 1200 is set to the default.
To configure/set your own array, there are two defines to use, `KEYCHRON_DPI_OPTIONS` to set the array, and `KEYCHRON_DPI_DEFAULT`.

​	\# define KEYCHRON_DPI_OPTIONS { 1200, 2400, 3600, 5000 }

​	# define KEYCHRON_DPI_DEFAULT 0

The `KEYCHRON_DPI_OPTIONS` array sets the values that you want to be able to cycle through, and the order they are in. The "default" define lets the firmware know which of these options is the default and should be loaded by default.

The `DPI_CONFIG` macro will cycle through the values in the array, each time you hit it. And it stores this value in persistent memory, so it will load it the next time the device powers up.

**caution**: The number of DPIs must be four and the value of each DPI is also between 50 and 5000, because we have corresponding led indicators for them, for example:

    value: 50 <= DPI <= 1200   color: white
    
    value: 1200 < DPI <= 2400  color: blue
    
    value: 2400 < DPI <= 3600  color: green
    
    value: 3600 < DPI <= 5000  color: red
