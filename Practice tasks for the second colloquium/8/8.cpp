#include <iostream>
#include <cstring>
using namespace std;

class Koncert{
private:
    char naziv[20];
    char lokacija[20];
    static double sezonski_popust;
    double cenaDenari;
public:
    Koncert(const char *naziv="",const char *lokacija="",double cenaDenari=0)
    {
        strcpy(this->naziv,naziv);
        strcpy(this->lokacija,lokacija);
        this->cenaDenari=cenaDenari;
    }
    Koncert (const Koncert &kon)
    {
        strcpy(this->naziv,kon.naziv);
        strcpy(this->lokacija,kon.lokacija);
        this->cenaDenari=kon.cenaDenari;
    }
    static void setSezonskiPopust(double k)
    {
        sezonski_popust=k;
    }
    static double getSezonskiPopust()
    {
        return sezonski_popust;
    }
    char* getNaziv()
    {
        return naziv;
    }
    char * getLokacija()
    {
        return lokacija;
    }
    virtual double cena()
    {
        return (1-sezonski_popust)*cenaDenari;
    }
    friend ostream&operator<<(ostream&o,Koncert &k)
    {
        o<<k.naziv<<" "<<k.cena()<<endl;
        return o;
    }
};
double Koncert::sezonski_popust=0.2;

class ElektronskiKoncert : public Koncert{
private:
    char *imeDJ;
    double vremetraenje;
    bool dali; //dnevna-true,nokna-false
public:
    ElektronskiKoncert(const char *naziv="",const char *lokacija="",double cenaDenari=0,const char *imeDJa="",double vremetraenje=0,bool dali=true)
    :Koncert(naziv,lokacija,cenaDenari)
    {
        imeDJ = new char [strlen(imeDJa)+1];
        strcpy(imeDJ,imeDJa);
        this->vremetraenje=vremetraenje;
        this->dali=dali;
    }
    ElektronskiKoncert(const ElektronskiKoncert &ek)
    :Koncert(ek)
    {
        imeDJ= new char [strlen(ek.imeDJ)+1];
        strcpy(this->imeDJ,ek.imeDJ);
        this->vremetraenje=ek.vremetraenje;
        this->dali=ek.dali;
    }
   /* ElektronskiKoncert&operator=(const ElektronskiKoncert &ek)
    {
        if(this!=&ek)
        {
        strcpy(this->naziv,ek.naziv);
        strcpy(this->lokacija,ek.lokacija);
        this->cenaDenari=ek.cenaDenari;
        imeDJ= new char [strlen(ek.imeDJ)+1];
        strcpy(this->imeDJ,ek.imeDJ);
        this->vremetraenje=ek.vremetraenje;
        this->dali=ek.dali;
        }
        return *this;
    }
    */
    friend ostream&operator<<(ostream&o,ElektronskiKoncert &ek)
    {
        o<<ek.getNaziv()<<" "<<ek.cena()<<endl;
        return o;
    }
    ~ElektronskiKoncert()
    {
        delete []imeDJ;
    }
    double cena()
    {
        double suma= Koncert::cena();
        if(vremetraenje>7)
            suma+=360;
        else if(vremetraenje>5)
            suma+=150;
        if(dali==true)
            suma-=50;
        else
            suma+=100;
        return suma;
    }
};

void najskapKoncert(Koncert ** koncerti, int n)
{
    int elek=0,obic=0;
    double suma=koncerti[0]->cena();
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(koncerti[i]->cena()>suma)
        {
            suma=koncerti[i]->cena();
            index = i;
        }
        ElektronskiKoncert * tmp = dynamic_cast <ElektronskiKoncert*> (koncerti[i]);
        if(tmp!=0)
            elek++;
        else
            obic++;
    }
    cout<<"Najskap koncert: "<<koncerti[index]->getNaziv()<<" "<<koncerti[index]->cena()<<endl;
    cout<<"Elektronski koncerti: "<<elek<<" od vkupno "<<elek+obic<<endl;

}

bool prebarajKoncert(Koncert ** koncerti, int n, char * naziv, bool elektronski)
{
    bool t=false;
    if(elektronski==true)
    {
        for(int i=0;i<n;i++)
        {
            ElektronskiKoncert *tmp = dynamic_cast <ElektronskiKoncert*> (koncerti[i]);
            if(tmp!=0)
            {
                if(!strcmp(koncerti[i]->getNaziv(),naziv))
                {
                    cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                    t=true;
                }
            }
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(!strcmp(koncerti[i]->getNaziv(),naziv))
            {
                cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                t=true;
            }
        }
    }
    return t;
}

int main(){

    int tip,n,novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

        cin>>tip;
        if (tip==1){//Koncert
        	cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
        }
        else if (tip==2){//cena - Koncert
            cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
        }
        else if (tip==3){//ElektronskiKoncert
            cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
            ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
            cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
        }
        else if (tip==4){//cena - ElektronskiKoncert
             cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
             ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
             cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
        }
        else if (tip==5) {//najskapKoncert

        }
        else if (tip==6) {//prebarajKoncert
            Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
        	najskapKoncert(koncerti,5);
        }
        else if (tip==7){//prebaraj
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
            bool elektronski;
        	cin>>elektronski;
        	if(prebarajKoncert(koncerti,5, "Area",elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

            if(prebarajKoncert(koncerti,5, "Area",!elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

        }
        else if (tip==8){//smeni cena
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[2] -> setSezonskiPopust(0.9);
        	najskapKoncert(koncerti,4);
        }

    return 0;
}
