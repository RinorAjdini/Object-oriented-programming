#include <cstring>
#include <iostream>
using namespace std;

// Your Code goes here
enum Size{small=0,large=2,family=3};
class Pizza{
protected:
    char ime[21];
    char sostojki[101];
    double osnovna_cena;
public:
    Pizza(const char *ime="",const char *sostojki="",double osnovna_cena=0)
    {
        strcpy(this->ime,ime);
        strcpy(this->sostojki,sostojki);
        this->osnovna_cena=osnovna_cena;
    }
    virtual double price() = 0;
    bool operator<(Pizza &p)
    {
        if(price()<p.price())
            return 1;
        return 0;
    }
};

class FlatPizza :public Pizza{
private:
    Size g;
public:
    FlatPizza(const char *ime="",const char *sostojki="",double osnovna_cena=0,Size g = (Size)0)
    :Pizza(ime,sostojki,osnovna_cena)
    {
        this->g=(Size)g;
    }
    double price()
    {
        if(g==0)
            return 1.1*osnovna_cena;
        else if(g==2)
            return 1.3*osnovna_cena;
        return 1.5*osnovna_cena;
    }
    friend ostream& operator<<(ostream&o,FlatPizza &fp)
    {
        o<<fp.ime<<": "<<fp.sostojki<<", ";
        if(fp.g==0)
            o<<"small - ";
        else if(fp.g==1)
            o<<"large - ";
        else
            o<<"family - ";
        o<<fp.price()<<endl;
        return o;
    }
};
class FoldedPizza:public Pizza{
private:
    bool dali;
public:
    FoldedPizza(const char *ime="",const char *sostojki="",double osnovna_cena=0,bool dali=true)
    :Pizza(ime,sostojki,osnovna_cena)
    {
        this->dali=dali;
    }
     double price()
     {
         if(dali==true)
            return 1.1*osnovna_cena;
         return 1.3*osnovna_cena;
     }
     void setWhiteFlour(bool t)
     {
         this->dali=t;
     }
     friend ostream& operator<<(ostream&o,FoldedPizza &fp)
     {
         o<<fp.ime<<": "<<fp.sostojki<<", ";
         if(fp.dali==true)
            o<<"wf - "<<fp.price()<<endl;
         else
            o<<"nwf - "<<fp.price()<<endl;

         return o;
     }
};

void expensivePizza(Pizza **pizza, int n)
{
    double suma=pizza[0]->price();
    int index=0;
    for(int i=1;i<n;i++)
    {
        if(pizza[i]->price()>suma)
        {
            suma=pizza[i]->price();
            index = i;
        }
    }
    FlatPizza *tmp = dynamic_cast<FlatPizza*>(pizza[index]);
    if(tmp!=0)
        cout<<*tmp;
    else
    {
        FoldedPizza *tmp1 = dynamic_cast <FoldedPizza*>(pizza[index]);
        if(tmp1!=0)
        cout<<*tmp1;
    }
}
// Testing

int main() {
  int test_case;
  char name[20];
  char ingredients[100];
  float inPrice;
  Size size;
  bool whiteFlour;

  cin >> test_case;
  if (test_case == 1) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FlatPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 2) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    int s;
    cin>>s;
    FlatPizza fp(name, ingredients, inPrice, (Size)s);
    cout << fp;

  } else if (test_case == 3) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 4) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    fp.setWhiteFlour(false);
    cout << fp;

  } else if (test_case == 5) {
	// Test Cast - operator <, price
    int s;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp1;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp2;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
    cout << *fp3;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
    fp4->setWhiteFlour(false);
    cout << *fp4;

    cout<<"Lower price: "<<endl;
    if(*fp1<*fp2)
        cout<<fp1->price()<<endl;
    else cout<<fp2->price()<<endl;

    if(*fp1<*fp3)
        cout<<fp1->price()<<endl;
    else cout<<fp3->price()<<endl;

    if(*fp4<*fp2)
        cout<<fp4->price()<<endl;
    else cout<<fp2->price()<<endl;

    if(*fp3<*fp4)
        cout<<fp3->price()<<endl;
    else cout<<fp4->price()<<endl;

  } else if (test_case == 6) {
	// Test Cast - expensivePizza
    int num_p;
    int pizza_type;

    cin >> num_p;
    Pizza **pi = new Pizza *[num_p];
    for (int j = 0; j < num_p; ++j) {

      cin >> pizza_type;
      if (pizza_type == 1) {
        cin.get();
        cin.getline(name,20);

        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << (*fp);
        pi[j] = fp;
      }
      if (pizza_type == 2) {

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp =
            new FoldedPizza (name, ingredients, inPrice);
        if(j%2)
          (*fp).setWhiteFlour(false);
        cout << (*fp);
        pi[j] = fp;

      }
    }

    cout << endl;
    cout << "The most expensive pizza:\n";
    expensivePizza(pi,num_p);


  }
  return 0;
}
