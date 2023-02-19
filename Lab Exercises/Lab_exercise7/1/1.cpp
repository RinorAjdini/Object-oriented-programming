#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Employee
{
protected:
    char ime[50];
    int godini;
    int rabotnoIskustvo;
public:
    Employee(const char *ime="",int godini=0,int rabotnoIskustvo=0)
    {
        strcpy(this->ime,ime);
        this->godini=godini;
        this->rabotnoIskustvo=rabotnoIskustvo;
    }
    virtual double plata() = 0;
    virtual double bonus() = 0;
    bool operator==(Employee &e)
    {
        return (godini == e.godini && bonus() == e.bonus());
    }
};
class FreeLancer : public Employee
{
private:
    int brojNaProekti;
    double proekti[15];
public:
    FreeLancer(const char *ime="",int godini=0,int rabotnoIskustvo=0,int brojNaProekti=0,double *proekti=0) : Employee(ime,godini,rabotnoIskustvo)
    {
        this->brojNaProekti=brojNaProekti;
        for(int i=0;i<brojNaProekti;i++)
        {
            this->proekti[i]=proekti[i];
        }
    }
    double bonus()
    {
        if(brojNaProekti>5)
            return (brojNaProekti-5)*1000;
        return 0;
    }
    double plata()
    {
        double total=0;
        for(int i=0;i<brojNaProekti;i++)
        {
            total+=proekti[i];
        }
        return total+bonus();
    }
};
class SalaryEmployee : public Employee
{
private:
    int osnovnaPlata;
public:
    SalaryEmployee(const char *ime="",int godini=0,int rabotnoIskustvo=0,int osnovnaPlata=0) : Employee(ime,godini,rabotnoIskustvo)
    {
        this->osnovnaPlata=osnovnaPlata;
    }
    double bonus()
    {
        return (rabotnoIskustvo*osnovnaPlata)/100;
    }
    double plata()
    {
        return osnovnaPlata+bonus();
    }
};
class HourlyEmployee : public Employee
{
private:
    int vkupniCasovi;
    int plataPoCas;
public:
    HourlyEmployee(const char *ime="",int godini=0,int rabotnoIskustvo=0,int vkupniCasovi=0,int plataPoCas=0) : Employee(ime,godini,rabotnoIskustvo)
    {
        this->vkupniCasovi=vkupniCasovi;
        this->plataPoCas=plataPoCas;
    }
    double bonus()
    {
        if(vkupniCasovi > 320)
        {
            return (vkupniCasovi-320)*0.5*plataPoCas;
        }
        return 0;
    }
    double plata()
    {
        return vkupniCasovi*plataPoCas + bonus();
    }
};

class Company
{
private:
    char ime[50];
    int brojNaVraboteni;
    Employee **niza;

public:
    Company(const char *ime="")
    {
        strcpy(this->ime,ime);
        brojNaVraboteni=0;
        niza=new Employee*[0];
    }
    ~Company()
    {
        delete[]niza;
    }
    Company&operator+=(Employee *e)
    {
        Employee **temp=new Employee*[brojNaVraboteni+1];
        for(int i=0;i<brojNaVraboteni;i++)
        {
            temp[i]=niza[i];
        }
        temp[brojNaVraboteni++]=e;
        delete[]niza;
        niza=temp;
        return *this;
    }
    double vkupnaPlata()
    {
        double total=0;
        for(int i=0;i<brojNaVraboteni;i++)
        {
            total+=niza[i]->plata();
        }
        return total;
    }
    double filtriranaPlata(Employee *emp)
    {
        double total=0;
        for(int i=0;i<brojNaVraboteni;i++)
        {
            if(*niza[i] == *emp)
            {
                total+=niza[i]->plata();
            }
        }
        return total;
    }
    void pecatiRabotnici()
    {
        int countSalary=0,countHourly=0,countFree=0;
        cout<<"Vo kompanijata "<<ime<< " rabotat:"<<endl;
        for(int i=0;i<brojNaVraboteni;i++)
        {
            SalaryEmployee *se = dynamic_cast<SalaryEmployee *>(niza[i]);
            if(se != 0)
            {
                countSalary++;
                continue;
            }
            HourlyEmployee *he = dynamic_cast<HourlyEmployee *>(niza[i]);
            if(he != 0)
            {
                countHourly++;
                continue;
            }
            FreeLancer *fl=dynamic_cast<FreeLancer*>(niza[i]);
            if(fl != 0)
            {
                countFree++;
                continue;
            }

        }
        cout<<"Salary employees: "<<countSalary<<endl;
        cout<<"Hourly employees: "<<countHourly<<endl;
        cout<<"Freelancers: "<<countFree<<endl;
    }
};
int main ()
{
char name[50];
cin >> name;
Company c(name);

int n;
cin >> n;

char employeeName[50];
int age;
int experience;
int type;

for (int i=0; i <n; ++i) {
  cin >> type;
  cin >> employeeName >> age >> experience;

  if (type == 1) {
    int basicSalary;
    cin >> basicSalary;
    c += new SalaryEmployee(employeeName, age, experience, basicSalary);
  }

  else if (type == 2) {
    int hoursWorked;
    int hourlyPay;
    cin >> hoursWorked >> hourlyPay;
    c += new HourlyEmployee(employeeName, age, experience, hoursWorked, hourlyPay);
  }

  else {
    int numProjects;
    cin >> numProjects;
    double projects[10];
    for (int i=0; i < numProjects; ++i) {
      cin >> projects[i];
    }
    c += new FreeLancer(employeeName, age, experience, numProjects, projects);
  }
}

c.pecatiRabotnici();
cout << "Vkupnata plata e: " << c.vkupnaPlata() << endl;
Employee * emp = new HourlyEmployee("Petre_Petrov",31,6,340,80);
cout << "Filtriranata plata e: " << c.filtriranaPlata(emp);

delete emp;
}
