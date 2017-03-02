#pragma once

#include <SFML/Graphics.hpp>

///////////////////////////////////////////
//odpowiada za okna i ich obsluge//////////
///////////////////////////////////////////
using namespace sf;


class window
{
	Image icon;
	
	



public:
	RenderWindow glowne;
	View main;
	window();
	~window();

private:

};


extern window *okna;