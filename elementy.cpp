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
	okno *tmp = new okno(Vector2f(1920, 100), "narzedzia");;
	okienka.push_back(*tmp);
	okno *tmp2 = new okno(Vector2f(200, 960), "atrybuty");;
	okienka.push_back(*tmp2);
	okno *tmp3 = new okno(Vector2f(200, 960), "elementy");;
	okienka.push_back(*tmp3);
	
	okienka[0].setPosition(0, 20);
	okienka[1].setPosition(1720, 120);
	okienka[2].setPosition(0, 120);
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
	tytul_menu plik("plik", elementy, false);
	tytul_menu dodaj("dodaj");
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