// fontStruct.h

#ifndef _FONTSTRUCT_h
#define _FONTSTRUCT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

typedef struct fontStruct {
	uint8_t * font;
	uint8_t characters;
	uint8_t start;
	uint8_t end;
	uint8_t width;
	uint8_t height;
	bool bitAlignVertical;
} fontStruct;

#endif

