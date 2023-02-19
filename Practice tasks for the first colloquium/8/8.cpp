#include <iostream>
#include <cstring>
using namespace std;
class Pica{
private:
    char ime[15];
    int cena;
    char *sostojki;
    int popust;
public:
    Pica(char *ime="",int cena=0,char *sostojki="",int popust=0)
    {
        strcpy(this->ime,ime);
        this->cena=cena;
        if(strlen(sostojki)!=0)
        this->sostojki = new char [strlen(sostojki)+1];
        else
        this->sostojki = new char [0];
        strcpy(this->sostojki,sostojki);
        this->popust= popust;
    }
    Pica (const Pica &p)
    {
        strcpy(this->ime,p.ime);
        this->cena=p.cena;
        this->sostojki = new char [strlen(p.sostojki)+1];
        strcpy(this->sostojki,p.sostojki);
        this->popust= p.popust;
    }
    Pica & operator=(const Pica & p)
    {
        if(this==&p)return *this;
        delete []sostojki;
        strcpy(this->ime,p.ime);
        this->cena=p.cena;
        this->sostojki = new char [strlen(p.sostojki)+1];
        strcpy(this->sostojki,p.sostojki);
        this->popust= p.popust;
        return *this;
    }
    void pecati()
    {
        cout<<ime<<" - "<<sostojki<<", "<<cena<<endl;
    }
    bool istiSe(Pica p)
    {
        if(strcmp(this->sostojki,p.sostojki)==0)
        return 1;
        return 0;
    }
    ~Pica()
    {
        delete []sostojki;
    }
    friend class Picerija;
};

class Picerija{
private:
    char ime[15];
    Pica *niza;
    int br_pici;
public:
    Picerija(char *ime)
    {
        strcpy(this->ime,ime);
        this->niza = new Pica [0];
        this->br_pici = 0;
    }
    Picerija(const Picerija &p)
    {
        this->br_pici=p.br_pici;
        strcpy(this->ime,p.ime);
        this->niza = new Pica [p.br_pici];
        for(int i=0;i<br_pici;i++)
        niza[i]=p.niza[i];
    }
    Picerija & operator= (const Picerija & p)
    {
        if(this==&p)return *this;
        delete [] niza;
        this->br_pici=p.br_pici;
        strcpy(this->ime,p.ime);
        this->niza = new Pica [br_pici];
        for(int i=0;i<br_pici;i++)
        niza[i]=p.niza[i];
        return *this;
    }
    void dodadi(Pica P)
    {
        int flag=1;
        for(int i=0;i<br_pici;i++)
        {
            if(niza[i].istiSe(P))
            {
            flag=0;
            break;
            }
        }
        if(flag)
        {
            Pica *tmp = new Pica [br_pici+1];
            for(int i=0;i<br_pici;i++)
            tmp[i]=niza[i];
            tmp[br_pici++]=P;
            delete [] niza;
            niza=tmp;
        }
    }
    Picerija & operator+=(Pica &p)
    {
        int flag=1;
        for(int i=0;i<br_pici;i++)
        {
            if(niza[i].istiSe(p))
            {
            flag=0;
            break;
            }
        }
        if(flag)
        {
        Pica *tmp = new Pica [br_pici+1];
        for(int i=0;i<br_pici;i++)
        tmp[i]=niza[i];
        tmp[br_pici++]=p;
        delete []niza;
        niza=tmp;
        return *this;
        }
    }
    void piciNaPromocija()
    {
        for(int i=0;i<br_pici;i++)
        {
            if(niza[i].popust!=0)
            {
            cout<<niza[i].ime<<" - "<<niza[i].sostojki<<", "<<niza[i].cena<<" ";
            double k=niza[i].popust/100.0;
            k=1-k;
            //cout<<niza[i].cena*(1-(niza[i].popust/100))<<endl;
            k*=niza[i].cena;
            cout<<k<<endl;
            }
        }
    }
    void setIme(char *ime)
    {
        strcpy(this->ime,ime);
    }
    char* getIme()
    {
        return ime;
    }
    ~Picerija()
    {
        delete []niza;
    }
};
int main() {

	int n;
	char ime[15];
	cin >> ime;
	cin >> n;

	Picerija p1(ime);
	for (int i = 0; i < n; i++){
		char imp[100];
		cin.get();
		cin.getline(imp, 100);
		int cena;
		cin >> cena;
		char sostojki[100];
		cin.get();
		cin.getline(sostojki, 100);
		int popust;
		cin >> popust;
		Pica p(imp, cena, sostojki, popust);
		p1+=p;
	}

	Picerija p2 = p1;
	cin >> ime;
	p2.setIme(ime);
	char imp[100];
	cin.get();
	cin.getline(imp, 100);
	int cena;
	cin >> cena;
	char sostojki[100];
	cin.get();
	cin.getline(sostojki, 100);
	int popust;
	cin >> popust;
	Pica p(imp, cena, sostojki, popust);
	p2+=p;

	cout << p1.getIme() << endl;
	cout << "Pici na promocija:" << endl;
	p1.piciNaPromocija();

	cout << p2.getIme() << endl;
	cout << "Pici na promocija:" << endl;
	p2.piciNaPromocija();

	return 0;
}
