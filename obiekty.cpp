#include "obiekty.h"
#include "consola.h"
#include "tekstury.h"
#include <SFML/Graphics.hpp>
using namespace sf;

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
	zamknij.setPosition(tmp.x-20,0);
	zamknij.setSize(Vector2f(20, 20));
}

okno::okno(Vector2f rozmiar,Color c_ramka , Color c_tlo )
{
	ramka.setFillColor(c_ramka);
	ramka.setPosition(0,0);
	ramka.setSize(rozmiar);
	tlo.setFillColor(c_tlo);
	tlo.setPosition( 2, 20);
	tlo.setSize(Vector2f(rozmiar.x-4,rozmiar.y - 25));
	
	zamknij.setTexture(&textury->zamknij_okno);
	zamknij.setTextureRect(sf::IntRect(0, 0, 128, 128));
	zamknij.setPosition( rozmiar.x - 20,0);
	zamknij.setSize(Vector2f(20, 20));
}