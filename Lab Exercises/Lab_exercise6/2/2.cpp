#include<iostream>
#include<cstring>
using namespace std;
class Kvadrat
{
protected:
    double strana;
public:
    Kvadrat(double strana=0)
    {
        this->strana=strana;
    }
    Kvadrat(const Kvadrat &k)
    {
        strana=k.strana;
    }
    double perimetar()
    {
        return 4*strana;
    }
    double plostina()
    {
        return strana*strana;
    }
    void pecati()
    {
        cout<<"Kvadrat so dolzina a="<<strana<<" ima plostina P="<<plostina()<<" i perimetar L="<<perimetar()<<endl;
    }
};
class Pravoagolnik : public Kvadrat
{
private:
    double x;
    double y;
public:
    Pravoagolnik(double a=0,double x=0,double y=0) : Kvadrat(a)
    {
        this->x=x;
        this->y=y;
    }
    Pravoagolnik(const Kvadrat &k, double x, double y) : Kvadrat(k)
    {
        this->x=x;
        this->y=y;
    }
    Pravoagolnik(const Pravoagolnik &p) : Kvadrat(p)
    {
        x=p.x;
        y=p.y;
    }
    double perimetar()
    {
        if(x==y)
        {
            strana=strana+x;
            return Kvadrat::perimetar();
        }
        else
        {
            return (2*(strana+x) + 2*(strana+y));
        }
    }
    double plostina()
    {
        if(x==y)
        {
            strana=strana+x;
            return Kvadrat::plostina();
        }
        else
        {
            return ((strana+x)*(strana+y));
        }
    }
    void pecati()
    {
        if(x==y)
        {
            strana=strana+x;
            Kvadrat::pecati();
        }
        else
        {
            cout<<"Pravoagolnik so strani: "<<strana+x<<" i "<<strana+y<<" ima plostina P="<<plostina()<<" i perimetar L="<<perimetar()<<endl;
        }
    }
};
int main ()
{
int n;
    double a,x,y;
    Kvadrat * kvadrati;
    Pravoagolnik * pravoagolnici;

    cin>>n;

    kvadrati = new Kvadrat [n];
    pravoagolnici = new Pravoagolnik [n];

    for (int i=0;i<n;i++){
        cin>>a;

        kvadrati[i] = Kvadrat(a);
    }

    for (int i=0;i<n;i++){
        cin>>x>>y;

        pravoagolnici[i]=Pravoagolnik(kvadrati[i],x,y);
    }

    int testCase;
    cin>>testCase;

    if (testCase==1){
        cout<<"===Testiranje na klasata Kvadrat==="<<endl;
        for (int i=0;i<n;i++)
            kvadrati[i].pecati();
    }
    else {
        cout<<"===Testiranje na klasata Pravoagolnik==="<<endl;
        for (int i=0;i<n;i++)
            pravoagolnici[i].pecati();
    }
}
