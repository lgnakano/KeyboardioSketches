# KeyboardioSketches
Keyboardio Sketch including multiple configurations

Multiple #define clauses are used to toggle in different features in the sketch.

To customize your own version, edit the configurationModel100.h or the configurationModel01.h (depending on which keyboardio you have).

All passwords and Magic Combos used to trigger them are on a passwords.h file. Currently checked in file contains dummy info.

Notice: the configuration I use requires a modified version of the OneShot plugin, and FunctionalColors plugin.
You can get the FunctionalColors plugin here: https://github.com/jdlien/Kaleidoscope-LEDEffect-FunctionalColor, or simply comment out the line that has #define USE_FUNCTIONAL_COLORS if you do not want to use it.
You can keep using the regular OneShot plugin if you do not define ONE_SHOT_STICKY_TIMEOUT on your configuration file, or you can use my branch https://github.com/lgnakano/Kaleidoscope-OneShot/tree/feature/stickyTimeout if you want to have a timeout after which all sticky keys and layers are cleared. I use this because I may walk away from the keyboardio and have it set on a different layer, or even with a mode key sticking, and not remember when I come back. So, after 5 minutes of no keys being pressed, my keyboard goes back to the first layer, with no sticky keys.

Update: Space cadet works now. Since it collides with OneShot, a macro was created that toggles them so either OneShot is enabled or Space Cadet is enabled. Macro is triggered on NumPad layer, Led key.

Further update: I've tried adding AutoShift (which does not seem to work on the model 100) and LEDEffect-BootGreeting, which works fine separately, but is not really visible because it is not the first effect on my sketch.
