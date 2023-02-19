#include<iostream>
#include<cstring>
using namespace std;
enum Zanr{akcija,komedija,drama};
class Film
{
private:
    char *ime;
    int goleminaNaFilm;
    Zanr z;
public:
    Film()
    {
        this->ime=new char[0];
        strcpy(this->ime,"");
        goleminaNaFilm=0;
        z=(Zanr)0;
    }
    Film(char *ime, int goleminaNaFilm,Zanr z)
    {
        this->ime=new char[0];
        strcpy(this->ime,ime);
        this->goleminaNaFilm=goleminaNaFilm;
        this->z=z;
    }
    Film(const Film &f1)
    {
        this->ime=new char[0];
        strcpy(this->ime,f1.ime);
        this->goleminaNaFilm=f1.goleminaNaFilm;
        this->z=f1.z;
    }
    Film &operator=(const Film &f1)
    {
        if(this!=&f1)
        {
            delete[]ime;
            this->ime=new char[0];
            strcpy(this->ime,f1.ime);
            this->goleminaNaFilm=f1.goleminaNaFilm;
            this->z=f1.z;
        }
        return *this;
    }
    ~Film()
    {
        delete[]ime;
    }
    void pecati()
    {
        cout<<goleminaNaFilm<<"MB-\""<<ime<<"\""<<endl;
    }
    int getGolemina()
    {
        return goleminaNaFilm;
    }
    Zanr getZanr()
    {
        return z;
    }

};
class DVD
{
private:
    Film f[5];
    int broj;
    int golemina;
public:
    DVD(Film *f,int golemina,int broj)
    {
        this->broj=broj;
        this->golemina=golemina;
        for(int i=0;i<5;i++)
        {
            this->f[i]=f[i];
        }
    }
    DVD (const DVD &d1)
    {
        broj=d1.broj;
        golemina=d1.golemina;
        for(int i=0;i<5;i++)
        {
            f[i]=d1.f[i];
        }
    }
    DVD(int golemina)
    {
        this->golemina=golemina;
        broj=0;
    }
    void dodadiFilm(Film f)
    {
        if(broj<5)
        {
           if(golemina>=f.getGolemina())
           {
               this->f[broj]=f;
               broj++;
               golemina-=f.getGolemina();
           }
           else
           {
               return;
           }
        }
    }
    Film getFilm(int i)
    {
        return f[i];
    }
    void pecatiFilmoviDrugZanr(Zanr z)
    {
        for(int i=0;i<broj;i++)
        {
            if(z!=f[i].getZanr())
            {
                f[i].pecati();
            }
        }
    }
    void procentNaMemorijaOdZanr(Zanr z)
    {
        double procent;
        int zbir=0;
        int golemina=0;
        for(int i=0;i<broj;i++)
        {
            golemina+=f[i].getGolemina();
            if(z == f[i].getZanr())
            {
                zbir+=f[i].getGolemina();
            }
        }
        procent=(zbir*1.0)/(golemina*1.0);
        procent=procent*100;
        cout<<procent;
    }
    int getBroj()
    {
        return broj;
    }
};
int main() {
    int testCase;
    cin>>testCase;
    int n,memorija,kojzanr;
    char ime[50];
    if(testCase == 1)
    {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin>>ime;
        cin>>memorija;
        cin>>kojzanr;
        Film f(ime,memorija,(Zanr)kojzanr);
        f.pecati();
    }
    else if(testCase == 2)
    {
         cout << "===== Testiranje na klasata DVD ======" << endl;
         DVD omileno(50);
         cin>>n;
         for(int i=0;i<n;i++)
         {
             cin>>ime>>memorija>>kojzanr;
             Film f(ime,memorija,(Zanr)kojzanr);
             omileno.dodadiFilm(f);
         }
         for(int i=0;i<n;i++)
         {
             (omileno.getFilm(i)).pecati();
         }
    }
    else if(testCase == 3)
    {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin>>n;
        for(int i=0;i<n;i++)
         {
             cin>>ime>>memorija>>kojzanr;
             Film f(ime,memorija,(Zanr)kojzanr);
             omileno.dodadiFilm(f);
         }
         Film f(ime,memorija,(Zanr)kojzanr);
         omileno.dodadiFilm(f);
         for(int i=0;i<omileno.getBroj();i++)
         {
             (omileno.getFilm(i)).pecati();
         }
    }
    else if(testCase == 4)
    {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ime>>memorija>>kojzanr;
            Film f(ime,memorija,(Zanr)kojzanr);
            omileno.dodadiFilm(f);
        }
        cin>>kojzanr;
        omileno.pecatiFilmoviDrugZanr((Zanr)kojzanr);
    }
    else if(testCase == 5)
    {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ime>>memorija>>kojzanr;
            Film f(ime,memorija,(Zanr)kojzanr);
            omileno.dodadiFilm(f);
        }
        cin>>kojzanr;
        omileno.pecatiFilmoviDrugZanr((Zanr)kojzanr);
    }
    else if(testCase == 6)
    {
        cout<<"===== Testiranje na metodot procentNaMemorijaOdZanr() od klasata DVD =====" <<endl;
        DVD omileno(40);
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ime>>memorija>>kojzanr;
            Film f(ime,memorija,(Zanr)kojzanr);
            omileno.dodadiFilm(f);
        }
        cin>>kojzanr;
        cout<<"Procent na filmovi od dadeniot zanr iznesuva: ";
        omileno.procentNaMemorijaOdZanr((Zanr) kojzanr);
        cout<<"%"<<endl;
    }
}
