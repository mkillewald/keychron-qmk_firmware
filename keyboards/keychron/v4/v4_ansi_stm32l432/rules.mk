# MCU name
<<<<<<< HEAD
MCU = STM32L433
=======
MCU = STM32L432
>>>>>>> playground_new

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable.
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable USB N-key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
ENCODER_ENABLE = no         # Enable Encoder
<<<<<<< HEAD
=======
ENCODER_MAP_ENABLE = no
>>>>>>> playground_new
DIP_SWITCH_ENABLE = yes
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = CKLED2001
RAW_ENABLE = yes
<<<<<<< HEAD
=======
LTO_ENABLE = yes
>>>>>>> playground_new

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

SRC += test.c
