#pragma once
#include "consola.h"
#include <SFML/Graphics.hpp>

using namespace sf;


class okno : public sf::Drawable, public sf::Transformable
{
public:
	////////////////////////


	///////////////
	okno();
	okno(Vector2f rozmiar, Color c_ramka = Color(0, 200, 255), Color c_tlo = Color(240, 240, 240));
private:
	RectangleShape ramka;
	RectangleShape tlo;
	RectangleShape zamknij;


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};