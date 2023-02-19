#include<iostream>
#include<cstring>
using namespace std;
class Ekipa
{
protected:
    char ime[15];
    int brojNaPorazi;
    int brojNaPobedi;
public:
    Ekipa(const char* ime="",int brojNaPobedi=0,int brojNaPorazi=0)
    {
        strcpy(this->ime,ime);
        this->brojNaPobedi=brojNaPobedi;
        this->brojNaPorazi=brojNaPorazi;
    }
    void pecati()
    {
        cout<<"Ime: "<<ime<<" Pobedi: "<<brojNaPobedi<<" Porazi: "<<brojNaPorazi;
    }
};
class FudbalskaEkipa : public Ekipa
{
private:
    int crven;
    int zut;
    int nereseni;
public:
    FudbalskaEkipa(char *ime, int brojNaPobedi, int brojNaPorazi,int crven, int zut, int nereseni) : Ekipa(ime,brojNaPobedi,brojNaPorazi)
    {
        this->crven=crven;
        this->zut=zut;
        this->nereseni=nereseni;
    }
    int vkupnoPoeni()
    {
        return((brojNaPobedi*3) + nereseni);
    }
    void pecati()
    {
        Ekipa::pecati();
        cout<<" Nereseni: "<<nereseni<<" Poeni: "<<vkupnoPoeni()<<endl;
    }
};
int main ()
{
    char ime[15];
    int pob,por,ck,zk,ner;
    cin>>ime>>pob>>por>>ck>>zk>>ner;
    FudbalskaEkipa f1(ime,pob,por,ck,zk,ner);
    f1.pecati();
    return 0;
}
