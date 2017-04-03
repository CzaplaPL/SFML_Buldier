#include "zdarzenia.h"
#include <windows.h>
#include "okna.h"
#include "elementy.h"
#include "tekstury.h"

using namespace sf;

wydarzenia *zdarzenie;

kol_win::kol_win()
{
	zajete = false;
	najechane = false;
	podglad.setFillColor(Color(200, 0, 100, 150));
}


//klasa wydarzen//////
wydarzenia::wydarzenia()
{
	//menu
	wcisnieta_mysz = false;
	kolizja_menu = false;
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

//okna
	wcisnieta_mysz_narzedzia = 0;
	wcisnieta_mysz_atrybuty = 0;
	wcisnieta_mysz_elementy = 0;
	///////////////////////////
	elementy->okienka[0].kolizja_ramka.top += elementy->okienka[0].getPosition().y;
	elementy->okienka[0].kolizja_tlo.top += elementy->okienka[0].getPosition().y;

	elementy->okienka[1].kolizja_ramka.top += elementy->okienka[1].getPosition().y;
	elementy->okienka[1].kolizja_tlo.top += elementy->okienka[1].getPosition().y;
	elementy->okienka[1].kolizja_ramka.left += elementy->okienka[1].getPosition().x;
	elementy->okienka[1].kolizja_tlo.left += elementy->okienka[1].getPosition().x;

	konsola.log(elementy->okienka[1].kolizja_ramka.left);
	konsola.log(elementy->okienka[1].kolizja_ramka.width);

	elementy->okienka[2].kolizja_ramka.top += elementy->okienka[2].getPosition().y;
	elementy->okienka[2].kolizja_tlo.top += elementy->okienka[2].getPosition().y;
	elementy->okienka[2].kolizja_ramka.width += elementy->okienka[2].getPosition().x;
	elementy->okienka[2].kolizja_tlo.width += elementy->okienka[2].getPosition().x;

	/////////////////////////////////////////////////
	kol_okna[0].podglad.setPosition(0, 20);
	kol_okna[0].podglad.setSize(Vector2f(100,1060));
	kol_okna[0].kolizja = kol_okna[0].podglad.getGlobalBounds();
	/////////////////////////////////////////////////
	kol_okna[1].podglad.setPosition(0, 20);
	kol_okna[1].podglad.setSize(Vector2f(1920, 100));
	kol_okna[1].kolizja = kol_okna[1].podglad.getGlobalBounds();
	kol_okna[1].kolizja.left = 100;
	kol_okna[1].kolizja.width = 1720;
	/////////////////////////////////////////////////
	kol_okna[2].podglad.setPosition(1820, 20);
	kol_okna[2].podglad.setSize(Vector2f(100, 1060));
	kol_okna[2].kolizja = kol_okna[2].podglad.getGlobalBounds();
	/////////////////////////////////////////////////
	kol_okna[3].podglad.setPosition(0, 980);
	kol_okna[3].podglad.setSize(Vector2f(1920, 100));
	kol_okna[3].kolizja = kol_okna[3].podglad.getGlobalBounds();
	kol_okna[3].kolizja.left = 100;
	kol_okna[3].kolizja.width = 1720;

		
}

wydarzenia::~wydarzenia()
{
}
/////////////////////////////////////////
//okno narzedzi
void wydarzenia::narzêdzia()
{
	if (!elementy->okienka[0].kolizja_tlo.contains(mysz2))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			x = mysz2.x;
			y = mysz2.y;
			wcisnieta_mysz_narzedzia = 1;

		
		}		
	}
	if (wcisnieta_mysz_narzedzia == 1)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (kol_okna[i].kolizja.contains(mysz2))
			{
				kol_okna[i].najechane = true;
			}
			else
			{
				kol_okna[i].najechane = false;
			}

		}
		
		if (event.type == sf::Event::MouseButtonReleased)
		{
			this->ustaw_okno(0);

			wcisnieta_mysz_narzedzia = 0;
			return;
		}

		x = mysz2.x - x;
		y = mysz2.y - y;
		elementy->okienka[0].move(x, y);
		elementy->okienka[0].kolizja_ramka.left += x;
		elementy->okienka[0].kolizja_ramka.top += y;
		elementy->okienka[0].kolizja_tlo.left += x;
		elementy->okienka[0].kolizja_tlo.top += y;
		x = mysz2.x;
		y = mysz2.y;
	}
}
///////////////////////////////////////
//okno atrybutow
void wydarzenia::atrybuty()
{
	if (!elementy->okienka[1].kolizja_tlo.contains(mysz2))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			x = mysz2.x;
			y = mysz2.y;
			wcisnieta_mysz_atrybuty = 1;
			if (elementy->okienka[1].miejsce != 1000)
			{
				
			}

		}
	}
	if (wcisnieta_mysz_atrybuty == 1)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (kol_okna[i].kolizja.contains(mysz2))
			{
				kol_okna[i].najechane = true;
			}
			else
			{
				kol_okna[i].najechane = false;
			}

		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			this->ustaw_okno(1);
			wcisnieta_mysz_atrybuty = 0;
			konsola.log(elementy->okienka[1].kolizja_ramka.left);
			konsola.log(elementy->okienka[1].kolizja_ramka.width);
			return;
		}

		x = mysz2.x - x;
		y = mysz2.y - y;
		elementy->okienka[1].move(x, y);
		elementy->okienka[1].kolizja_ramka.left += x;
		elementy->okienka[1].kolizja_ramka.top += y;
		elementy->okienka[1].kolizja_tlo.left += x;
		elementy->okienka[1].kolizja_tlo.top += y;
		x = mysz2.x;
		y = mysz2.y;
	}




}
/////////////////////////////////////////
//okno elementow
void wydarzenia::elementy_okno()
{
	/*if (!elementy->okienka[2].kolizja_tlo.contains(mysz2))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			x = mysz2.x;
			y = mysz2.y;
			wcisnieta_mysz_elementy = 1;


		}
	}
	if (wcisnieta_mysz_elementy == 1)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (kol_okna[i].kolizja.contains(mysz2))
			{
				kol_okna[i].najechane = true;
			}
			else
			{
				kol_okna[i].najechane = false;
			}

		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			this->ustaw_okno(2);

			wcisnieta_mysz_elementy = 0;
			return;
		}

		x = mysz2.x - x;
		y = mysz2.y - y;
		elementy->okienka[2].move(x, y);
		elementy->okienka[2].kolizja_ramka.left += x;
		elementy->okienka[2].kolizja_ramka.top += y;
		elementy->okienka[2].kolizja_tlo.left += x;
		elementy->okienka[2].kolizja_tlo.top += y;
		x = mysz2.x;
		y = mysz2.y;
	}*/
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

	if (zdarzenie->event.type == sf::Event::Closed)okna->glowne.close();
	//////////////////////////////////////////////////////////////////////////////
	if (glownemenu.contains(mysz2) || kolizja_menu && wcisnieta_mysz_atrybuty+ wcisnieta_mysz_narzedzia==0){menu();	}
	else if (elementy->okienka[2].kolizja_ramka.contains(mysz2) && wcisnieta_mysz_narzedzia  + wcisnieta_mysz_atrybuty ==0 || wcisnieta_mysz_elementy > 0){elementy_okno();}
	else if (elementy->okienka[1].kolizja_ramka.contains(mysz2) && wcisnieta_mysz_narzedzia == 0 || wcisnieta_mysz_atrybuty > 0 ){atrybuty();}
	else if (elementy->okienka[0].kolizja_ramka.contains(mysz2)  || wcisnieta_mysz_narzedzia > 0 ){narzêdzia();}
	/////////////////////////////////////////////////////////////////////////////////////
}

void wydarzenia::ustaw_okno(int numer_okna)
{
	if (kol_okna[0].najechane)
	{
		elementy->okienka[numer_okna].setPosition(kol_okna[0].podglad.getPosition());
		elementy->okienka[numer_okna].SetSize(Vector2f(kol_okna[0].podglad.getSize().x + 50, kol_okna[0].podglad.getSize().y));
		kol_okna[0].najechane = false;
		kol_okna[0].zajete = true;
		kol_okna[0].id = numer_okna;
		elementy->okienka[numer_okna].miejsce = 0;
		elementy->okienka[numer_okna].kolizja_ramka.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_tlo.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_ramka.left += elementy->okienka[numer_okna].getPosition().x;
		elementy->okienka[numer_okna].kolizja_tlo.left += elementy->okienka[numer_okna].getPosition().x;
		kol_okna[1].podglad.move(kol_okna[0].podglad.getSize().x + 50, 0);
		kol_okna[3].podglad.move(kol_okna[0].podglad.getSize().x + 50, 0);
		kol_okna[1].podglad.setSize(Vector2f(kol_okna[1].podglad.getSize().x - kol_okna[0].podglad.getSize().x-50, kol_okna[1].podglad.getSize().y));
		kol_okna[3].podglad.setSize(Vector2f(kol_okna[3].podglad.getSize().x - kol_okna[0].podglad.getSize().x- 50, kol_okna[3].podglad.getSize().y));
	}
	else if (kol_okna[1].najechane)
	{
		elementy->okienka[numer_okna].setPosition(kol_okna[1].podglad.getPosition());
		elementy->okienka[numer_okna].SetSize(Vector2f(kol_okna[1].podglad.getSize().x, kol_okna[1].podglad.getSize().y + 50));
		kol_okna[1].najechane = false;
		kol_okna[1].zajete = true;
		kol_okna[1].id = numer_okna;
		elementy->okienka[numer_okna].miejsce = 1;
		elementy->okienka[numer_okna].kolizja_ramka.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_tlo.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_ramka.left += elementy->okienka[numer_okna].getPosition().x;
		elementy->okienka[numer_okna].kolizja_tlo.left += elementy->okienka[numer_okna].getPosition().x;
		kol_okna[0].podglad.move(0, kol_okna[1].podglad.getSize().y + 50);
		kol_okna[2].podglad.move(0, kol_okna[1].podglad.getSize().y + 50);
		kol_okna[0].podglad.setSize(Vector2f(kol_okna[0].podglad.getSize().x, kol_okna[0].podglad.getSize().y - kol_okna[1].podglad.getSize().y - 50));
		kol_okna[2].podglad.setSize(Vector2f(kol_okna[2].podglad.getSize().x, kol_okna[2].podglad.getSize().y - kol_okna[1].podglad.getSize().y - 50));
	}
	else if (kol_okna[2].najechane)
	{
		elementy->okienka[numer_okna].setPosition(kol_okna[2].podglad.getPosition().x - 50, kol_okna[2].podglad.getPosition().y);
		elementy->okienka[numer_okna].SetSize(Vector2f(kol_okna[2].podglad.getSize().x + 50, kol_okna[2].podglad.getSize().y));
		kol_okna[2].najechane = false;
		kol_okna[2].zajete = true;
		kol_okna[2].id = numer_okna;
		elementy->okienka[numer_okna].miejsce = 2;
		elementy->okienka[numer_okna].kolizja_ramka.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_tlo.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_ramka.left += elementy->okienka[numer_okna].getPosition().x;
		elementy->okienka[numer_okna].kolizja_tlo.left += elementy->okienka[numer_okna].getPosition().x;
		kol_okna[1].podglad.setSize(Vector2f(kol_okna[1].podglad.getSize().x - kol_okna[2].podglad.getSize().x - 50, kol_okna[1].podglad.getSize().y));
		kol_okna[3].podglad.setSize(Vector2f(kol_okna[3].podglad.getSize().x - kol_okna[2].podglad.getSize().x - 50, kol_okna[3].podglad.getSize().y));
	}
	else if (kol_okna[3].najechane)
	{
		elementy->okienka[numer_okna].setPosition(kol_okna[3].podglad.getPosition().x, kol_okna[3].podglad.getPosition().y - 50);
		elementy->okienka[numer_okna].SetSize(Vector2f(kol_okna[3].podglad.getSize().x, kol_okna[3].podglad.getSize().y + 50));
		kol_okna[3].najechane = false;
		kol_okna[3].zajete = true;
		kol_okna[3].id = numer_okna;
		elementy->okienka[numer_okna].miejsce = 3;
		elementy->okienka[numer_okna].kolizja_ramka.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_tlo.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_ramka.left += elementy->okienka[numer_okna].getPosition().x;
		elementy->okienka[numer_okna].kolizja_tlo.left += elementy->okienka[numer_okna].getPosition().x;
		kol_okna[0].podglad.setSize(Vector2f(kol_okna[0].podglad.getSize().x, kol_okna[0].podglad.getSize().y - kol_okna[3].podglad.getSize().y - 50));
		kol_okna[2].podglad.setSize(Vector2f(kol_okna[2].podglad.getSize().x, kol_okna[2].podglad.getSize().y - kol_okna[3].podglad.getSize().y - 50));
	}


}

void wydarzenia::przywroc_okno(int numer_miejsca)
{
	if (numer_miejsca == 0)
	{
		if (kol_okna[1].zajete)
		{

		}


	}
		/*
		elementy->okienka[numer_okna].setPosition(kol_okna[0].podglad.getPosition());
		elementy->okienka[numer_okna].SetSize(Vector2f(kol_okna[0].podglad.getSize().x + 50, kol_okna[0].podglad.getSize().y));
		kol_okna[0].najechane = false;
		kol_okna[0].zajete = true;
		kol_okna[0].id = numer_okna;
		elementy->okienka[numer_okna].miejsce = 0;
		elementy->okienka[numer_okna].kolizja_ramka.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_tlo.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_ramka.width += elementy->okienka[numer_okna].getPosition().x;
		elementy->okienka[numer_okna].kolizja_tlo.width += elementy->okienka[numer_okna].getPosition().x;
		kol_okna[1].podglad.move(kol_okna[0].podglad.getSize().x + 50, 0);
		kol_okna[3].podglad.move(kol_okna[0].podglad.getSize().x + 50, 0);
		kol_okna[1].podglad.setSize(Vector2f(kol_okna[1].podglad.getSize().x - kol_okna[0].podglad.getSize().x - 50, kol_okna[1].podglad.getSize().y));
		kol_okna[3].podglad.setSize(Vector2f(kol_okna[3].podglad.getSize().x - kol_okna[0].podglad.getSize().x - 50, kol_okna[3].podglad.getSize().y));
	}
	else if (kol_okna[1].najechane)
	{
		elementy->okienka[numer_okna].setPosition(kol_okna[1].podglad.getPosition());
		elementy->okienka[numer_okna].SetSize(Vector2f(kol_okna[1].podglad.getSize().x, kol_okna[1].podglad.getSize().y + 50));
		kol_okna[1].najechane = false;
		kol_okna[1].zajete = true;
		kol_okna[1].id = numer_okna;
		elementy->okienka[numer_okna].miejsce = 1;
		elementy->okienka[numer_okna].kolizja_ramka.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_tlo.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_ramka.width += elementy->okienka[numer_okna].getPosition().x;
		elementy->okienka[numer_okna].kolizja_tlo.width += elementy->okienka[numer_okna].getPosition().x;
		kol_okna[0].podglad.move(0, kol_okna[1].podglad.getSize().y + 50);
		kol_okna[2].podglad.move(0, kol_okna[1].podglad.getSize().y + 50);
		kol_okna[0].podglad.setSize(Vector2f(kol_okna[0].podglad.getSize().x, kol_okna[0].podglad.getSize().y - kol_okna[1].podglad.getSize().y - 50));
		kol_okna[2].podglad.setSize(Vector2f(kol_okna[2].podglad.getSize().x, kol_okna[2].podglad.getSize().y - kol_okna[1].podglad.getSize().y - 50));
	}
	else if (kol_okna[2].najechane)
	{
		elementy->okienka[numer_okna].setPosition(kol_okna[2].podglad.getPosition().x - 50, kol_okna[2].podglad.getPosition().y);
		elementy->okienka[numer_okna].SetSize(Vector2f(kol_okna[2].podglad.getSize().x + 50, kol_okna[2].podglad.getSize().y));
		kol_okna[2].najechane = false;
		kol_okna[2].zajete = true;
		kol_okna[2].id = numer_okna;
		elementy->okienka[numer_okna].miejsce = 2;
		elementy->okienka[numer_okna].kolizja_ramka.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_tlo.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_ramka.width += elementy->okienka[numer_okna].getPosition().x;
		elementy->okienka[numer_okna].kolizja_tlo.width += elementy->okienka[numer_okna].getPosition().x;
		kol_okna[1].podglad.setSize(Vector2f(kol_okna[1].podglad.getSize().x - kol_okna[2].podglad.getSize().x - 50, kol_okna[1].podglad.getSize().y));
		kol_okna[3].podglad.setSize(Vector2f(kol_okna[3].podglad.getSize().x - kol_okna[2].podglad.getSize().x - 50, kol_okna[3].podglad.getSize().y));
	}
	else if (kol_okna[3].najechane)
	{
		elementy->okienka[numer_okna].setPosition(kol_okna[3].podglad.getPosition().x, kol_okna[3].podglad.getPosition().y - 50);
		elementy->okienka[numer_okna].SetSize(Vector2f(kol_okna[3].podglad.getSize().x, kol_okna[3].podglad.getSize().y + 50));
		kol_okna[3].najechane = false;
		kol_okna[3].zajete = true;
		kol_okna[3].id = numer_okna;
		elementy->okienka[numer_okna].miejsce = 3;
		elementy->okienka[numer_okna].kolizja_ramka.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_tlo.top += elementy->okienka[numer_okna].getPosition().y;
		elementy->okienka[numer_okna].kolizja_ramka.width += elementy->okienka[numer_okna].getPosition().x;
		elementy->okienka[numer_okna].kolizja_tlo.width += elementy->okienka[numer_okna].getPosition().x;
		kol_okna[0].podglad.setSize(Vector2f(kol_okna[0].podglad.getSize().x, kol_okna[0].podglad.getSize().y - kol_okna[3].podglad.getSize().y - 50));
		kol_okna[2].podglad.setSize(Vector2f(kol_okna[2].podglad.getSize().x, kol_okna[2].podglad.getSize().y - kol_okna[3].podglad.getSize().y - 50));
	}

	*/
}
