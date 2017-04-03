#pragma once
#include "consola.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
using namespace sf;

class czesc
{

};




class okno : public sf::Drawable, public sf::Transformable, public czesc
{
public:
	////////////////////////
	
	FloatRect kolizja_tlo;
	FloatRect kolizja_ramka;
	RectangleShape ramka;
	RectangleShape tlo;
	void SetSize(Vector2f rozmiar);
	short miejsce;
	///////////////
	okno();
	okno(Vector2f rozmiar, string nazwa, Color c_ramka = Color(0, 200, 255), Color c_tlo = Color(240, 240, 240));
private:
	RectangleShape zamknij;
	Text tytul;
	bool wyswietlaj_tytul;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};
//////////////////////////////////////////////////////////////////////


//menu
#if(1==1)
//tytuly menu
class tytul_menu : public sf::Drawable, public sf::Transformable
{
public:
	tytul_menu(string nazwa);
	tytul_menu(string nazwa, vector < tytul_menu > element, bool podmenu=false);
	
	bool wysuniete, ptaszek;
	Text  tytul;
	vector < tytul_menu > elementy;
	FloatRect kolizja;
	RectangleShape ramka;
	RectangleShape tlo;
	RectangleShape zaznaczenie;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


class menu : public sf::Drawable, public sf::Transformable, public czesc
{
public:
	menu(vector < tytul_menu > element);
	RectangleShape ramka;
	vector < tytul_menu > elementy;

	~menu();


private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif