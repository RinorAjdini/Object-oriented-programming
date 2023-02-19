#include <iostream>
using namespace std;

class Krug {
    float r;
    const float pi=3.14;
    public:
    Krug()
    {

    }
    Krug(float r1)
    {
        r=r1;
    }
    float plostina ()
    {
        return r*r*pi;
    }
    float perimetar()
    {
        return 2*r*pi;
    }
    bool ednakvi()
    {
        if(r*r*pi==2*r*pi)
        return 1;
        else
        return 0;
    }
};


int main() {
	float r;
	cin >> r;
	Krug k = Krug(r);
	//instanciraj objekt od klasata Krug cij radius e vrednosta procitana od tastatura
	cout << k.perimetar() << endl;
	cout << k.plostina() << endl;
	cout << k.ednakvi() <<endl;
    //instanciraj objekt od klasata Krug cij radius ne e definiran
	return 0;
}
