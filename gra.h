#ifndef GRA_H
#define GRA_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>
const int kolumny=41;
const int wiersze=20;
void tworz_plansza(char[][kolumny],char*);
char* tworz_ludzika(char [][kolumny],int,char);
void pokaz_plansza(const char[][kolumny],const std::string,int&,int&,int n=1);
int rusz_ludzika(char [][kolumny],char,char*&,int&,int&,int&,const std::string);
void czysc(void);
char poczatek(int&);
char dodaj_znak(char);
char dodaj_gracza(short);
char usun_gracza(short,short,int&);
void pobierz_dane(int&,int&,std::string&,char,char);
void zapisz_dane(int&,int&,char,char,const char*,const char[][kolumny]);
void usun_polozenie(short);
int laduj_energie(int&,const std::string gracz,int&);
void teleportuj(const char[][kolumny],char*&,int&,int&,const std::string);
inline void start(void)
{
    system("xcowsay Witamy w grze!");
}
void kolor(char tab[][85],int,int);
int labirynt(int&,int&,const std::string,int&);
int milionerzy(int&,int&,const std::string,int&);
#endif // GRA_H