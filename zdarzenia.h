#pragma once
#include <vector>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
////////////////////////////////////////////////
//odpowiada za obsluge komunikatow i wydarzen///
////////////////////////////////////////////////

class wydarzenia
{
public:
	Event event;
	//wykrywanie myszki
	Vector2f mysz2;
	Vector2i Mysz;
	//kolizja okien
	FloatRect glownemenu;	
	//kolizja menu
	 bool  kolizja_menu;
	/////
	wydarzenia();
	~wydarzenia();
	void zdarzenia();
	void narzêdzia();
	void menu();

private:
	

};

extern wydarzenia * zdarzenie;