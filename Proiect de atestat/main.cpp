#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <windows.h>
#include "tic_tac_toe.h"
#include "mare_mic.h"
#include "centrate_necentrate.h"
#include "provocare_atentie.h"
#include "minesweper.h"

using namespace std;
void SetColor(int );
void meniu_Introducere(int& );
void introduce_date(bool& );
void meniu_jocuri(int& );
void afiseaza_lista_jocuri(int& );
void afiseazaClasament();
void incarca_clasament();
bool cautare_clasament(char nume[], char prenume[]);
void salvare_clasament();
void ordoneaza_clasament();
void joaca_joc_ales(int );
void joc_random(int& );
void afiseazaTitlu();
char ch;

struct CONCURENT
{
    char nume[31];
    char prenume[31];
    int scor;
}con[20];
CONCURENT c_activ;
int numar_concurenti, pozitie;
int main()
{
    srand(time(NULL));
    int alegere_optiune, joc_ales, alegere_joc;
    bool aplicatie_deschisa=true, ok;
    incarca_clasament();
    ordoneaza_clasament();
    do
    {
        meniu_Introducere(alegere_optiune);  // afiseaza primul meniu
        if(alegere_optiune==1)
        {
            introduce_date(ok); // introduce datele si verifica daca mai exista un jucator cu acelasi nume
            do
            {
                meniu_jocuri(alegere_joc);   // afiseaza al doilea meniu , cel cu jocuri
                if(alegere_joc==1)
                {
                    do
                    {
                        afiseaza_lista_jocuri(joc_ales);
                        joaca_joc_ales(joc_ales);
                    }while(joc_ales!=5);
                }
                else if(alegere_joc==2)
                {
                    system("cls");
                    joc_random(joc_ales);
                    joaca_joc_ales(joc_ales);
                }
                else if(alegere_joc==3)
                {
                    con[pozitie].scor+=provocare_atentie();
                }
                else if(alegere_joc==4)
                {
                    afiseazaClasament();
                }
                else if(alegere_joc==5)
                    ok=false;
            }while(ok);
        }
        if(alegere_optiune==2)
        {
            ordoneaza_clasament();
            afiseazaClasament();
        }
        if(alegere_optiune==3)
            aplicatie_deschisa=false;
    }while(aplicatie_deschisa);
    ordoneaza_clasament();
    salvare_clasament();
}

void meniu_Introducere(int& alegere_optiune)
{
    system("cls");
    afiseazaTitlu();
    ch = 176;
    SetColor(15);
    for(int f=0; f<25; f++)
        cout<<ch;
    cout<<endl;
    SetColor(3);
    cout<<ch<<" 1-> Intra in aplicatie "<<endl;
    cout<<ch<<" 2-> Clasament "<<endl;
    cout<<ch<<" 3-> Iesire "<<endl;
    SetColor(15);
    for(int f=0; f<25; f++)
        cout<<ch;
    cout<<endl;
    cin>>alegere_optiune;
}
void introduce_date(bool& ok)
{
    system("cls");
    afiseazaTitlu();
    cout<<endl;
    SetColor(11);
    cout<<" Introduceti numele si prenumele "<<endl;
    cout<<" Nume : "; cin>>c_activ.nume;
    cout<<" Prenume : "; cin>>c_activ.prenume;
    cout<<endl;
    if(cautare_clasament(c_activ.nume, c_activ.prenume)==true)   //verificam daca acest concurent are deja un loc in clasament
    {
        ok=true;
        cout<<endl;
        cout<<" Numele dumneavoastra a fost gasit in clasamentul oficial."<<endl;
        cout<<" Punctele obtinute se vor adauga la scorul pe care deja il aveti inregistrat."<<endl;
        cout<<endl;
        cout<<" Pentru a continua apasati o tasta ";
        system("pause>nul");
    }
    else
    {
        ok=true;
        cout<<endl;
        cout<<" Numele dumneavoastra nu a fost gasit in clasamentul oficial."<<endl;
        cout<<" Se va creea un loc automat iar data viitoare cand vei reveni punctele obtinute se vor adauga la scorul pe care deja il aveti inregistrat."<<endl;
        cout<<" Succes!"<<endl;
        cout<<endl;     //daca numele nu este gasit se creeaza inca o pozitie pentru noul participant
        strcpy(con[numar_concurenti].nume, c_activ.nume);
        strcpy(con[numar_concurenti].prenume, c_activ.prenume);
        c_activ.scor=0;
        con[numar_concurenti].scor=c_activ.scor;
        pozitie=numar_concurenti;
        numar_concurenti++;
        system("pause");
    }
}
void meniu_jocuri(int& alegere_joc)
{
    system("cls");
    afiseazaTitlu();
    cout<<endl;
    SetColor(11);
    cout<<" Bine ai venit, "<<c_activ.nume<<' '<<c_activ.prenume<<" !"<<endl;
    ch=176;
    SetColor(5);
    for(int f=0; f<45; f++)
        cout<<ch;
    SetColor(11);
    cout<<endl<<" Poti alege una din activitatile urmatoare : "<<endl;
    ch=177;
    SetColor(5);
    for(int f=0; f<45; f++)
        cout<<ch;
    SetColor(11);
    cout<<endl<<endl;
    cout<<" 1 -> Alege joc "<<endl;
    cout<<" 2 -> Joc random "<<endl;
    cout<<" 3 -> Provocare "<<endl;
    cout<<" 4 -> Clasament "<<endl;
    cout<<" 5 -> Inapoi "<<endl<<endl;
    ch=178;
    SetColor(5);
    for(int f=0; f<45; f++)
        cout<<ch;
    cout<<endl;
    SetColor(15);
    cin>>alegere_joc;
}
void afiseaza_lista_jocuri(int& joc_ales)
{
    system("cls");
    cout<<endl;
    SetColor(rand()%15+1);  cout<<" 1-> X si O ( Tic Tac Toe ) "<<endl;
    SetColor(rand()%15+1);  cout<<" 2-> Mare sau Mic "<<endl;
    SetColor(rand()%15+1);  cout<<" 3-> Centrate / Necentrate "<<endl;
    SetColor(rand()%15+1);  cout<<" 4-> Minesweeper "<<endl;
    SetColor(rand()%15+1);  cout<<" 5-> Inapoi "<<endl;
    cin>>joc_ales;
}
void joc_random(int& joc_ales)
{
    joc_ales=rand()%4+1;
}
void joaca_joc_ales(int joc_ales)
{
    switch(joc_ales)
    {
        case 1:
            SetColor(11);
            con[pozitie].scor+=tic_tac_toe();
            break;
        case 2:
            SetColor(10);
            con[pozitie].scor+=mare_mic();
            break;
        case 3:
            SetColor(10);
            con[pozitie].scor+=centrate_necentrate();
            break;
        case 4:
            SetColor(10);
            con[pozitie].scor+=mnswp();
            break;
        }
}
void afiseazaClasament()
{
    system("cls");
    ch=205;
    cout<<" Nume   Prenume   Scor"<<endl;
    for(int f=0; f<25; f++)
        cout<<ch;
    cout<<endl;
    for(int t=0; t<numar_concurenti; t++)
    {
        cout<<' '<<t+1<<" ) "<<con[t].nume<<' '<<con[t].prenume<<' '<<con[t].scor<<endl;
    }
    cout<<endl;
    system("pause");
}
void incarca_clasament()
{
    ifstream clasam_i("clasament.txt");
    clasam_i>>numar_concurenti;
    for(int t=0; t<numar_concurenti; t++)
    {
        clasam_i>>con[t].nume>>con[t].prenume>>con[t].scor;
    }
    clasam_i.close();
}
bool cautare_clasament(char nume[31], char prenume[31])
{
    int t=-1;
    bool nume_gasit=false;
    do
    {
        t++;
        if(strcmp(c_activ.nume, con[t].nume)==0)   // verifica daca numele este deja inscris in clasament
        {
            if(strcmp(c_activ.prenume, con[t].prenume)==0)    // daca gaseste numele , verifica si prenumele
            {
                nume_gasit=true;
            }
        }
    }while(!nume_gasit and t<numar_concurenti);
    if(nume_gasit)
        pozitie=t;
    return nume_gasit;
}
void salvare_clasament()
{
    ofstream clasam_o("clasament.txt");
    clasam_o<<numar_concurenti<<endl;
    for(int r=0; r<numar_concurenti; r++)
    {
        clasam_o<<con[r].nume<<' '<<con[r].prenume<<' '<<con[r].scor<<endl;
    }
    clasam_o.close();
}
void ordoneaza_clasament()
{
    CONCURENT aux;
    int i, j;
    for(i=0; i<numar_concurenti-1; i++)
    {
        for(j=i+1; j<numar_concurenti; j++)
        {
            if(con[i].scor<con[j].scor)
            {
                aux=con[i];
                con[i]=con[j];
                con[j]=aux;
            }
        }
    }
}

void afiseazaTitlu()
{
    SetColor(10);
    cout<<endl;
    ch=176;
    cout<<"   "<<ch<<ch<<ch<<"  "<<ch<<ch<<ch<<ch<<"  "<<ch<<ch<<ch<<ch<<"       "<<ch<<ch<<ch<<"   "<<ch<<ch<<ch<<ch<<"  "<<ch<<ch<<ch<<ch<<"  "<<ch<<ch<<ch<<"  "<<ch<<endl;
    cout<<"     "<<ch<<"  "<<ch<<"  "<<ch<<"  "<<ch<<"          "<<ch<<"  "<<ch<<"  "<<ch<<"  "<<ch<<"  "<<ch<<"  "<<ch<<"  "<<ch<<"    "<<ch<<endl;
    cout<<"     "<<ch<<"  "<<ch<<"  "<<ch<<"  "<<ch<<"          "<<ch<<"  "<<ch<<"  "<<ch<<"  "<<ch<<"  "<<ch<<ch<<ch<<ch<<"  "<<ch<<ch<<"   "<<ch<<endl;
    cout<<"   "<<ch<<" "<<ch<<"  "<<ch<<"  "<<ch<<"  "<<ch<<"          "<<ch<<"  "<<ch<<"  "<<ch<<"  "<<ch<<"  "<<ch<<" "<<ch<<"   "<<ch<<"    "<<ch<<endl;
    cout<<"   "<<ch<<ch<<ch<<"  "<<ch<<ch<<ch<<ch<<"  "<<ch<<ch<<ch<<ch<<"       "<<ch<<ch<<ch<<"   "<<ch<<ch<<ch<<ch<<"  "<<ch<<"  "<<ch<<"  "<<ch<<ch<<ch<<"  "<<ch<<ch<<ch<<endl;
    cout<<endl;
    cout<<endl;
}

void SetColor(int value)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),value);
};
