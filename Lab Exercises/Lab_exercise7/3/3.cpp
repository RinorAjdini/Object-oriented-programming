#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Shape
{
protected:
    int strana;
public:
    Shape()
    {
        strana=0;
    }
    Shape(int strana)
    {
        this->strana=strana;
    }
    virtual double plostina() = 0;
    virtual void pecati() = 0;
    virtual int getType() = 0;
};
class Square : public Shape
{
public:
    Square(int strana) : Shape(strana)
    {
    }
    double plostina()
    {
        return strana*strana;
    }
    void pecati()
    {
        cout<<"Kvadrat so plostina = "<<plostina()<<endl;
    }
    int getType()
    {
        return 1;
    }
};
class Circle : public Shape
{
public:
    Circle(int strana) : Shape(strana)
    {

    }
    double plostina()
    {
        return 3.14*strana*strana;
    }
    void pecati()
    {
        cout<<"Krug so plostina = "<<plostina()<<endl;
    }
    int getType()
    {
        return 2;
    }
};
class Triangle : public Shape
{
public:
    Triangle(int strana=0) : Shape(strana)
    {

    }
    double plostina()
    {
        return (sqrt(3)/4) * strana * strana;
    }
    void pecati()
    {
        cout<<"Triagolnik so plostina = "<<plostina()<<endl;
    }
    int getType()
    {
        return 3;
    }
};
void checkNumTypes(Shape **niza,int n)
{
    int countTriangle=0,countCircle=0,countSquare=0;
    for(int i=0;i<n;i++)
    {
        if(niza[i]->getType() == 1)
        {
            countSquare++;
        }
        else if(niza[i]->getType() == 2)
        {
            countCircle++;
        }
        else if(niza[i]->getType() == 3)
        {
            countTriangle++;
        }
    }
    cout<<"Broj na kvadrati vo nizata = "<<countSquare<<endl;
    cout<<"Broj na krugovi vo nizata = "<<countCircle<<endl;
    cout<<"Broj na triagolnici vo nizata = "<<countTriangle<<endl;
}
int main ()
{
    int n,t,a;
    cin>>n;
    Shape **niza=new Shape*[n];
    for(int i=0;i<n;i++)
    {
        cin>>t>>a;
        if(t == 1)
        {
            niza[i]=new Square(a);
        }
        else if(t == 2)
        {
            niza[i]=new Circle(a);
        }
        else if(t == 3)
        {
            niza[i]=new Triangle(a);
        }
    }
    for(int i=0;i<n;i++)
    {
        niza[i]->pecati();
    }
    checkNumTypes(niza,n);
    delete[]niza;
}
