// Font.cpp

#include <Font.h>



Font::Font( const fontStruct & fontPROGMEM )
{
	ToRAM( fontPROGMEM, data );
}

 Font::Font()
{
	data.bitmap = NULL;
}

void Font::SetData( const fontStruct & fontPROGMEM )
{
	ToRAM( fontPROGMEM, data );
}

Font & Font::operator=(const Font &newFont)
{
	this->data = newFont.data;
}
