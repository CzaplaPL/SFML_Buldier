#include "obiekty.h"
#include "consola.h"
#include "tekstury.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
using namespace sf;

//okno

	void okno::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(ramka, states);
		target.draw(tlo, states);
		target.draw(zamknij, states);


	}

	okno::okno()
	{
		ramka.setFillColor(Color(100, 100, 100));
		ramka.setPosition(0, 0);
		ramka.setSize(Vector2f(400, 400));
		tlo.setFillColor(Color(220, 220, 220));
		tlo.setPosition(5, 20);
		tlo.setSize(Vector2f(390, 375));
		Vector2f tmp = ramka.getSize();
		zamknij.setTexture(&textury->zamknij_okno);
		zamknij.setTextureRect(sf::IntRect(0, 0, 128, 128));
		zamknij.setPosition(tmp.x - 20, 0);
		zamknij.setSize(Vector2f(20, 20));
	}

	okno::okno(Vector2f rozmiar, Color c_ramka, Color c_tlo)
	{
		ramka.setFillColor(c_ramka);
		ramka.setPosition(0, 0);
		ramka.setSize(rozmiar);
		tlo.setFillColor(c_tlo);
		tlo.setPosition(2, 20);
		tlo.setSize(Vector2f(rozmiar.x - 4, rozmiar.y - 25));

		zamknij.setTexture(&textury->zamknij_okno);
		zamknij.setTextureRect(sf::IntRect(0, 0, 128, 128));
		zamknij.setPosition(rozmiar.x - 20, 0);
		zamknij.setSize(Vector2f(20, 20));
	}

////////////////////////////////////////////////////
//Menu
menu::menu(vector < tytul_menu > element)
{
	ramka.setFillColor(Color(220, 220, 220));
	ramka.setPosition(0, 0);
	ramka.setSize(Vector2f(1920, 20));
	elementy = element;
	elementy[0].setPosition(0, 0);
	int tmp=0;
	for (size_t i = 1; i < elementy.size(); i++)
	{
		tmp += elementy[i - 1].tlo.getSize().x;
		elementy[i].setPosition(tmp, 0);
		
	}
	for (size_t i = 0; i < elementy.size(); i++)
	{
		elementy[i].kolizja = elementy[i].tlo.getGlobalBounds();
	}


}

menu::~menu()
{
}
void menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(ramka, states);

	for (size_t i = 0; i < elementy.size(); i++)
	{
			target.draw(elementy[i], states);
	}


}
//tytul_menu
tytul_menu::tytul_menu(string nazwa)
{
	tytul.setFont(textury->Arvo_Regular);
	tytul.setString(nazwa);
	tytul.setCharacterSize(14); 
	tytul.setColor(Color(0,0,0));
	tytul.setPosition(6, 1);
	wysuniete = false;
	ramka.setFillColor(Color(220, 220, 220));
	ramka.setPosition(2, 0);
	ramka.setSize(Vector2f(tytul.getGlobalBounds().width+12, 20));
	tlo.setFillColor(Color(100, 100, 100));
	tlo.setPosition(0, 0);
	tlo.setSize(Vector2f(tytul.getGlobalBounds().width+16, 20));
	
}

tytul_menu::tytul_menu(string nazwa, vector < tytul_menu > element,bool podmenu)
{
	tytul.setFont(textury->Arvo_Regular);
	tytul.setString(nazwa);
	tytul.setCharacterSize(14);
	tytul.setColor(Color(0, 0, 0));
	tytul.setPosition(6, 1);
	wysuniete = false;
	ramka.setFillColor(Color(220, 220, 220));
	ramka.setPosition(2, 0);
	ramka.setSize(Vector2f(tytul.getGlobalBounds().width + 12, 20));
	tlo.setFillColor(Color(100, 100, 100));
	tlo.setPosition(0, 0);
	tlo.setSize(Vector2f(tytul.getGlobalBounds().width + 16, 20));
	elementy = element;
	int tmp = 0;
	if (podmenu)
	{
		for (size_t i = 0; i < elementy.size(); i++)
		{
			if (i == 0)
			{
				elementy[0].setPosition(tytul.getGlobalBounds().width+16, tmp);
			}
			else
			{

				tmp += elementy[i - 1].tlo.getSize().y;
				elementy[i].setPosition(tytul.getGlobalBounds().width + 16, tmp);
			}

		}
	}else
	{
		for (size_t i = 0; i < elementy.size(); i++)
			{
				if (i == 0)
				{
					elementy[0].setPosition(0, 20);
					tmp = 20;
					
				}else
				{
					tmp += elementy[i - 1].tlo.getSize().y;
					elementy[i].setPosition(0, tmp);
				}
			
			}
	}

		



}

void tytul_menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(tlo, states);
	target.draw(ramka, states);
	target.draw(tytul, states);
	for (int i = elementy.size() -1; i >= 0; i--)
	{
		if (wysuniete)target.draw(elementy[i], states);
	}



}