// fontStruct.h

#ifndef _FONTSTRUCT_h
#define _FONTSTRUCT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

typedef struct fontStruct {
	PROGMEM uint8_t * font;
	PROGMEM uint8_t characters;
	PROGMEM uint8_t start;
	PROGMEM uint8_t end;
	PROGMEM uint8_t width;
	PROGMEM uint8_t height;
	PROGMEM uint8_t spacing;
	PROGMEM bool bitAlignVertical;
} fontStruct;

#endif

