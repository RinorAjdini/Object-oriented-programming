#include<iostream>
#include<cstring>
using namespace std;
class SMS { //Во рамките на еден телекомуникациски оператор, СМС пораките се делат на регуларни и специјални.
protected: //За секојa СМС порака се знае:
    double cena; //основна цена за една порака до 160 знаци (реален број)
    char pretplatnik[15]; //претплатнички број на кој е испратена (низа од знаци со должина 12) //dolzina 12 my ass
public://Класата за опишување на СМС пораки е апстрактна (5 поени).
    SMS() {
    strcpy(this->pretplatnik, "");
    this->cena = 0.0;
    }
    SMS(char * pretplatnik, double cena) {
        this->cena = cena;
        strcpy(this->pretplatnik, pretplatnik);
    }
    SMS(const SMS &copy) {
        this->cena = copy.cena;
        strcpy(this->pretplatnik, copy.pretplatnik);
    }
    virtual double SMS_cena() {
    return cena;
    }
    friend ostream &operator<<(ostream &o, SMS &print) {//Преоптоварен оператор <<
        o<<"Tel: "<<print.pretplatnik<<" - cena: "<<print.SMS_cena()<<"den."<<endl;  //за печатење на податоците за СМС пораките во формат:
    return o;
    }//Тел.број: цена
};
//EEEEEEEEEEEEEEEEEEEEEEEEEEEBITE SE EBITE SE ZNAEV DEKA 12 E MALCE ZA EDEN BROJ SI REKOV
//DALI POJSE DA STAAM AMA NEEEEEEEEEEE DA NE TROSAM MEMORIJA DEMEK EPA MALCE SE 12 INACE
//MI ZAZIMASE MESTO U DRUGIOT STRING E B I T E SE
class RegularSMS : public SMS {
private://За секоја Регуларна СМС дополнително се чуваат податоци за текстот на пораката
    bool roaming; // и тоа дали е користена роаминг услуга (bool променлива).
    char tekst[1000];
    static int rprocent;
public:
    RegularSMS() {
    strcpy(this->tekst, "");
    this->roaming = false;
    }
    RegularSMS(char * pretplatnik, double cena, char * tekst, bool roaming) : SMS (pretplatnik, cena) {
        strcpy(this->tekst, tekst);
        this->roaming = roaming;
    }
    RegularSMS(const RegularSMS &copy) : SMS(copy) {
        strcpy(this->tekst, copy.tekst);
        this->roaming = copy.roaming;
    }
    static void set_rProcent(int p) {
        rprocent = p;
    }
    int calc() {
        int counter=0;
        for(int copy=strlen(tekst); copy>0; copy=copy-160)
            counter++;
        return counter;
    }
    double SMS_cena() { //За регуларна СМС -
        double temp = SMS::SMS_cena();
        if(this->roaming)
            temp = temp+temp* rprocent/100;//цената се зголемува за 300% од основната цена ако е испратена од странство,
        else temp = temp+temp*0.18;//а 18% од дома и цената се формира врз база на тоа во колку СМС пораки
        return temp*calc();
    } //или повеќе пораки (пр. за 162 знаци, цената на СМС е иста како и за 320 знаци).
};
int RegularSMS::rprocent = 300;
class SpecialSMS : public SMS { //За секоја Специјална
private: //СМС дополнително се чуваат податоци за тоа
    bool humanitarna; //дали е наменета за хуманитарни цели (bool променлива). (5 поени)
    static int sprocent;
public:
    SpecialSMS() {
    this->humanitarna = true;
    }
    SpecialSMS(char * pretplatnik, double cena, bool humanitarna) : SMS(pretplatnik, cena) {
        this->humanitarna = humanitarna;
    }
    SpecialSMS(const SpecialSMS & copy) : SMS(copy) {
        this->humanitarna = copy.humanitarna;
    }
     double SMS_cena() {// специјална СМС - цената се зголемува за 150% од основната
                if(this->humanitarna)//цена ако пораката HE е наменета за хуманитарни цели.
                return SMS::SMS_cena();//Пресметувањето 18% данок на цената на сите СМС пораки е фиксен и не се менува,
            else
                return SMS::SMS_cena() + SMS::SMS_cena() * sprocent/100;
     } // менува. Да се обезбеди механизам за можност за нивно менување. (5 поени)
    static void set_sProcent(int p) {
        sprocent = p;
    }
};
int SpecialSMS::sprocent = 150;
void vkupno_SMS(SMS **poraka, int n) {//Да се имплементира функција vkupno_SMS со потпис:
    int r = 0, s = 0;//void vkupno_SMS(SMS** poraka, int n)
    double reg=0.0, spec=0.0;
    for(int i=0; i<n; i++) {
        RegularSMS * p1 = dynamic_cast<RegularSMS *>(poraka[i]);
        if(p1!=0) {
            r++;//во која се печати вкупниот број на регуларни СМС пораки и нивната вкупна цена,
            reg=reg+poraka[i]->SMS_cena();
        }
        SpecialSMS * p2 = dynamic_cast<SpecialSMS *>(poraka[i]);
        if(p2!=0) {
            s++;//како и бројот на специјални СМС пораки и нивната вкупна цена во проследената
            spec = spec+poraka[i]->SMS_cena();
        }//низа посебно. (15 поени)
    }
    cout<<"Vkupno ima "<<r<<" regularni SMS poraki i nivnata cena e: "<<reg<<endl;
    cout<<"Vkupno ima "<<s<<" specijalni SMS poraki i nivnata cena e: "<<spec<<endl;
}
int main() {
    char tel[20], msg[1000];
    float cena;
    float price;
    int p;
    bool roam, hum;
    SMS  **sms;
    int n;
    int tip;
    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "====== Testing RegularSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];
        for (int i = 0; i < n; i++) {
            cin >> tel;
            cin >> cena;
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new RegularSMS(tel, cena, msg, roam);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 2) {
        cout << "====== Testing SpecialSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];
        for (int i = 0; i < n; i++) {
            cin >> tel;
            cin >> cena;
            cin >> hum;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new SpecialSMS(tel, cena, hum);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 3) {
        cout << "====== Testing method vkupno_SMS() ======" << endl;
        cin >> n;
        sms = new SMS *[n];
        for (int i = 0; i<n; i++) {
            cin >> tip;
            cin >> tel;
            cin >> cena;
            if (tip == 1) {
                cin.get();
                cin.getline(msg, 1000);
                cin >> roam;
                sms[i] = new RegularSMS(tel, cena, msg, roam);
            } else {
                cin >> hum;
                sms[i] = new SpecialSMS(tel, cena, hum);
            }
        }
        vkupno_SMS(sms, n);
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 4) {
        cout << "====== Testing RegularSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        sms1 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms1;
        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        cin >> p;
        RegularSMS::set_rProcent(p);
        sms2 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms2;
        delete sms1, sms2;
    }
    if (testCase == 5) {
        cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        cin >> tel;
        cin >> cena;
        cin >> hum;
        sms1 = new SpecialSMS(tel, cena, hum);
        cout << *sms1;
        cin >> tel;
        cin >> cena;
        cin >> hum;
        cin >> p;
        SpecialSMS::set_sProcent(p);
        sms2 = new SpecialSMS(tel, cena, hum);
        cout << *sms2;
        delete sms1, sms2;
    }
    return 0;
}
