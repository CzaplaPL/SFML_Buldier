#include <SFML/Graphics.hpp>
#include "consola.h"
#include "tekstury.h"

using namespace sf;
tex * textury;
tex::tex()
{

	//obiekty 
	
	//okno
	if (!zamknij_okno.loadFromFile("data/grafika/obj/okno_zamknij.png"))konsola.log("nie udalo sie wczytac grafiki zamknij_okno.png");
	if (!Arial.loadFromFile("data/czcionki/arial.ttf"))konsola.log("nie udalo sie wczytac czcionki arial.ttf");
	if (!Arvo_Regular.loadFromFile("data/czcionki/Arvo-Regular.ttf"))konsola.log("nie udalo sie wczytac czcionki Arvo-Regular.ttf");

}

tex::~tex()
{
}