// FontToRam.hpp

#ifndef _FONTTORAM_hpp
#define _FONTTORAM_hpp

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <fontStruct.h>

class Font {
	public:
	static void ToRAM ( const fontStruct & fontPROGMEM, fontStruct & fontRAM ){
		memcpy_P(&fontRAM, &fontPROGMEM, sizeof(fontStruct));
	};
};

Font FontPROGMEM;

#endif // _FONTTORAM_hpp

