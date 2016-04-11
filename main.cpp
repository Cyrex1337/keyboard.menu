#include <process.h>
#include "Menu.h"

void hookedRenderFunction( )
{
	Menu::CMenu* pMenu = new Menu::CMenu( "Hallo" );
	pMenu->Add( "What tha fuck", &testfunc );
	pMenu->Draw( );

	Menu::HandleFunctions( pMenu );
}

void MainThread( void* pReserved )
{
	//hook something
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID lpReserved )
{
	if ( dwReason == DLL_PROCESS_ATTACH )
		_beginthread( MainThread, 0, nullptr );

	return TRUE;
}