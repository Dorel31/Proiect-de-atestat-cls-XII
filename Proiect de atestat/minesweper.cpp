#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "minesweper.h"
using namespace std;

int vp[52][52],nlin,ncol,nbombe,punctaj;
int m[52][52];
void prelucrare(int vp[52][52])
{
    int i;
    for(i=0;i<=ncol;i++)
        vp[0][i]=i;
    for(i=0;i<=nlin;i++)
        vp[i][ncol]=i;
    for(i=0;i<=nlin;i++)
        vp[i][0]=i;
    for(i=0;i<=ncol;i++)
        vp[nlin][i]=i;
        vp[nlin][ncol]=0;

}
void prelucrare_1(int vp[52][52])
{
    int i,j;
    for(i=1;i<=nlin-1;i++)
        for(j=1;j<=ncol-1;j++)
            vp[i][j]=100;
}
void revenire(int vp[52][52])
{
    int i;
    for(i=0;i<=ncol;i++)
        vp[0][i]=0;
    for(i=0;i<=nlin;i++)
        vp[i][ncol]=0;
    for(i=0;i<=nlin;i++)
        vp[i][0]=0;
    for(i=0;i<=ncol;i++)
        vp[nlin][i]=0;
        vp[nlin][ncol]=0;
}
void scrie(int vp[52][52])
{
    int i,j;
    for(i=0;i<=nlin;i++)
    {
        for(j=0;j<=ncol;j++)
            cout<<" "<<vp[i][j];
        cout<<endl<<endl;
    }
}
void scrie_2(int vp[52][52])
{
    int i,j;
    char chr=176;
    for(i=0;i<=nlin;i++)
    {
        for(j=0;j<=ncol;j++)
            {
                if(vp[i][j]!=100)
                    cout<<" "<<vp[i][j];
                else
                    cout<<" "<<chr;
            }
        cout<<endl<<endl;
    }
}
int mnswp()
{
    int i,j,x,y,nrbombe,ok=1,k=0;
    bool jTerminat=false;
    system("cls");
    cout<<" Minesweeper"<<endl<<endl;
    do{
        cout<<"Cate linii, coloane si bombe doriti sa aveti?"<<endl;
        cin>>nlin>>ncol>>nbombe;
        if(nlin*ncol<nbombe)
        {
            cout<<" Alegere incorecta!"<<endl;
            system("pause");
            system("cls");
        }
    }while(nlin*ncol<nbombe);

    int s[200],t[200];
    nlin=nlin+1;
    ncol=ncol+1;
    srand(time(0));
    prelucrare(vp);
    for(i=1;i<=nbombe;i++)
    {
        do
        {
            x=rand()%(nlin-1)+1;
            y=rand()%(ncol-1)+1;
        }while(vp[x][y]==1);
        vp[x][y]=1;
    }
    revenire(vp);
    cout<<endl;
    prelucrare(m);
    s[0]=0;
    t[0]=0;
    prelucrare_1(m);
    do
    {
        system("cls");
        scrie_2(m);
        cout<<endl<<endl<<"Punctaj: "<<punctaj<<endl;
        cout<<endl<<"Scrieti numarul liniei si al coloanei:";
        cin>>x>>y;
        ok=1;
        k++;
        s[k]=x;
        t[k]=y;
        for(i=0;i<k;i++)
            if(s[i]==x && t[i]==y)
                ok=0;
        if(ok==1 && x<=nlin-1 && y<=ncol-1)
        {
        if(vp[x][y]==0)
        {
            punctaj++;
            nrbombe=0;
            for(i=x-1;i<=x+1;i++)
                for(j=y-1;j<=y+1;j++)
                    if(vp[i][j]==1)
                        nrbombe++;
            m[x][y]=nrbombe;
        }
        else if(vp[x][y]==1)
        {
            system("cls");
            cout<<endl<<"Ai pierdut"<<endl;
            prelucrare(vp);
            scrie(vp);
            revenire(vp);
            cout<<"Aceasta era pozitia bombelor:"<<endl<<endl;
            cout<<endl;
            jTerminat=true;
        }
        }
        else
            {cout<<"Alegere incorecta.Incearca din nou:"<<endl;
            system("pause>nul");}
        if((nlin-1)*(ncol-1)-nbombe==punctaj)
            cout<<"Ai castigat"<<endl;

    }while((nlin-1)*(ncol-1)-nbombe!=punctaj and jTerminat==false);
    system("pause");
    cout<<endl<<" Ai obtinut "<<punctaj<<" puncte!"<<endl;
    system("pause");
    return punctaj;
}
