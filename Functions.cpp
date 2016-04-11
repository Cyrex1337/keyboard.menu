#include "Menu.h"

int testfunc = 0;

void Menu::HandleFunctions( Menu::CMenu* menu )
{
	if ( testfunc )
		MessageBoxA( NULL, "Hallo", "Hallo", 0 );
}