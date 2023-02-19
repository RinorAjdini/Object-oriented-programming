#include<iostream>
#include<cstring>
using namespace std;
class Number
{
    public:
        virtual double doubleValue() = 0;
        virtual int intValue() = 0;
        virtual void print()= 0;
};
bool operator ==(Number *n1,Number &n2)
{
    if(n1->doubleValue() == n2.doubleValue() && n1->intValue() == n2.intValue())
        return true;
    else
        return false;
}
class Integer : public Number
{
private:
    int broj;
public:
    Integer(int broj)
    {
        this->broj=broj;
    }
    double doubleValue()
    {
        return (double)broj;
    }
    int intValue()
    {
        return broj;
    }
    void print()
    {
        cout<<"Integer: "<<broj<<endl;
    }
};
class Double : public Number
{
private:
    double broj;
public:
    Double(double broj)
    {
        this->broj=broj;
    }
    double doubleValue()
    {
        return broj;
    }
    int intValue()
    {
        return (int)broj;
    }
    void print()
    {
        cout<<"Double: "<<broj<<endl;
    }
};
class Numbers
{
private:
    Number **niza;
    int broj;

    void copy(const Numbers &n)
    {
        this->broj=n.broj;
        this->niza=new Number*[broj];
        for(int i=0;i<broj;i++)
        {
            niza[i]=n.niza[i];
        }
    }
public:
    Numbers()
    {
        broj=0;
        niza=new Number*[0];
    }
    Numbers(const Numbers &n)
    {
        copy(n);
    }
    Numbers&operator=(const Numbers &n)
    {
        if(this!=&n)
        {
            delete[]niza;
            copy(n);
        }
        return *this;
    }
    ~Numbers()
    {
        delete[]niza;
    }
    Numbers&operator+=(Number *num)
    {
        for(int i=0;i<broj;i++)
        {
            if(niza[i] == *num)
                return *this;
        }
        Number **temp=new Number*[broj+1];
        for(int i=0;i<broj;i++)
        {
            temp[i]=niza[i];
        }
        temp[broj++]=num;
        delete[]niza;
        niza=temp;
        return *this;
    }
    void statistics()
    {
        double suma=0;
        for(int i=0;i<broj;i++)
        {
            suma+=niza[i]->doubleValue();
        }
        int countOfInteger=0,countOfDouble=0,sumInt=0;
        double sumDouble=0;
        for(int i=0;i<broj;i++)
        {
            Integer *in=dynamic_cast<Integer *>(niza[i]);
            if(in != 0)
            {
                countOfInteger++;
                sumInt+=niza[i]->intValue();
            }
            Double *d=dynamic_cast<Double *>(niza[i]);
            if(d != 0)
            {
                countOfDouble++;
                sumDouble+=niza[i]->doubleValue();
            }
        }
        cout<<"Count of numbers: "<<this->broj<<endl;
        cout<<"Sum of all numbers: "<<suma<<endl;
        cout<<"Count of integer numbers: "<<countOfInteger<<endl;
        cout<<"Sum of integer numbers: "<<sumInt<<endl;
        cout<<"Count of double numbers: "<<countOfDouble<<endl;
        cout<<"Sum of double numbers: "<<sumDouble<<endl;
    }
    void integersLessThan(Integer n)
    {
        int count=0;
        int max=n.intValue();
        for(int i=0;i<broj;i++)
        {
            Integer *in=dynamic_cast<Integer *>(niza[i]);
            if(in)
            {
                if(niza[i]->intValue() < max)
                {
                    niza[i]->print();
                    count++;
                }
            }
        }
        if(count == 0)
            cout<<"None"<<endl;
    }
    void doublesBiggerThan(Double n)
    {
        int count=0;
        int min=n.doubleValue();
        for(int i=0;i<broj;i++)
        {
            Double *d=dynamic_cast<Double *>(niza[i]);
            if(d)
            {
                if(niza[i]->doubleValue()>min)
                {
                    niza[i]->print();
                    count++;
                }
            }
        }
        if(count == 0)
        {
            cout<<"None"<<endl;
        }
    }
};
int main ()
{
int n;
    cin>>n;
    Numbers numbers;
    for (int i=0;i<n;i++){
        int type;
        double number;
        cin>>type>>number;
        if (type==0){//Integer object
            Integer * integer = new Integer((int) number);
            numbers+=integer;
        }
        else {
            Double * doublee = new Double(number);
            numbers+=doublee;
        }
    }

    int lessThan;
    double biggerThan;

    cin>>lessThan;
    cin>>biggerThan;

    cout<<"STATISTICS FOR THE NUMBERS\n";
    numbers.statistics();
    cout<<"INTEGER NUMBERS LESS THAN "<<lessThan<<endl;
    numbers.integersLessThan(Integer(lessThan));
    cout<<"DOUBLE NUMBERS BIGGER THAN "<<biggerThan<<endl;
    numbers.doublesBiggerThan(Double(biggerThan));
}
