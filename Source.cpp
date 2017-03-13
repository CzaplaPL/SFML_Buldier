#include "consola.h"
#include "okna.h"
#include "obiekty.h"
#include "zdarzenia.h"
#include "tekstury.h"
#include <windows.h>
#include "elementy.h"





int main()
{

	try
	{
		//tworzenie glownych skladowych programow
		textury = new tex;
		okna = new window;
		elementy = new ele;
		zdarzenie = new wydarzenia;
	}
	catch (int error_no)
	{
		
			MessageBox(NULL, "Nie uda³o siê utworzyæ okna", "b³¹d...", MB_ICONEXCLAMATION);
			return 0;
		
	}

	while (okna->glowne.isOpen())
	{
			while (okna->glowne.pollEvent(zdarzenie->event))
			{
				zdarzenie->zdarzenia();
			}

			okna->glowne.clear(Color(255,255,255));

			okna->glowne.draw(*elementy->glowne_menu);
			
			//okna->glowne.draw(*elementy->narzedzia);
		
			okna->glowne.display();
	}
	return 0;
}

