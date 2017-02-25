#include "okna.h"
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

	main.setViewport(sf::FloatRect(0.2f, 0, 0.6f, 1));
	main.reset(sf::FloatRect(0, 0, 1920, 1080));
	glowne.create(VideoMode(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)), "Monopoly", Style::Titlebar, settings);
	glowne.setFramerateLimit(60);
	glowne.setView(main);
	
}

window::~window()
{
}

/////////////////////