#pragma once

#include <SFML/Graphics.hpp>

///////////////////////////////////////////
//odpowiada za okna i ich obsluge//////////
///////////////////////////////////////////
using namespace sf;


class window
{
	RenderWindow glowne;
	View main;



public:
	window();
	~window();

private:

};


extern window *okna;