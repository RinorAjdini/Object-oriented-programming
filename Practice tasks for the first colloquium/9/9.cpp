#include<iostream>
#include<string.h>
using namespace std;

class Zichara{
private:
    char *mesto;
    int cena_dnevna_karta;
public:
    Zichara(char *mesto,int cena_dnevna_karta)
    {
        this->mesto = new char [strlen(mesto)+1];
        strcpy(this->mesto,mesto);
        this->cena_dnevna_karta=cena_dnevna_karta;
    }
    Zichara(const Zichara &z)
    {
        mesto= new char [strlen(z.mesto)+1];
        strcpy(mesto,z.mesto);
        cena_dnevna_karta=z.cena_dnevna_karta;
    }
    Zichara& operator= (const Zichara &z)
    {
        if(this==&z)return *this;
        delete [] mesto;
        mesto= new char [strlen(z.mesto)+1];
        strcpy(mesto,z.mesto);
        cena_dnevna_karta=z.cena_dnevna_karta;
        return *this;
    }
    ~Zichara()
    {
        delete []mesto;
    }
    friend class PlaninarskiDom;
};

class PlaninarskiDom{
private:
    char ime[15];
    int cena_po_sezon[2];
    char klasa;
    bool daliima_zichara;
    Zichara *zichara;
public:
    PlaninarskiDom()
    {
        strcpy(this->ime,"");
        for(int i=0;i<2;i++)
        this->cena_po_sezon[i]=0;
        this->klasa='F';
        this->daliima_zichara=0;
    }
    PlaninarskiDom(char *ime,int *cena_po_sezon,char klasa)
    {
        strcpy(this->ime,ime);
        for(int i=0;i<2;i++)
        this->cena_po_sezon[i]=cena_po_sezon[i];
        this->klasa=klasa;
        this->daliima_zichara=0;
    }
    PlaninarskiDom(const PlaninarskiDom &pd)
    {
        strcpy(this->ime,pd.ime);
        for(int i=0;i<2;i++)
        this->cena_po_sezon[i]=pd.cena_po_sezon[i];
        this->klasa=pd.klasa;
        this->daliima_zichara=pd.daliima_zichara;
        if(daliima_zichara==1)
        this->zichara = pd.zichara;
    }
    PlaninarskiDom& operator= (const PlaninarskiDom &pd)
    {
        if(this==&pd)return *this;
        strcpy(this->ime,pd.ime);
        for(int i=0;i<2;i++)
        this->cena_po_sezon[i]=pd.cena_po_sezon[i];
        this->klasa=pd.klasa;
        this->daliima_zichara=pd.daliima_zichara;
        if(daliima_zichara==1)
        this->zichara = pd.zichara;
        return *this;
    }
    PlaninarskiDom& operator--()
    {
        if(this->klasa=='A')
        this->klasa='B';
        else if(this->klasa=='B')
        this->klasa='C';
        else if(this->klasa=='C')
        this->klasa='D';
        else if(this->klasa=='D')
        this->klasa='E';
        else if(this->klasa=='E')
        this->klasa='F';
        return *this;
    }
    friend ostream & operator<< (ostream &out, PlaninarskiDom &pd)
    {
        out<<pd.ime<<" klasa:"<<pd.klasa;
        if(pd.daliima_zichara==1)
        out<<" so Zichara"<<endl;
        else
        out<<endl;
        return out;
    }
    bool operator<=(char d)
    {
        if(this->klasa>=d)
            return 1;
        return 0;
       // cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so "<<d;

    }
    void presmetajDnevenPrestoj(int den,int mesec,int &cena_za_dneven_prestoj)
    {
        if((den<1 || den>31)||(mesec<1 || mesec>12))
        {
            throw 1;
        }
        else
        {
            int c=0;
            if(mesec>=4 && mesec<=9)
            {
                c+=cena_po_sezon[0];
                if(daliima_zichara==1)
                c+=zichara->cena_dnevna_karta;
            }
            else
            {
                c+=cena_po_sezon[1];
                if(daliima_zichara==1)
                c+=zichara->cena_dnevna_karta;
            }
            cena_za_dneven_prestoj=c;
        }
    }
    void setZichara(Zichara &z)
    {
        zichara=&z;
        daliima_zichara=true;
    }
    ~PlaninarskiDom()
    {
    }

};


int main(){

   PlaninarskiDom p; //креирање на нов објект од класата планинарски дом

   //во следниот дел се вчитуваат информации за планинарскиот дом
   char imePlaninarskiDom[15],mestoZichara[30],klasa;
   int ceni[12];
   int dnevnakartaZichara;
   bool daliZichara;
   cin>>imePlaninarskiDom;
   for (int i=0;i<2;i++) cin>>ceni[i];
   cin>>klasa;
   cin>>daliZichara;

   //во следниот дел се внесуваат информации и за жичарата ако постои
   if (daliZichara) {
      cin>>mestoZichara>>dnevnakartaZichara;
      PlaninarskiDom pom(imePlaninarskiDom,ceni,klasa);
      Zichara r(mestoZichara,dnevnakartaZichara);
      pom.setZichara(r);
      p=pom;
   }
   else{
      PlaninarskiDom *pok=new PlaninarskiDom(imePlaninarskiDom,ceni,klasa);
      p=*pok;
   }

   //се намалува класата на планинарскиот дом за 2
   --p;
   --p;

   int cena;
   int den,mesec;
   cin>>den>>mesec;
   try{
   p.presmetajDnevenPrestoj(den,mesec,cena); //тука се користи функцијата presmetajDnevenPrestoj
   cout<<"Informacii za PlaninarskiDomot:"<<endl;
   cout<<p;
   if (p<='D')
       cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";

   cout<<"Cenata za "<<den<<"."<<mesec<<" e "<<cena; //се печати цената за дадениот ден и месец
   }
   catch (int){
      cout<<"Mesecot ili denot e greshno vnesen!";
   }
}
