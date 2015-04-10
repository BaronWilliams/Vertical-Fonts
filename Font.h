// Font.h

#ifndef _FONT_h
#define _FONT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <fontStruct.h>

class Font {


public:
	Font ( const fontStruct & fontPROGMEM );
	Font ();

	void SetData ( const fontStruct & fontPROGMEM );

	byte GetBitmapByte ( int bitmapIndex ) { return GetBitmapByte ( data, bitmapIndex ); }
	byte GetBitmapByte ( int character, int bitmapIndex  ) { return GetBitmapByte ( data, character, bitmapIndex ); }

	/**********************************************************************
	 * public byte Font::Start
	 **********************************************************************
	 * Description: Returns the first valid character for a font
	 *
	 *
	 * Author: Baron Williams
	 *
	 * Returns: byte
	 **********************************************************************/
	byte Start () { return data.start; }
	/**********************************************************************
	 * public byte Font::End
	 **********************************************************************
	 * Description: Returns the last valid character for a font
	 *
	 *
	 * Author: Baron Williams
	 *
	 * Returns: byte
	 **********************************************************************/
	byte End () { return data.end; }

	fontStruct data;

	Font & operator=(const Font &newFont);

private:
	static void ToRAM ( const fontStruct & fontPROGMEM, fontStruct & fontRAM ){
		memcpy_P(&fontRAM, &fontPROGMEM, sizeof(fontStruct));
	};

	static byte GetBitmapByte ( fontStruct & fontRAM, int index ){
		return pgm_read_byte_near(fontRAM.bitmap+index);
	};

	static byte GetBitmapByte ( fontStruct & fontRAM, int character, int bitmapIndex ){
		return pgm_read_byte_near(fontRAM.bitmap+((character-fontRAM.start)*fontRAM.width)+bitmapIndex);
	};



};

#endif // _FONT_h

