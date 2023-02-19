#include <iostream>
#include <cstring>
using namespace std;
enum tip{POP,RAP,ROK};
class Pesna{
private:
    char *ime;
    int vreme;
    tip t;
public:
    Pesna(char *ime="",int vreme=0,tip t=(tip)0)
    {
        this->ime=new char [strlen(ime)+1];
        strcpy(this->ime,ime);

        this->vreme=vreme;
        this->t=t;
    }
    Pesna (const Pesna &p)
    {
        this->ime=new char [strlen(p.ime)+1];
        strcpy(this->ime,p.ime);

        this->vreme=p.vreme;
        this->t=p.t;
    }
    Pesna & operator= (const Pesna &p)
    {
        if(this==&p)return *this;
        delete [] ime;
        this->ime=new char [strlen(p.ime)+1];
        strcpy(this->ime,p.ime);
        this->vreme=p.vreme;
        this->t=p.t;
        return *this;
    }
    void pecati()
    {
        cout<<"\""<<ime<<"\"-"<<vreme<<"min"<<endl;
    }
    ~Pesna()
    {
        delete [] ime;
    }
    friend class CD;
};

class CD{
private:
    Pesna niza[10];
    int br_pesni;
    int maks_vreme;
public:
    CD(int maks_vreme=0)
    {
        this->maks_vreme=maks_vreme;
        this->br_pesni=0;
    }
    void dodadiPesna (Pesna p)
    {
        int r=0;
        for(int i=0;i<br_pesni;i++)
        {
            r+=niza[i].vreme;
        }
        if(br_pesni<10 && r+p.vreme<=maks_vreme)
        {
            niza[br_pesni++]=p;
        }
    }
    Pesna getPesna(int i)
    {
        return niza[i];
    }
    int getBroj()
    {
        return br_pesni;
    }
    void pecatiPesniPoTip(tip t)
    {
        for(int i=0;i<br_pesni;i++)
        {
            if(niza[i].t==t)
            {
                niza[i].pecati();
            }
        }
    }

};

int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;

	int n, minuti, kojtip;
	char ime[50];

	if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
		p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<n; i++)
				(omileno.getPesna(i)).pecati();
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<omileno.getBroj(); i++)
				(omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

return 0;
}
