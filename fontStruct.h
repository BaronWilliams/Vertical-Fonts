// fontStruct.h

#ifndef _FONTSTRUCT_h
#define _FONTSTRUCT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

typedef struct fontStruct {
	PROGMEM uint8_t * bitmap; // The bitmap data to represent the font
	PROGMEM uint8_t characters; // The number of valid characters in a font
	PROGMEM uint8_t start; // The first valid character in a font
	PROGMEM uint8_t end; // The last valid character in a font
	PROGMEM uint8_t width; // The width of the font in pixels
	PROGMEM uint8_t height; // The height of the font in pixels
	PROGMEM uint8_t spacing; // The horizontal spacing required for a font
	PROGMEM bool bitAlignVertical; // True if the data is stored vertically
} fontStruct;

#endif

