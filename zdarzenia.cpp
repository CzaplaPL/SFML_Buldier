#include "zdarzenia.h"
#include <windows.h>
#include "okna.h"
#include "elementy.h"
#include "tekstury.h"

using namespace sf;

wydarzenia *zdarzenie;

//klasa wydarzen//////
wydarzenia::wydarzenia()
{
	//menu

	glownemenu = elementy->glowne_menu->ramka.getGlobalBounds();
	for (size_t i = 0; i < elementy->glowne_menu->elementy.size(); i++)
	{

		elementy->glowne_menu->elementy[i].kolizja.left += elementy->glowne_menu->elementy[i].getPosition().x;
		elementy->glowne_menu->elementy[i].kolizja.top += elementy->glowne_menu->elementy[i].getPosition().y;
		for (size_t j = 0; j < elementy->glowne_menu->elementy[i].elementy.size(); j++)
		{
			elementy->glowne_menu->elementy[i].elementy[j].kolizja = elementy->glowne_menu->elementy[i].elementy[j].tlo.getGlobalBounds();
			elementy->glowne_menu->elementy[i].elementy[j].kolizja.top += elementy->glowne_menu->elementy[i].elementy[j].getPosition().y;
			elementy->glowne_menu->elementy[i].elementy[j].kolizja.left += elementy->glowne_menu->elementy[i].elementy[j].getPosition().x;
			elementy->glowne_menu->elementy[i].elementy[j].kolizja.top += elementy->glowne_menu->elementy[i].getPosition().y;
			elementy->glowne_menu->elementy[i].elementy[j].kolizja.left += elementy->glowne_menu->elementy[i].getPosition().x;
		}
	}



	
		
	
	
}

wydarzenia::~wydarzenia()
{
}
/////////////////////////////////////////
//okno narzedzi
void wydarzenia::narzêdzia()
{






}
//menu

void wydarzenia::menu()
{
	
	for (size_t i = 0; i < elementy->glowne_menu->elementy.size(); i++)
	{
		
		if (elementy->glowne_menu->elementy[i].kolizja.contains(mysz2))
		{
		
			elementy->glowne_menu->elementy[i].wysuniete = true;
			elementy->glowne_menu->elementy[i].tlo.setFillColor(Color::Red);
			kolizja_menu = true;
		}
		else
		{
			
			elementy->glowne_menu->elementy[i].tlo.setFillColor(Color::Blue);
			
		}
	
		if (elementy->glowne_menu->elementy[i].wysuniete&& !elementy->glowne_menu->elementy[i].kolizja.contains(mysz2))
		{
			size_t j;
			int b;
			
			for ( j = 0; j < elementy->glowne_menu->elementy[i].elementy.size(); j++)
			{
				if (elementy->glowne_menu->elementy[i].elementy[j].kolizja.contains(mysz2))
				{
				
					elementy->glowne_menu->elementy[i].elementy[j].wysuniete = true;
					elementy->glowne_menu->elementy[i].elementy[j].tlo.setFillColor(Color::Red);
					kolizja_menu = true;
					b = j;
					j = elementy->glowne_menu->elementy[i].elementy.size();
				}
				else
				{
					elementy->glowne_menu->elementy[i].elementy[j].wysuniete = false;
					elementy->glowne_menu->elementy[i].elementy[j].tlo.setFillColor(Color::Blue);
					kolizja_menu = false;
				}
				
			}
		
		}
		if (!kolizja_menu && !elementy->glowne_menu->elementy[i].kolizja.contains(mysz2))
		{
			elementy->glowne_menu->elementy[i].wysuniete = false;
		}
	

		
		
	}





}

void wydarzenia::zdarzenia()
{
	zdarzenie->Mysz = Mouse::getPosition(okna->glowne);
	zdarzenie->mysz2 = okna->glowne.mapPixelToCoords(zdarzenie->Mysz);

	if (zdarzenie->event.type == sf::Event::Closed)
		okna->glowne.close();
	if (glownemenu.contains(mysz2) || kolizja_menu)menu();


}


