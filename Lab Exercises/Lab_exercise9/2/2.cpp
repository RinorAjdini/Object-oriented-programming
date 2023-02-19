#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class ArithmeticException
{
public:
    void message()
    {
        cout<<"Division by zero is not allowed"<<endl;
    }
};
class NumbersNotDivisibleException
{
private:
    int number;
public:
    NumbersNotDivisibleException(int number)
    {
        this->number=number;
    }
    void message()
    {
        cout<<"Division by "<<number<<" is not supported"<<endl;
    }
};
class ArrayFullException
{
public:
    void message()
    {
        cout<<"The array is full. Increase the capacity"<<endl;
    }
};
class IndexOutOfBoundsException
{
private:
    int index;
public:
    IndexOutOfBoundsException(int index)
    {
        this->index=index;
    }
    void message()
    {
        cout<<"Index "<<index<<" is out of bounds"<<endl;
    }
};
class NumberIsNotPositiveException
{
private:
    int number;
public:
    NumberIsNotPositiveException(int number)
    {
        this->number = number;
    }
    void message()
    {
        cout<<"Number "<<number<<" is not positive integer"<<endl;
    }
};
class PositiveIntegers
{
private:
    int *niza;
    int broj;
    int maksBroj;

    void copy(const PositiveIntegers &pi)
    {
        broj=pi.broj;
        maksBroj=pi.maksBroj;
        niza = new int[broj];
        for(int i=0;i<broj;i++)
        {
            niza[i]=pi.niza[i];
        }
    }
public:
    PositiveIntegers(int maksBroj=0)
    {
        this->maksBroj=maksBroj;
        broj = 0;
        niza=new int[0];
    }
    PositiveIntegers(const PositiveIntegers &pi)
    {
        copy(pi);
    }
    PositiveIntegers&operator=(const PositiveIntegers &pi)
    {
        if(this!=&pi)
        {
            delete[]niza;
            copy(pi);
        }
        return *this;
    }
    ~PositiveIntegers()
    {
        delete[]niza;
    }
    PositiveIntegers&operator+=(int number)
    {
        if(broj == maksBroj)
        {
            throw(ArrayFullException());
        }
        if(number <= 0)
        {
            throw(NumberIsNotPositiveException(number));
        }
        int *temp = new int[broj+1];
        for(int i=0;i<broj;i++)
        {
            temp[i]=niza[i];
        }
        temp[broj++]=number;
        delete[]niza;
        niza=temp;
        return *this;
    }
    PositiveIntegers operator *(int number)
    {
        PositiveIntegers pi(*this);
        for(int i=0;i<broj;i++)
        {
            pi.niza[i]*=number;
        }
        return pi;
    }
    PositiveIntegers operator /(int number)
    {
        if(number == 0)
        {
            throw ArithmeticException();
        }
        for(int i=0;i<broj;i++)
        {
            if(niza[i]%number != 0)
            {
                throw NumbersNotDivisibleException(number);
            }
        }
        PositiveIntegers pi(*this);
        for(int i=0;i<broj;i++)
        {
            pi.niza[i]/=number;
        }
        return pi;
    }
    int&operator[](int index)
    {
        if(index<0 || index>broj)
        {
            throw(IndexOutOfBoundsException(index));
        }
        return niza[index];
    }
    void increaseCapacity(int c)
    {
        maksBroj+=c;
    }
    void print()
    {
        cout<<"Size: "<<broj<<" Capacity: "<<maksBroj<<" Numbers: ";
        for (int i=0;i<broj;i++)
            cout<<niza[i]<<" ";
        cout<<endl;
    }
};
int main ()
{
int n,capacity;
    cin >> n >> capacity;
    PositiveIntegers pi (capacity);
    for (int i=0;i<n;i++){
        int number;
        cin>>number;
        try{
        pi+=number;
        }
        catch(ArrayFullException &ae)
        {
            ae.message();
        }
        catch(NumberIsNotPositiveException & ne)
        {
            ne.message();
        }

    }
    cout<<"===FIRST ATTEMPT TO ADD NUMBERS==="<<endl;
    pi.print();
    int incCapacity;
    cin>>incCapacity;
    pi.increaseCapacity(incCapacity);
    cout<<"===INCREASING CAPACITY==="<<endl;
    pi.print();

    int n1;
    cin>>n1;
    for (int i=0;i<n1;i++){
        int number;
        cin>>number;
        try{
        pi+=number;
        }
        catch(ArrayFullException &ae)
        {
            ae.message();
        }
        catch(NumberIsNotPositiveException & ne)
        {
            ne.message();
        }
    }
    cout<<"===SECOND ATTEMPT TO ADD NUMBERS==="<<endl;

    pi.print();
    PositiveIntegers pi1;

    cout<<"===TESTING DIVISION==="<<endl;
    try{
    pi1 = pi/0;
    pi1.print();
    }
    catch(ArithmeticException &a)
    {
        a.message();
    }
    catch(NumbersNotDivisibleException &nn)
    {
        nn.message();
    }

    try{
    pi1 = pi/1;
    pi1.print();
    }
    catch(ArithmeticException &a)
    {
        a.message();
    }
    catch(NumbersNotDivisibleException &nn)
    {
        nn.message();
    }

    try{
        pi1 = pi/2;
        pi1.print();
    }
    catch(ArithmeticException &a)
    {
        a.message();
    }
    catch(NumbersNotDivisibleException &nn)
    {
        nn.message();
    }
    cout<<"===TESTING MULTIPLICATION==="<<endl;
    pi1 = pi*3;
    pi1.print();
    cout<<"===TESTING [] ==="<<endl;
    try{
    cout<<"PositiveIntegers[-1] = "<<pi[-1]<<endl;
    }
    catch(IndexOutOfBoundsException &ie)
    {
        ie.message();
    }
    try{
    cout<<"PositiveIntegers[2] = "<<pi[2]<<endl;
    }
    catch(IndexOutOfBoundsException &ie)
    {
        ie.message();
    }
    try{
    cout<<"PositiveIntegers[3] = "<<pi[3]<<endl;
    }
    catch(IndexOutOfBoundsException &ie)
    {
        ie.message();
    }
    try{
    cout<<"PositiveIntegers[12] = "<<pi[12]<<endl;
    }
    catch(IndexOutOfBoundsException &ie)
    {
        ie.message();
    }




    return 0;
}
