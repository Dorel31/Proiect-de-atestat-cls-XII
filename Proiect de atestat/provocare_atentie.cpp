#include <iostream>
#include <cstring>
#include <cstdlib>
#include "provocare_atentie.h"
using namespace std;

void instructiuni_provocare()
{
    system("cls");
    cout<<" Acesta este un test pentru a va verifica atentia si puterea de concentrare ."<<endl<<endl;
    system("pause");
}
int provocare_atentie()
{
    int raspuns_oficial_1=4;
    int raspuns_oficial_2=2;
    int raspuns_oficial_3=12;
    int raspuns_oficial_4=4;
    int raspuns_oficial_5=48;
    int raspuns_oficial_6=0;
    int raspuns_oficial_7=1;
    int raspuns_oficial_8=10;
    int raspuns_oficial_9=16;
    char raspuns_oficial_10[11]="cub";
    int raspuns_dat;
    char raspuns_d[31], enter[10];
    int puncte=0;
    instructiuni_provocare();
    system("cls");
    cout<<" 1-> Intr-un cos sunt 4 mere verzi si 3 rosii.Cate mere sunt in cos?"<<endl;
    cout<<" Raspunsul dumneavoastra : ";
    cin>>raspuns_dat;
    if(raspuns_dat==raspuns_oficial_1)
    {
        cout<<" Raspuns corect !"<<endl;
        puncte++;
    }
    else
    {
        cout<<" Raspuns gresit !"<<endl;
        cout<<" Raspunsul corect este : "<<raspuns_oficial_1<<endl;
    }
    system("pause");
    system("cls");
    cout<<" 2-> Daca esti ?ntr-o competitie si il depasesti pe cel de pe locul 2, pe ce loc vei fi la final?"<<endl;
    cout<<" Raspunsul dumneavoastra : ";
    cin>>raspuns_dat;
    if(raspuns_dat==raspuns_oficial_2)
    {
        cout<<" Raspuns corect !"<<endl;
        puncte++;
    }
    else
    {
        cout<<" Raspuns gresit !"<<endl;
        cout<<" Raspunsul corect este : "<<raspuns_oficial_2<<endl;
    }
    system("pause");

    system("cls");
    cout<<" 3-> Unele luni au 31 de zile , unele au 30. Cate luni au 28?"<<endl;
    cout<<" Raspunsul dumneavoastra : ";
    cin>>raspuns_dat;
    if(raspuns_dat==raspuns_oficial_3)
    {
        cout<<" Raspuns corect !"<<endl;
        puncte++;
    }
    else
    {
        cout<<" Raspuns gresit !"<<endl;
        cout<<" Raspunsul corect este : "<<raspuns_oficial_3<<endl;
    }
    system("pause");

    system("cls");
    cout<<" 4-> Daca pe talerul unui cantar punem 4 kg de mere cu 3 lei/kg, cate kg de mere cu 2 lei/kg trebuie puse pe celalalt taler pentru a echilibra balanta?"<<endl;
    cout<<" Raspunsul dumneavoastra : ";
    cin>>raspuns_dat;
    if(raspuns_dat==raspuns_oficial_4)
    {
        cout<<" Raspuns corect !"<<endl;
        puncte++;
    }
    else
    {
        cout<<" Raspuns gresit !"<<endl;
        cout<<" Raspunsul corect este : "<<raspuns_oficial_4<<endl;
    }
    system("pause");

    system("cls");
    cout<<" 5-> Daca 3 gaini fac 3 oua in 3 zile cate oua fac 12 gaini in 12 zile?"<<endl;
    cout<<" Raspunsul dumneavoastra : ";
    cin>>raspuns_dat;
    if(raspuns_dat==raspuns_oficial_5)
    {
        cout<<" Raspuns corect !"<<endl;
        puncte++;
    }
    else
    {
        cout<<" Raspuns gresit !"<<endl;
        cout<<" Raspunsul corect este : "<<raspuns_oficial_5<<endl;
    }
    system("pause");

    system("cls");
    cout<<" 6-> Cate kg de pamant are o groapa de 3m latime 2m lungime si 1m adancime sapata in America de Sud ?"<<endl;
    cout<<" Raspunsul dumneavoastra : ";
    cin>>raspuns_dat;
    if(raspuns_dat==raspuns_oficial_6)
    {
        cout<<" Raspuns corect !"<<endl;
        puncte++;
    }
    else
    {
        cout<<" Raspuns gresit !"<<endl;
        cout<<" Raspunsul corect este : "<<raspuns_oficial_6<<endl;
    }
    system("pause");

    system("cls");
    cout<<" 7-> Cate mere poti manca dimineata pe stomacul gol?"<<endl;
    cout<<" Raspunsul dumneavoastra : ";
    cin>>raspuns_dat;
    if(raspuns_dat==raspuns_oficial_7)
    {
        cout<<" Raspuns corect !"<<endl;
        puncte++;
    }
    else
    {
        cout<<" Raspuns gresit !"<<endl;
        cout<<" Raspunsul corect este : "<<raspuns_oficial_7<<endl;
    }
    system("pause");

    system("cls");
    cout<<" 8-> Daca 3 oua fierb in 10 minute, 56 de oua in cate minute fierb?"<<endl;
    cout<<" Raspunsul dumneavoastra : ";
    cin>>raspuns_dat;
    if(raspuns_dat==raspuns_oficial_8)
    {
        cout<<" Raspuns corect !"<<endl;
        puncte++;
    }
    else
    {
        cout<<" Raspuns gresit !"<<endl;
        cout<<" Raspunsul corect este : "<<raspuns_oficial_8<<endl;
    }
    system("pause");

    system("cls");
    cout<<" 9-> Care este continuarea logica a sirului de numere 1, 2, 4, 8, ... ?"<<endl;
    cout<<" Raspunsul dumneavoastra : ";
    cin>>raspuns_dat;
    if(raspuns_dat==raspuns_oficial_9)
    {
        cout<<" Raspuns corect !"<<endl;
        puncte++;
    }
    else
    {
        cout<<" Raspuns gresit !"<<endl;
        cout<<" Raspunsul corect este : "<<raspuns_oficial_9<<endl;
    }
    system("pause");

    system("cls");
    cout<<" 10-> Ce figura geometrica nu ar trebui sa fie in lista urmatoare? (dreptunghi, cub, triunghi, patrat) "<<endl;
    cout<<" Raspunsul dumneavoastra : ";
    cin.getline(enter, 10);
    cin.getline(raspuns_d, 31);
    if(strcmp(raspuns_d, raspuns_oficial_10)==0)
    {
        cout<<" Raspuns corect !"<<endl;
        puncte++;
    }
        else
    {
        cout<<" Raspuns gresit !"<<endl;
        cout<<" Raspunsul corect este : "<<raspuns_oficial_10<<endl;
    }
    system("pause");
    system("cls");
    cout<<" Ai obtinut "<<puncte<<" puncte. Felicitari!"<<endl;
    system("pause");
    return puncte;
}

