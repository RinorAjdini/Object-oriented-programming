#include <iostream>
#include <cstring>

using namespace std;

class Masa{
  private:
  int dolzina;
  int sirina;
  public:
  Masa(){}
  Masa(int s,int d)
  {
      sirina=s;
       dolzina=d;
  }
  ~Masa(){}
  void pecati ()
  {
      cout<<" Masa: "<<sirina<<" "<<dolzina<<endl;
  }
};

class Soba{
    private:
    Masa masa;
    int dolzina_soba;
    int sirina_soba;
    public:
    Soba(){}
    Soba(int sirina,int dolzina,Masa m)
    {
        sirina_soba=sirina;
        dolzina_soba=dolzina;
        masa=m;
    }
    void pecati()
    {
        cout<<" Soba: "<<sirina_soba<<" "<<dolzina_soba;
        masa.pecati();
    }
};
class Kukja {
  private:
  Soba s;
  char adresa[50];
  public:
  Kukja(){}
  Kukja(Soba s,char *adresa)
  {
      this->s=s;
      strcpy(this->adresa,adresa);
  }
  ~Kukja(){}
  void pecati()
  {
      cout<<"Adresa: "<<adresa;
      s.pecati();

  }
};

//ne smee da se menuva main funkcijata!
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	int masaSirina,masaDolzina;
        cin>>masaSirina;
        cin>>masaDolzina;
    	Masa m(masaSirina,masaDolzina);
    	int sobaSirina,sobaDolzina;
        cin>>sobaSirina;
        cin>>sobaDolzina;
    	Soba s(sobaSirina,sobaDolzina,m);
    	char adresa[30];
        cin>>adresa;
    	Kukja k(s,adresa);
    	k.pecati();
	}

    return 0;
}
