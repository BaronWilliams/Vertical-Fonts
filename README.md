# Vertical-Fonts
THIS CODE IS CURRENTLY INCOMPLETE. THIS README IS ALSO INCOMPLETE.

This is a collection of bitmap fonts designed for small displays. These are intended for use on an Arduino, but could be easily modified to work on other platforms.

The fonts are given as C source code with header files.

The font bitmaps are designed to be stored in flash using PROGMEM which saves valuable SRAM on an Arduino. On an Arduino Micro, transfering data from flash to SRAM is extremely fast. There's little advantage to storing the font in SRAM.

Included in the code is Font.h and Font.cpp, containing the C++ Font class that has methods allowing easy access to font data stored in flash. For example:

	// Wrap the font in the Font class for easy transfer of data from flash to SRAM.
	Font font ( font7x8 );
	
	// Here we write the 'A' character to display memory using the Arduino Wire class.
	// In this example case the diplay we are writing to is a SSD1306 with 128x64 pixels.
	// The display using I2C, so we use the Wire class to send data to it.
	// The rest of the display code is not in this sample, just the portion where we send
	// the actually font character data.
	int x;
	
	for (x = 0; x < font.data.width; x++ ) {			
		Wire.write ( font.GetBitmapByte( 'A', x) );
	}

All of the fonts are 1 bit per pixel bitmap fonts.

Font data is stored vertically. For example, a 7x8 font will constist of 7 bytes. The first byte being the first column including 8 rows of pixels. Bit 0 is the top pixel. Bit 7 is the bottom pixel. The next column is stored in the next byte, and so on.
