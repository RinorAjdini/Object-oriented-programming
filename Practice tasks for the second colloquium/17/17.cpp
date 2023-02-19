#include<iostream>
#include<cstring>
using namespace std;
class FudbalskaEkipa { // Да се имплементира апстрактна класа FudblaskaEkipa
protected://во која се чува: (5 поени)
char imetrener[100]; //име на тренерот на екипата (максимум 100 знаци)
int golovi[10]; //бројот на постигнати голови на последните 10 натпревари,
public: //последниот натпревар е на позиција 9, предпоследниот на позиција 8, итн (поле од 10 цели броеви)
FudbalskaEkipa() {
    strcpy(this->imetrener, "");
    this->golovi[0] = 0;
}
FudbalskaEkipa(char * imetrener, int * golovi) {
    strcpy(this->imetrener, imetrener);
    for(int i=0;i<10;i++)
    this->golovi[i] = golovi[i];
}
FudbalskaEkipa(const FudbalskaEkipa &copy) {
    strcpy(this->imetrener, copy.imetrener);
    for(int i=0;i<10;i++)
    this->golovi[i] = copy.golovi[i];
}
FudbalskaEkipa &operator=(const FudbalskaEkipa &copy) {
    if(this!=&copy) {
        strcpy(this->imetrener, copy.imetrener);
    for(int i=0;i<10;i++)
    this->golovi[i] = copy.golovi[i];
    }
    return *this;
}
    FudbalskaEkipa &operator+=(int add) { //преоптоварен оператор += за додавање на голови од последниот натпревар
    golovi[0] = add;
    return *this; //(внимавајте секогаш се чуваат головите само од последните 10 натпревари)
    } //NEMAM POJMA SO ZNACE VOAAAAAAAAAAA nema sansi da e tocno
//tocno bese ne znam kako, ne znam zosto
virtual int uspeh() = 0;
bool operator>(FudbalskaEkipa &compare) { //преоптоварен оператор > за споредба на две фудбласки екипи од
if(this->uspeh() > compare.uspeh()) //каков било вид (клубови или репрезентации)
       return true; //според успехот (5 поени)
       else return false;
}
    virtual char * getime() = 0;
    friend ostream &operator<<(ostream &o, FudbalskaEkipa &print) { // оператор << за печатење на стандарден излез
    o<<print.getime()<<endl;//во формат [IME_NA_KLUB/DRZHAVA]\n[TRENER]\n[USPEH]\n
    o<<print.imetrener<<endl;
    o<<print.uspeh()<<endl;
    return o;
    }
};
class Klub : public FudbalskaEkipa { //Од класата FudblaskaEkipa да се изведат класите Klub и Reprezentacija.
private: //За секој клуб дополнително се чува податок за
char imeklub[50]; //името и
int tituli; //бројот на титули што ги има освоено,
public:
Klub() {
    strcpy(this->imeklub, "");
    this->tituli = 0;
}
Klub(char * imetrener, int * golovi, char * imeklub, int tituli) : FudbalskaEkipa(imetrener, golovi) {
    strcpy(this->imeklub, imeklub);
    this->tituli = tituli;
}
Klub(const Klub &copy) : FudbalskaEkipa(copy) {
strcpy(this->imeklub, copy.imeklub);
    this->tituli = copy.tituli;
}
    int uspeh() { //За Klub се пресметува како збир од
     int zbir=0;//збирот на головите од последните 10 натпревари помножен
     for(int i=0;i<10;i++)// со 3 и бројот на титули помножен со 1000
     zbir=zbir+golovi[i];//   (на пр. голови = {2, 0, 1, 3, 2, 0, 1, 4, 2, 3} и
     return zbir*3 + this->tituli*1000; // број на титули = 3, достигнување = 18 * 3 + 3 * 1000 = 3054)
    }
    friend ostream &operator<<(ostream &o, Klub &print) {// оператор << за печатење на стандарден излез
    o<<print.imeklub<<endl;//во формат [IME_NA_KLUB/DRZHAVA]\n[TRENER]\n[USPEH]\n
    o<<print.imetrener<<endl;
    o<<print.uspeh()<<endl;
    return o;
    }
    char * getime() {
    return imeklub;
    }
};
class Reprezentacija : public FudbalskaEkipa {
private://а за репрезентацијата се чуваат податоци за
char imedrzava[50];//името на државата и
int nastapi;//вкупен број на меѓународни настапи.
public://За овие класи да се имплементираат следните методи:
Reprezentacija() {
    strcpy(this->imedrzava, "");
    this->nastapi = 0;
}
Reprezentacija(char * imetrener, int * golovi, char * imedrzava, int nastapi) : FudbalskaEkipa(imetrener, golovi) {
    strcpy(this->imedrzava, imedrzava);
    this->nastapi = nastapi;
}// соодветен конструктор (5 поени)
Reprezentacija(const Reprezentacija &copy) : FudbalskaEkipa(copy) {
    strcpy(this->imedrzava, copy.imedrzava);
    this->nastapi = copy.nastapi;
}
int uspeh() { //За Reprezentacija
    int zbir=0;//збирот на головите од последните 10 натпревари помножен
     for(int i=0;i<10;i++)// со 3 и бројот на титули помножен со 1000
     zbir=zbir+golovi[i];//   (на пр. голови = {2, 0, 1, 3, 2, 0, 1, 4, 2, 3} и
 return zbir*3 + nastapi*50; //и бројот на меѓународни настапи помножен со 50
}
    friend ostream &operator<<(ostream &o, Reprezentacija &print) {// оператор << за печатење на стандарден излез
    o<<print.imedrzava<<endl;//во формат [IME_NA_KLUB/DRZHAVA]\n[TRENER]\n[USPEH]\n
    o<<print.imetrener<<endl;
    o<<print.uspeh()<<endl;
    return o;
    }
    char * getime() {
    return imedrzava;
    }
};
void najdobarTrener(FudbalskaEkipa **niza, int n) {//Да се имплементира функција najdobarTrener
int max = niza[0]->uspeh();// што на влез прима низа од покажувачи кон FudblaskaEkipa и
int indeks=0;
for(int i=0; i<n; i++) //големина на низата и го печати тимот со најголем успех (10 поени).
if(niza[i]->uspeh() > max) {
max = niza[i]->uspeh();
indeks = i;
}
cout<<*niza[indeks];
}
int main() {
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa*[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            ekipi[i] = new Klub(coach, goals, x, tg);
        } else if (type == 1) {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i) {
        delete ekipi[i];
    }
    delete [] ekipi;
    return 0;
}
