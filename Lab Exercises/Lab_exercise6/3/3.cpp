#include<iostream>
#include<cstring>
using namespace std;
class Lekar
{
protected:
    int faksimil;
    char ime[15];
    char prezime[15];
    double plata;
public:
    Lekar(int faksimil=0,const char *ime="",const char *prezime="",double plata=0)
    {
        this->faksimil=faksimil;
        strcpy(this->ime,ime);
        strcpy(this->prezime,prezime);
        this->plata=plata;
    }
    Lekar(const Lekar &l)
    {
        faksimil=l.faksimil;
        strcpy(ime,l.ime);
        strcpy(prezime,l.prezime);
        plata=l.plata;
    }
    void pecati()
    {
        cout<<faksimil<<": "<<ime<<" "<<prezime<<endl;
    }
    double getPlata()
    {
        return plata;
    }
};
class MaticenLekar : public Lekar
{
private:
    int broj;
    double *kotizacii;

    void copy(const MaticenLekar &ml)
    {
        broj=ml.broj;
        kotizacii=new double[broj];
        for(int i=0;i<broj;i++)
        {
            kotizacii[i]=ml.kotizacii[i];
        }
        strcpy(ime,ml.ime);
        strcpy(prezime,ml.prezime);
        plata=ml.plata;
        faksimil=ml.faksimil;
    }
public:
    MaticenLekar() : Lekar()
    {
        broj=0;
        kotizacii=new double[0];
    }
    MaticenLekar(int faksimil,const char *ime, const char *prezime,double plata,int broj, double *kotizacii) : Lekar(faksimil,ime,prezime,plata)
    {
        this->broj=broj;
        this->kotizacii=new double[broj];
        for(int i=0;i<broj;i++)
        {
            this->kotizacii[i]=kotizacii[i];
        }
    }
    MaticenLekar(const Lekar &l,int broj, double *kotizacii) : Lekar(l)
    {
        this->broj=broj;
        this->kotizacii=new double[broj];
        for(int i=0;i<broj;i++)
        {
            this->kotizacii[i]=kotizacii[i];
        }
    }
    MaticenLekar(const MaticenLekar &ml)
    {
        copy(ml);
    }
    MaticenLekar&operator=(const MaticenLekar &ml)
    {
        if(this!=&ml)
        {
            delete[]kotizacii;
            copy(ml);
            plata=ml.plata;
            faksimil=ml.faksimil;
            strcpy(ime,ml.ime);
            strcpy(prezime,ml.prezime);
        }
        return *this;
    }
    ~MaticenLekar()
    {
        delete[]kotizacii;
    }
    double Kotizacija()
    {
        double vkupno=0;
        for(int i=0;i<broj;i++)
        {
            vkupno+=kotizacii[i];
        }
        return(vkupno/broj);
    }
    double getPlata()
    {
        return plata + (0.3 * Kotizacija());
    }
    void pecati()
    {
        Lekar::pecati();
        cout<<"Prosek na kotizacii: "<<Kotizacija()<<endl;
    }


};

int main ()
{
    int n;
    cin>>n;
    int pacienti;
    double kotizacii[100];
    int faksimil;
    char ime [20];
    char prezime [20];
    double osnovnaPlata;

    Lekar * lekari = new Lekar [n];
    MaticenLekar * maticni = new MaticenLekar [n];

    for (int i=0;i<n;i++){
        cin >> faksimil >> ime >> prezime >> osnovnaPlata;
        lekari[i] = Lekar(faksimil,ime,prezime,osnovnaPlata);
    }

    for (int i=0;i<n;i++){
        cin >> pacienti;
        for (int j=0;j<pacienti;j++){
            cin >> kotizacii[j];
        }
        maticni[i]=MaticenLekar(lekari[i],pacienti,kotizacii);
    }

    int testCase;
    cin>>testCase;

    if (testCase==1){
        cout<<"===TESTIRANJE NA KLASATA LEKAR==="<<endl;
        for (int i=0;i<n;i++){
            lekari[i].pecati();
            cout<<"Osnovnata plata na gorenavedeniot lekar e: "<<lekari[i].getPlata()<<endl;
        }
    }
    else {
        cout<<"===TESTIRANJE NA KLASATA MATICENLEKAR==="<<endl;
        for (int i=0;i<n;i++){
            maticni[i].pecati();
            cout<<"Platata na gorenavedeniot maticen lekar e: "<<maticni[i].getPlata()<<endl;
        }
    }

    delete [] lekari;
    delete [] maticni;

    return 0;
}
