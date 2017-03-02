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
		zdarzenie = new wydarzenia;
		textury = new tex;
		okna = new window;
		elementy = new ele;

	}
	catch (int error_no)
	{
		
			MessageBox(NULL, "Nie uda³o siê utworzyæ okna", "b³¹d...", MB_ICONEXCLAMATION);
			return 0;
		
	}
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	okno pierwsze;
	okno drugie( Vector2f(500, 500));
	while (okna->glowne.isOpen())
	{
			while (okna->glowne.pollEvent(zdarzenie->event))
			{
				zdarzenie->Mysz = Mouse::getPosition(okna->glowne);
				zdarzenie->mysz2 = okna->glowne.mapPixelToCoords(zdarzenie->Mysz);

			}

			okna->glowne.clear(Color(255,255,255));
			okna->glowne.draw(shape);
		//	okna->glowne.draw(pierwsze);
		//	okna->glowne.draw(drugie);
			okna->glowne.draw(elementy->narzedzia);
			okna->glowne.display();
	}
	return 0;
}

