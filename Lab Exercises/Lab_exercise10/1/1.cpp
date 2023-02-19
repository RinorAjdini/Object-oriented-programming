#include<iostream>
#include<cmath>
using namespace std;
template <typename T>
class Array
{
private:
    T *p;
    int broj;
public:
    Array<T>(int broj)
    {
        this->broj=broj;
        p = new T[this->broj];
    }
    void Erase()
    {
        delete[]p;
    }
    T &operator[](int i)
    {
        if(i>=0 && i < broj)
        {
            return p[i];
        }
    }
    int GetLength()
    {
        return broj;
    }
    friend ostream&operator <<(ostream &out,const Array<T> &a)
    {
        for(int i=0;i<a.broj;i++)
        {
            if(i==a.broj-1)
            {
                out<<"Array["<<i<<"] = "<<a.p[i]<<endl;
            }
            else
            {
                out<<"Array["<<i<<"] = "<<a.p[i]<<", ";
            }
        }
        return out;
    }
};
template <typename T>
void BubbleSort(Array<T> &t)
{
    T temp;
    for(int i=0;i<t.GetLength()-1;i++)
    {
        for(int j=i+1;j<t.GetLength();j++)
        {
            if(t[i] > t[j])
            {
                temp=t[i];
                t[i]=t[j];
                t[j]=temp;
            }
        }
    }
}
template <typename T>
T Sum(Array<T> &t)
{
    T vkupno=0;
    for(int i=0;i<t.GetLength();i++)
    {
        vkupno+=t[i];
    }
    return vkupno;
}

template <typename T>
double Average(Array<T> &t)
{
    return Sum(t)/t.GetLength();
}
template <typename T,typename M>
bool Equal(Array<T> &t, Array<M> &m)
{
    if(t.GetLength() != m.GetLength())
        return false;
    for(int i=0;i<t.GetLength();i++)
    {
        if(t[i] != m[i])
        {
            return false;
        }
    }
    return true;
}
template <typename T>
bool Equal(Array<T> &t, Array<double> &m)
{
    bool flag;
    if(t.GetLength() != m.GetLength())
        return false;
    for(int i=0;i<t.GetLength();i++)
    {
        if(abs(t[i]-m[i])<0.1)
        {
            flag=true;
        }
        else
        {
            return false;
        }
    }
    if(abs(Average(t) - Average(m)) < 0.5 && flag == true)
    {
        return true;
    }
    return false;
}
int main ()
{
  int n;
  double r;

  cin>>r;
  cin>>n;

  Array<int> anArray(n);
  Array<double> adArray(n);
  Array<int> intArray2(n);

  for (int nCount = 0; nCount < n; nCount++)
  {

      cin>>anArray[nCount];
      adArray[nCount] = anArray[nCount] + r;
  }

  BubbleSort(anArray);

  intArray2 = anArray;

  cout<<"The arrays: "<<endl;
  cout<<anArray;
  cout<<"and "<<endl;
  cout<<intArray2;
  cout<<((Equal(anArray,intArray2))?" ARE":" ARE NOT")<<" same!"<<endl;
  cout<<"The Average of the array adArray is: "<<Average(adArray)<<endl;

  cout<<"The arrays: "<<endl;
  cout<<anArray;
  cout<<"and "<<endl;
  cout<<adArray;
  cout<<((Equal(anArray,adArray))?" ARE":" ARE NOT")<<" same!";


return 0;
}
