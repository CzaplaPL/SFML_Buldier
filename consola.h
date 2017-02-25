#pragma once

#include <string>
#include <fstream>
#include <windows.h>

//===================================//
//konsola i system kontroli b��d�w//
//===================================//


using namespace std;


class Konsola
{
	/*
	obiekt pozwala na szybkie wys�anie informacji do pliku 
	*/
	SYSTEMTIME st;
	string nazwa;

public:
	ofstream plik;
	Konsola();
	void log(string tekst);
	void log(int b);
	void log(double b);
	void log(string tekst, double b);
};
extern Konsola konsola;

