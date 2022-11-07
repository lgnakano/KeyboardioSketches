#include "passwords.h"
#ifdef ARDUINO_keyboardio_model_100
#include "configurationModel100.h"
#endif

#ifdef ARDUINO_AVR_MODEL01
#include "configurationModel01.h"
#endif

#ifndef BOARD_TYPE
#error "Must define one of BOARD_MODEL100 or BOARD_MODEL01
#endif

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION BOARD_TYPE " locally built on " __DATE__ " at " __TIME__
#endif
