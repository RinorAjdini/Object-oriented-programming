#include <iostream>
#include <cstring>
using namespace std;

class List{
private:
    int *niza;
    int br_elementi;
public:
    List ()
    {
        this->br_elementi = 0;
        this->niza = new int [0];
    }
    List(int *niza,int br_elementi)
    {
        this->br_elementi = br_elementi;
        this->niza = new int [this->br_elementi];
        for(int i=0;i<br_elementi;i++)
        {
            this->niza[i]=niza[i];
        }
    }
    List (const List &ls)
    {
        this->br_elementi =ls.br_elementi;
        this->niza = new int [this->br_elementi];
        for(int i=0;i<br_elementi;i++)
        {
            this->niza[i]=ls.niza[i];
        }
    }
    List & operator= (const List &ls)
    {
        if(this==&ls)return *this;
        delete []niza;
        this->br_elementi =ls.br_elementi;
        this->niza = new int [this->br_elementi];
        for(int i=0;i<br_elementi;i++)
        {
            this->niza[i]=ls.niza[i];
        }
        return *this;
    }
    void pecati()
    {
        cout<<br_elementi<<": ";
        for(int i=0;i<br_elementi;i++)
        {
            cout<<niza[i]<<" ";
        }
        cout<<"sum: "<<sum();
        cout<<" average: "<<average();
    }
    int sum()
    {
        int s=0;
        for(int i=0;i<br_elementi;i++)
        {
            s+=niza[i];
        }
        return s;
    }
    double average()
    {
        double r=0;
        for(int i=0;i<br_elementi;i++)
        {
            r+=niza[i];
        }
        return (r*1.0/br_elementi);
    }
    int getBrojac()
    {
        return br_elementi;
    }
    ~List ()
    {
        delete []niza;
    }
};

class ListContainer{
private:
    List *list;
    int br_listi;
    int br_obidi;
public:
    ListContainer()
    {
        this->br_listi=0;
        this->br_obidi=0;
        this->list = new List [0];
    }
    ListContainer(const ListContainer &ls)
    {
        this->br_listi=ls.br_listi;
        this->br_obidi=ls.br_obidi;
        this->list = new List [br_listi];
        for(int i=0;i<br_listi;i++)
        {
            this->list[i]=ls.list[i];
        }
    }
    ListContainer & operator= (const ListContainer &ls)
    {
        if(this==&ls)
        return *this;
        delete []list;
        this->br_listi=ls.br_listi;
        this->br_obidi=ls.br_obidi;
        this->list = new List [br_listi];
        for(int i=0;i<br_listi;i++)
        {
            this->list[i]=ls.list[i];
        }
        return *this;
    }
    void addNewList(List l)
    {
        int s=l.sum();
        br_obidi++;
        int kec=0;
        for(int i=0;i<br_listi;i++)
        {
            if(s==list[i].sum())
            {
                kec=1;
                break;
            }
        }
        if(kec==0)
        {
            List *tmp = new List [br_listi+1];
            br_listi++;
            for(int i=0;i<br_listi-1;i++)
            {
                tmp[i]=list[i];
            }
            delete[]list;
            tmp[br_listi-1]=l;
            list=tmp;
        }
    }
    int sum()
    {
        int s=0;
        for(int i=0;i<br_listi;i++)
        {
            s+=list[i].sum();
        }
        return s;
    }
    double average()
    {
         int s=sum();
         int zbir=0;
         for(int i=0;i<br_listi;i++)
         {
             zbir+=list[i].getBrojac();
         }
         return (s*1.0/zbir);
    }
    void pecati()
    {
        if(br_listi==0)
        cout<<"The list is empty"<<endl;
        else
        {
            for(int i=0;i<br_listi;i++)
            {
                cout<<"List number: "<<i+1<<" List info: ";
                list[i].pecati();
                cout<<endl;
            }
        cout<<"Sum: "<<sum()<<" Average: "<<average()<<endl;
        cout<<"Successful attempts: "<<br_listi<<" Failed attempts: "<<br_obidi-br_listi<<endl;
        }
    }
    ~ListContainer()
    {
        delete [] list;
    }
};

int main() {

	ListContainer lc;
	int N;
	cin>>N;

	for (int i=0;i<N;i++) {
		int n;
		int niza[100];

		cin>>n;

		for (int j=0;j<n;j++){
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
        lc1.sum();
        lc1.average();

    }
    else {
        lc.pecati();
    }
}
