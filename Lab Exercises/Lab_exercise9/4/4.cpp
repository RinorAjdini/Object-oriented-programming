#include<iostream>
#include<cstring>

using namespace std;

class InvalidDateException
{
private:
    int den,mesec,godina;
public:
    InvalidDateException(int den,int mesec,int godina)
    {
        this->den=den;
        this->mesec=mesec;
        this->godina=godina;
    }
    void message()
    {
        cout<<"Invalid Date "<<den<<"/"<<mesec<<"/"<<godina<<endl;
    }

};

class NotSupportedCurrencyException
{
private:
    char valuta[3];
public:
    NotSupportedCurrencyException(const char *valuta)
    {
        strcpy(this->valuta,valuta);
    }
    void message()
    {
        cout<<valuta<<" is not a supported currency"<<endl;
    }
};

class Transakcija{
protected:
    int den;
    int mesec;
    int godina;
    double iznos;
    static double EUR;
    static double USD;
public:
    Transakcija(int den=0,int mesec=0,int godina=0,double iznos=0)
    {
        if(den<1 || den>31)
            throw InvalidDateException(den,mesec,godina);
        if(mesec<1 || mesec>12)
            throw InvalidDateException(den,mesec,godina);
        this->den=den;
        this->mesec=mesec;
        this->godina=godina;
        this->iznos=iznos;
    }
    static double getEUR()
    {
        return EUR;
    }
    static double getUSD()
    {
        return USD;
    }
    static void setEUR(double newEUR)
    {
        EUR=newEUR;
    }
    static void setUSD(double newUSD)
    {
        USD=newUSD;
    }
    virtual double voDenari() = 0;
    virtual double voEvra() = 0;
    virtual double voDolari() = 0;
    virtual void pecati() =0;
};
class DenarskaTransakcija : public Transakcija{
public:
    DenarskaTransakcija(int den=0,int mesec=0,int godina=0,double iznos=0)
    :Transakcija(den,mesec,godina,iznos)
    {}
    double voDenari()
    {
        return iznos;
    }
    double voEvra()
    {
        return iznos*1.0/Transakcija::EUR;
    }
    double voDolari()
    {
        return iznos*1.0/Transakcija::USD;
    }
    void pecati()
    {
        cout<<den<<"/"<<mesec<<"/"<<godina<<" "<<iznos<<" MKD"<<endl;
    }
};
class DeviznaTransakcija : public Transakcija{
private:
    char valuta[3];
public:
    DeviznaTransakcija(int den=0,int mesec=0,int godina=0,double iznos=0,const char *valuta="")
    :Transakcija(den,mesec,godina,iznos)
    {
        if(strcmp(valuta,"USD") && strcmp(valuta,"EUR"))
            throw NotSupportedCurrencyException(valuta);
        strcpy(this->valuta,valuta);
    }
    double voDenari()
    {
        if(!strcmp(valuta,"USD"))
        {
            return iznos*Transakcija::USD;
        }
        return iznos*Transakcija::EUR;
    }
    double voEvra()
    {
        double suma=0;
        if(!strcmp(valuta,"USD"))
        {
            suma+=iznos*Transakcija::USD/Transakcija::EUR;
            return suma;
        }
        return iznos;
    }
    double voDolari()
    {
        double suma=0;
        if(!strcmp(valuta,"EUR"))
        {
            suma+=iznos*Transakcija::EUR/Transakcija::USD;
            return suma;
        }
        return iznos;
    }
    void pecati()
    {
        cout<<den<<"/"<<mesec<<"/"<<godina<<" "<<iznos<<" "<<valuta<<endl;
    }

};
double Transakcija::EUR=61;
double Transakcija::USD=50;

class Smetka{
private:
    Transakcija **niza;
    int br_elementi;
    char br_smetka[15];
    double pocetnoSaldo;
public:
    Smetka(const char *br_smetka="",double pocetnoSaldo=0)
    {
        strcpy(this->br_smetka,br_smetka);
        this->pocetnoSaldo=pocetnoSaldo;
        this->br_elementi=0;
        niza = new Transakcija* [br_elementi];
    }
    Smetka (const Smetka &s)
    {
         strcpy(this->br_smetka,s.br_smetka);
        this->pocetnoSaldo=s.pocetnoSaldo;
        this->br_elementi=s.br_elementi;
        niza = new Transakcija* [s.br_elementi];
    }
    Smetka&operator+=(Transakcija *tr)
    {
        Transakcija **tmp = new Transakcija*[br_elementi+1];
        for(int i=0;i<br_elementi;i++)
        {
            tmp[i]=niza[i];
        }
        tmp[br_elementi++]=tr;
        delete []niza;
        niza=tmp;
        return *this;
    }
    double vkupnoSaldo()
    {
        double saldo=pocetnoSaldo;
        for(int i=0;i<br_elementi;i++)
            saldo+=niza[i]->voDenari();
        return saldo;
    }
    void izvestajVoDenari()
    {
        cout<<"Korisnikot so smetka: "<<br_smetka<<" ima momentalno saldo od "<<vkupnoSaldo()<<" MKD"<<endl;
    }
    void izvestajVoEvra()
    {
        double vkupnoEvro=vkupnoSaldo()/Transakcija::getEUR();
        cout<<"Korisnikot so smetka: "<<br_smetka<<" ima momentalno saldo od "<<vkupnoEvro<<" EUR"<<endl;
    }
    void izvestajVoDolari()
    {
        double vkupnoDolari=vkupnoSaldo()/Transakcija::getUSD();
        cout<<"Korisnikot so smetka: "<<br_smetka<<" ima momentalno saldo od "<<vkupnoDolari<<" USD"<<endl;
    }
    void pecatiTransakcii()
    {
        for(int i=0;i<br_elementi;i++)
        {
            niza[i]->pecati();
        }
    }
    ~Smetka()
    {
        delete []niza;
    }
};

int main () {

	Smetka s ("300047024112789",1500);

	int n, den, mesec, godina, tip;
	double iznos;
	char valuta [3];

	cin>>n;
    cout<<"===VNESUVANJE NA TRANSAKCIITE I SPRAVUVANJE SO ISKLUCOCI==="<<endl;
	for (int i=0;i<n;i++){
		cin>>tip>>den>>mesec>>godina>>iznos;
		if (tip==2){
			cin>>valuta;
			try{
			Transakcija * t = new DeviznaTransakcija(den,mesec,godina,iznos,valuta);
			s+=t;
            //delete t;
			}
			catch(InvalidDateException &ide)
			{
			    ide.message();
			}
			catch(NotSupportedCurrencyException &nsc)
			{
			    nsc.message();
			}
		}
		else {
                try{
			Transakcija * t = new DenarskaTransakcija(den,mesec,godina,iznos);
			s+=t;
            //delete t;
                }
                catch(InvalidDateException &ide)
                {
                    ide.message();
                }
                catch(NotSupportedCurrencyException &nsc)
			{
			    nsc.message();
			}
		}

	}
    cout<<"===PECHATENJE NA SITE TRANSAKCII==="<<endl;
    s.pecatiTransakcii();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
    s.izvestajVoDenari();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
    s.izvestajVoEvra();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
    s.izvestajVoDolari();

    cout<<"\n===PROMENA NA KURSOT NA EVROTO I DOLAROT===\n"<<endl;


    double newEUR, newUSD;
    cin>>newEUR>>newUSD;
    Transakcija::setEUR(newEUR);
    Transakcija::setUSD(newUSD);
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
    s.izvestajVoDenari();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
    s.izvestajVoEvra();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
    s.izvestajVoDolari();



	return 0;
}
