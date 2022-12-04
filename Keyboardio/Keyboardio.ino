/*

MUST USE keyboardio GD32 version 1.99.7 and Arduino 
Version: 2.0.1
Date: 2022-10-27T13:26:40.924Z
CLI Version: 0.28.0 [06fb1909]

Copyright © 2022 Arduino SA 

All work as expected.

Copyright © 2022 Arduino SA
*/

/* -*- mode: c++ -*-

 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "configuration.h"

// The Kaleidoscope core
#include "Kaleidoscope.h"

#ifdef USE_EEPROM
  // Support for storing the keymap in EEPROM
  #include "Kaleidoscope-EEPROM-Settings.h"
  #ifdef USE_EEPROM_KEYMAP
  #include "Kaleidoscope-EEPROM-Keymap.h"
  #endif USE_EEPROM_KEYMAP
#endif USE_EEPROM

#ifdef USE_FOCUS_SERIAL
// Support for communicating with the host via a simple Serial protocol
#include "Kaleidoscope-FocusSerial.h"
   #ifdef USE_FIRMWARE_VERSION
   // Support for querying the firmware version via Focus
   #include "Kaleidoscope-FirmwareVersion.h"
   #endif USE_FIRMWARE_VERSION
#endif USE_FOCUS_SERIAL

#ifdef USE_MOUSE_KEYS
// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"
#endif USE_MOUSE_KEYS

#ifdef USE_MACROS
// Support for macros
#include "Kaleidoscope-Macros.h"
#endif USE_MACROS

#ifdef USE_LED_CONTROL
// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"
  #ifdef USE_LED_EFFECT_BOOT_GREETING
  // Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
  // when the keyboard is connected to a computer (or that computer is powered on)
  #include "Kaleidoscope-LEDEffect-BootGreeting.h"
  #endif USE_LED_EFFECT_BOOT_GREETING
 
  #ifdef USE_LED_EFFECT_SOLID_COLOR
  // Support for LED modes that set all LEDs to a single color
  #include "Kaleidoscope-LEDEffect-SolidColor.h"
  #endif USE_LED_EFFECT_SOLID_COLOR

  #ifdef USE_LED_EFFECT_BREATHE
  // Support for an LED mode that makes all the LEDs 'breathe'
  #include "Kaleidoscope-LEDEffect-Breathe.h"
  #endif USE_LED_EFFECT_BREATHE

  #ifdef USE_LED_EFFECT_CHASE  
  // Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
  #include "Kaleidoscope-LEDEffect-Chase.h"
  #endif USE_LED_EFFECT_CHASE

  #ifdef USE_LED_EFFECT_RAINBOW
  // Support for LED modes that pulse the keyboard's LED in a rainbow pattern
  #include "Kaleidoscope-LEDEffect-Rainbow.h"
  #endif USE_LED_EFFECT_RAINBOW

  #ifdef USE_LED_STALKER
  // Support for an LED mode that lights up the keys as you press them
  #include "Kaleidoscope-LED-Stalker.h"
  #endif USE_LED_STALKER

  #ifdef USE_LED_ALPHASQUARE
  // Support for an LED mode that prints the keys you press in letters 4px high
  #include "Kaleidoscope-LED-AlphaSquare.h"
  #endif USE_LED_ALPHASQUARE

  #ifdef USE_LED_PALETTE_THEME
  // Support for shared palettes for other plugins, like Colormap below
  #include "Kaleidoscope-LED-Palette-Theme.h"

      #ifdef USE_COLORMAP  
      // Support for an LED mode that lets one configure per-layer color maps
      #include "Kaleidoscope-Colormap.h"
      #endif USE_COLORMAP

   #endif USE_LED_PALETTE_THEME

   #ifdef USE_IDLE_LEDS
   // Support for turning the LEDs off after a certain amount of time
   #include "Kaleidoscope-IdleLEDs.h"
   #endif USE_IDLE_LEDS

   #ifdef USE_EEPROM
      // Support for setting and saving the default LED mode
      #ifdef USE_DEFAULT_LED_MODE_CONFIG
      #include "Kaleidoscope-DefaultLEDModeConfig.h"
      #endif USE_DEFAULT_LED_MODE_CONFIG
   #endif USE_EEPROM
   
  // Show status of mod buttons
  #ifdef USE_ACTIVE_MOD_COLOR
  #include <Kaleidoscope-LED-ActiveModColor.h>
  #endif USE_ACTIVE_MOD_COLOR

  #ifdef USE_NUMPAD
  // Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
  #include "Kaleidoscope-NumPad.h"
  #endif USE_NUMPAD
#endif USE_LED_CONTROL

#ifdef USE_HARDWARE_TEST_MODE
// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-HardwareTestMode.h"
#endif USE_HARDWARE_TEST_MODE

#ifdef USE_HOST_POWER_MANAGEMENT
// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"
#endif USE_HOST_POWER_MANAGEMENT

#ifdef USE_KALEIDOSCOPE_MAGIC_COMBO
// Support for magic combos (key chords that trigger an action)
#include "Kaleidoscope-MagicCombo.h"
#endif USE_KALEIDOSCOPE_MAGIC_COMBO

// Support for USB quirks, like changing the key state report protocol
#include "Kaleidoscope-USB-Quirks.h"

// Support for secondary actions on keys
#include "Kaleidoscope-Qukeys.h"
#ifdef USE_ONE_SHOT
// Support for one-shot modifiers and layer keys
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Escape-OneShot.h"
#endif USE_ONE_SHOT

#ifdef USE_DYNAMIC_MACROS
// Support for dynamic, Chrysalis-editable macros
#include <Kaleidoscope-DynamicMacros.h>
#endif USE_DYNAMIC_MACROS

#ifdef USE_SPACE_CADET
// Support for SpaceCadet keys
#include "Kaleidoscope-SpaceCadet.h"
#endif USE_SPACE_CADET

#ifdef USE_LAYER_NAMES
// Support for editable layer names
#include "Kaleidoscope-LayerNames.h"
#endif USE_LAYER_NAMES

#ifdef USE_STENO
// Support for the GeminiPR Stenography protocol
#include "Kaleidoscope-Steno.h"
#endif USE_STENO

#ifdef USE_TOPSY_TURVY
#include <Kaleidoscope-TopsyTurvy.h>
#endif USE_TOPSY_TURVY

#ifdef USE_AUTO_SHIFT
#include <Kaleidoscope-AutoShift.h>
#endif USE_AUTO_SHIFT

/** This 'enum' is a list of all the macros used by the Model 100's firmware

  * The names aren't particularly important. What is important is that each
  * is unique.
  *
  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

enum {
#ifdef USER  
  MACRO_USER,
#endif USER
  MACRO_VERSION_INFO,
#ifdef USE_SPACE_CADET,
  MACRO_SWITCH_SPACE_CADET,
  MACRO_SWITCH_SPACE_CADET2,
#endif
  MACRO_FCDOWN,
  MACRO_FCUP
};

/** The Model 100's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs/keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs/consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs/sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs/keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   keeping NUM and FN consistent and accessible on all layers
  *
  * The PROG key is special, since it is how you indicate to the board that you
  * want to flash the firmware. However, it can be remapped to a regular key.
  * When the keyboard boots, it first looks to see whether the PROG key is held
  * down; if it is, it simply awaits further flashing instructions. If it is
  * not, it continues loading the rest of the firmware and the keyboard
  * functions normally, with whatever binding you have set to PROG. More detail
  * here: https://community.keyboard.io/t/how-the-prog-key-gets-you-into-the-bootloader/506/8
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  *
  */
enum {
  PRIMARY,
#ifdef USE_SPACE_CADET
  SECONDARY,  
#endif USE_SPACE_CADET,
  NUMPAD,
  FUNCTION
};  // layers

/**
  * To change your keyboard's layout from QWERTY to DVORAK or COLEMAK, comment out the line
  *
  * #define PRIMARY_KEYMAP_QWERTY
  *
  * by changing it to
  *
  * // #define PRIMARY_KEYMAP_QWERTY
  *
  * Then uncomment the line corresponding to the layout you want to use.
  *
  */

#ifdef USE_MACROS
	#ifdef USER
	static void user(uint8_t keyState) {  // triggered from single key, so needs keyToggledOn
	  if (keyToggledOn(keyState)) {
	    Macros.type(PSTR(USER));
	  }
	}
	#endif USER

	#ifdef USE_KALEIDOSCOPE_MAGIC_COMBO
		#ifdef PASSWORD
		// this is triggered by magic combo, so do not check if keyToggledOn
		static void pass(uint8_t key_state) {
		  Macros.type(PSTR(PASSWORD));
		}
		#endif PASSWORD

		#ifdef PASSWORD2
		static void pass2(uint8_t key_state) {
		  Macros.type(PSTR(PASSWORD2));
		}
		#endif PASSWORD2
		#ifdef PASSWORD3
		static void pass3(uint8_t keyState) {
		   Macros.type(PSTR(PASSWORD3));
		}
		#endif PASSWORD3
	#endif USE_KALEIDOSCOPE_MAGIC_COMBO

	static void versionInfoMacro(uint8_t key_state) {
	  if (keyToggledOn(key_state)) {
	    Macros.type(PSTR(BUILD_INFORMATION));
	  }
	}

#ifdef USE_SPACE_CADET
  static void toggleSpaceCadet2(uint8_t key_state) {
    toggleSpaceCadet(key_state);    
  }
#endif USE_SPACE_CADET

#ifdef USE_SPACE_CADET
  static void toggleSpaceCadet(uint8_t key_state) {
	  if (keyToggledOn(key_state)) {
#ifdef USE_ONE_SHOT
  #ifdef DEBUGGING
		  Macros.type(PSTR("Toggling Auto One Shot Modifiers\n"));
  #endif DEBUGGING
		  OneShot.toggleAutoModifiers();
#endif USE_ONE_SHOT
#ifdef USE_AUTO_SHIFT
  #ifdef DEBUGGING
		  Macros.type(PSTR("Toggling Auto Shift\n"));
  #endif DEBUGGING
      AutoShift.toggle();
#endif USE_AUTO_SHIFT
		  if (SpaceCadet.active()) {
    #ifdef DEBUGGING
		    Macros.type(PSTR("Space Cadet was active, toggling off\n"));
		#endif DEBUGGING
        SpaceCadet.disable();
        Layer.move(PRIMARY);
		  }
		  else {
      #ifdef DEBUGGING      
		    Macros.type(PSTR("Space Cadet was not active, toggling on\n"));    
		  #endif DEBUGGING
        SpaceCadet.enable();
        Layer.move(SECONDARY);
		  } 
	  }
  }
#endif USE_SPACE_CADET

	/** anyKeyMacro is used to provide the functionality of the 'Any' key.
	 *
	 * When the 'any key' macro is toggled on, a random alphanumeric key is
	 * selected. While the key is held, the function generates a synthetic
	 * keypress event repeating that randomly selected key.
	 *
	 */

	// static void anyKeyMacro(KeyEvent &event) {
	//   if (keyToggledOn(event.state)) {
	//     event.key.setKeyCode(Key_A.getKeyCode() + (uint8_t)(millis() % 36));
	//     event.key.setFlags(0);
	//   }
	// }

#endif USE_MACROS
/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// clang-format off
KEYMAPS(
#if defined (PRIMARY_KEYMAP_QWERTY)
  [PRIMARY] = KEYMAP_STACKED
  (___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   M(MACRO_ANY),  Key_6, Key_7, Key_8,     Key_9,         Key_0,         LockLayer(NUMPAD),
   Key_Enter,     Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                  Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   Key_RightAlt,  Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

#elif defined (PRIMARY_KEYMAP_DVORAK)

  [PRIMARY] = KEYMAP_STACKED
  (___,          Key_1,         Key_2,     Key_3,      Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Quote,     Key_Comma, Key_Period, Key_P, Key_Y, Key_Tab,
   Key_PageUp,   Key_A,         Key_O,     Key_E,      Key_U, Key_I,
   Key_PageDown, Key_Semicolon, Key_Q,     Key_J,      Key_K, Key_X, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   M(MACRO_ANY),   Key_6, Key_7, Key_8, Key_9, Key_0, LockLayer(NUMPAD),
   Key_Enter,      Key_F, Key_G, Key_C, Key_R, Key_L, Key_Slash,
                   Key_D, Key_H, Key_T, Key_N, Key_S, Key_Minus,
   Key_RightAlt,   Key_B, Key_M, Key_W, Key_V, Key_Z, Key_Equals,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

#elif defined (PRIMARY_KEYMAP_COLEMAK)

  [PRIMARY] = KEYMAP_STACKED
  (___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Q, Key_W, Key_F, Key_P, Key_B, Key_Tab,
   Key_PageUp,   Key_A, Key_R, Key_S, Key_T, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_D, Key_V, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   M(MACRO_ANY),  Key_6, Key_7, Key_8,     Key_9,         Key_0,         LockLayer(NUMPAD),
   Key_Enter,     Key_J, Key_L, Key_U,     Key_Y,         Key_Semicolon, Key_Equals,
                  Key_M, Key_N, Key_E,     Key_I,         Key_O,         Key_Quote,
   Key_RightAlt,  Key_K, Key_H, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),
#elif defined (PRIMARY_KEYMAP_CUSTOM)
  // Edit this keymap to make a custom layout
  [PRIMARY] = KEYMAP_STACKED
  (___, 
#ifdef USE_TOPSY_TURVY
        TOPSY(1),      TOPSY(2),  TOPSY(3),   TOPSY(4), TOPSY(5), 
#else
		    Key_1,         Key_2,     Key_3,      Key_4,    Key_5, 
#endif TOPSY_TURVY
#ifdef USE_SPACE_CADET
                                                                M(MACRO_SWITCH_SPACE_CADET),
#else
                                                                ___,
#endif USE_SPACE_CADET                                                                   
   Key_Backtick, Key_Quote,     Key_Comma, Key_Period, Key_P, Key_Y, Key_Tab,
   Key_PageUp,   Key_A,         Key_O,     Key_E,      Key_U, Key_I,
   Key_PageDown, Key_Semicolon, Key_Q,     Key_J,      Key_K, Key_X, Key_Escape,
	#if defined(USE_ONE_SHOT) && !defined(USE_ENABLE_AUTO_ONE_SHOT)
	   OSM(LeftControl), Key_Backspace, OSM(LeftShift), OSM(LeftGui),
	   OSL(NUMPAD),
	#else 
	   Key_LeftControl, Key_Backspace, Key_LeftShift, Key_LeftGui, 
	   ShiftToLayer(NUMPAD),
	#endif USE_ONE_SHOT && ! USE_ENABLE_AUTO_ONE_SHOT
	#if defined(USE_MACROS) && defined(USER)
	   M(MACRO_USER),   
	#else 
	   ___,
	#endif USE_MACROS && USER

	#ifdef USE_TOPSY_TURVY
	   TOPSY(6), TOPSY(7), TOPSY(8), TOPSY(9), TOPSY(0), 
	#else
	   Key_6,    Key_7,    Key_8,    Key_9,    Key_0, 
	#endif USE_TOPSY_TURVY
                                                      LockLayer(NUMPAD),
   Key_Enter, Key_F, Key_G, Key_C, Key_R, Key_L, Key_Slash,
              Key_D, Key_H, Key_T, Key_N, Key_S, Key_Minus,
	#if defined(USE_ONE_SHOT) && !defined(USE_ENABLE_AUTO_ONE_SHOT)
	   OSM(RightGui),   Key_B, Key_M, Key_W, Key_V, Key_Z, Key_Equals,
	   OSM(LeftAlt), OSM(RightShift), Key_Spacebar, OSM(RightControl),
	   OSL(FUNCTION)),
	#else
	   Key_RightGui,   Key_B, Key_M, Key_W, Key_V, Key_Z, Key_Equals,
	   Key_LeftAlt, Key_RightShift,  Key_Spacebar, Key_RightControl,
	   ShiftToLayer(FUNCTION)),
	#endif USE_ONE_SHOT && ! USE_ENABLE_AUTO_ONE_SHOT
#else

#error "No default keymap defined. You should make sure that you have a line like '#define PRIMARY_KEYMAP_QWERTY' in your sketch"

#endif LAYERS

#ifdef USE_SPACE_CADET
[SECONDARY] = KEYMAP_STACKED
(
     ___, ___, ___, ___, ___, ___, M(MACRO_SWITCH_SPACE_CADET2),
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,
),
#endif USE_SPACE_CADET
     
  [NUMPAD] =  KEYMAP_STACKED
  (
   ___, ___, ___, ___, ___, ___, Key_LEDEffectNext,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,
#ifdef USE_MACROS
    M(MACRO_VERSION_INFO),
#else
    ___,
#endif USE_MACROS
                           ___, Key_7, Key_8,   Key_9,        Key_KeypadSubtract, ___,
   ___,                    ___, Key_4, Key_5,   Key_6,        Key_KeypadAdd,      ___,
                           ___, Key_1, Key_2,   Key_3,        Key_Equals,         ___,
   ___,                    ___, Key_0, Key_Period, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___),

  [FUNCTION] =  KEYMAP_STACKED
  (
   ___, Key_F1,           Key_F2,      Key_F3,     Key_F4,         Key_F5,           Key_CapsLock,
   Key_Tab,  Key_mouseScrollUp,  Key_mouseUp, Key_mouseScrollDn,        Key_mouseBtnL, Key_mouseWarpEnd, Key_mouseWarpNE,
   Key_Home, Key_mouseL,       Key_mouseDn, Key_mouseR, Key_mouseBtnR, Key_mouseWarpNW,
   Key_End,  Key_PrintScreen,  Key_Insert,  ___,        Key_mouseBtnM, Key_mouseWarpSW,  Key_mouseWarpSE,
   ___, Key_Delete, ___, ___,
   ___,

   Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_F11,
   ___,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_F12,
                               Key_LeftArrow,          Key_DownArrow,            Key_UpArrow,              Key_RightArrow,
#ifdef USE_MACROS
  #ifdef USE_FUNCTIONAL_COLORS
                                                                                                                            M(MACRO_FCDOWN), M(MACRO_FCUP),
  #else
                                                                                                                            ___, ___,
  #endif USE_FUNCTIONAL_COLORS
#else
                                                                                                                            ___, ___,
#endif USE_MACROS
   Key_PcApplication,          Consumer_Mute,          Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,    Key_Pipe,
   ___, ___, Consumer_PlaySlashPause, ___,
   ___)

)
/* Re-enable astyle's indent enforcement */
// clang-format on

#ifdef USE_LED_CONTROL
#ifdef USE_FUNCTIONAL_COLORS
  /******************** ADD FUNCTIONALCOLOR CONFIGURATION HERE ********************/
  //Include FunctionalColor before creating your color override list and creating FC instances
  #include "Kaleidoscope-LEDEffect-FunctionalColor.h"
  //Add this line if you don't want to have to prefix colors and functions with kaleidoscope::LEDFunctionalColor
  using namespace kaleidoscope::plugin::LEDFunctionalColor;
  // No arguments are needed to use the default theme and brightness.
    #ifdef USE_FUNCTIONAL_COLOR_CUSTOM
    FC_START_COLOR_LIST(customColors)
    //// // Set the color of keys with brightness macros
    //// // Use any number of FCGROUPKEYs above a FC_KEYCOLOR to set several keys to the same color

    FC_GROUPKEY(Key_mouseBtnL)
    FC_GROUPKEY(Key_mouseBtnM)
    FC_KEYCOLOR(Key_mouseBtnR, dim(orange, 255))
    #ifdef USER
    FC_KEYCOLOR(M(MACRO_USER), dim(orangered,255))
    #endif USER
    FC_KEYCOLOR(M(MACRO_VERSION_INFO), dim(yellowgreen, 255)) 
    #ifdef USE_SPACE_CADET
    FC_KEYCOLOR(M(MACRO_SWITCH_SPACE_CADET), dim(greenyellow, 255))
    FC_KEYCOLOR(M(MACRO_SWITCH_SPACE_CADET2), dim(skyblue, 255))
    #endif USE_SPACE_CADET
    FC_KEYCOLOR(M(MACRO_FCDOWN), dim(blue,255))
    FC_KEYCOLOR(M(MACRO_FCUP), dim(blue,255))
    FC_KEYCOLOR(Key_mouseScrollDn, dim(orange,128))
    FC_KEYCOLOR(Key_mouseScrollUp, dim(orange,128))
    FC_GROUPKEY(Key_F1)
    FC_GROUPKEY(Key_F2)
    FC_GROUPKEY(Key_F3)
    FC_GROUPKEY(Key_F4)
    FC_GROUPKEY(Key_F5)
    FC_GROUPKEY(Key_F6)
    FC_GROUPKEY(Key_F7)
    FC_GROUPKEY(Key_F8)
    FC_GROUPKEY(Key_F9)
    FC_GROUPKEY(Key_F10)
    FC_GROUPKEY(Key_F11)
    FC_KEYCOLOR(Key_F12, dim(coral, 128))
    FC_KEYCOLOR(Key_CapsLock, dim(purple,128 ))
  //// 
  //// //FC_NOCOLOR() makes a key not change color, as if "transparent".
  //// // In this example The key with uparrow won't change color, when uprrow appears on the active layer.

  FC_END_COLOR_LIST_DEFAULT(dim(forestgreen, 255));

  FunctionalColor funColorCustom(FC_COLOR_LIST(customColors));
  #endif USE_FUNCTIONAL_COLOR_CUSTOM

  #ifdef USE_FUNCTIONAL_COLOR_DEFAULT
  FunctionalColor funColorDefault(200, Default);
  #endif USE_FUNCTIONAL_COLOR_FRUIT

  #ifdef USE_FUNCTIONAL_COLOR_FRUIT
  FunctionalColor funColorFruit(200, Fruit);
  #endif USE_FUNCTIONAL_COLOR_FRUIT

  #ifdef USE_FUNCTIONAL_COLOR_MONO
  FunctionalColor funColorMono(200, Mono);
  #endif USE_FUNCTIONAL_COLOR_MONO

  #ifdef USE_FUNCTIONAL_COLOR_DUO
  FunctionalColor funColorDuo(200, Duo);
  #endif USE_FUNCTIONAL_COLOR_DUO

  #ifdef USE_FUNCTIONAL_COLOR_PRINCESS
  FunctionalColor funColorPrincess(200, Princess);
  #endif USE_FUNCTIONAL_COLOR_PRINCESS

  #ifdef USE_FUNCTIONAL_COLOR_SEA
  FunctionalColor funColorSea(200, Sea);
  #endif USE_FUNCTIONAL_COLOR_SEA

  #ifdef USE_FUNCTIONAL_COLOR_FLOWER
  FunctionalColor funColorFlower(200, Flower);
  #endif USE_FUNCTIONAL_COLOR_FLOWER

  #ifdef USE_FUNCTIONAL_COLOR_KIDS
  FunctionalColor funColorKids(200, Kids);
  #endif USE_FUNCTIONAL_COLOR_KIDS

  #ifdef USE_FUNCTIONAL_COLOR_RED_WHITE_BLUE
  FunctionalColor funColorRedWhiteBlue(200, RedWhiteBlue);
  #endif USE_FUNCTIONAL_COLOR_RED_WHITE_BLUE

#endif USE_FUNCTIONAL_COLORS

#endif USE_LED_CONTROL

#ifdef USE_MACROS
/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  switch (macro_id) {
    #ifdef USER
    case MACRO_USER:
      user(event.state);
    break;
    #endif USER
    #ifdef USE_SPACE_CADET
    case MACRO_SWITCH_SPACE_CADET:
    case MACRO_SWITCH_SPACE_CADET2:
      toggleSpaceCadet(event.state);
    break;
    #endif USE_SPACE_CADET
    case MACRO_VERSION_INFO:
      versionInfoMacro(event.state);
    break;
#ifdef USE_FUNCTIONAL_COLORS
    /******************** FUNCTIONALCOLOR MACROS GO HERE ********************/
    // Here are macros that control the brightness of the active FunctionalColor instance.
    // These names must be in the macros enum near the beginning of this file.
    // Assign M(MACRO_FCUP) and M(MACRO_FCDOWN) to keys you'd like to use for this purpose.
    // In this example they have been assigned to the semicolon and comma keys on the fn layer.
    case MACRO_FCUP:
      FunctionalColor::brightnessUp(event.state);
      break;

    case MACRO_FCDOWN:
      FunctionalColor::brightnessDown(event.state);
      break;
#endif USE_FUNCTIONAL_COLORS
  }
  return MACRO_NONE;
}
#endif USE_MACROS

#ifdef USE_LED_CONTROL
	#ifdef USE_LED_EFFECT_SOLID_COLOR
	// These 'solid' color effect definitions define a rainbow of
	// LED color modes calibrated to draw 500mA or less on the
	// Keyboardio Model 100.
    #ifdef USE_LED_EFFECT_SOLID_RED
    static kaleidoscope::plugin::LEDSolidColor solidRed(160, 0, 0);
    #endif USE_LED_EFFECT_SOLID_RED
    #ifdef USE_LED_EFFECT_SOLID_ORANGE  
    static kaleidoscope::plugin::LEDSolidColor solidOrange(140, 70, 0);
    #endif USE_LED_EFFECT_SOLID_ORANGE
    #ifdef USE_LED_EFFECT_SOLID_YELLOW
    static kaleidoscope::plugin::LEDSolidColor solidYellow(130, 100, 0);
    #endif USE_LED_EFFECT_SOLID_YELLOW
    #ifdef USE_LED_EFFECT_SOLID_GREEN
    static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
    #endif USE_LED_EFFECT_SOLID_GREEN
    #ifdef USE_LED_EFFECT_SOLID_BLUE
    static kaleidoscope::plugin::LEDSolidColor solidBlue(0, 70, 130);
    #endif USE_LED_EFFECT_SOLID_BLUE
    #ifdef USE_LED_EFFECT_SOLID_INDIGO
    static kaleidoscope::plugin::LEDSolidColor solidIndigo(0, 0, 170);
    #endif USE_LED_EFFECT_SOLID_INDIGO
    #ifdef USE_LED_EFFECT_SOLID_VIOLET
    static kaleidoscope::plugin::LEDSolidColor solidViolet(130, 0, 120);
    #endif USE_LED_EFFECT_SOLID_VIOLET
  #endif USE_LED_EFFECT_SOLID_COLOR

  #ifdef USE_HOST_POWER_MANAGEMENT
// toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep.
void toggleLedsOnSuspendResume(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    LEDControl.disable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.enable();
    LEDControl.refreshAll();
    #ifdef USE_SPACE_CADET
		if (SpaceCadet.active()) {
      #ifdef USE_ONE_SHOT
		  OneShot.toggleAutoOneShot();
      #endif USE_ONE_SHOT
      SpaceCadet.disable();
    }
    #endif USE_SPACE_CADET
    #ifdef USE_AUTO_SHIFT
    AutoShift.disable();
    #endif USE_AUTO_SHIFT
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}
  #endif USE_HOST_POWER_MANAGEMENT
#endif USE_LED_CONTROL

#ifdef USE_KALEIDOSCOPE_MAGIC_COMBO
  /** This 'enum' is a list of all the magic combos used by the Model 100's
  * firmware The names aren't particularly important. What is important is that
  * each is unique.
  *
  * These are the names of your magic combos. They will be used by the
  * `USE_MAGIC_COMBOS` call below.
  */
  enum {
    // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
    // mode.
    COMBO_TOGGLE_NKRO_MODE,
    // Enter test mode
    COMBO_ENTER_TEST_MODE
  };

  /** Wrappers, to be used by MagicCombo. **/

  /**
  * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
  * a function with an unused argument, to match what MagicCombo expects.
  */
  static void toggleKeyboardProtocol(uint8_t combo_index) {
    USBQuirks.toggleKeyboardProtocol();
  }

  /**
  * Toggles between using the built-in keymap, and the EEPROM-stored one.
  */
  #ifdef USE_EEPROM
    #ifdef USE_EEPROM_KEYMAP
    static void toggleKeymapSource(uint8_t combo_index) {
      if (Layer.getKey == Layer.getKeyFromPROGMEM) {
        Layer.getKey = EEPROMKeymap.getKey;
      } else {
        Layer.getKey = Layer.getKeyFromPROGMEM;
      }
    }
    #endif USE_EEPROM_KEYMAP
  #endif USE_EEPROM

  #ifdef USE_HARDWARE_TEST_MODE
    /**
    *  This enters the hardware test mode
    */
    static void enterHardwareTestMode(uint8_t combo_index) {
      HardwareTestMode.runTests();
    }
  #endif USE_HARDWARE_TEST_MODE


  /** Magic combo list, a list of key combo and action pairs the firmware should
  * recognise.
  */
  USE_MAGIC_COMBOS(
                  { .action = toggleKeyboardProtocol,
                    // Left Fn + Esc + cmd
                    .keys = { R3C6, R2C6, R3C7 } }
  #ifdef USE_HARDWARE_TEST_MODE
                    ,

                  { .action = enterHardwareTestMode,
                    // Left Fn + Prog + LED
                    .keys = { R3C6, R0C0, R0C6 } }
  #endif USE_HARDWARE_TEST_MODE

  #ifdef PASSWORD
    #ifdef PASS_MACRO
                    ,
                  { .action = pass,
                    .keys = { PASS_MACRO} }
    #endif PASS_MACRO
  #endif PASSWORD
  #ifdef PASSWORD2
    #ifdef PASS_MACRO_2
                    ,
                  { .action = pass2,
                    .keys = { PASS_MACRO_2 } }
    #endif PASS_MACRO_2
  #endif PASSWORD2
  #ifdef USE_EEPROM
    #ifdef USE_EEPROM_KEYMAP
                    ,
                  {.action = toggleKeymapSource,
                  // Left Fn + Prog + Cmd
                  .keys = {R3C6, R0C0, R3C7}}
    #endif USE_EEPROM_KEYMAP
  #endif USE_EEPROM
                    );
#endif USE_KALEIDOSCOPE_MAGIC_COMBO
// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
#ifdef USE_EEPROM
  #ifdef USE_EEPROM_KEYMAP
    // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
    // editable keymap in EEPROM.
    EEPROMSettings,
    EEPROMKeymap,
  #endif USE_EEPROM_KEYMAP
#endif USE_EEPROM

#ifdef USE_SPACE_CADET
  // SpaceCadet can turn your shifts into parens on tap, while keeping them as
  // Shifts when held. SpaceCadetConfig lets Chrysalis configure some aspects of
  // the plugin.
  SpaceCadet,
  SpaceCadetConfig,
#endif USE_SPACE_CADET

#ifdef USE_AUTO_SHIFT
  AutoShift,
  AutoShiftConfig, // for AutoShiftConfig
#endif USE_AUTO_SHIFT

#ifdef USE_EEPROM
	#ifdef USE_FOCUS_SERIAL
  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  Focus,
  // FocusSettingsCommand adds a few Focus commands, intended to aid in
  // changing some settings of the keyboard, such as the default layer (via the
  // `settings.defaultLayer` command)
  FocusSettingsCommand,
  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  FocusEEPROMCommand,
  #endif USE_FOCUS_SERIAL
#endif USE_EEPROM
#ifdef USE_LED_CONTROL
	#ifdef USE_LED_EFFECT_BOOT_GREETING
    // The boot greeting effect pulses the LED button for 10 seconds after the keyboard is first connected
    BootGreetingEffect,
  #endif USE_LED_EFFECT_BOOT_GREETING
  #ifdef USE_LEB_EFFECT_BOOT_ANIMATION
    BootAnimationEffect,
  #endif USE_LED_EFFECT_BOOT_ANIMATION
#endif USE_LED_CONTROL

#ifdef USE_HARDWARE_TEST_MODE
  // The hardware test mode, which can be invoked by tapping Prog, LED and the
  // left Fn button at the same time.
  HardwareTestMode,
#endif USE_HARDWARE_TEST_MODE

#ifdef USE_LED_CONTROL
#ifdef USE_FUNCTIONAL_COLORS
  /********************** FUNCTIONALCOLOR EFFECTS INITIALIZED HERE **********************/
  // All FunctionalColor instances go here in the order you want them in
  // FunctionalColor map defined previously
  #ifdef USE_FUNCTIONAL_COLOR_CUSTOM
  funColorCustom,
  #endif USE_FUNCTIONAL_COLOR_CUSTOM

  #ifdef USE_FUNCTIONAL_COLOR_DEFAULT
  funColorDefault,
  #endif USE_FUNCTIONAL_COLOR_DEFAULT

  #ifdef USE_FUNCTIONAL_COLOR_FRUIT
  funColorFruit,
  #endif USE_FUNCTIONAL_COLOR_FRUIT

  #ifdef USE_FUNCTIONAL_COLOR_MONO
  funColorMono,
  #endif USE_FUNCTIONAL_COLOR_MONO

  #ifdef USE_FUNCTIONAL_COLOR_DUO
  funColorDuo,
  #endif USE_FUNCTIONAL_COLOR_DUO

  #ifdef USE_FUNCTIONAL_COLOR_PRINCESS
  funColorPrincess,
  #endif USE_FUNCTIONAL_COLOR_PRINCESS

  #ifdef USE_FUNCTIONAL_COLOR_SEA
  funColorSea,
  #endif USE_FUNCTIONAL_COLOR_SEA

  #ifdef USE_FUNCTIONAL_COLOR_FLOWER
  funColorFlower,
  #endif USE_FUNCIONAL_COLOR_FLOWER

  #ifdef USE_FUNCTIONAL_COLOR_KIDS
  funColorKids,
  #endif USE_FUNCTIONAL_COLOR_KIDS
  
  #ifdef USE_FUNCTIONAL_COLOR_RED_WHITE_BLUE
  funColorRedWhiteBlue,
  #endif USE_FUNCTIONAL_COLOR_RED_WHITE_BLUE
#endif USE_FUNCTIONAL_COLORS
  
  // LEDControl provides support for other LED modes
  LEDControl,
  LEDOff,

  #ifdef USE_LED_EFFECT_RAINBOW
  // The rainbow effect changes the color of all of the keyboard's keys at the same time
  // running through all the colors of the rainbow.
  LEDRainbowEffect,

  // The rainbow wave effect lights up your keyboard with all the colors of a rainbow
  // and slowly moves the rainbow across your keyboard
  LEDRainbowWaveEffect,
  #endif USE_LED_EFFECT_RAINBOW

  #ifdef USE_LED_EFFECT_CHASE
  // The chase effect follows the adventure of a blue pixel which chases a red pixel across
  // your keyboard. Spoiler: the blue pixel never catches the red pixel
  LEDChaseEffect,
  #endif USE_LED_EFFECT_CHASE

	#ifdef USE_LED_EFFECT_SOLID_COLOR
	  // These static effects turn your keyboard's LEDs a variety of colors
	solidRed,
	solidOrange,
	solidYellow,
	solidGreen,
	solidBlue,
	solidIndigo,
	solidViolet,
	#endif USE_LED_EFFECT_SOLID_COLOR

  #ifdef USE_LED_EFFECT_BREATHE
  // The breathe effect slowly pulses all of the LEDs on your keyboard
  LEDBreatheEffect,
  #endif USE_LED_EFFECT_BREATHE

  #ifdef USE_LED_ALPHASQUARE
  // The AlphaSquare effect prints each character you type, using your
  // keyboard's LEDs as a display
  AlphaSquareEffect,
  #endif USE_LED_ALPHASQUARE

  #ifdef USE_LED_STALKER
  // The stalker effect lights up the keys you've pressed recently
  StalkerEffect,
  #endif USE_LED_STALKER
  
  #ifdef USE_LED_PALETTE_THEME
  // The LED Palette Theme plugin provides a shared palette for other plugins,
  // like Colormap below
  LEDPaletteTheme,

    #ifdef USE_COLORMAP
    // The Colormap effect makes it possible to set up per-layer colormaps
    ColormapEffect,
    #endif USE_COLORMAP

  #endif USE_LED_PALETTE_THEME

#endif USE_LED_CONTROL
#ifdef USE_MACROS
  // The macros plugin adds support for macros
  Macros,
#endif USE_MACROS

#ifdef USE_TOPSY_TURVY
  TopsyTurvy,
#endif USE_TOPSY_TURVY

#ifdef USE_MOUSE_KEYS 
  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  MouseKeys,
#endif USE_MOUSE_KEYS

#ifdef USE_HOST_POWER_MANAGEMENT
  // The HostPowerManagement plugin allows us to turn LEDs off when then host
  // goes to sleep, and resume them when it wakes up.
 HostPowerManagement,
#endif USE_HOST_POWER_MANAGEMENT

#ifdef USE_LED_CONTROL
  #ifdef USE_NUMPAD
    // The numpad plugin is responsible for lighting up the 'numpad' mode
    // with a custom LED effect
    // NumPad,
  #endif USE_NUMPAD
#endif USE_LED_CONTROL  

#ifdef USE_KALEIDOSCOPE_MAGIC_COMBO
  // Magic combo needs to be above Macros (I guess)
  MagicCombo,
#endif USE_KALEIDOSCOPE_MAGIC_COMBO

  // The USBQuirks plugin lets you do some things with USB that we aren't
  // comfortable - or able - to do automatically, but can be useful
  // nevertheless. Such as toggling the key report protocol between Boot (used
  // by BIOSes) and Report (NKRO).
  USBQuirks,

  // The Qukeys plugin enables the "Secondary action" functionality in
  // Chrysalis. Keys with secondary actions will have their primary action
  // performed when tapped, but the secondary action when held.
  Qukeys,

#ifdef USE_ONE_SHOT
  // Enables the "Sticky" behavior for modifiers, and the "Layer shift when
  // held" functionality for layer keys.
  OneShot,
  EscapeOneShot,
  EscapeOneShotConfig,
#endif USE_ONE_SHOT

#ifdef USE_LED_CONTROL
  #ifdef USE_IDLE_LEDS
    // Turns LEDs off after a configurable amount of idle time.
    IdleLEDs,
    PersistentIdleLEDs,
  #endif USE_IDLE_LEDS
#endif  USE_LED_CONTROL

#ifdef USE_DYNAMIC_MACROS
  // Enables dynamic, Chrysalis-editable macros.
  DynamicMacros,
#endif USE_DYNAMIC_MACROS

#ifdef USE_FOCUS_SERIAL
  #ifdef USE_FIRMWARE_VERSION
  // The FirmwareVersion plugin lets Chrysalis query the version of the firmware
  // programmatically.
  FirmwareVersion,
  #endif USE_FIRMWARE_VERSION
  #ifdef USE_LAYER_NAMES
  // The LayerNames plugin allows Chrysalis to display - and edit - custom layer
  // names, to be shown instead of the default indexes.
  LayerNames,
  #endif USE_LAYER_NAMES
#endif USE_FOCUS_SERIAL
#ifdef USE_LED_CONTROL
  #ifdef USE_ACTIVE_MOD_COLOR
  ActiveModColorEffect
  #endif USE_ACTIVE_MOD_COLOR
#endif USE_LED_CONTROL

#ifdef USE_STENO
  // Enables the GeminiPR Stenography protocol. Unused by default, but with the
  // plugin enabled, it becomes configurable - and then usable - via Chrysalis.
  , GeminiPs
#endif USE_STENO
  );

/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();
  
#ifdef USE_LED_CONTROL
	#ifdef USE_LED_EFFECT_BOOT_GREETING
	  // Set the hue of the boot greeting effect to something that will result in a
	  // nice green color.
	  BootGreetingEffect.hue = 85;
  	#endif USE_LED_EFFECT_BOOT_GREETING
#endif USE_LED_CONTROL

#ifdef USE_NUMPAD
  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  NumPad.numPadLayer = NUMPAD;
#endif USE_NUMPAD

#ifdef USE_LED_CONTROL
  #ifdef USE_LED_ALPHASQUARE
  // We configure the AlphaSquare effect to use RED letters
  AlphaSquare.color = CRGB(255, 0, 0);
  #endif USE_LED_ALPHASQUARE
  
  #ifdef USE_LED_EFFECT_RAINBOW
  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  LEDRainbowEffect.brightness(255);
  LEDRainbowWaveEffect.brightness(255);
  #endif USE_LED_EFFECT_RAINBOW
#endif USE_LED_CONTROL

#ifdef USE_HARDWARE_TEST_MODE
  // Set the action key the test mode should listen for to Left Fn
  HardwareTestMode.setActionKey(R3C6);
#endif USE_HARDWARE_TEST_MODE

#ifdef USE_LED_CONTROL
  #ifdef USE_LED_STALKER
  // The LED Stalker mode has a few effects. The one we like is called
  // 'BlazingTrail'. For details on other options, see
  // https://github.com/keyboardio/Kaleidoscope/blob/master/docs/plugins/LED-Stalker.md
  StalkerEffect.variant = STALKER(BlazingTrail);
  #endif USE_LED_STALKER
#endif USE_LED_CONTROL

#ifdef USE_EEPROM
  #ifndef NUM_LAYERS
  #define NUM_LAYERS 3
  #endif NUM_LAYERS
  #ifdef USE_EEPROM_KEYMAP
  // To make the keymap editable without flashing new firmware, we store
  // additional layers in EEPROM. For now, we reserve space for eight layers. If
  // one wants to use these layers, just set the default layer to one in EEPROM,
  // by using the `settings.defaultLayer` Focus command, or by using the
  // `keymap.onlyCustom` command to use EEPROM layers only.
  EEPROMKeymap.setup(NUM_LAYERS);
  #endif USE_EEPROM_KEYMAP

  #ifdef USE_LED_CONTROL
    #ifdef USE_LED_PALETTE_THEME 
      #ifdef USE_COLORMAP
      // We need to tell the Colormap plugin how many layers we want to have custom
      // maps for. To make things simple, we set it to eight layers, which is how
      // many editable layers we have (see above).
      ColormapEffect.max_layers(NUM_LAYERS);
      #endif USE_COLORMAP
    #endif USE_LED_PALETTE_THEME
  #endif USE_LED_CONTROL  

  #ifdef USE_DYNAMIC_MACROS
    // For Dynamic Macros, we need to reserve storage space for the editable
    // macros. A kilobyte is a reasonable default.
    DynamicMacros.reserve_storage(1024); 
  #endif USE_DYNAMIC_MACROS

  #ifdef USE_EEPROM_DEFAULT_LAYER
    // If there's a default layer set in EEPROM, we should set that as the default
    // here.
    Layer.move(EEPROMSettings.default_layer()); 
  #endif USE_EEPROM_DEFAULT_LAYER
#endif USE_EEPROM

#ifdef USE_EEPROM
  #ifdef USE_LAYER_NAMES
    // Editable layer names are stored in EEPROM too, and we reserve 16 bytes per
    // layer for them. We need one extra byte per layer for bookkeeping, so we
    // reserve 17 / layer in total.
    LayerNames.reserve_storage(17 * NUM_LAYERS);
    // Unless configured otherwise with Chrysalis, we want to make sure that the
    // firmware starts with LED effects off. This avoids over-taxing devices that
    // don't have a lot of power to share with USB devices
  #endif USE_LAYER_NAMES

  #ifdef USE_DEFAULT_LED_MODE_CONFIG
  DefaultLEDModeConfig.activateLEDModeIfUnconfigured(&LEDOff);
  #endif USE_DEFAULT_LED_MODE_CONFIG
#endif USE_EEPROM

#ifdef USE_LED_CONTROL
  #ifdef USE_ACTIVE_MOD_COLOR
  ActiveModColorEffect.setOneShotColor(CRGB(0x00, 0xff, 0x00));
  ActiveModColorEffect.setHighlightColor(CRGB(0x00, 0x00, 0xff));
  ActiveModColorEffect.setStickyColor(CRGB(0xff, 0x00, 0x00));
  ActiveModColorEffect.highlightNormalModifiers(true);
  #endif USE_ACTIVE_MOD_COLOR
#endif USE_LED_CONTROL
#ifdef USE_ONE_SHOT
  // Uncomment the following to enable OneShot on normal modifier keys:
  #ifdef USE_ENABLE_AUTO_ONE_SHOT
  OneShot.enableAutoOneShot();
  #endif USE_ENABLE_AUTO_ONE_SHOT
  #ifdef ONE_SHOT_STICKY_TIMEOUT
  OneShot.setStickyTimeOutSeconds(ONE_SHOT_STICKY_TIMEOUT);
  #endif ONE_SHOT_STICKY_TIMEOUT
#endif USE_ONE_SHOT

#ifdef USE_SPACE_CADET
  // To avoid any surprises, SpaceCadet is turned off by default. However, it
  // can be permanently enabled via Chrysalis, so we should only disable it if
  // no configuration exists.
  // SpaceCadetConfig.disableSpaceCadetIfUnconfigured();
    //Set the SpaceCadet map
  //Setting is {KeyThatWasPressed, AlternativeKeyToSend, TimeoutInMS}
  //Note: must end with the SPACECADET_MAP_END delimiter
  static kaleidoscope::plugin::SpaceCadet::KeyBinding spacecadetmap[] = {

    {Key_LeftGui, Key_LeftParen, 250},
    {Key_LeftAlt, Key_RightParen, 250},    
    {Key_LeftShift, Key_LeftCurlyBracket, 250},
    {Key_RightShift, Key_RightCurlyBracket, 250},    
    {Key_LeftControl, Key_LeftBracket, 250},
    {Key_RightControl, Key_RightBracket, 250},
    SPACECADET_MAP_END,
  };
  //Set the map.
  SpaceCadet.setMap(spacecadetmap);
  SpaceCadet.disable();
#endif USE_SPACE_CADET

#ifdef USE_AUTO_SHIFT
    // Enable AutoShift for letter keys and number keys only:
  AutoShift.setEnabled(AutoShift.letterKeys() | AutoShift.numberKeys());
  // Add symbol keys to the enabled categories:
  AutoShift.enable(AutoShift.symbolKeys());
  // Set the AutoShift long-press time to 150ms:
  AutoShift.setTimeout(150);
  // Start with AutoShift turned on:
  AutoShift.enable();
#endif USE_AUTO_SHIFT

#ifdef USE_IDLE_LEDS
  #ifdef IDLE_LEDS_TIMEOUT
    IdleLEDs.setIdleTimeoutSeconds(IDLE_LEDS_TIMEOUT);
  #endif IDLE_LEDS_TIMEOUT
#endif USE_IDLE_LEDS
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}