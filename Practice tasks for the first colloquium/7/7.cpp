#include <iostream>
#include <cstring>
using namespace std;
class Ucesnik
{
private:
    char *ime;
    bool pol;
    int vozrast;
public:
    Ucesnik(char *ime="",bool pol=0,int vozrast=0)
    {
        this->ime = new char [strlen(ime)+1];
        strcpy(this->ime,ime);
        this->pol=pol;
        this->vozrast=vozrast;
    }
    Ucesnik (const Ucesnik &u)
    {
        this->ime = new char [strlen(u.ime)+1];
        strcpy(this->ime,u.ime);
        this->pol=u.pol;
        this->vozrast=u.vozrast;
    }
    Ucesnik& operator=(const Ucesnik &u)
    {
        if(this==&u)return *this;
        delete [] ime;
        this->ime = new char [strlen(u.ime)+1];
        strcpy(this->ime,u.ime);
        this->pol=u.pol;
        this->vozrast=u.vozrast;
        return *this;
    }
    bool operator> (const Ucesnik &u)
    {
        if(this->vozrast>u.vozrast)
        return 1;
        return 0;
    }
    friend ostream & operator<< (ostream &out ,const Ucesnik &u)
    {
        out<<u.ime<<endl;
        if(u.pol==1)
        out<<"mashki"<<endl;
        else
        out<<"zhenski"<<endl;
        out<<u.vozrast<<endl;
        return out;
    }
    int getVozrast()
    {
        return vozrast;
    }
    ~Ucesnik()
    {
        delete []ime;
    }
    friend class Maraton;

};
class Maraton{
private:
    char lokacija[100];
    Ucesnik *niza;
    int br_ucesnici;
public:
    Maraton(char *lokacija="")
    {
        strcpy(this->lokacija,lokacija);
        this->br_ucesnici=0;
        niza = new Ucesnik [0];
    }
    Maraton (const Maraton &m)
    {
        strcpy(this->lokacija,m.lokacija);
        this->br_ucesnici=m.br_ucesnici;
        niza = new Ucesnik [br_ucesnici];
        for(int i=0;i<br_ucesnici;i++)
        {
            niza[i]=m.niza[i];
        }
    }
    Maraton & operator= (const Maraton &m)
    {
        if(this==&m)return *this;
        delete [] niza;
        strcpy(this->lokacija,m.lokacija);
        this->br_ucesnici=m.br_ucesnici;
        niza = new Ucesnik [br_ucesnici];
        for(int i=0;i<br_ucesnici;i++)
        {
            niza[i]=m.niza[i];
        }
        return *this;
    }
    Maraton & operator+= (const Ucesnik &u)
    {
        Ucesnik *tmp = new Ucesnik [br_ucesnici+1];
        for(int i=0;i<br_ucesnici;i++)
        tmp[i]=niza[i];
        tmp[br_ucesnici++]=u;
        delete []niza;
        niza=tmp;
        return *this;
    }
    float prosecnoVozrast()
    {
        float r=0;
        for(int i=0;i<br_ucesnici;i++)
        {
            r+=niza[i].getVozrast();
        }
        return (r*1.0/br_ucesnici);
    }
    void pecatiPomladi(Ucesnik &u)
    {
        for(int i=0;i<br_ucesnici;i++)
        {
            if(niza[i].getVozrast()<u.getVozrast())
            cout<<niza[i];
        }
    }
    ~Maraton()
    {
        delete []niza;
    }
};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
    	u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
	m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
	return 0;
}
