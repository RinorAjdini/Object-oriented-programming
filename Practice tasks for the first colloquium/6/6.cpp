#include<iostream>
#include <cstring>
using namespace std;

typedef struct Voz{
 char relacija[50];
 float kilometri;
 int br_patnici;
}voz;

typedef struct ZeleznickaStanica{
    char grad[20];
    voz niza[30];
    int br_vozovi;
}ZeleznickaStanica;

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad)
{
    int indexi=0;
     int indexj=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(zs[i].grad,grad)==0)
        {
            float k = zs[i].niza[0].kilometri;
            for(int j=0;j<zs[i].br_vozovi;j++)
            {
                if(zs[i].niza[j].kilometri<=k)
                {
                    k=zs[i].niza[j].kilometri;
                    indexj=j;
                    indexi=i;
                }

            }
            cout<<"Najkratka relacija: "<<zs[indexi].niza[indexj].relacija<<" ("<<zs[indexi].niza[indexj].kilometri<<" km)";
        }
    }
}
int main(){

    int n;
	cin>>n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){
        //se citaat infomracii za n zelezlnichkite stanici i se zacuvuvaat vo poleto zStanica
        cin>>zStanica[i].grad;
        cin>>zStanica[i].br_vozovi;
        for(int j=0;j<zStanica[i].br_vozovi;j++)
        {
            cin>>zStanica[i].niza[j].relacija;
            cin>>zStanica[i].niza[j].kilometri;
            cin>>zStanica[i].niza[j].br_patnici;
        }
    }

    char grad[25];
    cin>>grad;

	najkratkaRelacija(zStanica,n,grad);
	return 0;
}
