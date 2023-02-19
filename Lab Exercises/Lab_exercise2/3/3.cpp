#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Film {
  private:
    char ime[100];
    char reziser[50];
    char zanr[50];
    int godina;
  public:
  Film ()
  {

  }
  Film(char *imee,char *r,char *z,int g)
  {
      strcpy(ime,imee);
      strcpy(reziser,r);
      strcpy(zanr,z);
      godina=g;
  }
  void pecati()
  {
      cout<<"Ime: "<<ime<<endl;
      cout<<"Reziser: "<<reziser<<endl;
      cout<<"Zanr: "<<zanr<<endl;
      cout<<"Godina: "<<godina<<endl;
  }
  int get_godina()
  {
      return godina;
  }
};

void pecati_po_godina(Film *f, int n, int godina)
{
    for(int i=0;i<n;i++)
    {
        if(f[i].get_godina()==godina)
        {
            f[i].pecati();
        }
    }
}

int main() {
 	int n;
 	cin >> n;
 	Film f[n];
 	for(int i = 0; i < n; ++i) {
 		char ime[100];
 		char reziser[50];
 		char zanr[50];
 		int godina;
 		cin >> ime;
 		cin >> reziser;
 		cin >> zanr;
 		cin >> godina;
 		f[i]=Film(ime,reziser,zanr,godina);
 	}
 	int godina;
 	cin >> godina;
 	pecati_po_godina(f,n,godina);
 	return 0;
 }
