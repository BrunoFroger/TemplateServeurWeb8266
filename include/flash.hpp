// --------------------------------
//
//      flash.hpp
//
// --------------------------------
#include <Arduino.h>

#ifndef __FLASH__
#define __FLASH__

    extern void flashInit(void);
    extern String flashFileRead (const char *filename);

#endif