#ifdef BOARD_TYPE
#error "Only one board type can be defined"
#endif
#define BOARD_TYPE "Model 100"

// #define PRIMARY_KEYMAP_QWERTY
// #define PRIMARY_KEYMAP_DVORAK
// #define PRIMARY_KEYMAP_COLEMAK
#define PRIMARY_KEYMAP_CUSTOM

#define USE_EEPROM
#ifdef USE_EEPROM
  #define USE_EEPROM_KEYMAP
  #define USE_EEPROM_DEFAULT_LAYER
  #define USE_DEFAULT_LED_MODE_CONFIG
#endif USE_EEPROM

#define USE_FOCUS_SERIAL
#ifdef USE_FOCUS_SERIAL
  #define USE_FIRMWARE_VERSION
  // #define USE_DYNAMIC_MACROS
  #define USE_LAYER_NAMES
#endif USE_FOCUS_SERIAL

#define USE_MOUSE_KEYS
#define USE_MACROS

#ifdef USE_MACROS
  #define USE_KALEIDOSCOPE_MAGIC_COMBO
#endif USE_MACROS

#define USE_TOPSY_TURVY
#define USE_LED_CONTROL
#ifdef USE_LED_CONTROL
  #define USE_LED_EFFECT_BOOT_GREETING
// #define USE_LED_EFFECT_SOLID_COLOR

  #ifdef USE_LED_EFFECT_SOLID_COLOR
    #define USE_LED_EFFECT_SOLID_RED
    #define USE_LED_EFFECT_SOLID_ORANGE  
    #define USE_LED_EFFECT_SOLID_YELLOW
    #define USE_LED_EFFECT_SOLID_GREEN
    #define USE_LED_EFFECT_SOLID_BLUE
    #define USE_LED_EFFECT_SOLID_INDIGO
    #define USE_LED_EFFECT_SOLID_VIOLET
  #endif USE_LED_EFFECT_SOLID_COLOR

// #define USE_LED_EFFECT_BREATHE
// #define USE_LED_EFFECT_CHASE
// #define USE_LED_EFFECT_RAINBOW
// #define USE_LED_STALKER
// #define USE_LED_ALPHASQUARE

  // #define USE_LED_PALETTE_THEME  
  #ifdef USE_LED_PALETTE_THEME
    #define USE_COLORMAP
  #endif USE_LED_PALETTE_THEME
  
  #define USE_FUNCTIONAL_COLORS
  
    #ifdef USE_FUNCTIONAL_COLORS
      #define USE_FUNCTIONAL_COLOR_CUSTOM
      // #define USE_FUNCTIONAL_COLOR_DEFAULT
      // #define USE_FUNCTIONAL_COLOR_FRUIT
      // #define USE_FUNCTIONAL_COLOR_MONO
      // #define USE_FUNCTIONAL_COLOR_DUO
      // #define USE_FUNCTIONAL_COLOR_PRINCESS
      // #define USE_FUNCTIONAL_COLOR_SEA
      // #define USE_FUNCTIONAL_COLOR_FLOWER
      // #define USE_FUNCTIONAL_COLOR_KIDS
      // #define USE_FUNCTIONAL_COLOR_RED_WHITE_BLUE
    #endif USE_FUNCTIONAL_COLORS

  #define USE_ACTIVE_MOD_COLOR
  #define USE_IDLE_LEDS
  
  #ifdef USE_IDLE_LEDS
    #define IDLE_LEDS_TIMEOUT 600
  #endif USE_IDLE_LEDS
  
#endif USE_LED_CONTROL

#define USE_HOST_POWER_MANAGEMENT

#define USE_ONE_SHOT
#ifdef USE_ONE_SHOT
  #define ONE_SHOT_STICKY_TIMEOUT 300
  // #define USE_ENABLE_AUTO_ONE_SHOT
#endif USE_ONE_SHOT

// #define USE_SPACE_CADET
// #define USE_STENO
// #define USE_NUMPAD
// DO NOT DEFINE USE_NUMPAD
 