#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


class Person{
char ime[20];
char prezime[20];
public:
Person()
{}
Person(char *imee,char *prezimee)
{
    strcpy(ime,imee);
    strcpy(prezime,prezimee);
}
void print()
{
    cout<<ime<<" "<<prezime<<endl;
}
};

class Date{
    int year;
    int month;
    int day;
    public:
    void print()
    {
        cout<<year<<"."<<month<<"."<<day<<endl;
    }
    Date()
    {

    }
    Date(int y,int m,int d)
    {
        year=y;
        month=m;
        day=d;
    }
    Date (const Date &date)
    {
        year=date.year;
        month=date.month;
        day=date.day;
    }
};

class Car {
  private:
  Person owner;
  Date d;
  float price;
  public:
  Car(Person p,Date dd, int g)
  {
      owner=p;
      d=dd;
      price=g;
  }
  Car ()
  {

  }
  void print()
  {
      owner.print();
      d.print();
      cout<<"Price: "<<price;
  }
  float get_price()
  {
      return price;
  }
};

void cheaperThan(Car* cars, int numCars, float price)
{
    for(int i=0;i<numCars;i++)
    {
        if(cars[i].get_price()<price)
        {
            cars[i].print();
        }
    }
}

int main() {
	char name[20];
	char lastName[20];
	int year;
	int month;
	int day;
	float price;

	int testCase;
	cin >> testCase;

	if (testCase == 1) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);

		cin >> year;
		cin >> month;
		cin >> day;
		Date date(year, month, day);

		cin >> price;
		Car car(lik, date,  price);

		car.print();
	}
	else if (testCase == 2) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);

		cin >> year;
		cin >> month;
		cin >> day;
		Date date(Date(year, month, day));

		cin >> price;
		Car car(lik, date,  price);
		car.print();
	}
	else {
		int numCars;
		cin >> numCars;

		Car cars[10];
		for (int i = 0; i < numCars; i++) {
			cin >> name;
			cin >> lastName;
			Person lik(name, lastName);

			cin >> year;
			cin >> month;
			cin >> day;
			Date date(year, month, day);

			cin >> price;
			cars[i] = Car(lik, date,  price);
		}
        float priceLimit;
        cin >> priceLimit;
		cheaperThan(cars, numCars, priceLimit);
	}


	return 0;
}
