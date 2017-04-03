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
	int iloscklatek=0;
	sf::Clock clock;
	while (okna->glowne.isOpen())
	{
		iloscklatek++;
		okna->glowne.clear(Color(255, 255, 255));
			

			//glowne okno
		
		
			for (size_t i = 0; i < elementy->okienka.size(); i++)
			{
				okna->glowne.draw(elementy->okienka[i]);
			}
			//menu
			okna->glowne.draw(*elementy->glowne_menu);
			for (size_t i = 0; i < 4; i++)
			{
				if (zdarzenie->kol_okna[i].najechane)
				{
					okna->glowne.draw(zdarzenie->kol_okna[i].podglad);
				}
			}

		/*licznik fps
			if (clock.getElapsedTime().asSeconds() > 1)
			{
				konsola.log(iloscklatek);
				iloscklatek = 0;
				clock.restart();
				
			}
			*/
			while (okna->glowne.pollEvent(zdarzenie->event))
			{
				zdarzenie->zdarzenia();

			}
			okna->glowne.display();
	}
	return 0;
}

