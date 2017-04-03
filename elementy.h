#pragma once
#include "obiekty.h"
#include "consola.h"
#include "tekstury.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;

class ele
{
public:
	vector <okno>okienka;
	menu *glowne_menu;
	ele();
	~ele();

private:

};




extern ele *elementy;