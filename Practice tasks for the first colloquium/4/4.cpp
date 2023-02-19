#include<iostream>
#include<cstring>
using namespace std;

class Patnik{
    private:
        char ime[100];
        int klasa;
        bool velosiped;
    public:
        Patnik(){}
        Patnik(char ime[], int klasa, bool velosiped){
            strcpy(this->ime,ime);
            this->klasa=klasa;
            this->velosiped=velosiped;
        }
        friend ostream &operator<<(ostream &os, Patnik &pk){
            os<<pk.ime<<endl<<pk.klasa<<endl<<pk.velosiped<<endl;
        }
        Patnik &operator=(Patnik &pk){
            if(this==&pk) return *this;
            strcpy(this->ime,pk.ime);
            this->klasa=pk.klasa;
            this->velosiped=pk.velosiped;
            return *this;
        }
        bool isVelo(){return velosiped;}
        int getKlasa(){return klasa;}

};

class Voz{
    private:
        char destinacija[100];
        Patnik *patnici;
        int broj;
        int velosipedi;
    public:
        Voz(char destinacija[],int maks){
            strcpy(this->destinacija,destinacija);
            this->velosipedi=maks;
            this->broj = 0;
        }
        Voz &operator+=(Patnik &pk){
            // int velos = 0;
            Patnik *temp = new Patnik[broj+1];
            for(int i=0;i<broj;i++){
                temp[i] = patnici[i];
                // if(patnici[i].isVelo()) velos++;
            }
            if(velosipedi==0&&pk.isVelo()){
                delete [] temp;
                return *this;
            }
            temp[broj] = pk;
            if(broj) delete [] patnici;
            patnici = temp;
            broj++;
            return *this;
        }
        friend ostream& operator<<(ostream &os, Voz &voz){
            os<<voz.destinacija<<endl;
            for(int i=0;i<voz.broj;i++){
                os<<voz.patnici[i]<<endl;
            }
            return os;
        }
        void patniciNemaMesto(){
            int velos = 0,odbieni1=0,odbieni2=0;
            for(int i=0;i<broj;i++){
                if(patnici[i].getKlasa()==1 && patnici[i].isVelo()){
                    velos++;
                    if(velos>velosipedi) odbieni1++;
                }
            }
            for(int i=0;i<broj;i++){
                if(patnici[i].getKlasa()==2 && patnici[i].isVelo()){
                    velos++;
                    if(velos>velosipedi) odbieni2++;
                }
            }
            cout<<"Brojot na patnici od 1-va klasa koi ostanale bez mesto e: "<<odbieni1<<endl;
            cout<<"Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: "<<odbieni2<<endl;

        };

};


int main()
{
	Patnik p;
	char ime[100], destinacija[100];
	int n;
	bool velosiped;
	int klasa;
	int maxv;
	cin >> destinacija >> maxv;
	cin >> n;
	Voz v(destinacija, maxv);
	//cout<<v<<endl;
	for (int i = 0; i < n; i++){
		cin >> ime >> klasa >> velosiped;
		Patnik p(ime, klasa, velosiped);
		//cout<<p<<endl;
		v += p;
	}
	cout << v;
	v.patniciNemaMesto();

	return 0;
}
