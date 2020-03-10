#include "gra.h"
int labirynt(int &monety,int &energia,const std::string gracz,int &n)
{
    using std::cout;
    using std::endl;
    char tab[40][85];
    char los[40][80];
    int liczba_los,konto=0;
    bool zapis=0,exit,show=0,pomoc=0,numer=0,prepare=0,koniec=0;
    int dlugosc=gracz.length();
    char *nazwa=new char[dlugosc+1];
    for(int i=0;i<dlugosc;++i)
        nazwa[i]=gracz[i];
    nazwa[dlugosc]='\0';
    int x=10,y=10,k[6],l[6],k1[6],l1[6];
    int znak;
    float secs=2.0,secs2=3.0;
    clock_t delay=secs*CLOCKS_PER_SEC;
    clock_t czas=clock();
    clock_t licznik=0;
    cout << "Labirynt" << endl;
    cout << "Trwa ladowanie gry..." << endl;
    while(clock()-czas<delay);
    system("clear");
    initscr();
    energia-=5;
    do
    {
        if(numer==0)
        {
            for(int i=0;i<6;++i)
            {
                k1[i]=1;
                l1[i]=1;
                k[i]=(rand()%38)+1;
                l[i]=(rand()%77)+1;
                if(k[i]==k[0]&&l[i]==l[0]&&i!=0)
                    --i;
            }
            for(int i=1;i<49;++i)
            {
                for(int j=1;j<78;++j)
                {
                    liczba_los=(rand()%4)+0;
                    if(liczba_los>0)
                        los[i][j]=' ';
                    else
                        los[i][j]='o';
                    if(k[5]==i&&l[5]==j)
                        los[i][j]='*';
                    if(k[4]==i&&l[4]==j)
                        los[i][j]='*';
                    if(k[3]==i&&l[3]==j)
                        los[i][j]='*';
                    if(k[2]==i&&l[2]==j)
                        los[i][j]='$';
                    if(k[1]==i&&l[1]==j)
                        los[i][j]='$';
                    if(k[0]==i&&j==l[0])
                        los[i][j]='@';
                }
            }
        }
        exit=0;
        if(numer==1)
        {
            licznik=1000-(clock()-czas)/1000;
            if(clock()-czas>1000000)
            {
                show=1;
                exit=1;
                koniec=1;
            }
        }
        for(int i=0;i<40;++i)
        {
            for(int j=0;j<85;++j)
            {
                if(j==0||j==78)
                    tab[i][j]='|';
                else
                {
                    if(j>0&&j<78&&(i==0||i==39))
                        tab[i][j]='-';
                    else
                    {
                        if(numer==0)
                            tab[i][j]=' ';
                        else
                        {
                            if(i>0&&i<39&&j>0&&j<79)
                                tab[i][j]=los[i][j];
                            else
                                tab[i][j]=' ';
                        }
                    }
                }
                if(j==y&&i==x)
                    tab[x][y]='x';
                if(i==0&&j==84)
                    printw("Gra: Labirynt");
                if(i==1&&j==84)
                    printw("Gracz: %s",nazwa);
                if(numer==1&&prepare==1&&i==2&&j==84&&koniec==0)
                {
                    static int licznik=4;
                    licznik--;
                    printw("Gra zacznie sie za: %d",licznik);
                    if(licznik==0)
                    {
                        prepare=0;
                        licznik=4;
                    }
                }
                if(numer==1&&i==2&&j==84&&prepare==0&&koniec==0)
                    printw("Czas: %d",licznik);
                if(koniec==1)
                {
                    if(i==2&&j==84)
                        printw("Zdobyto: %d monet",konto);
                    if(i==3&&j==84)
                        printw("Trwa zapisywanie wynikow...");
                }
                if(numer==0)
                {
                    if(i==2&&j==84)
                        printw("Monety: %d",monety);
                    if(i==3&&j==84)
                        printw("Energia: %d\%%",energia);
                }
                if(i==5&&j==84)
                    printw("Menu: ");
                if(numer==0)
                {
                    if(i==6&&j==84)
                        printw("[q] - wyjscie");
                    if(i==7&&j==84)
                        printw("[p] - powrot");
                }
                if(numer==1)
                    if(i==6&&j==84)
                        printw("[p] - poddaj sie");
                if(numer==0&&pomoc==0)
                {
                    if(i==8&&j==84)
                        printw("[n] - rozpocznij gre");
                    if(i==9&&j==84)
                        printw("[h] - zasady gry");
                }
                if(pomoc==1)
                {
                    if(i==9&&j==84)
                        printw("Zasady gry: ");
                    if(i==10&&j==84)
                        printw("1. Gra jest w trybie bezposrednim(interakcje zachodza bez nacisku klawisza enter)");
                    if(i==11&&j==84)
                        printw("2. Poruszane odbywa sie za pomoca klawiszy: W,A,S,D.");
                    if(i==12&&j==84)
                        printw("3. Warunkiem ukonczenia gry jest zdobycie miejsca oznaczonego znakiem '@', wyroznionym kolorem czerwonym.");
                    if(i==13&&j==84)
                        printw("4. Miejsca oznaczone znakami '$' oraz '*' pozwalaja na zdobycie bonusowych monet");
                    if(i==14&&j==84)
                        printw("5. Bonusy za poszczegolne miejsca: ");
                    if(i==15&&j==84)
                        printw("- @ - 300 monet");
                    if(i==16&&j==84)
                        printw("- $ - 200 monet");
                    if(i==17&&j==84)
                        printw("- * - 100 monet");
                }
                if(i==x&&j==y)
                {
                    start_color();
                    init_pair(1,COLOR_CYAN,COLOR_BLACK);
                    init_pair(2,COLOR_YELLOW,COLOR_BLACK);
                    attron(COLOR_PAIR(1));
                    attron(A_BOLD);
                    printw("%c",tab[i][j]);
                    attroff(COLOR_PAIR(1));
                    attroff(A_BOLD);
                }
                else
                {
                    if((i==k[3]&&j==l[3]&&k1[3]==1&&l1[3]==1)||(i==k[4]&&j==l[4]&&1==k1[4]&&1==l1[4])||(i==k[5]&&j==l[5]&&1==k1[5]&&1==l1[5]))
                    {
                        if(i==k[3]&&j==l[3])
                            kolor(tab,i,j);
                        if(i==k[4]&&j==l[4])
                            kolor(tab,i,j);
                        if(i==k[5]&&j==l[5])
                            kolor(tab,i,j);
                    }
                    else
                    {
                        if((i==k[2]&&j==l[2]&&1==k1[2]&&1==l1[2])||(i==k[1]&&j==l[1]&&1==k1[1]&&1==l1[1]))
                        {
                            if(i==k[2]&&j==l[2])
                                kolor(tab,i,j);
                            if(i==k[1]&&j==l[1])
                                kolor(tab,i,j);
                        }
                        else
                        {
                            if(i==k[0]&&j==l[0])
                            {
                                init_pair(3,COLOR_RED,COLOR_BLACK);
                                attron(COLOR_PAIR(3));
                                attron(A_BOLD);
                                printw("%c",tab[i][j]);
                                attroff(COLOR_PAIR(3));
                                attroff(A_BOLD);
                            }
                            else
                            {
                                attron(A_DIM);
                                printw("%c",tab[i][j]);
                                attroff(A_DIM);
                            }
                        }
                    }
                }
            }
            printw("\n");
        }
        if(koniec==1)
        {
            numer=0;
            konto=0;
            koniec=0;
            refresh();
            sleep(2);
        }
        if(prepare==1)
        {
            refresh();
            sleep(1);
        }
        do
        {
            noecho();
            if(numer==1)
                timeout(75);
            znak=getch();
            switch(znak)
            {
            case -1:
                exit=1;
                break;
            case 'w':
                if(prepare==0)
                {
                    if(tab[x-1][y]==' ')
                    {
                        x--;
                        exit=1;
                    }
                    if(tab[x-1][y]=='@'&&exit==0)
                    {
                        koniec=1;
                        zapis=1;
                        konto+=300;
                        x--;
                        exit=1;
                        show=1;
                    }
                    if(tab[x-1][y]=='*'&&exit==0)
                    {
                        if(x-1==k[3]&&y==l[3]&&k1[3]==1)
                        {
                            konto+=100;
                            k1[3]=0;
                            l1[3]=0;
                        }
                        if(x-1==k[4]&&y==l[4]&&k1[4]==1)
                        {
                            konto+=100;
                            k1[4]=0;
                            l1[4]=0;
                        }
                        if(x-1==k[5]&&y==l[5]&&k1[5]==1)
                        {
                            k1[5]=0;
                            l1[5]=0;
                            konto+=100;
                        }
                        x--;
                        exit=1;
                    }
                    if(tab[x-1][y]=='$'&&exit==0)
                    {
                        if(x-1==k[1]&&y==l[1]&&k1[1]==1)
                        {
                            konto+=200;
                            k1[1]=0;
                            l1[1]=0;
                        }
                        if(x-1==k[2]&&y==l[2]&&k1[2]==1)
                        {
                            konto+=200;
                            k1[2]=0;
                            l1[2]=0;
                        }
                        x--;
                        exit=1;
                    }
                }
                break;
            case 's':
                if(prepare==0)
                {
                    if(tab[x+1][y]==' ')
                    {
                        x++;
                        exit=1;
                    }
                    if(tab[x+1][y]=='@'&&exit==0)
                    {
                        koniec=1;
                        zapis=1;
                        konto+=300;
                        x++;
                        exit=1;
                        show=1;
                    }
                    if(tab[x+1][y]=='*'&&exit==0)
                    {
                        if(x+1==k[3]&&y==l[3]&&k1[3]==1)
                        {
                            konto+=100;
                            k1[3]=0;
                            l1[3]=0;
                        }
                        if(x+1==k[4]&&y==l[4]&&k1[4]==1)
                        {
                            konto+=100;
                            k1[4]=0;
                            l1[4]=0;
                        }
                        if(x+1==k[5]&&y==l[5]&&k1[5]==1)
                        {
                            konto+=100;
                            k1[5]=0;
                            l1[5]=0;
                        }
                        x++;
                        exit=1;
                    }
                    if(tab[x+1][y]=='$'&&exit==0)
                    {
                        if(x+1==k[1]&&y==l[1]&&k1[1]==1)
                        {
                            konto+=200;
                            k1[1]=0;
                            l1[1]=0;
                        }
                        if(x+1==k[2]&&y==l[2]&&k1[2]==1)
                        {
                            konto+=200;
                            k1[2]=0;
                            l1[2]=0;
                        }
                        x++;
                        exit=1;
                    }
                }
                break;
            case 'a':
                if(prepare==0)
                {
                    if(tab[x][y-1]==' '&&exit==0)
                    {
                        y--;
                        exit=1;
                    }
                    if(tab[x][y-1]=='@')
                    {
                        koniec=1;
                        zapis=1;
                        konto+=300;
                        y--;
                        exit=1;
                        show=1;
                    }
                    if(tab[x][y-1]=='*'&&exit==0)
                    {
                        if(x==k[3]&&y-1==l[3]&&k1[3]==1)
                        {
                            konto+=100;
                            k1[3]=0;
                            l1[3]=0;
                        }
                        if(x==k[4]&&y-1==l[4]&&k1[4]==1)
                        {
                            konto+=100;
                            k1[4]=0;
                            l1[4]=0;
                        }
                        if(x==k[5]&&y-1==l[5]&&k1[5]==1)
                        {
                            konto+=100;
                            k1[5]=0;
                            l1[5]=0;
                        }
                        y--;
                        exit=1;
                    }
                    if(tab[x][y-1]=='$'&&exit==0)
                    {
                        if(x==k[1]&&y-1==l[1]&&k1[1]==1)
                        {
                            konto+=200;
                            k1[1]=0;
                            l1[1]=0;
                        }
                        if(x==k[2]&&y-1==l[2]&&k1[2]==1)
                        {
                            konto+=200;
                            k1[2]=0;
                            l1[2]=0;
                        }
                        y--;
                        exit=1;
                    }
                }
                break;
            case 'd':
                if(prepare==0)
                {
                    if(tab[x][y+1]==' ')
                    {
                        y++;
                        exit=1;
                    }
                    if(tab[x][y+1]=='@'&&exit==0)
                    {
                        koniec=1;
                        zapis=1;
                        konto+=300;
                        y++;
                        exit=1;
                        show=1;
                    }
                    if(tab[x][y+1]=='*'&&exit==0)
                    {
                        if(x==k[3]&&y+1==l[3]&&k1[3]==1)
                        {
                            konto+=100;
                            k1[3]=0;
                            l1[3]=0;
                        }
                        if(x==k[4]&&y+1==l[4]&&k1[4]==1)
                        {
                            konto+=100;
                            k1[4]=0;
                            l1[4]=0;
                        }
                        if(x==k[5]&&y+1==l[5]&&k1[5]==1)
                        {
                            konto+=100;
                            k1[5]=0;
                            l1[5]=0;
                        }
                        y++;
                        exit=1;
                    }
                    if(tab[x][y+1]=='$'&&exit==0)
                    {
                        if(x==k[1]&&y+1==l[1]&&k1[1]==1)
                        {
                            konto+=200;
                            k1[1]=0;
                            l1[1]=0;
                        }
                        if(x==k[2]&&y+1==l[2]&&k1[2]==1)
                        {
                            konto+=200;
                            k1[2]=0;
                            l1[2]=0;
                        }
                        y++;
                        exit=1;
                    }
                }
                break;
            case 'p':
                if(numer==0)
                {
                    exit=1;
                    if(pomoc==1)
                    {
                        znak=' ';
                        pomoc=0;
                    }
                }
                else
                {
                    if(prepare==0)
                    {
                        znak=' ';
                        exit=1;
                        zapis=0;
                        show=1;
                        koniec=1;
                    }
                }
                break;
            case 'q':
                if(numer==0)
                    exit=1;
                break;
            case 'n':
                if(numer==0)
                {
                    prepare=1;
                    energia-=20;
                    numer=1;
                    exit=1;
                    czas=clock();
                }
                break;
            case 'h':
                if(numer==0&&pomoc==0)
                {
                    exit=1;
                    pomoc=1;
                }
                break;
            }
        }while(exit==0);
        wclear(stdscr);
        if(show==1)
        {
            wclear(stdscr);
            if(zapis==0)
                konto=0;
            monety+=konto;
            show=0;
            zapis=0;
            prepare=0;
        }
    }while(znak!='q'&&znak!='p');
    endwin();
    if(znak!='q')
        energia+=5;
    if(znak=='p')
    {
        system("clear");
        cout << "Dziekujemy za udzial w grze!" << endl;
        cout << "Trwa powrot na plansze..." << endl;
        czas=clock();
        while(clock()-czas<delay);
        system("clear");
        return(n);
    }
    if(znak=='q')
        return(0);
}
void kolor(char tab[][85],int i,int j)
{
    attron(COLOR_PAIR(2));
    attron(A_BOLD);
    printw("%c",tab[i][j]);
    attroff(COLOR_PAIR(2));
    attroff(A_BOLD);
}
