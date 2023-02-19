#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class DELO
{
private:
    char ime[50];
    int godina;
    char poteklo[50];
public:
    DELO(const char *ime="",int godina=0,const char *poteklo="")
    {
        strcpy(this->ime,ime);
        this->godina=godina;
        strcpy(this->poteklo,poteklo);
    }
    void setIme(const char *ime)
    {
        strcpy(this->ime,ime);
    }
    void setGodina(int godina)
    {
        this->godina=godina;
    }
    void setPoteklo(const char *poteklo)
    {
        strcpy(this->poteklo,poteklo);
    }
    char *getIme()
    {
        return ime;
    }
    char *getPoteklo()
    {
        return poteklo;
    }
    int getGodina()
    {
        return godina;
    }
    bool operator == (const DELO &d)
    {
        return !(strcmp(ime,d.ime));
    }
};
class Pretstava
{
private:
    DELO d;
    int broj;
    char datum[15];
public:
    Pretstava(DELO d=0,int broj=0,const char *datum="")
    {
        this->d=d;
        this->broj=broj;
        strcpy(this->datum,datum);
    }
    DELO getDelo()
    {
        return d;
    }
    int getBroj()
    {
        return broj;
    }
    virtual int cena()
    {
        if(d.getGodina() > 1900)
        {
            if(strcmp(d.getPoteklo(),"Italija") == 0)
            {
                return 150;
            }
            if(strcmp(d.getPoteklo(),"Rusija") == 0)
            {
                return 200;
            }
            return 130;
        }
        if(d.getGodina()>=1800 && d.getGodina()<=1900)
        {
            if(strcmp(d.getPoteklo(),"Italija") == 0)
            {
                return 175;
            }
            if(strcmp(d.getPoteklo(),"Rusija") == 0)
            {
                return 225;
            }
            return 155;
        }
        else
        {
            if(strcmp(d.getPoteklo(),"Italija") == 0)
            {
                return 200;
            }
            if(strcmp(d.getPoteklo(),"Rusija") == 0)
            {
                return 250;
            }
            return 180;
        }
    }
};
class Opera : public Pretstava
{
public:
    Opera(DELO d=0,int broj=0,const char *datum="") : Pretstava(d,broj,datum)
    {

    }
};
class Balet : public Pretstava
{
private:
    static int dopolnitelnaCena;
public:
    Balet(DELO d=0,int broj=0,const char *datum="") : Pretstava(d,broj,datum)
    {

    }
    static void setCenaBalet(int number)
    {
        dopolnitelnaCena=number;
    }
    int cena()
    {
        return Pretstava::cena()+dopolnitelnaCena;
    }
};
int Balet::dopolnitelnaCena=150;
int prihod(Pretstava **pretstavi,int n)
{
    int total=0;
    for(int i=0;i<n;i++)
    {
        total+=pretstavi[i]->cena() * pretstavi[i]->getBroj();
    }
    return total;
}
int brojPretstaviNaDelo(Pretstava **pretstavi,int n,DELO d)
{
    int total=0;
    for(int i=0;i<n;i++)
    {
        if(pretstavi[i]->getDelo()==d)
        {
            total++;
        }
    }
    return total;
}
//citanje na delo
DELO readDelo(){
    char ime[50];
    int godina;
    char zemja[50];
    cin>>ime>>godina>>zemja;
    return DELO(ime,godina,zemja);
}
//citanje na pretstava
Pretstava* readPretstava(){
    int tip; //0 za Balet , 1 za Opera
    cin>>tip;
    DELO d=readDelo();
    int brojProdadeni;
    char data[15];
    cin>>brojProdadeni>>data;
    if (tip==0)  return new Balet(d,brojProdadeni,data);
    else return new Opera(d,brojProdadeni,data);
}
int main(){
    int test_case;
    cin>>test_case;

    switch(test_case){
    case 1:
    //Testiranje na klasite Opera i Balet
    {
        cout<<"======TEST CASE 1======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->getDelo().getIme()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->getDelo().getIme()<<endl;
    }break;

    case 2:
    //Testiranje na  klasite Opera i Balet so cena
    {
        cout<<"======TEST CASE 2======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->cena()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->cena()<<endl;
    }break;

    case 3:
    //Testiranje na operator ==
    {
        cout<<"======TEST CASE 3======="<<endl;
        DELO f1=readDelo();
        DELO f2=readDelo();
        DELO f3=readDelo();

        if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
        if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;

    }break;

    case 4:
    //testiranje na funkcijata prihod
    {
        cout<<"======TEST CASE 4======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();

        }
        cout<<prihod(pole,n);
    }break;

    case 5:
    //testiranje na prihod so izmena na cena za 3d proekcii
    {
        cout<<"======TEST CASE 5======="<<endl;
        int cenaBalet;
        cin>>cenaBalet;
        Balet::setCenaBalet(cenaBalet);
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        cout<<prihod(pole,n);
        }break;

    case 6:
    //testiranje na brojPretstaviNaDelo
    {
        cout<<"======TEST CASE 6======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }

        DELO f=readDelo();
        cout<<brojPretstaviNaDelo(pole,n,f);
    }break;

    };


return 0;
}
