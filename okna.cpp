#include "okna.h"
#include "consola.h"
#include "zdarzenia.h"
#include <SFML/Graphics.hpp>
#include "zdarzenia.h"
#include <windows.h>
using namespace sf;
window *okna;




	

	


//klasa okna//
window::window()
{
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;

    if (!icon.loadFromFile("data/grafika/sys/ikona.jpg")) konsola.log("nie uda³o siê wczytac ikony");
	main.reset(sf::FloatRect(0, 0, 1920, 1080));
	glowne.create(VideoMode(GetSystemMetrics(SM_CXSCREEN)-20, GetSystemMetrics(SM_CYSCREEN)-20), "Monopoly", Style::Resize | Style::Close| Style::Titlebar, settings);
//	glowne.setFramerateLimit(60);
	glowne.setView(main);
	glowne.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

window::~window()
{
}

/////////////////////