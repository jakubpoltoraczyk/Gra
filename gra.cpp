#include "gra.h"
int main(void)
{
    using namespace std;
    srand(time(NULL));
    char znak,osoba1,osoba2;
    char *polozenie;
    int rozmiar=3,energia,monety,n=1;
    string smieci,gracz;
    char tab[wiersze][kolumny]{};
    //start();
    do
    {
        system("clear");
        osoba1=poczatek(n);
        osoba2=dodaj_znak(osoba1);
        system("clear");
        pobierz_dane(monety,energia,gracz,osoba1,osoba2);
        polozenie=tworz_ludzika(tab,rozmiar,osoba1);
        tworz_plansza(tab,polozenie);
        pokaz_plansza(tab,gracz,monety,energia);
        do
        {
            cin >> znak;
            getline(cin,smieci);
            system("clear");
            if(znak!='q')
            {
                n=rusz_ludzika(tab,znak,polozenie,energia,monety,n,gracz);
                tworz_plansza(tab,polozenie);
                pokaz_plansza(tab,gracz,monety,energia,n);
            }
        }while(znak!='q'&&n!=0);
        zapisz_dane(monety,energia,osoba1,osoba2,polozenie,tab);
    }while(1);
}
void tworz_plansza(char tab[][kolumny],char*polozenie)
{
    using namespace std;
    for(int i=0;i<wiersze;++i)
    {
        for(int j=0;j<kolumny+1;++j)
        {
            if((i==0||i==wiersze-1)&&j!=0)
                tab[i][j]='-';
            else
            tab[i][j]=' ';
            if(j==0||j==kolumny)
                tab[i][j]='|';
            if(polozenie==&tab[i][j])
                tab[i][j]='x';
            if(i==15&&j==5)
                tab[i][j]='1';
            if(i==10&&j==8)
                tab[i][j]='2';
            if(i==8&&j==15)
                tab[i][j]='3';
        }
    }
}
void pokaz_plansza(const char tab[][kolumny],const std::string gracz,int &monety,int &energia,int n)
{
    using namespace std;
    if(n==1)
    {
        for(int i=0;i<wiersze;++i)
        {
            for(int j=0;j<kolumny+1;++j)
            {
                cout << tab[i][j];
                if(j==kolumny&&i==0)
                    cout << " Gracz: " << gracz;
                if(j==kolumny&&i==1)
                    {
                        cout << " Ranga: ";
                        if(monety<1500)
                            cout << "Amator";
                        if(monety>=1500&&monety<2000)
                            cout << "Poczatkujacy";
                        if(monety>=2000&&monety<3000)
                            cout << "Zawodowiec";
                        if(monety>=3000&&monety<4000)
                            cout << "Mistrz";
                        if(monety>=4000)
                            cout << "Arcymistrz";
                    }
                if(j==kolumny&&i==2)
                        cout << " Monety: " << monety;
                if(j==kolumny&&i==3)
                    {
                        energia-=5;
                        cout << " Energia: " << energia << "%";
                    }
                if(j==kolumny&&i==5)
                    cout << " Menu(ekran glowny):";
                if(j==kolumny&&i==6)
                    cout << " [q] - wyjscie";
                if(j==kolumny&&i==7)
                    cout << " [f] - sklep";
                if(j==kolumny&&i==8)
                    cout << " [l] - doladuj energie";
            }
            cout << endl;
        }
    }
    if(n==2)
    {
        for(int i=0;i<wiersze;++i)
        {
            for(int j=0;j<kolumny+1;++j)
            {
                cout << tab[i][j];
                if(j==kolumny&&i==0)
                    cout << " Gracz: " << gracz;
                if(j==kolumny&&i==1)
                    {
                        cout << " Ranga: ";
                        if(monety<1500)
                            cout << "Amator";
                        if(monety>=1500&&monety<2000)
                            cout << "Poczatkujacy";
                        if(monety>=2000&&monety<3000)
                            cout << "Zawodowiec";
                        if(monety>=3000&&monety<4000)
                            cout << "Mistrz";
                        if(monety>=4000)
                            cout << "Arcymistrz";
                    }
                if(j==kolumny&&i==2)
                        cout << " Monety: " << monety;
                if(j==kolumny&&i==3)
                    {
                        energia-=5;
                        cout << " Energia: " << energia << "%";
                    }
                if(j==kolumny&&i==5)
                    cout << " Menu(sklep): ";
                if(j==kolumny&&i==6)
                    cout << " [q] - wyjscie";
                if(j==kolumny&&i==7)
                    cout << " [p] - powrot";
                if(j==kolumny&&i==8)
                    cout << " [m] - kup 100% energii(500 monet)";
                if(j==kolumny&&i==9)
                    cout << " [n] - kup 50% energii(300 monet)";
                if(j==kolumny&&i==10)
                    cout << " [b] - kup 25% energii(200 monet)";
                if(j==kolumny&&i==11)
                    cout << " [t] - teleportuj(niedlugo dostepne)";
            }
            cout << endl;
        }
    }
    if(n==3)
    {
        for(int i=0;i<wiersze;++i)
        {
            for(int j=0;j<kolumny+1;++j)
            {
                cout << tab[i][j];
                if(j==kolumny&&i==0)
                    cout << " Gracz: " << gracz;
                if(j==kolumny&&i==1)
                    {
                        cout << " Ranga: ";
                        if(monety<1500)
                            cout << "Amator";
                        if(monety>=1500&&monety<2000)
                            cout << "Poczatkujacy";
                        if(monety>=2000&&monety<3000)
                            cout << "Zawodowiec";
                        if(monety>=3000&&monety<4000)
                            cout << "Mistrz";
                        if(monety>=4000)
                            cout << "Arcymistrz";
                    }
                if(j==kolumny&&i==2)
                        cout << " Monety: " << monety;
                if(j==kolumny&&i==3)
                    {
                        energia-=5;
                        cout << " Energia: " << energia << "%";
                    }
                if(j==kolumny&&i==5)
                    cout << " Menu(zasady gry):";
                if(j==kolumny&&i==6)
                    cout << " [q] - wyjscie";
                if(j==kolumny&&i==7)
                    cout << " [p] - powrot";
            }
            cout << endl;
        }
    }
}
char* tworz_ludzika(char tab[][kolumny],int rozmiar,char osoba1)
{
    using namespace std;
    ifstream plik;
    string smieci;
    int wiersz,kolumna;
    plik.open("gra_dane2");
    while(plik.get()!=osoba1)
        getline(plik,smieci,'\n');
    plik >> wiersz;
    plik >> kolumna;
    plik.close();
    return(&tab[wiersz][kolumna]);
}
int rusz_ludzika(char tab[][kolumny],char znak,char*&polozenie,int &energia,int &monety,int &n,const std::string gracz)
{
    for(int i=0;i<wiersze;++i)
    {
        for(int j=0;j<kolumny+1;++j)
        {
            if(polozenie==&tab[i][j])
            {
                switch(znak)
                {
                case 'w':
                    if(tab[i-1][j]==' '||tab[i-1][j]=='1'||tab[i-1][j]=='2'||tab[i-1][j]=='3')
                    {
                        if(tab[i-1][j]=='1')
                            n=milionerzy(monety,energia,gracz,n);
                        if(tab[i-1][j]=='2')
                            n=labirynt(monety,energia,gracz,n);
                        polozenie=&(tab[i-1][j]);
                        break;
                    }
                    break;
                case 's':
                    if(tab[i+1][j]==' '||tab[i+1][j]=='1'||tab[i+1][j]=='2'||tab[i+1][j]=='3')
                    {
                        if(tab[i+1][j]=='1')
                            n=milionerzy(monety,energia,gracz,n);
                        if(tab[i+1][j]=='2')
                            n=labirynt(monety,energia,gracz,n);
                        polozenie=&tab[i+1][j];
                        break;
                    }
                    break;
                case 'a':
                    if(tab[i][j-1]==' '||tab[i][j-1]=='1'||tab[i][j-1]=='2'||tab[i][j-1]=='3')
                    {
                        if(tab[i][j-1]=='1')
                            n=milionerzy(monety,energia,gracz,n);
                        if(tab[i][j-1]=='2')
                        n=labirynt(monety,energia,gracz,n);
                        polozenie=&tab[i][j-1];
                        break;
                    }
                    break;
                case 'd':
                    if(tab[i][j+1]==' '||tab[i][j+1]=='1'||tab[i][j+1]=='2'||tab[i][j+1]=='3')
                    {
                        if(tab[i][j+1]=='1')
                            n=milionerzy(monety,energia,gracz,n);
                        if(tab[i][j+1]=='2')
                            n=labirynt(monety,energia,gracz,n);
                        polozenie=&tab[i][j+1];
                        break;
                    }
                case 'f':
                    if(n==1)
                    {
                        energia+=5;
                        n=2;
                    }
                    break;
                case 'p':
                    if(n==2)
                    {
                        energia+=5;
                        n=1;
                    }
                    break;
                case 'm':
                    if(n==2)
                    {
                        if(monety>=500)
                        {
                            energia=105;
                            monety-=500;
                        }
                    }
                    break;
                case 'n':
                    if(n==2)
                    {
                        if(monety>=300)
                        {
                            if(energia<=50)
                                energia+=55;
                            else
                                energia=105;
                            monety-=300;
                        }
                    }
                    break;
                case 'b':
                    if(n==2)
                    {
                        if(monety>=200)
                        {
                            if(energia<=75)
                                energia+=30;
                            else
                                energia=105;
                            monety-=200;
                        }
                    }
                    break;
                case 'l':
                    if(n==1)
                    {
                        laduj_energie(energia,gracz,n);
                    }
                case 't':
                    if(n==2&&monety>=1000)
                    {
                        teleportuj(tab,polozenie,monety,energia,gracz);
                        monety-=1000;
                    }
                    break;
                }
                j=kolumny;
                i=wiersze;
            }
        }
    }
    return (n);
}
char poczatek(int &n)
{
    using namespace std;
    fstream plik;
    plik.open("gra_dane");
    string nazwa;
    char znak;
    short check=1,i=3,licznik=2;
    n=1;
    cout << "Lista profili i opcji do wyboru:" << endl;
    cout << "0). Wyjdz z gry" << endl;
    cout << "1). Stworz nowy profil" << endl;
    cout << "2). Usun gracza" << endl;
    do
    {
        if(plik.get()=='n')
        {
            getline(plik,nazwa,'\n');
            cout << i << "). " << nazwa << endl;
            i++;
            licznik++;
        }
        else
            check=0;
    }while(check==1);
    do
    {
        check=0;
        cout << "Podaj swoj wybor: ";
        cin >> i;
        if(!cin.fail())
            check=1;
        czysc();
        switch(i)
        {
        case 0:
            if(check==1)
            {
                system("clear");
                exit(0); break;
            }
            else
                break;
        case 1:
            if(licznik<7)
                return(dodaj_gracza(licznik));
            else
            {
                cout << "Osiagnieto limit zapisow\n";
                break;
            }
        case 2:
            if(licznik==2)
            {
                cout << "Brak graczy do usuniecia\n";
                break;
            }
            do
            {
                cout << "Podaj numer gracza do usuniecia: ";
                cin >> check;
                czysc();
            }while((check<2||check>licznik)&&check!=0);
            if(check==0)
                break;
            else
            {
                licznik-=2;
                return(usun_gracza(check,licznik,n));
                break;
            }
        case 3:
            if(3<=licznik)
            {
                znak='A';
                return (znak);
            }
            else
            {
                cout << "Blad wyboru gracza\n";
                break;
            }
        case 4:
            if(4<=licznik)
            {
                znak='B';
                return (znak);
            }
            else
            {
                cout << "Blad wyboru gracza\n";
                break;
            }
        case 5:
            if(5<=licznik)
            {
                znak='C';
                return (znak);
            }
            else
            {
                cout << "Blad wyboru gracza\n";
                break;
            }
        case 6:
            if(6<=licznik)
            {
                znak='D';
                return (znak);
            }
            else
            {
                cout << "Blad wyboru gracza\n";
                break;
            }
        case 7:
            if(7<=licznik)
            {
                znak='E';
                return (znak);
            }
            else
            {
                cout << "Blad wyboru gracza\n";
                break;
            }
        }
    }while(1);
    plik.close();
}
void czysc(void)
{
    using namespace std;
    cin.clear();
    while(cin.get()!='\n');
}
char dodaj_znak(char osoba1)
{
    char osoba2;
    switch(osoba1)
    {
    case 'A':
        osoba2='a';
        return(osoba2);
    case 'B':
        osoba2='b';
        return(osoba2);
    case 'C':
        osoba2='c';
        return(osoba2);
    case 'D':
        osoba2='d';
        return(osoba2);
    case 'E':
        osoba2='e';
        return(osoba2);
    }
}
char dodaj_gracza(short licznik)
{
    using namespace std;
    ifstream plik;
    ofstream pliczek;
    plik.open("gra_dane");
    char znak;
    string dodaj1,dodaj2;
    string nazwa;
    string osoba[15];
    switch(licznik)
    {
    case 2:
        znak='A';
        dodaj1="A1000";
        dodaj2="a105";
        break;
    case 3:
        znak='B';
        dodaj1="B1000";
        dodaj2="b105";
        break;
    case 4:
        znak='C';
        dodaj1="C1000";
        dodaj2="c105";
        break;
    case 5:
        znak='D';
        dodaj1="D1000";
        dodaj2="d105";
        break;
    case 6:
        znak='E';
        dodaj1="E1000";
        dodaj2="e105";
        break;
    }
    for(int i=0;i<15;++i)
        getline(plik,osoba[i],'\n');
    plik.close();
    for(licznik=0;osoba[licznik]!="";++licznik);
    pliczek.open("gra_dane");
    cout << "Podaj nazwe gracza: ";
    cin >> nazwa;
    licznik/=3;
    for(int i=0;i<15;++i)
    {
        if(i==licznik)
        {
            pliczek << 'n';
            pliczek << nazwa;
            pliczek << '\n';
        }
        if(osoba[i]!="")
        {
            pliczek << osoba[i];
            pliczek << '\n';
        }
    }
    pliczek << dodaj1;
    pliczek << '\n';
    pliczek << dodaj2;
    pliczek << '\n';
    pliczek.close();
    return(znak);
}
char usun_gracza(short numer,short licznik,int &n)
{
    using namespace std;
    ifstream plik;
    ofstream pliczek;
    plik.open("gra_dane");
    string osoba[15];
    string nazwa;
    short check=0;
    numer-=3;
    usun_polozenie(numer);
    for(int i=0;i<15;++i)
        getline(plik,osoba[i],'\n');
    short numer2=licznik+2*numer;
    plik.close();
    pliczek.open("gra_dane");
    for(int i=0;i<15;++i)
    {
        if(i==numer2)
            check=1;
        if(i!=numer&&i!=numer2&&i!=numer2+1)
        {
            if(check==0)
            {
                pliczek << osoba[i];
                pliczek << '\n';
            }
            if(check==1)
            {
                nazwa=osoba[i];
                --nazwa[0];
                pliczek << nazwa;
                pliczek << '\n';
            }
        }
    }
    pliczek.close();
    system("clear");
    return(poczatek(n));
}
void pobierz_dane(int &monety,int &energia,std::string &gracz,char osoba1,char osoba2)
{
    using namespace std;
    ifstream plik;
    string smieci;
    short check=0;
    plik.open("gra_dane");
    switch(osoba1)
    {
    case 'A':
        plik.get();
        getline(plik,smieci,'\n');
        gracz=smieci; break;
    case 'B':
        for(short i=0;i<2;++i)
        {
            plik.get();
            getline(plik,smieci,'\n');
        }
        gracz=smieci; break;
    case 'C':
        for(short i=0;i<3;++i)
        {
            plik.get();
            getline(plik,smieci,'\n');
        }
        gracz=smieci; break;
    case 'D':
        for(short i=0;i<4;++i)
        {
            plik.get();
            getline(plik,smieci,'\n');
        }
        gracz=smieci; break;
    case 'E':
        for(short i=0;i<5;++i)
        {
            plik.get();
            getline(plik,smieci,'\n');
        }
        gracz=smieci; break;
    }
    while(plik.get()!=osoba1)
        getline(plik,smieci,'\n');
    plik >> monety;
    plik.get();
    while(plik.get()!=osoba2)
        getline(plik,smieci,'\n');
    plik >> energia;
    plik.close();
}
void zapisz_dane(int &monety,int &energia,char osoba1,char osoba2,const char* polozenie,const char plansza[][kolumny])
{
    using namespace std;
    ifstream plik;
    plik.open("gra_dane");
    string tab[15];
    for(int i=0;i<15;++i)
    {
        getline(plik,tab[i],'\n');
    }
    plik.close();
    ofstream pliczek;
    ostringstream zamiana;
    string nowe;
    pliczek.open("gra_dane");
    for(int i=0;i<15;++i)
    {
        if(tab[i][0]==osoba1)
        {
            zamiana << monety;
            tab[i]=osoba1;
            nowe=zamiana.str();
            tab[i]+=nowe;
            tab[i]+='\n';
            pliczek << tab[i];
        }
        else
        {
            if(tab[i][0]==osoba2)
            {
                energia+=5;
                zamiana.str("");
                zamiana << energia;
                nowe=zamiana.str();
                tab[i]=osoba2;
                tab[i]+=nowe;
                tab[i]+='\n';
                pliczek << tab[i];
            }
            else
            {
                if(tab[i]!="")
                {
                    pliczek << tab[i];
                    pliczek << '\n';
                }
            }
        }
    }
    pliczek.close();
    plik.open("gra_dane2");
    for(int i=0;i<5;++i)
        getline(plik,tab[i],'\n');
    plik.close();
    pliczek.open("gra_dane2");
    for(int i=0;i<5;++i)
    {
        if(tab[i][0]==osoba1)
        {
            for(int j=0;j<wiersze;++j)
            {
                for(int k=0;k<kolumny;++k)
                {
                    if(&(plansza[j][k])==polozenie)
                    {
                        pliczek << osoba1;
                        pliczek << j;
                        pliczek << ' ';
                        pliczek << k;
                        pliczek << '\n';
                    }
                }
            }
        }
        else
        {
            pliczek << tab[i];
            pliczek << '\n';
        }
    }
    pliczek.close();
}
void usun_polozenie(short numer)
{
    using namespace std;
    ifstream plik;
    plik.open("gra_dane2");
    string tab[5];
    for(int i=0;i<5;++i)
        getline(plik,tab[i],'\n');
    plik.close();
    ofstream pliczek;
    pliczek.open("gra_dane2");
    char osoba,znak;
    short check=0;
    switch(numer)
    {
    case 0:
        osoba='A'; break;
    case 1:
        osoba='B'; break;
    case 2:
        osoba='C'; break;
    case 3:
        osoba='D'; break;
    case 4:
        osoba='E'; break;
    }
    for(int i=0;i<5;++i)
    {
        if(tab[i][0]==osoba)
            check=1;
        else
        {
            if(check==0)
            {
                pliczek << tab[i];
                pliczek << '\n';
            }
            if(check==1)
            {
                if(tab[i][0]!='A')
                {
                    znak=tab[i][0];
                    znak--;
                    pliczek << znak;
                    for(int j=1;j<tab[i].length();++j)
                    {
                        pliczek << tab[i][j];
                    }
                    pliczek << '\n';
                }
                else
                {
                    pliczek << "A18 1";
                    pliczek << '\n';
                }
            }
        }
    }
    pliczek << "E18 1";
    pliczek << '\n';
    pliczek.close();
}
int laduj_energie(int &energia,const std::string gracz,int &n)
{
    using namespace std;
    system("clear");
    char tab[21][13];
    float sec=6.0;
    clock_t delay=sec*CLOCKS_PER_SEC;
    clock_t licz;
    char znak;
    string ilosc;
    short check=0;
    int liczba,licznik=0;
    do
    {
        int k=0;
        for(int i=20;i>=0;--i)
        {
            for(int j=0;j<13;++j)
            {
                if((j==0||j==11)&&i>=0&&i<=20)
                    tab[i][j]='|';
                else
                {
                    if(j>0&&j<11&&i>=0&&i<=20&&i%2==0)
                        tab[i][j]='-';
                    else
                        tab[i][j]=' ';
                }
                if(j>0&&j<11&&(i%2!=0)&&k<energia)
                    {
                        tab[i][j]='*';
                        k++;
                    }
            }
        }
        for(int i=0;i<21;++i)
        {
            for(int j=0;j<13;++j)
            {
                cout << tab[i][j];
                if(check==0)
                {
                    if(j==12&&i==0)
                        cout << " Gracz: " << gracz;
                    if(j==12&&i==1)
                        cout << " Energia: " << energia << "%";
                    if(j==12&&i==3)
                        cout << " Menu(bateria): ";
                    if(j==12&&i==4)
                        cout << " [q] - wyjscie";
                    if(j==12&&i==5)
                        cout << " [p] - powrot";
                    if(j==12&&i==6)
                        cout << " [l] - rozpocznij ladowanie";
                }
                if(check==1)
                {
                    if(j==12&&i==0)
                        cout << " Gracz: " << gracz;
                    if(j==12&&i==1)
                        cout << " Energia: " << energia << "%";
                    if(j==12&&i==3)
                        cout << " Menu(bateria): ";
                    if(j==12&&i==4)
                        cout << " [q] - wyjscie";
                    if(j==12&&i==5)
                        cout << " [p] - powrot";
                    if(j==12&&i==9)
                    {
                        cout << " Podaj procent energii do naladowania: ";
                        check++;
                    }
                    if(j==12&&i==7)
                        cout << " Uwaga! Ladowania energii nie mozna w zaden sposob przerwac";
                }
                if(check==3)
                {
                    if(j==12&&i==0)
                        cout << " Gracz: " << gracz;
                    if(j==12&&i==1)
                        cout << " Energia: " << energia << "%";
                    if(j==12&&i==3)
                        cout << " Trwa ladowanie...";
                }
            }
            cout << endl;
        }
        if(check==0)
        {
            cin >> znak;
            czysc();
        }
        if(check==3)
        {
            if(licznik==liczba-1)
            {
                check=0;
                licznik=-1;
            }
            licz=clock();
            while(clock()-licz<delay)
                ;
            energia+=1;
            licznik++;

        }
        if(znak=='l'||check==2)
        {
            if(check==0)
                check=1;
            if(check==2)
            {
                getline(cin,ilosc,'\n');
                if(ilosc=="q")
                    znak='q';
                if(ilosc=="p")
                    check=0;
                else
                {
                    int dlugosc;
                    dlugosc=ilosc.length();
                    if(dlugosc==1&&ilosc[0]>'0'&&ilosc[0]<'9')
                    {
                        istringstream zamiana(ilosc);
                        zamiana >> liczba;
                        if(liczba+energia<=100)
                        {
                            check=3;
                            znak='\0';
                        }
                        else
                            check=1;
                    }
                    else
                    {
                        if(dlugosc==2&&ilosc[0]>'0'&&ilosc[0]<'9'&&ilosc[1]>='0'&&ilosc[1]<'9')
                        {
                            istringstream zamiana(ilosc);
                            zamiana >> liczba;
                            if(liczba+energia<=100)
                            {
                                check=3;
                                znak='\0';
                            }
                            else
                                check=1;
                        }
                        else
                        {
                            if(dlugosc==3&&ilosc=="100")
                            {
                                istringstream zamiana(ilosc);
                                zamiana >> liczba;
                                if(liczba+energia<=100)
                                {
                                    check=3;
                                    znak='\0';
                                }
                                else
                                    check=1;
                            }
                            else
                                check=1;
                        }
                    }
                }
            }
        }
        system("clear");
    }while(znak!='q'&&znak!='p');
    if(znak=='q')
        n=0;
    if(energia<=95)
        energia+=5;
    system("clear");
    return (n);
}
void teleportuj(const char tab[][kolumny],char* &polozenie,int &monety,int &energia,const std::string gracz)
{
    using namespace std;
    pokaz_plansza(tab,gracz,monety,energia,1);
    char znak;
    do
    {
        cin >> znak;
        czysc();
    }while(znak!='q');
}
