#include <iostream>
#include <cstring>
using namespace std;

class PlDrustvo{
private:
    char *ime;
    int br_turi;
    int br_clenovi;
public:
    PlDrustvo(char *ime="",int br_turi=0,int br_clenovi=0)
    {
        this->ime=new char [strlen(ime)+1];
        strcpy(this->ime,ime);
        this->br_turi=br_turi;
        this->br_clenovi=br_clenovi;
    }
    PlDrustvo(const PlDrustvo &pl)
    {
         this->ime=new char [strlen(pl.ime)+1];
        strcpy(this->ime,pl.ime);
        this->br_turi=pl.br_turi;
        this->br_clenovi=pl.br_clenovi;
    }
    PlDrustvo& operator= (const PlDrustvo &pl)
    {
        if(this==&pl)return *this;
        delete []ime;
         this->ime=new char [strlen(pl.ime)+1];
        strcpy(this->ime,pl.ime);
        this->br_turi=pl.br_turi;
        this->br_clenovi=pl.br_clenovi;
        return *this;
    }
    PlDrustvo operator+(const PlDrustvo &pl)
    {
        PlDrustvo tmp;
        tmp.br_clenovi=this->br_clenovi+pl.br_clenovi;
        if(this->br_clenovi>=pl.br_clenovi)
        {
            tmp.br_turi=this->br_turi;
            tmp.ime = new char [strlen(this->ime)+1];
            strcpy(tmp.ime,this->ime);
        }
        else
        {
            tmp.br_turi=pl.br_turi;
            tmp.ime = new char [strlen(pl.ime)+1];
            strcpy(tmp.ime,pl.ime);
        }
        return tmp;
    }
    bool operator> (const PlDrustvo &pl)
    {
        if(this->br_clenovi>pl.br_clenovi)
        return 1;
        return 0;
    }
    bool operator< (const PlDrustvo &pl)
    {
        if(this->br_clenovi<pl.br_clenovi)
        return 1;
        return 0;
    }
    friend ostream & operator<< (ostream &out,PlDrustvo &pl)
    {
        out<<"Ime: "<<pl.ime<<" Turi: "<<pl.br_turi<<" Clenovi: "<<pl.br_clenovi<<endl;
        return out;
    }
    ~PlDrustvo()
    {
        delete []ime;
    }

};

void najmnoguClenovi(PlDrustvo *pl, int n)
{
    PlDrustvo rin=pl[0];
    int index=0;
    for(int i=1;i<n;i++)
    {
        if(pl[i]>rin)
        {
            rin=pl[i];
            index=i;
        }
    }
    cout<<"Najmnogu clenovi ima planinarskoto drustvo: "<<pl[index];
}

int main()
{
    PlDrustvo drustva[3];
    PlDrustvo pl;
    for (int i=0;i<3;i++)
   	{
    	char ime[100];
    	int brTuri;
    	int brClenovi;
    	cin>>ime;
    	cin>>brTuri;
    	cin>>brClenovi;
    	PlDrustvo p(ime,brTuri,brClenovi);
        drustva[i] = p;

   	}

    pl = drustva[0] + drustva[1];
    cout<<pl;

    najmnoguClenovi(drustva, 3);

    return 0;
}
