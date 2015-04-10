/*
 * font3x6limited.h
 *
 * Created: 4/8/2015 11:31:21 AM
 *  Author: Baron Williams
 */

#ifndef _FONT3X6LIMITED_h
#define _FONT3X6LIMITED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "fontStruct.h"

extern const fontStruct font3x6limited;

#endif // _FONT3X6LIMITED_h