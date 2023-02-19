#include <iostream>
#include <cstring>
using namespace std;
class Gitara{
private:
    char seriskibroj[25];
    float cena;
    int godina;
    char tip[40];
public:
    Gitara(char *tip="",char *seriskibroj="",int godina=0,float cena=0)
    {
        strcpy(this->tip,tip);
        strcpy(this->seriskibroj,seriskibroj);
        this->godina=godina;
        this->cena=cena;
    }
    bool daliIsti (Gitara &g1)
    {
        if(strcmp(this->seriskibroj,g1.seriskibroj)==0)
        return 1;
        return 0;
    }
    char *getTip()
    {
        return tip;
    }
    int getGodina()
    {
        return godina;
    }
    char * getSeriski()
    {
        return seriskibroj;
    }
    float getNabavna()
    {
        return cena;
    }
    void pecati()
    {
        cout<<seriskibroj<<" "<<tip<<" "<<cena<<endl;
    }
    friend class Magacin;
};

class Magacin{
private:
    char ime[30];
    char lokacija[60];
    Gitara *niza;
    int br_gitara;
    int godina_otvaranje;
public:
    Magacin(char *ime="",char *lokacija="",int godina_otvaranje=0)
    {
        strcpy(this->ime,ime);
        strcpy(this->lokacija,lokacija);
        this->godina_otvaranje=godina_otvaranje;
        this->br_gitara=0;
        niza = new Gitara [br_gitara];
        for(int i=0;i<br_gitara;i++)
        niza[i]=0;
    }
    Magacin (const Magacin &mg)
    {
        strcpy(this->ime,mg.ime);
        strcpy(this->lokacija,mg.lokacija);
        this->godina_otvaranje=mg.godina_otvaranje;
        this->br_gitara=mg.br_gitara;
        niza = new Gitara [mg.br_gitara];
        for(int i=0;i<br_gitara;i++)
        niza[i]=mg.niza[i];
    }
    Magacin & operator= (const Magacin &mg)
    {
        if(this==&mg)return *this;
        strcpy(this->ime,mg.ime);
        strcpy(this->lokacija,mg.lokacija);
        this->godina_otvaranje=mg.godina_otvaranje;
        this->br_gitara=mg.br_gitara;
        niza = new Gitara [mg.br_gitara];
        for(int i=0;i<br_gitara;i++)
        niza[i]=mg.niza[i];
        return *this;
    }
    void dodadi(Gitara d)
    {
        Gitara *tmp = new Gitara [br_gitara+1];
        for(int i=0;i<br_gitara;i++)
        tmp[i]=niza[i];
        tmp[br_gitara++]=d;
        delete []niza;
        niza=tmp;
    }
    void prodadi(Gitara p)
    {
        int j=0;
        for(int i=0;i<br_gitara;i++)
        {
            if(niza[i].daliIsti(p))
            {
                continue;
            }
            else
            {
                niza[j++]=niza[i];
            }
        }
        this->br_gitara=j;
    }
    void pecati(bool daliNovi)
    {
        cout<<ime<<" "<<lokacija<<endl;
        if(daliNovi==1)
        {
        for(int i=0;i<br_gitara;i++)
        {
        if(niza[i].godina>godina_otvaranje)
            niza[i].pecati();
        }
        }
        else
        {
            for(int i=0;i<br_gitara;i++)
                niza[i].pecati();
        }
    }
    double vrednost()
    {
        double r=0;
        for(int i=0;i<br_gitara;i++)
        {
            r+=niza[i].getNabavna();
        }
        return r;
    }
    ~Magacin(){
        delete []niza;
    }

};

int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;

	int n, godina;
	float cena;
	char seriski[50],tip[50];

	if(testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin>>tip;
        cin>>seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip,seriski, godina,cena);
		cout<<g.getTip()<<endl;
		cout<<g.getSeriski()<<endl;
		cout<<g.getGodina()<<endl;
		cout<<g.getNabavna()<<endl;
    } else if(testCase == 2){
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
		Magacin kb("Magacin1","Lokacija1");
        kb.pecati(false);
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2005);
		cin>>n;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;
                Gitara g(tip,seriski, godina,cena);
                cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
        kb.pecati(true);
    }

    else if(testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2012);
            cin>>n;
            Gitara brisi;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;

                Gitara g(tip,seriski, godina,cena);
                if(i==2)
                    brisi=g;
                cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    }
    else if(testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2011);
            cin>>n;
            Gitara brisi;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;

                Gitara g(tip,seriski, godina,cena);
                if(i==2)
                    brisi=g;
                cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
        kb.pecati(true);
        kb.prodadi(brisi);
        cout<<"Po brisenje:"<<endl;
        Magacin kb3;
        kb3=kb;
        kb3.pecati(true);
    }
   else if(testCase ==6)
        {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1","Lokacija1",2011);
            cin>>n;
            Gitara brisi;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;

                Gitara g(tip,seriski, godina,cena);
                if(i==2)
                    brisi=g;
				kb.dodadi(g);
			}
        cout<<kb.vrednost()<<endl;
        kb.prodadi(brisi);
        cout<<"Po brisenje:"<<endl;
        cout<<kb.vrednost();
        Magacin kb3;
        kb3=kb;
        }
    return 0;
}
