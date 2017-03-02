#pragma once
#include <windows.h>
#include <SFML/Graphics.hpp>

using namespace sf;
////////////////////////////////////////////////
//odpowiade za obsluge komunikatow i wydarzen///
////////////////////////////////////////////////
class wydarzenia
{
public:
	Event event;
	//wykrywanie myszki
	Vector2f mysz2;
	Vector2i Mysz;
	//kolizja okien

	/////
	wydarzenia();
	~wydarzenia();
	void narzêdzia();

private:
	

};

extern wydarzenia * zdarzenie;