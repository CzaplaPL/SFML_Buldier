#pragma once
#include <SFML/Graphics.hpp>
#include "consola.h"

using namespace sf;

class tex
{
public:
	//obiektu okna
	Texture zamknij_okno;
	Font Arial;
	Font Arvo_Regular;
	tex();
	~tex();

private:

};

extern tex * textury;