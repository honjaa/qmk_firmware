COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
AUTO_SHIFT_ENABLE = yes


# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
UNICODE_ENABLE = no        # Unicode
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes        # Use shared split_common code
LAYOUTS = split_3x5_2
CONFIG_USB_ACM = yes        #recommended for atmega32u4 on linux
CAPS_WORD_ENABLE = yes      #enable caps word

#recommended to save space
LTO_ENABLE = yes 	    # Link time optimization
SPACE_CADET_ENABLE = no     #disable () when tapping given mod
GRAVE_ESC_ENABLE = no       #shift or win + esc backtick - did not work for NO.
MAGIC_ENABLE = no           #disable magic keys
MUSIC_ENABLE = no	    #disable music keys
