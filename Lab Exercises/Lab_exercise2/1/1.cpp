#include <iostream>
using namespace std;

class Agol {
    private:
    int stepeni;
    int minuti;
    int sekundi;
    public:
    Agol()
     {

     }
   Agol (int s,int m,int st)
   {
       stepeni=s;
       minuti=m;
       sekundi=st;
   }
   void set_stepeni(int s)
   {
       stepeni=s;
   }
    void set_minuti(int m)
   {
       minuti=m;
   }
   void set_sekundi(int s1)
   {
       sekundi=s1;
   }
   int getSekundi()
   {
       return sekundi;
   }
   int to_sekundi()
   {
       int sek1=(stepeni*3600)+(minuti*60)+sekundi;
       return sek1;
   }
}a1;

int proveri(int a,int b,int c)
{
    if(a>0 && a<360 && b>0 && c>=0)
    return 1;
    else
    cout<<"Nevalidni vrednosti za agol"<<endl;
    return 0;
}

bool changeOfSeconds(Agol a, int sec){
	return a.getSekundi()!=sec;
}

int main() {
    //da se instancira objekt od klasata Agol
    int deg, min, sec;
    cin >> deg >> min >> sec;

    if (proveri(deg, min, sec)) {

    	a1.set_stepeni(deg);
        a1.set_minuti(min);
        a1.set_sekundi(sec);
        cout << a1.to_sekundi();
        if (changeOfSeconds(a1,sec))
			cout << "Ne smeete da gi menuvate sekundite vo ramkite na klasata!" << endl;

    }

    return 0;
}
