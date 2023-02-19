#include <iostream>
#include <cstring>

using namespace std;

class Rabotnik{
    private:
        char ime[50];
        char prezime[50];
        int plata;
    public:
        Rabotnik(){
            //default
        }
        Rabotnik(char *ime, char *prezime, int plata){
            strcpy(this->ime,ime);
            strcpy(this->prezime,prezime);
            this->plata=plata;
        }
        int getPlata(){
            return this->plata;
        }
        void pecati(){
            cout<<this->ime<<" "<<this->prezime<<" "<<this->plata<<endl;
        }
};

class Fabrika{
    private:
        Rabotnik rabotnik[100];
        int brojVraboteni;
    public:
        Fabrika(){
            //default
        }
        Fabrika(Rabotnik rabotnik[100], int brojVraboteni){
            for(int i=0;i<brojVraboteni;i++){
                this->rabotnik[i]=rabotnik[i];
            }
            this->brojVraboteni=brojVraboteni;
        }
        void pecatiVraboteni(){
            for(int i=0;i<this->brojVraboteni;i++){
                rabotnik[i].pecati();
            }
        }
        void pecatiSoPlata(int plata){
            for(int i=0;i<this->brojVraboteni;i++){
                if(rabotnik[i].getPlata()>plata) rabotnik[i].pecati();
            }
        }
};

int main(){
    int n;
    cin>>n;
    Rabotnik *rabotnik = new Rabotnik[n];
    for(int i=0;i<n;i++){
        char ime[30], prezime[30];
        int plata;
        cin>>ime>>prezime>>plata;
        Rabotnik r(ime,prezime,plata);
        rabotnik[i]=r;
    }
    int minPlata;
    cin>>minPlata;
    Fabrika f(rabotnik,n);

    cout<<"Site vraboteni:"<<endl;
    f.pecatiVraboteni();
    cout<<"Vraboteni so plata povisoka od "<<minPlata<<" :"<<endl;
    f.pecatiSoPlata(minPlata);
}
