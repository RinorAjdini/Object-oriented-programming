// vashiot kod ovde
#include <iostream>
#include <cstring>
using namespace std;

class Vozac{
protected:
    char ime[100];
    int vozrast;
    int br_trkii;
    bool daliVeteran;
public:
    Vozac(const char *ime="",int vozrast=0,int br_trkii=0,bool daliVeteran=false)
    {
        strcpy(this->ime,ime);
        this->vozrast=vozrast;
        this->br_trkii=br_trkii;
        this->daliVeteran=daliVeteran;
    }
    friend ostream &operator<<(ostream &out,Vozac &v)
    {
        out<<v.ime<<endl<<v.vozrast<<endl<<v.br_trkii<<endl;
        if(v.daliVeteran)
            out<<"VETERAN"<<endl;
        return out;
    };
    bool operator== (Vozac &v)
    {
        if(this->zarabotuvacka()==v.zarabotuvacka())
            return 1;
        return 0;
    }
    virtual double zarabotuvacka() = 0;
    virtual double danok() = 0;
};

class Avtomobilist : public Vozac {
private:
    double cena;
public:
    Avtomobilist(const char *ime="",int vozrast=0,int br_trkii=0,bool daliVeteran=false,double cena=0)
    :Vozac(ime,vozrast,br_trkii,daliVeteran)
    {
        this->cena=cena;
    }
    double zarabotuvacka()
    {
        return this->cena/5.0;
    }
    double danok()
    {
        if(br_trkii>10)
        {
            return 0.15*zarabotuvacka();
        }
        return 0.1*zarabotuvacka();
    }
};
class Motociklist : public Vozac {
private:
    int moknost;
public:
    Motociklist(const char *ime="",int vozrast=0,int br_trkii=0,bool daliVeteran=false,int moknost=0)
    :Vozac(ime,vozrast,br_trkii,daliVeteran)
    {
        this->moknost=moknost;
    }
    double zarabotuvacka()
    {
        return moknost*20;
    }
    double danok()
    {
        if(daliVeteran==true)
            return 0.25*zarabotuvacka();
        return 0.2*zarabotuvacka();
    }
};

int soIstaZarabotuvachka (Vozac **niza,int n,Vozac *posledniot)
{
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(*niza[i]==*posledniot)
            k++;
    }
    return k;
}

int main() {
	int n, x;
	cin >> n >> x;
	Vozac **v = new Vozac*[n];
	char ime[100];
	int vozrast;
	int trki;
	bool vet;
	for(int i = 0; i < n; ++i) {
		cin >> ime >> vozrast >> trki >> vet;
		if(i < x) {
			float cena_avto;
			cin >> cena_avto;
			v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
		} else {
			int mokjnost;
			cin >> mokjnost;
			v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
		}
	}
	cout << "=== DANOK ===" << endl;
	for(int i = 0; i < n; ++i) {
		cout << *v[i];
		cout << v[i]->danok() << endl;
	}
	cin >> ime >> vozrast >> trki >> vet;
	int mokjnost;
	cin >> mokjnost;
	Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
	cout << "=== VOZAC X ===" << endl;
	cout << *vx;
	cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
	cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
	return 0;
}
