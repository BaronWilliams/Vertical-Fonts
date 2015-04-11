// Font.h

#ifndef _FONT_h
#define _FONT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <fontStruct.h>


/**********************************************************************
 * Font Class
 **********************************************************************
 * Description: The Font class simplifies the use of fonts stored in
 *				flash. It includes methods to access the font data in
 *				SRAM.
 *				
 *				By storing font data in flash on an Arduino, we can
 *				free up valuable SRAM. This class allows SRAM access to
 *				the flash data without needing to copy the entire font
 *				data into SRAM.
 *
 * Author: Baron Williams
 **********************************************************************/
class Font {


public:
	/**********************************************************************
	 * public byte Font::Font
	 **********************************************************************
	 * Description: Constructs a new Font class.
	 *				Sets the font data encapsulated by the font class.
	 *				The font must be stored in flash and specified using
	 *				the fontStruct data type.
	 *
	 * Author: Baron Williams
	 **********************************************************************/
	Font ( const fontStruct & fontPROGMEM );
	
	/**********************************************************************
	 * public byte Font::Font
	 **********************************************************************
	 * Description: Constructs a new empty Font class with no associated
	 *				font data.
	 *				
	 *				Use SetData to load font data into the class.
	 *
	 * Author: Baron Williams
	 **********************************************************************/
	Font ();

	/**********************************************************************
	 * public byte Font::SetData
	 **********************************************************************
	 * Description: Sets the font data encapsulated by the font class.
	 *				The font must be stored in flash and specified using
	 *				the fontStruct data type.
	 *
	 * Author: Baron Williams
	 **********************************************************************/
	void SetData ( const fontStruct & fontPROGMEM );

	/**********************************************************************
	 * public byte Font::GetBitmapByte
	 **********************************************************************
	 * Description: Returns a byte in SRAM from the font's bitmap data in
	 *				flash. The bitmap byte returned is specified by giving
	 *				the bitmap byte index. Index 0 is the first byte of
	 *				bitmap data used to represent all characters.
	 *
	 * Author: Baron Williams
	 *
	 * Returns: byte in SRAM from the font's bitmap stored in flash.
	 **********************************************************************/
	byte GetBitmapByte ( int bitmapIndex ) { return GetBitmapByte ( data, bitmapIndex ); }
		
		
	/**********************************************************************
	 * public byte Font::GetBitmapByte
	 **********************************************************************
	 * Description: Returns a byte in SRAM from the font's bitmap data in
	 *				flash. The bitmap byte returned is specified by giving
	 *				the character and it's bitmap byte index. Index 0 is
	 *				the first byte of bitmap data used to represent the
	 *				character.
	 *
	 * Author: Baron Williams
	 *
	 * Returns: byte in SRAM from the font's bitmap stored in flash.
	 **********************************************************************/	
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

