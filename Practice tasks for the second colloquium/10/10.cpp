#include<iostream>
#include<cstring>
using namespace std;
class NegativnaVrednost {
private:
    char msg[100];
    public:
    NegativnaVrednost(char * msg = "") {
    strcpy(this->msg, msg);
    }
    void showMessage() {
    cout<<msg;
    }
};
class Oglas { //За потребите на електронскиот огласник ФИНКИ-Огласи треба да се развие класа Oglas
private://со информации за
char naslov[50];//наслов (текстуална низа од максимум 50 знаци),
char kategorija[30];//категорија (текстуална низа од максимум 30 знаци),
char opis[100];//опис (текстуална низа од максимум 100 знаци) и
double evra;// цена изразена во евра (реален број). (5 поени)
public: //За оваа класа да се обезбедат:
    Oglas() {
    strcpy(this->naslov, "");
    strcpy(this->kategorija, "");
    strcpy(this->opis, "");
    this->evra =0.0;
    }
Oglas(char * naslov, char * kategorija, char * opis, double evra) {
    strcpy(this->naslov, naslov);
    strcpy(this->kategorija, kategorija);
    strcpy(this->opis, opis);
    this->evra = evra;
}
Oglas(const Oglas &copy) {
strcpy(this->naslov, copy.naslov);
    strcpy(this->kategorija, copy.kategorija);
    strcpy(this->opis, copy.opis);
    this->evra = copy.evra;
}
Oglas &operator=(const Oglas &copy) {
    if(this!=&copy) {
        strcpy(this->naslov, copy.naslov);
    strcpy(this->kategorija, copy.kategorija);
    strcpy(this->opis, copy.opis);
    this->evra = copy.evra;
    }
    return *this;
}
double getevra() {
    return this->evra;
}
char * getkategorija () {
    return this->kategorija;
}
    bool operator>(Oglas &compare) { //Оператор > за споредба на двa огласи според цената (5 поени)
    return this->evra > compare.evra;
    }
    friend ostream &operator<<(ostream &o, Oglas &print) {//Оператор << за печатење на податоците за огласот во форма:
    o<<print.naslov<<endl;//[наслов]
    o<<print.opis<<endl;//[опiс]
    o<<print.evra<< " evra"<<endl;//[цена] evra
    return o;
    }
};
class Oglasnik { //Да се развие класа Oglasnik
private://во која се чуваат податоци за
char ime[20];//iме на огласникот (текстуална низа од максимум 20 знаци),
Oglas * niza; //низа од огласи (динамички резервирана низа од објекти од класата Oglas)
int broj;//и број на огласи во низата (цел број) (5 поени)
    public:
    Oglasnik() {
    strcpy(this->ime, "");
    }
Oglasnik(char * ime) {
    strcpy(this->ime, ime);
    this->broj = 0;
    this->niza = new Oglas[0];
}
Oglasnik(const Oglasnik &copy) {
    this->broj = copy.broj;
    strcpy(this->ime, copy.ime);
    this->niza = new Oglas[copy.broj];
    for(int i=0;i<copy.broj;i++)
    this->niza[i] = copy.niza[i];
}//За оваа класа да се обезбедат:
Oglasnik &operator+=(Oglas &add) { //Оператор += за додавање нов оглас во низата од огласи.
if(add.getevra() < 0 ) //Ако цената на огласот што се внесува е негативна,
throw NegativnaVrednost("Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!\n");
else { //треба да се генерира исклучок NegativnaVrednost .Во ваков случај се печати порака
Oglas * tmp = new Oglas[broj+1];//“Oglasot ima nevalidna vrednost za cenata i nema da
for(int i=0; i<broj; i++)//bide evidentiran!“ и не се додава во низата. (5 поени)
tmp[i] = niza[i];
tmp[broj++] = add;
delete [] niza;
niza = tmp;
}
return *this;
}
   friend ostream &operator<<(ostream &o, Oglasnik &print) {// Оператор << за печатење на огласите во огласникот.
   o<<print.ime<<endl;// Печатењето треба да биде во следниот формат: [Име на огласникот]
   for(int i=0;i<print.broj;i++)
    o<<print.niza[i]<<endl;//[наслов1] [опис1] [цена1]
   return o;
   }
    void oglasiOdKategorija(const char *k) { //Функција void oglasOdKategorija(const char *k) со која се печатат
        for(int i=0; i<broj; i++)
            if(strcmp(niza[i].getkategorija(), k)==0)
    cout<<niza[i]<<endl; //сите огласи од категоријата k што е проследена како влезен аргумент на методот. (5 поени)
    }
    void najniskaCena() { //Функција void najniskaCena() со која се печати огласот што има најниска цена.
    int indeks = 0;
    double min = niza[0].getevra();//Ако има повеќе огласи со иста најниска цена,
    for(int i=0;i<broj;i++) //да се испечатат податоците за првиот од нив. (5 поени)
    if(min > niza[i].getevra()) {
    min = niza[i].getevra();
    indeks = i;
    }
    cout<<niza[indeks]<<endl;
    }//Сите променливи во класите се приватни.
};
int main(){
    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;

    int tip;
    cin>>tip;

    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout<<o;
    }
    else if (tip==2){
        cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
            ogl+=o;
            }
            catch(NegativnaVrednost &exc) {
            exc.showMessage();
            }
        }
        cout<<ogl;
    }
    else if (tip==4){
        cout<<"-----Test oglasOdKategorija -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl+=o;
            }
             catch(NegativnaVrednost &exc) {
            exc.showMessage();
            }

        }
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
        ogl.oglasiOdKategorija(k);

    }
    else if (tip==5){
        cout<<"-----Test Exception -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
            ogl+=o;
            }
             catch(NegativnaVrednost &exc) {
            exc.showMessage();
            }
        }
        cout<<ogl;

    }
    else if (tip==6){
        cout<<"-----Test najniskaCena -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
            ogl+=o;
            }
             catch(NegativnaVrednost &exc) {
            exc.showMessage();
            }
        }
        cout<<"Oglas so najniska cena:"<<endl;
        ogl.najniskaCena();

    }
    else if (tip==7){
        cout<<"-----Test All -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
            ogl+=o;
            }
             catch(NegativnaVrednost &exc) {
            exc.showMessage();
            }
        }
        cout<<ogl;
        cin.get();
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
        ogl.oglasiOdKategorija(k);
        cout<<"Oglas so najniska cena:"<<endl;
        ogl.najniskaCena();
    }
    return 0;
}
