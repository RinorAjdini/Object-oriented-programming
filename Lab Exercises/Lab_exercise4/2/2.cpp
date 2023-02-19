#include<iostream>
#include<cstring>
using namespace std;
enum Ekstenzija{txt,pdf,exe};
class File
{
private:
    char *imeNaDatoteka;
    Ekstenzija e;
    char *imeNaSopstvenik;
    int goleminaNaDatoteka;
public:
    File()
    {
        this->imeNaDatoteka=new char[50];
        strcpy(this->imeNaDatoteka,"");

        this->imeNaSopstvenik=new char[50];
        strcpy(this->imeNaSopstvenik,"");

        this->goleminaNaDatoteka=0;

        this->e=(Ekstenzija)0;
    }
    File(char *imeNaDatoteka, char *imeNaSopstvenik, int goleminaNaDatoteka, Ekstenzija e)
    {
       this->imeNaDatoteka=new char[50];
       strcpy(this->imeNaDatoteka,imeNaDatoteka);

       this->imeNaSopstvenik=new char[50];
       strcpy(this->imeNaSopstvenik,imeNaSopstvenik);

       this->goleminaNaDatoteka=goleminaNaDatoteka;

       this->e=e;
    }
    File(const File &file)
    {
        this->imeNaSopstvenik=new char[50];
        strcpy(this->imeNaSopstvenik,file.imeNaSopstvenik);

        this->imeNaDatoteka=new char[50];
        strcpy(this->imeNaDatoteka,file.imeNaDatoteka);

        this->goleminaNaDatoteka=file.goleminaNaDatoteka;

        this->e=file.e;
    }
    ~File()
    {
        delete[]imeNaDatoteka;
        delete[]imeNaSopstvenik;
    }
    File &operator=(const File &f1)
    {
        if(this!=&f1)
        {
            delete[]imeNaDatoteka;
            delete[]imeNaSopstvenik;
            imeNaSopstvenik=new char[50];
            imeNaDatoteka=new char[50];
            strcpy(this->imeNaDatoteka,f1.imeNaDatoteka);
            strcpy(this->imeNaSopstvenik,f1.imeNaSopstvenik);
            goleminaNaDatoteka=f1.goleminaNaDatoteka;
            e=f1.e;
        }
        return *this;
    }
    void print_ekstenzija(Ekstenzija e)
    {
        if(e==0)
        {
            cout<<"pdf";
        }
        else if(e==1)
        {
            cout<<"txt";
        }
        else
        {
            cout<<"exe";
        }
    }
    void print()
    {
        cout<<"File name: "<<imeNaDatoteka<<".";
        print_ekstenzija(e);
        cout<<endl;
        cout<<"File owner: "<<imeNaSopstvenik<<endl;
        cout<<"File size: "<<goleminaNaDatoteka<<endl;
    }
    bool equals(const File &that)
        {
            if(strcmp(this->imeNaDatoteka,that.imeNaDatoteka) == 0 && strcmp(this->imeNaSopstvenik,that.imeNaSopstvenik) == 0 && e==that.e)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool equalsType(const File &that)
        {
            if(strcmp(this->imeNaDatoteka,that.imeNaDatoteka) == 0 && e==that.e)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

class Folder
{
private:
    char *imeNaFolder;
    int brojNaDatoteki;
    File *file;
public:
    Folder()
    {
        this->imeNaFolder=new char[50];
        strcpy(this->imeNaFolder,"");

        this->brojNaDatoteki=0;

        this->file=new File[0];
    }
    Folder(const char* name)
    {
        this->imeNaFolder=new char[50];
        strcpy(this->imeNaFolder,name);

        this->brojNaDatoteki=0;

        this->file=new File[0];

    }
    Folder(const Folder &f1)
    {
        this->brojNaDatoteki=f1.brojNaDatoteki;
        this->imeNaFolder=new char[50];
        strcpy(this->imeNaFolder,f1.imeNaFolder);
        this->file=new File[0];
        for(int i=0;i<f1.brojNaDatoteki;i++)
        {
            file[i]=f1.file[i];
        }
    }
    Folder &operator=(Folder &f1)
    {
        if(this!=&f1)
        {
            delete[]imeNaFolder;
            delete[]file;

            this->brojNaDatoteki=f1.brojNaDatoteki;

            this->imeNaFolder=new char[50];
            strcpy(this->imeNaFolder,f1.imeNaFolder);

            this->file=new File[0];
            for(int i=0;i<f1.brojNaDatoteki;i++)
            {
                file[i]=f1.file[i];
            }
        }
    }
    ~Folder()
    {
        delete[]imeNaFolder;
        delete[]file;
    }
    void add(const File &files)
    {
        File *temp=new File[brojNaDatoteki+1];
        for(int i=0;i<brojNaDatoteki;i++)
        {
            temp[i]=file[i];
        }
        temp[brojNaDatoteki++]=files;
        delete[]file;
        file=temp;
    }
    void remove(const File &files)
    {
        int brojac=0;
        File *temp=new File[brojNaDatoteki-1];
        for(int i=0;i<brojNaDatoteki;i++)
        {
            if(file[i].equals(files) == 1)
            {
                continue;
            }
            else
            {
                temp[brojac++]=file[i];
            }
        }
        delete[]file;
        file=temp;
        brojNaDatoteki-=1;
    }
    void print()
    {
        cout<<"Folder name: "<<imeNaFolder<<endl;
        for(int i=0;i<brojNaDatoteki;i++)
        {
            this->file[i].print();
        }

    }
};
int main ()
{
        char ime[20];
        char sopstvenik[20];
        int ext;
        int golemina;
        int testCase;
        cin>>testCase;
        if(testCase == 1)
        {
            cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
            cin>>ime;
            cin>>sopstvenik;
            cin>>golemina;
            cin>>ext;
            File created=File(ime,sopstvenik,golemina,(Ekstenzija) ext);
            File copied=File(created);
            File assigned=created;
            cout << "======= CREATED =======" << endl;
            created.print();
            cout << endl;
            cout << "======= COPIED =======" << endl;
            copied.print();
            cout << endl;
            cout << "======= ASSIGNED =======" << endl;
            assigned.print();
        }
        else if(testCase == 2)
        {
            cout << "======= FILE EQUALS AND EQUALS TYPE =======" << endl;
            cin>>ime>>sopstvenik>>golemina>>ext;
            File first(ime,sopstvenik,golemina,(Ekstenzija)ext);
            first.print();
            cin>>ime>>sopstvenik>>golemina>>ext;
            File second(ime,sopstvenik,golemina,(Ekstenzija)ext);
            second.print();
            cin>>ime>>sopstvenik>>golemina>>ext;
            File third(ime,sopstvenik,golemina,(Ekstenzija)ext);
            third.print();
            bool equals = first.equals(second);
            cout << "FIRST EQUALS SECOND: ";
            if (equals)
                cout << "TRUE" << endl;
            else
                cout << "FALSE" << endl;

            equals = first.equals(third);
            cout << "FIRST EQUALS THIRD: ";
            if (equals)
                cout << "TRUE" << endl;
            else
                cout << "FALSE" << endl;

            bool equalsType = first.equalsType(second);
            cout << "FIRST EQUALS TYPE SECOND: ";
            if (equalsType)
                cout << "TRUE" << endl;
            else
                cout << "FALSE" << endl;

            equalsType = second.equals(third);
            cout << "SECOND EQUALS TYPE THIRD: ";
            if (equalsType)
                cout << "TRUE" << endl;
            else
                cout << "FALSE" << endl;

        }
        else if(testCase == 3)
        {
            cout << "======= FOLDER CONSTRUCTOR =======" << endl;
            cin>>ime;
            Folder folder(ime);
            folder.print();
        }
        else if(testCase == 4)
        {
            cout << "======= ADD FILE IN FOLDER =======" << endl;
            char name[20];
            cin>>name;
            Folder folder(name);
            int itter;
            cin>>itter;
            while(itter>0)
            {
                cin>>ime>>sopstvenik>>golemina>>ext;
                File file=File(ime,sopstvenik,golemina,(Ekstenzija)ext);
                folder.add(file);
                itter--;
            }
            folder.print();
        }
        else
        {
            cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
            char name[20];
            cin >> name;
            Folder folder(name);

            int iter;
            cin >> iter;

            while (iter > 0) {
                cin >> ime;
                cin >> sopstvenik;
                cin >> golemina;
                cin >> ext;

                File file(ime, sopstvenik, golemina, (Ekstenzija) ext);
                folder.add(file);
                iter--;
            }
                cin >> ime;
                cin >> sopstvenik;
                cin >> golemina;
                cin >> ext;

            File file(ime, sopstvenik, golemina, (Ekstenzija) ext);
            folder.remove(file);
            folder.print();
        }
}
