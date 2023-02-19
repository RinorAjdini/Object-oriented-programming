#include<iostream>
#include<cstring>
using namespace std;
class List
{
private:
    int *broevi;
    int brojac;
public:
    List()
    {
        broevi=new int[0];
        brojac=0;
    }
    List(int *broevi, int brojac)
    {
        this->brojac=brojac;
        this->broevi=new int[brojac];
        for(int i=0;i<brojac;i++)
        {
            this->broevi[i]=broevi[i];
        }
    }
    List(const List& l)
    {
        this->brojac=l.brojac;
        this->broevi=new int[l.brojac];
        for(int i=0;i<l.brojac;i++)
        {
            this->broevi[i]=l.broevi[i];
        }
    }
    ~List()
    {
        delete[]broevi;
    }
    List& operator=(List& l)
    {
        if(this!=&l)
        {
            delete[]broevi;
            brojac=l.brojac;
            broevi=new int[l.brojac];
            for(int i=0;i<l.brojac;i++)
            {
                broevi[i]=l.broevi[i];
            }

        }
        return *this;
    }
    int sum()
    {
        int zbir=0;
        for(int i=0;i<brojac;i++)
        {
            zbir+=broevi[i];
        }
        return zbir;
    }
    double average()
    {
        double prosek=0.0;
        for(int i=0;i<brojac;i++)
        {
            prosek+=broevi[i];
        }
        prosek/=brojac;
        return prosek;
    }
    void pecati()
    {
        cout<<brojac<<": ";
        for(int i=0;i<brojac;i++)
        {
            cout<<broevi[i]<<" ";
        }
        cout<<"sum: "<<sum();
        cout<<" average: "<<average();
    }
    int getBrojac()
    {
        return brojac;
    }
};
class ListContainer
{
private:
    List* listi;
    int brojacNaElementi;
    int brojNaObidi;
public:
    ListContainer()
    {
        listi=new List[0];
        brojacNaElementi=0;
        brojNaObidi=0;
    }
    ~ListContainer()
    {
        delete[]listi;
    }
    ListContainer(const ListContainer &lc)
    {
        this->brojNaObidi=lc.brojNaObidi;
        this->brojacNaElementi=lc.brojacNaElementi;
        this->listi=new List[lc.brojacNaElementi];
        for(int i=0;i<lc.brojacNaElementi;i++)
        {
            this->listi[i]=lc.listi[i];
        }
    }
    ListContainer &operator = (ListContainer &lc)
    {
        if(this!=&lc)
        {
            delete[]listi;
            brojNaObidi=lc.brojNaObidi;
            brojacNaElementi=lc.brojacNaElementi;
            listi=new List[lc.brojacNaElementi];
            for(int i=0;i<lc.brojacNaElementi;i++)
            {
                listi[i]=lc.listi[i];
            }
        }
        return *this;
    }
    int sum()
    {
        int zbir=0;
        for(int i=0;i<brojacNaElementi;i++)
        {
            zbir+=listi[i].sum();
        }
        return zbir;
    }
    double average()
    {
        int suma=sum();
        int zbirNaBroevi=0;
        for(int i=0;i<brojacNaElementi;i++)
        {
            zbirNaBroevi+=listi[i].getBrojac();
        }
        return (suma/(zbirNaBroevi*1.0));
    }
    void addNewList(List l)
    {
        brojNaObidi+=1;
        for(int i=0;i<brojacNaElementi;i++)
        {
            if(l.sum() == listi[i].sum())
            {
                return;
            }
        }
        List* tmp=new List[brojacNaElementi+1];
        for(int i=0;i<brojacNaElementi;i++){
            tmp[i]=listi[i];
        }
        tmp[brojacNaElementi++]=l;
        delete [] listi;
        listi=tmp;
    }
    void pecati()
    {
        if(brojacNaElementi == 0)
        {
            cout<<"The list is empty"<<endl;
            return;
        }
        else{
        for(int i=0;i<brojacNaElementi;i++)
        {
            cout<<"List number: "<<i+1<<" List info: ";
            listi[i].pecati();
            cout<<endl;
        }
        }
        cout<<"Sum: "<<sum()<<" Average: "<<average();
        cout<<endl;
        cout<<"Successful attempts: "<<brojacNaElementi<<" Failed attempts: "<<brojNaObidi-brojacNaElementi<<endl;
    }

};
int main ()
{
    ListContainer lc;
    int N;
    cin>>N;

    for (int i=0; i<N; i++) {
        int n;
        int niza[100];

        cin>>n;

        for (int j=0; j<n; j++) {
            cin>>niza[j];

        }

        List l=List(niza,n);

        lc.addNewList(l);
    }


    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.pecati();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.pecati();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;

    } else {
        lc.pecati();
    }
}
