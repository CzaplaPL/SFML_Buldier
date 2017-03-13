#include "obiekty.h"
#include "consola.h"
#include "tekstury.h"
#include "elementy.h"
#include <SFML/Graphics.hpp>
#include "okna.h"
#include <vector>
using namespace sf;
ele *elementy;


ele::ele()
{
	narzedzia = new okno(Vector2f(1920, 200));
	//tworzenie menu
	vector < tytul_menu > elementy;

	tytul_menu nowy("nowy");
	tytul_menu zapisz("zapisz");
	tytul_menu wczytaj("wczytaj");
	tytul_menu eksportuj("eksportuj");
	tytul_menu importuj("importuj");
	elementy.clear();
	elementy.push_back(nowy);
	elementy.push_back(zapisz);
	elementy.push_back(wczytaj);
	elementy.push_back(eksportuj);
	elementy.push_back(importuj);
	tytul_menu plik("plik");
	tytul_menu dodaj("dodaj", elementy, false);
	tytul_menu widok("widok");
	elementy.clear();

	elementy.push_back(plik);
	elementy.push_back(dodaj);
	elementy.push_back(widok);
	glowne_menu = new menu(elementy);
}

ele::~ele()
{
}