#include "gra.h"
int milionerzy(int &monety,int &energia,const std::string gracz,int &n)
{
    using namespace std;
    char tab[19][15];
    int tablica[4]{};
    string nagroda;
    int liczba=1,licznik=0,numer,x=18,wyjdz=1,zdobycz=0,first=0,zapis=0,repeat,pomoc=0,jest_pomoc1=1,jest_pomoc2=1;
    char *wygrana=&tab[x][0];
    char znak;
    float secs=4.0,secs2=6.0;
    clock_t delay=secs*CLOCKS_PER_SEC;
    clock_t delay2=secs2*CLOCKS_PER_SEC;
    cout << "Milionerzy" << endl;
    cout << "Trwa ladowanie gry..." << endl;
    clock_t licz=clock();
    while(clock()-licz<delay);
    system("clear");
    string smieci,pytanie,odpowiedz[5];
    energia-=5;
    do
    {
        for(int i=18;i>=0;--i)
        {
            for(int j=0;j<15;++j)
            {
                if(wygrana==&tab[i][j])
                {
                    if(liczba!=1)
                    {
                        tab[i][j]=':';
                        tab[i][++j]=')';
                    }
                    else
                    {
                        tab[i][j]='-';
                        tab[i][++j]='>';
                    }
                }
                else
                {
                    if(i>=0&&i%2==0&&j==0)
                        tab[i][j]='-';
                    else
                    {
                        if(i>=0&&i%2==0&&j==1)
                            tab[i][j]='>';
                        else
                        {
                            tab[i][j]=' ';
                        }
                    }
                }
            }
        }
        for(int i=0;i<19;++i)
        {
            for(int j=0;j<15;++j)
                {
                    cout << tab[i][j];
                    if(j==2&&i>=0&&i%2==0)
                    {
                        switch(i)
                        {
                        case 0:
                            nagroda="2500"; break;
                        case 2:
                            nagroda="1250"; break;
                        case 4:
                            nagroda="1000"; break;
                        case 6:
                            nagroda="800"; break;
                        case 8:
                            nagroda="600"; break;
                        case 10:
                            nagroda="400*"; break;
                        case 12:
                            nagroda="250"; break;
                        case 14:
                            nagroda="150"; break;
                        case 16:
                            nagroda="100*"; break;
                        case 18:
                            nagroda="50"; break;
                        }
                        cout << nagroda;
                    }
                    if(j==9&&i==0)
                        cout << " Gra: Milionerzy";
                    if(j==14&&i==1)
                        cout << "Gracz: " << gracz;
                    if(liczba==1)
                    {
                        if(j==9&&i==2)
                            cout << " Monety: " << monety;
                        if(j==14&&i==3)
                            cout << "Energia: " << energia << "%";
                        if(j==14&&i==5)
                            cout << "Menu: ";
                        if(j==10&&i==6)
                            cout << " [q] - wyjscie";
                        if(j==14&&i==7)
                            cout << "[p] - powrot";
                        if(j==10&&i==8)
                            cout << " [n] - rozpocznij gre";
                    }
                    if(liczba==2)
                    {
                        if(j==14&&i==3)
                            cout << "Menu: ";
                        if(j==9&&i==4)
                            cout << " [q] - wyjscie";
                        if(j==14&&i==5)
                            cout << "[p] - poddaj sie";
                        if(j==10&&i==6)
                            cout << " [n] - nastepne pytanie";
                    }
                    if(liczba==3)
                    {
                        if(j==14&&i==3)
                            cout << "Menu: ";
                        if(j==10&&i==4)
                            cout << "[p] - poddaj sie";
                        if(j==14&&i==5)
                        {
                            if(jest_pomoc2==1)
                            {
                                if(pomoc==0)
                                    cout << "[h] - kolo ratunkowe - usun dwie odpowiedzi - dostepne";
                                else
                                    cout << "[h] - kolo ratunkowe - usun dwie odpowiedzi - tymczasowo niedostepne";
                            }
                            else
                                cout << "[h] - kolo ratunkowe - usun dwie odpowiedzi - niedostepne";
                        }
                        if(j==10&&i==6)
                        {
                            if(jest_pomoc1==1)
                            {
                                if(pomoc==0)
                                    cout << " [g] - kolo ratunkowe - usun jedna odpowiedz - dostepne";
                                else
                                    cout << " [g] - kolo ratunkowe - usun jedna odpowiedz - tymczasowo niedostepne";
                            }
                            else
                                cout << " [g] - kolo ratunkowe - usun jedna odpowiedz - niedostepne";
                        }
                        if(j==10&&i==8)
                        {
                            ifstream plik;
                            if(pomoc==0)
                            {
                                if(licznik<3)
                                {
                                    plik.open("pytania_milionerzy");
                                    do
                                    {
                                        repeat=0;
                                        numer=(rand()%19)+1;
                                        for(int i=0;i<3;++i)
                                        {
                                            if(tablica[i]==numer)
                                                repeat=1;
                                        }
                                    }while(repeat==1);
                                    tablica[zapis++]=numer;
                                }
                                if(licznik>=3&&licznik<7)
                                {
                                    if(licznik==3)
                                    {
                                        zapis=0;
                                        for(int i=0;i<4;++i)
                                            tablica[i]=0;
                                    }
                                    plik.open("pytania_milionerzy2");
                                    do
                                    {
                                        repeat=0;
                                        numer=(rand()%10)+1;
                                        for(int i=0;i<4;++i)
                                        {
                                            if(tablica[i]==numer)
                                                repeat=1;
                                        }
                                    }while(repeat==1);
                                    tablica[zapis++]=numer;
                                }
                                if(licznik>=7)
                                {
                                    if(licznik==7)
                                    {
                                        zapis=0;
                                        for(int i=0;i<3;++i)
                                            tablica[i]=0;
                                    }
                                    plik.open("pytania_milionerzy3");
                                    do
                                    {
                                        repeat=0;
                                        numer=(rand()%3)+1;
                                        for(int i=0;i<3;++i)
                                        {
                                            if(tablica[i]==numer)
                                                repeat=1;
                                        }
                                    }while(repeat==1);
                                    tablica[zapis++]=numer;
                                }
                                if(numer!=1)
                                numer*=2;
                                numer-=2;
                                for(int i=0;i<numer;++i)
                                    getline(plik,pytanie,'\n');
                                getline(plik,pytanie,'\n');
                                for(int i=0;i<5;++i)
                                    getline(plik,odpowiedz[i],'*');
                                plik.close();
                            }
                            cout << " Pytanie nr " << licznik+1 << ": ";
                        }
                        if(j==14&&i==9)
                            cout << pytanie;
                        if(j==10&&i==10)
                        {
                            if(pomoc==0)
                                cout << odpowiedz[0] << " " << odpowiedz[1] << " " << odpowiedz[2] << " " << odpowiedz[3];
                            else
                            {
                                int losuj;
                                switch(odpowiedz[4][0])
                                {
                                case 'a':
                                    losuj=0; break;
                                case 'b':
                                    losuj=1; break;
                                case 'c':
                                    losuj=2; break;
                                case 'd':
                                    losuj=3; break;
                                }
                                int show[2]={losuj,losuj};
                                while(show[0]==losuj)
                                    show[0]=(rand()%4)+0;
                                if(pomoc==1)
                                {
                                while(show[1]==losuj||show[1]==show[0])
                                    show[1]=(rand()%4)+0;
                                    for(int i=0;i<4;++i)
                                    {
                                        if(i==show[0]||i==show[1]||i==losuj)
                                            cout << odpowiedz[i] << " ";
                                    }
                                }
                                if(pomoc==2)
                                {
                                    for(int i=0;i<4;++i)
                                    {
                                        if(i==show[0]||i==losuj)
                                            cout << odpowiedz[i] << " ";
                                    }
                                }
                            }
                        }
                    }
                    if(liczba==4)
                    {
                        switch(licznik)
                        {
                        case 1:
                            zdobycz=50; break;
                        case 2:
                            zdobycz=100; break;
                        case 3:
                            zdobycz=150; break;
                        case 4:
                            zdobycz=250; break;
                        case 5:
                            zdobycz=400; break;
                        case 6:
                            zdobycz=600; break;
                        case 7:
                            zdobycz=800; break;
                        case 8:
                            zdobycz=1000; break;
                        case 9:
                            zdobycz=1250; break;
                        case 10:
                            zdobycz=2500; break;
                        }
                        if(zdobycz!=0&&licznik!=10)
                        {
                            if(j==14&&i==3)
                                cout << "Twoja wygrana to: " << zdobycz;
                            if(j==9&&i==4)
                                cout << " Gratulacje!";
                            if(j==14&&i==5)
                                cout << "Trwa zapisywanie wynikow...";
                            if(i==18&&j==14)
                            {
                                energia-=20;
                                liczba=5;
                                zapis=0;
                                monety+=zdobycz;
                                first++;
                            }
                        }
                        if(zdobycz==0&&licznik!=10)
                        {
                            if(j==14&&i==3)
                                cout << "Twoja wygrana to: " << zdobycz;
                            if(j==9&&i==4)
                                cout << " Nastepnym razem pojdzie lepiej!";
                            if(j==14&&i==5)
                                cout << "Trwa zapisywanie wynikow...";
                            if(i==18&&j==14)
                            {
                                energia-=20;
                                liczba=5;
                                zapis=0;
                                first++;
                            }
                        }
                        if(licznik==10)
                        {
                            if(j==14&&i==3)
                                cout << "Twoja wygrana to: " << zdobycz;
                            if(j==9&&i==4)
                                cout << " Wygrano glowna nagrode! Gratulacje!";
                            if(j==14&&i==5)
                                cout << "Trwa zapisywanie wynikow...";
                            if(i==18&&j==14)
                            {
                                energia-=20;
                                liczba=5;
                                zapis=0;
                                monety+=zdobycz;
                            }
                        }
                    }
                }
            cout << endl;
        }
        if(liczba==5)
        {
            licz=clock();
            while(clock()-licz<delay2);
            liczba=0;
            licznik=0;
            zdobycz=0;
            jest_pomoc1=1;
            jest_pomoc2=1;
        }
        do
        {
            if(liczba!=0)
            {
                if(liczba==1||liczba==2)
                {
                    do
                    {
                        cin >> znak;
                        czysc();
                    }while(znak!='q'&&znak!='p'&&znak!='n');
                    if(znak=='q')
                            wyjdz=0;
                    if(znak=='n')
                        liczba++;
                    if(znak=='p')
                    {
                        if(liczba==2)
                        {
                            liczba=4;
                            x=18;
                            znak=' ';
                            wygrana=&tab[x][0];
                        }
                        if(liczba==1)
                            wyjdz=0;
                    }
                }
                else
                {
                    do
                    {
                        int escape=0;
                        while(escape==0&&znak!='a'&&znak!='b'&&znak!='c'&&znak!='d'&&znak!='p')
                        {
                            cin >> znak;
                            czysc();
                            if(znak=='h'&&jest_pomoc2==1&&pomoc==0)
                                escape=1;
                            if(znak=='g'&&jest_pomoc1==1&&pomoc==0)
                                escape=1;
                        }
                    }while(znak!='a'&&znak!='b'&&znak!='c'&&znak!='d'&&znak!='p'&&znak!='h'&&znak!='g');
                    switch(znak)
                    {
                    case 'a':
                        if('a'==odpowiedz[4][0])
                        {
                            x-=2;
                            wygrana=&tab[x][0];
                            liczba--;
                            licznik++;
                        }
                        else
                        {
                            liczba=4;
                            x=18;
                            wygrana=&tab[x][0];
                            if(licznik>=2&&licznik<5)
                                licznik=2;
                            else
                            {
                                if(licznik>=5)
                                    licznik=5;
                                else
                                {
                                    licznik=0;
                                    zdobycz=0;
                                }
                            }
                        }
                        pomoc=0;
                        break;
                    case 'b':
                        if('b'==odpowiedz[4][0])
                        {
                            x-=2;
                            wygrana=&tab[x][0];
                            liczba--;
                            licznik++;
                        }
                        else
                        {
                            x=18;
                            wygrana=&tab[x][0];
                            liczba=4;
                            if(licznik>=2&&licznik<5)
                                licznik=2;
                            else
                            {
                                if(licznik>=5)
                                    licznik=5;
                                else
                                {
                                    licznik=0;
                                    zdobycz=0;
                                }
                            }
                        }
                        pomoc=0;
                        break;
                    case 'c':
                        if('c'==odpowiedz[4][0])
                         {
                            x-=2;
                            wygrana=&tab[x][0];
                            liczba--;
                            licznik++;
                         }
                         else
                         {
                            x=18;
                            wygrana=&tab[x][0];
                             liczba=4;
                             if(licznik>=2&&licznik<5)
                                licznik=2;
                            else
                            {
                                if(licznik>=5)
                                    licznik=5;
                                else
                                {
                                    licznik=0;
                                    zdobycz=0;
                                }
                            }
                         }
                         pomoc=0;
                        break;
                    case 'd':
                        if('d'==odpowiedz[4][0])
                        {
                            x-=2;
                            wygrana=&tab[x][0];
                            liczba--;
                            licznik++;
                        }
                        else
                        {
                            x=18;
                            wygrana=&tab[x][0];
                            liczba=4;
                            if(licznik>=2&&licznik<5)
                                licznik=2;
                            else
                            {
                                if(licznik>=5)
                                    licznik=5;
                                else
                                {
                                    licznik=0;
                                    zdobycz=0;
                                }
                            }
                        }
                        pomoc=0;
                        break;
                    case 'p':
                        liczba=4;
                        x=18;
                        znak=' ';
                        wygrana=&tab[x][0];
                        break;
                    case 'h':
                        pomoc=2;
                        jest_pomoc2=0;
                        break;
                    case 'g':
                        pomoc=1;
                        jest_pomoc1=0;
                        break;
                    }
                    if(licznik==10)
                        liczba=4;
                }
            }
            else
                liczba++;
        }while(znak!='n'&&znak!=' '&&znak!='a'&&znak!='b'&&znak!='c'&&znak!='d'&&wyjdz==1&&znak!='h'&&znak!='g');
        system("clear");
    }while(znak!='q'&&znak!='p');
    energia+=5;
    if(znak=='q')
        n=0;
    if(znak!='q')
    {
        cout << "Dziekujemy za udzial w grze!" << endl;
        cout << "Trwa powrot na plansze..." << endl;
        licz=clock();
        while(clock()-licz<delay);
        system("clear");
    }
    return(n);
}
