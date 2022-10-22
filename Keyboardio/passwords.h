#define USER "user"
#define PASSWORD "password"
#ifdef PASSWORD
  #define PASS_MACRO R0C0, R0C1
#endif PASSWORD
// #define PASSWORD2
#ifdef PASSWORD2
  #define PASS_MACRO_2 R0C1, R0C2
#endif PASSWORD2
