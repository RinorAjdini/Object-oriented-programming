#include <iostream>
#include <cstring>
using namespace std;

class Transport{
protected:
    char destinacija[20];
    int osnovna_cena;
    int rastojanie;
public:
    Transport(const char *destinacija="",int osnovna_cena=0,int rastojanie=0)
    {
        strcpy(this->destinacija,destinacija);
        this->osnovna_cena=osnovna_cena;
        this->rastojanie=rastojanie;
    }
    virtual float cenaTransport()= 0;
    bool operator < (Transport &t)
    {
        if(this->rastojanie<t.rastojanie)
            return 1;
        return 0;
    }
    char *getDestinacija()
    {
        return destinacija;
    }
    int getRastojanie()
    {
        return rastojanie;
    }
};

class AvtomobilTransport : public Transport{
protected:
    bool platen_sofer;
public:
    AvtomobilTransport(const char *destinacija="",int osnovna_cena=0,int rastojanie=0,bool platen_sofer=false)
    :Transport(destinacija,osnovna_cena,rastojanie)
    {
        this->platen_sofer=platen_sofer;
    }
    void setPlaten_Sofer(bool t)
    {
        this->platen_sofer=t;
    }
    bool getPlaten_Sofer()
    {
        return platen_sofer;
    }
    float cenaTransport()
    {
        int oc=0;
        if(platen_sofer==true)
            oc=osnovna_cena*1.2;
        else
            oc=osnovna_cena;
            return oc;
    }

};
class KombeTransport : public Transport{
protected:
    int br_lugje;
public:
    KombeTransport(const char *destinacija="",int osnovna_cena=0,int rastojanie=0,int br_lugje=0)
    :Transport(destinacija,osnovna_cena,rastojanie)
    {
        this->br_lugje=br_lugje;
    }
    void setBr_Lugje(int novBroj)
    {
        this->br_lugje=novBroj;
    }
    int getBr_Lugje()
    {
        return this->br_lugje;
    }
    float cenaTransport()
    {
       if(osnovna_cena-200*br_lugje>=0)
        return osnovna_cena-(200*br_lugje);
       return 0;
    }
};

void pecatiPoloshiPonudi (Transport *niza[],int n,Transport &t)
{
    Transport *A[n];
    int br=0;
    for(int i=0;i<n;i++)
    {
        if(niza[i]->cenaTransport()>t.cenaTransport())
            A[br++]=niza[i];
    }
    for(int i=0;i<br;i++)
    {
        for(int j=i+1;j<br;j++)
        {
            if(A[i]->cenaTransport()>A[j]->cenaTransport())
            {
                Transport *tmp = A[i];
                A[i]=A[j];
                A[j]=tmp;
            }
        }
    }
    for(int i=0;i<br;i++)
    {
        cout<<A[i]->getDestinacija()<<" "<<A[i]->getRastojanie()<<" "<<A[i]->cenaTransport()<<endl;
    }
}

int main(){

char destinacija[20];
int tip,cena,rastojanie,lugje;
bool shofer;
int n;
cin>>n;
Transport  **ponudi;
ponudi=new Transport *[n];

for (int i=0;i<n;i++){

    cin>>tip>>destinacija>>cena>>rastojanie;
    if (tip==1) {
        cin>>shofer;
        ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

    }
    else {
        cin>>lugje;
        ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
    }


}

AvtomobilTransport nov("Ohrid",2000,600,false);
pecatiPoloshiPonudi(ponudi,n,nov);

for (int i=0;i<n;i++) delete ponudi[i];
delete [] ponudi;
return 0;
}
