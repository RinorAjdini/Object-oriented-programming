#include<iostream>
#include<cstring>
using namespace std;
class FINKI_Education
{
protected:
    char ISBN[20];
    char naslov[50];
    char avtor[30];
    double cena;
public:
    FINKI_Education(const char *ISBN="",const char *naslov="",const char *avtor="",double cena=0)
    {
        strcpy(this->ISBN,ISBN);
        strcpy(this->naslov,naslov);
        strcpy(this->avtor,avtor);
        this->cena=cena;
    }

    bool operator >(FINKI_Education &f)
    {
        return bookPrice() > f.bookPrice();
    }

    bool operator >(FINKI_Education *f)
    {
        return bookPrice() > f->bookPrice();
    }

    friend ostream&operator<<(ostream &out,FINKI_Education &fe)
    {
        out<<fe.ISBN<<": "<<fe.naslov<<", "<<fe.avtor<<" "<< fe.bookPrice()<<endl;
        return out;
    }

    void setISBN(const char *ISBN)
    {
        strcpy(this->ISBN,ISBN);
    }

    virtual double bookPrice() = 0;
};
class OnlineBook : public FINKI_Education
{
private:
    char *url;
    int golemina;
public:
    OnlineBook(const char *ISBN="",const char *naslov="",const char *avtor="",double cena=0,const char *url="",int golemina=0) : FINKI_Education(ISBN,naslov,avtor,cena)
    {
        this->url = new char [strlen(url)+1];
        strcpy(this->url,url);
        this->golemina=golemina;
    }
    double bookPrice()
    {
        if(golemina > 20)
        {
            return cena*1.2;
        }
        return cena;
    }
};
class PrintedBook : public FINKI_Education
{
private:
    double masa;
    bool zaliha;
public:
    PrintedBook(const char *ISBN="",const char *naslov="",const char *avtor="",double cena=0,double masa=0,bool zaliha=false) : FINKI_Education(ISBN,naslov,avtor,cena)
    {
        this->masa = masa;
        this->zaliha = zaliha;
    }
    double bookPrice()
    {
        if(masa > 0.7)
        {
            return cena*1.15;
        }
        return cena;
    }
};
void mostExpensiveBook(FINKI_Education **books,int n)
{
    int brojacPrinted=0,brojacOnline=0;
    FINKI_Education *temp = books[0];
    for(int i=0;i<n;i++)
    {
        PrintedBook *tmp = dynamic_cast<PrintedBook*>(books[i]);
        if(tmp != 0)
        {
            brojacPrinted++;
        }
        else
        {
            brojacOnline++;
        }
        if(i == 0)
        {
            continue;
        }
        else
        {
            if((*books[i]) > (*temp))
            {
                temp=books[i];
            }
        }
    }
    cout<<"FINKI-Education"<<endl;
    cout<<"Total number of online books: "<<brojacOnline<<endl;
    cout<<"Total number of print books: "<<brojacPrinted<<endl;
    cout<<"The most expensive book is: "<<endl;
    cout<<*temp<<endl;
}
int main ()
{
    char isbn[20], title[50], author[30], url[100];
    int size, tip;
    float price, weight;
    bool inStock;
    FINKI_Education  **books;
    int n;

    int testCase;
    cin >> testCase;

    if (testCase == 1){
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new FINKI_Education *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> url;
            cin >> size;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new OnlineBook(isbn, title, author, price, url, size);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 2){
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price;
        cin >> url;
        cin >> size;
        cout << "CONSTRUCTOR" << endl;
        OnlineBook ob1(isbn, title, author, price, url, size);
        cout << ob1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        OnlineBook ob2(ob1);
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
        cout << "OPERATOR =" << endl;
        ob1 = ob2;
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
    }
    if (testCase == 3){
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new FINKI_Education *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> weight;
            cin >> inStock;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new PrintedBook(isbn, title, author, price, weight, inStock);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 4){
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cin >> n;
        books = new FINKI_Education *[n];

        for (int i = 0; i<n; i++){

            cin >> tip >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            if (tip == 1) {

                cin >> url;
                cin >> size;

                books[i] = new OnlineBook(isbn, title, author, price, url, size);

            }
            else {
                cin >> weight;
                cin >> inStock;

                books[i] = new PrintedBook(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    for (int i = 0; i<n; i++) delete books[i];
        delete[] books;
    return 0;
}
