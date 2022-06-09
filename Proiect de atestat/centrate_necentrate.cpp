#include <iostream>
#include <cstdlib>
#include <ctime>
#include "centrate_necentrate.h"
using namespace std;
int v[10];
void instructiuni_ghiceste_nr()
{
    cout<<" Scopul acestui joc este de a va antrena gandirea."<<endl;
    cout<<" Computerul a generat un numar de 4 cifre distincte. Dumneavoastra trebuie sa ghiciti acest numar."<<endl;
    cout<<" Ca si ajutor computerul va va spune cate cifre din acest numar sunt aranjate conform numarului generat"<<endl;
    cout<<endl<<" Succes!"<<endl<<endl;
}
int apare(int nr,int cifra)
{
    int ap=0;
    do
    {
        if(nr%10==cifra)
            ap++;
        nr=nr/10;
    }while(nr!=0);
    return ap;
}
bool cifre_distincte(int nr)
{
    int c;
    for(c=0;c<=9;c++)
        if(apare(nr,c)>1)
            return false;
    return true;
}
int centrate_necentrate()
{
    int n,i,x[10],a,b,c,d,j,cop,n_incercari=0;
    srand((int)time(0));
    n=1111;
    do
    {
        n=(rand()%9000)+1000;
    }while(cifre_distincte(n)!=1);
    cop=n;
    for(i=1;i<=4;i++)
    {
        v[i]=cop%10;
        cop=cop/10;
    }
    system("cls");
    instructiuni_ghiceste_nr();
    cout<<"Ghiceste numarul"<<endl<<endl;
    do
    {
        cin>>a;
        n_incercari++;
        if(a>=1000 && a<=9999)
        {
            b=a;
            for(i=1;i<=4;i++)
            {
                x[i]=b%10;
                b=b/10;
            }
            c=0;
            d=0;
            for(i=1;i<=4;i++)
                if(v[i]==x[i])
                    c++;
            for(i=1;i<=4;i++)
                for(j=1;j<=4;j++)
                    if(v[i]==x[j] && i!=j)
                        d++;
            cout<<c<<" centrate si "<<d<<" necentrate"<<endl<<endl;
            if(c==4)
                cout<<"Felicitari! Ai avut "<<n_incercari<<" incercari !"<<endl;
        }
    else
        cout<<"Alegere incorecta.Introdu alta valoare:"<<endl<<endl;
    }while(c!=4);
    cout<<" Ai obtinut 3 puncte."<<endl;
    system("pause");
    return 3;
}
