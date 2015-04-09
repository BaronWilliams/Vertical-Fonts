#include "font11x16.h"
#include "font3x6.h"
#include "font5x7.h"
#include "font9x16.h"

void setup()
{

  /* add setup code here */
	int x;
	
	x = font9x16.font[0]; Serial.print( x, DEC );
	x = font3x6.font[0]; Serial.print( x, DEC );
	x = font5x7.font[0]; Serial.print( x, DEC );
	x = font11x16.font[0]; Serial.print( x, DEC );
}

void loop()
{

  /* add main program code here */

}
