#include<iostream>
#include<cstring>
using namespace std;
class Avtomobil
{
private:
    char boja[20];
    char brend[20];
    char model[20];
public:
    Avtomobil()
    {
        strcpy(boja,"");
        strcpy(brend,"");
        strcpy(model,"");
    }
    Avtomobil(const char *boja,const  char *brend, const char *model)
    {
        strcpy(this->boja,boja);
        strcpy(this->brend,brend);
        strcpy(this->model,model);
    }
    Avtomobil(const Avtomobil &avto)
    {
        strcpy(boja,avto.boja);
        strcpy(brend,avto.brend);
        strcpy(model,avto.model);
    }
    Avtomobil &operator=(const Avtomobil &avto)
    {
        if(this!= &avto)
        {
            strcpy(boja,avto.boja);
            strcpy(brend,avto.brend);
            strcpy(model,avto.model);
        }
        return *this;
    }
    friend class ParkingPlac;
};
class ParkingPlac
{
private:
    char adresa[20];
    char *identifikaciskiBroj;
    int cena;
    int zarabotka;
    Avtomobil *avtomobili;
    int brojNaParkiraniAvtomobili;
public:
    ParkingPlac()
    {
        strcpy(adresa,"");
        identifikaciskiBroj=new char[0];
        cena=0;
        zarabotka=0;
        avtomobili=new Avtomobil[0];
        brojNaParkiraniAvtomobili=0;
    }
    ParkingPlac(const char *adresa,const char *identifikaciskiBroj,int cena)
    {
        zarabotka=0;
        this->cena=cena;
        strcpy(this->adresa,adresa);
        this->identifikaciskiBroj=new char[strlen(identifikaciskiBroj)+1];
        strcpy(this->identifikaciskiBroj,identifikaciskiBroj);
        brojNaParkiraniAvtomobili=0;
        avtomobili=new Avtomobil[0];
    }
    ParkingPlac(const ParkingPlac &plac1)
    {
        strcpy(adresa,plac1.adresa);
        zarabotka=plac1.zarabotka;
        cena=plac1.cena;
        brojNaParkiraniAvtomobili=plac1.brojNaParkiraniAvtomobili;

        identifikaciskiBroj=new char[strlen(plac1.identifikaciskiBroj)+1];
        strcpy(identifikaciskiBroj,plac1.identifikaciskiBroj);

        avtomobili=new Avtomobil[plac1.brojNaParkiraniAvtomobili];
        for(int i=0;i<plac1.brojNaParkiraniAvtomobili;i++)
        {
            this->avtomobili[i]=plac1.avtomobili[i];
        }
    }
    ParkingPlac &operator =(const ParkingPlac &plac1)
    {
        if(this!=&plac1)
        {
            delete[]identifikaciskiBroj;
            delete[]avtomobili;
            zarabotka=plac1.zarabotka;
            cena=plac1.cena;
            brojNaParkiraniAvtomobili=plac1.brojNaParkiraniAvtomobili;
            strcpy(adresa,plac1.adresa);

            identifikaciskiBroj=new char[strlen(plac1.identifikaciskiBroj)+1];
            strcpy(identifikaciskiBroj,plac1.identifikaciskiBroj);

            avtomobili=new Avtomobil[plac1.brojNaParkiraniAvtomobili];
            for(int i=0;i<plac1.brojNaParkiraniAvtomobili;i++)
            {
                this->avtomobili[i]=plac1.avtomobili[i];
            }
        }
        return *this;
    }
    ~ParkingPlac()
    {
        delete[]avtomobili;
        delete[]identifikaciskiBroj;
    }
    char *getId()
    {
        return identifikaciskiBroj;
    }
    void pecati()
    {
        cout<<identifikaciskiBroj<<" "<<adresa;
        if(zarabotka)
        {
            cout<<" - "<<zarabotka<<" denari"<<endl;
        }
        else
            cout<<endl;
    }
    void platiCasovi(int casovi)
    {
        zarabotka+=cena*casovi;
    }
    bool daliIstaAdresa(ParkingPlac p)
    {
        if(strcmp(this->adresa,p.adresa) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void parkirajVozilo(Avtomobil novoVozilo)
    {
        Avtomobil *temp=new Avtomobil[brojNaParkiraniAvtomobili+1];
        for(int i=0;i<brojNaParkiraniAvtomobili;i++)
        {
            temp[i]=avtomobili[i];
        }
        temp[brojNaParkiraniAvtomobili++]=novoVozilo;
        delete[]avtomobili;
        avtomobili=temp;
    }
    void pecatiParkiraniVozila()
    {
        cout<<"Vo parkingot se parkirani slednite vozila: "<<endl;
        for(int i=0;i<brojNaParkiraniAvtomobili;i++)
        {
            cout<<i+1<<"."<<avtomobili[i].boja<<" "<<avtomobili[i].brend<<" "<<avtomobili[i].model<<endl;
        }
    }
};
int main ()
{
    ParkingPlac p[100];
    int n,m;
    char adresa[50],id[50];
    int brojcasovi,cenacas;
    cin>>n;
    if(n > 0){


        for (int i=0;i<n;i++){
            cin.get();
            cin.getline(adresa,50);
            cin>>id>>cenacas;

            ParkingPlac edna(adresa,id,cenacas);

            p[i]=edna;
        }

        //plakjanje
        cin>>m;
        for (int i=0;i<m;i++){

            cin>>id>>brojcasovi;

            int findId=false;
            for (int j=0;j<m;j++){
                if (strcmp(p[j].getId(),id)==0){
                    p[j].platiCasovi(brojcasovi);
                    findId=true;
                }
            }
            if (!findId)
            cout<<"Ne e platen parking. Greshen ID."<<endl;
        }

        cout<<"========="<<endl;
        ParkingPlac pCentar("Cvetan Dimov","C10",80);
        for (int i=0;i<n;i++)
            if (p[i].daliIstaAdresa(pCentar))
                p[i].pecati();
    } else {

        ParkingPlac najdobarPlac("Mars", "1337", 1);
        int brVozila;
        cin >> brVozila;
        for(int i = 0; i < brVozila; ++i){

            char boja[20];
            char brend[20];
            char model[20];

            cin >> boja >> brend >> model;
            Avtomobil novAvtomobil(boja, brend, model);
            najdobarPlac.parkirajVozilo(novAvtomobil);
        }
        if(brVozila != 0)
        najdobarPlac.pecatiParkiraniVozila();

    }
}
