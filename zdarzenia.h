#pragma once
#include <vector>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
////////////////////////////////////////////////
//odpowiada za obsluge komunikatow i wydarzen///
////////////////////////////////////////////////
class kol_win
{
public:
	short id;
	bool zajete;
	bool najechane;
	kol_win();
	FloatRect kolizja;
	RectangleShape podglad;
};
class wydarzenia
{
public:

	Event event;
	//wykrywanie myszki
	Vector2f mysz2;
	Vector2i Mysz;
	//kolizja okien
	kol_win kol_okna[4];
	short wcisnieta_mysz_narzedzia;
	short wcisnieta_mysz_atrybuty;
	short wcisnieta_mysz_elementy;
	void ustaw_okno(int numer_okna);
	void przywroc_okno(int numer_miejsca);
	//kolizja menu
	FloatRect glownemenu;
	 bool  kolizja_menu;
	/////
	wydarzenia();
	~wydarzenia();
	void zdarzenia();
	void narzêdzia();
	void atrybuty();
	void elementy_okno();
	void menu();

private:
	bool wcisnieta_mysz;
	float x, y;

	

};

extern wydarzenia * zdarzenie;