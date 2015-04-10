// fontStruct.c
// 

#include <fontStruct.h>

void FontToRAM ( const fontStruct * fontPROGMEM, fontStruct * fontRAM ){
	memcpy_P(fontRAM, fontPROGMEM, sizeof(fontStruct));
}