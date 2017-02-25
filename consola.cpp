
#include <fstream>
#include <iostream> 
#include "consola.h"
#include <string>
#include <windows.h>
Konsola konsola;

using namespace std;



 Konsola ::Konsola(void)
{

	plik.open("log/konsola.log", ios::trunc | ios::in| ios::out);
	plik << "SFML_Buldier" << endl;
	plik << "autor: Czapla " << endl;
	plik << "wersja: 0.0.0.1" << endl;
	GetLocalTime(&st);

	plik << "data uruchomienia : " << st.wHour << ":" << st.wMinute << " , ";
	if (st.wDay < 10) { plik << st.wDay<<"."; }else { plik << "0" << st.wDay << "."; }
	if (st.wMonth < 10) { plik << st.wMonth << "."; }else { plik << "0" << st.wMonth << "."; }
	plik << st.wYear << endl;


}


 void Konsola::log(string tekst)
 {
	 plik << tekst << endl;


 }
 void Konsola::log(int b)
 {
	 plik << b << endl;
 }
 void Konsola::log(double b)
 {
	 plik << b << endl;
 }
 void Konsola::log(string tekst, double b)
 {
	 plik << tekst <<b<< endl;


 }