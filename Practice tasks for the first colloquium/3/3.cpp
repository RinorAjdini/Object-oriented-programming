#include<iostream>
#include<cstring>
using namespace std;

// vasiot kod za klasite ovde

class StockRecord{
private:
    char id[12];
    char ime[50];
    double cena;
    double momentalna_cena;
    int br_akcii;
public:
    StockRecord(char *id="",char *ime="",double cena=0,double br_akcii=0)
    {
        strcpy(this->id,id);
        strcpy(this->ime,ime);
        this->cena=cena;
        this->br_akcii=br_akcii;
    }
    void setNewPrice(double c)
    {
        momentalna_cena=c;
    }
    double value()
    {
        double v=br_akcii * momentalna_cena;
        return v;
    }
    double profit()
    {
        double p=br_akcii*(momentalna_cena-cena);
        return p;
    }
    friend ostream & operator<< (ostream &out, const StockRecord &st)
    {
        out<<st.ime<<" "<<st.br_akcii<<" "<<st.cena<<" "<<st.momentalna_cena<<" ";
        out<<st.br_akcii*(st.momentalna_cena-st.cena)<<endl;
        return out;
    }
    friend class Client;
};

class Client{
private:
    char ime_prezime[60];
    int id_smetka;
    StockRecord *stc;
    int br_stc;
public:
    Client(char *ime_prezime="",int id_smetka=0)
    {
        strcpy(this->ime_prezime,ime_prezime);
        this->id_smetka=id_smetka;
        this->stc = new StockRecord [0];
        this->br_stc=0;
    }
    Client (const Client & cl)
    {
        strcpy(this->ime_prezime,cl.ime_prezime);
        this->id_smetka=cl.id_smetka;
        this->stc = new StockRecord [cl.br_stc];
        for(int i=0;i<cl.br_stc;i++)
        this->stc[i]=cl.stc[i];
        this->br_stc=cl.br_stc;
    }
    Client & operator= (const Client & cl)
    {
        if(this==&cl)
        return *this;
        delete [] stc;
        strcpy(this->ime_prezime,cl.ime_prezime);
        this->id_smetka=cl.id_smetka;
        this->stc = new StockRecord [cl.br_stc];
        for(int i=0;i<cl.br_stc;i++)
        this->stc[i]=cl.stc[i];
        this->br_stc=cl.br_stc;
        return *this;
    }
    ~Client()
    {
        delete []stc;
    }
    double totalValue()
    {
        double r=0;
        for(int i=0;i<br_stc;i++)
        {
            r+=stc[i].value();
        }
        return r;
    }
    Client & operator+= (StockRecord & stc1)
    {
        StockRecord *tmp = new StockRecord [br_stc+1];
        for(int i=0;i<br_stc;i++)
        tmp[i]=stc[i];
        tmp[br_stc++]=stc1;
        delete [] stc;
        stc = tmp;
        return *this;
    }
    friend ostream & operator<< (ostream &out ,Client &cl)
    {
        out<<cl.id_smetka<<" "<<cl.totalValue()<<endl;
        for(int i=0;i<cl.br_stc;i++)
        out<<cl.stc[i];
        return out;
    }

};

// ne menuvaj vo main-ot

int main(){

    int test;
    cin >> test;

    if(test == 1){
    	double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    }
    else if(test == 2){
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
    	char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for(int i = 0; i < n; ++i){
        	cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    }
    else if(test == 3){
    	cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for(int i = 0; i < n; ++i){
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
        	StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if(flag){
            	cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;

}
