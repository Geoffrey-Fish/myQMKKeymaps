MOUSEKEY_ENABLE = yes
ENCODER_ENABLE = yes
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
WPM_ENABLE = yes
VELOCIKEY_ENABLE = yes
UNICODE_ENABLE = yes
SEND_STRING_ENABLE = yes

OLED_DRIVER_ENABLE = yes
OLED_DRIVER = SSD1306

RGBLIGHT_ENABLE = yes
RGB_LIGHT_DRIVER = WS2812

RGBMATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

SRC += graphics.c

BOOTLOADER = rp2040
CONVERT_TO = promicro_rp2040