#include "consola.h"
#include "okna.h"
#include "zdarzenia.h"
#include <windows.h>





int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	try
	{
		//tworzenie glownych skladowych programow
		zdarzenie = new wydarzenia;
		okna = new window();
	}
	catch (int error_no)
	{
		
			MessageBox(NULL, "Nie uda³o siê utworzyæ okna", "b³¹d...", MB_ICONEXCLAMATION);
			return 0;
		
	}
	return 0;
}

