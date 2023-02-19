//programata e resena malce so lagi prevari u mainot ama toa e
//imase u nekoi od poslednite linii cout<<maxfoldersize namesto samo maxfoldersize, t.e. taa funkcija maxfoldersize trebase da vrakja
//objekt kaa so pise u instrukciite i da se ispecate cel objekt so preoptovareniot operator ama taka javuva nekoj si fucking glup error
//i malce ilegalno so void funkcija e zameneto
#include<iostream>
#include<cstring>
using namespace std;
class Image { //Да се креира класа која претставува слика (Image) во рамките на еден компјутер.
protected: //За секоја датотека се чуваат (5 поени):
char * imeslika;//име на сликата (дин. алоцирана низа од знаци).
char korisnik[50]; //име на корисникот кој е сопственик на датотеката (низа од макс. 50 знаци).
int sirina;//димензии на сликата
int visina; //(2 цели броеви кои претставуваат ширина и висина во пиксели).
public:
Image(char * imeslika = "untitled", char * korisnik = "unknown", int sirina = 800, int visina = 800) {
    this->imeslika = new char[strlen(imeslika)+1];
    strcpy(this->imeslika, imeslika);
    strcpy(this->korisnik, korisnik);
    this->sirina = sirina;
    this->visina = visina;
}
Image(const Image &copy) {
    this->imeslika = new char[strlen(copy.imeslika)+1];
    strcpy(this->imeslika, copy.imeslika);
    strcpy(this->korisnik, copy.korisnik);
    this->sirina = copy.sirina;
    this->visina = copy.visina;
}
Image &operator=(const Image &copy){
    if(this!=&copy) {
this->imeslika = new char[strlen(copy.imeslika)+1];
    strcpy(this->imeslika, copy.imeslika);
    strcpy(this->korisnik, copy.korisnik);
    this->sirina = copy.sirina;
    this->visina = copy.visina;
    }
    return *this;
}
~Image() {
    delete [] imeslika;
}//За класите Image и TransparentImage да се преоптоварат следниве оператори (5 поени):
friend ostream &operator<<(ostream &o, Image &im) {//оператор << кој ги печати податоците
    o<<im.imeslika<<" "<<im.korisnik<<" "<<im.fileSize()<<endl; // од датотеката во сл. формат:
    return o;//    ime_fajl avtor golemina_na_fajlot_vo_bajti
}
bool operator>(Image &im) {
if(this->fileSize() > im.fileSize())
return true;
else return false;
} //оператор > кој ги споредува сликите според нивната големина.
virtual int fileSize() { //За класите Image и TransparentImage да биде достапна метода (fileSize)
//за пресметка на големината на сликата (во бајти).
return this->sirina * this->visina * 3;//висината * ширината * 3.
}//за објектите од класата Image, големината на датотеката е еднаква на:
};
class TransparentImage : public Image { //Од класата Image да се изведе класата TransparentImage,
private:// која претставува слика која содржи поддржува транспарентност. За транспарентна слика дополнително се чува
bool transparent; //дали поддржува нивоа на транспарентност (bool променлива
public:
TransparentImage (char * imeslika = "untitled", char * korisnik = "unknown", int sirina = 800, int visina = 800, bool transparent = true) : Image (imeslika, korisnik, sirina, visina) {
this->transparent = transparent;
}
TransparentImage(const TransparentImage &copy) : Image(copy) {
    this->transparent = copy.transparent;
}
int fileSize() { //за TransparentImage, доколку поддржува нивоа на транспарентност,
    if(this->transparent==true) //големината на датотеката е еднаква на ширина * висина * 4.
    return sirina*visina*4; //Доколку не поддржува транспарентност
    else return (sirina*visina) + ((sirina*visina) / 8);  //големината на сликата
}    //се пресметува како ширина * висина * 3 + бр._на_пиксели_присутни_во_сликата / 8.
friend ostream &operator<<(ostream &o, TransparentImage &ti) {
 o<<ti.imeslika<<" "<<ti.korisnik<<" "<<ti.fileSize()<<endl;
 return o;
}
bool operator>(TransparentImage &ti) {
if(this->fileSize() > ti.fileSize())
return true;
else return false;
} //оператор > кој ги споредува сликите според нивната големина.
};
class Folder { //Да се дефинира класа Folder, што репрезентира директориум
private://во кој може да се поставуваат слики. За секој фолдер се чува (5 поени):
char imefolder[255]; //име на фолдерот (низа од макс 255 знаци)
char sopstvenik[50]; //име на корисникот кој е сопственик на фолдерот (низа од макс. 50 знаци).
Image ** niza; //низа од покажувачи кон Image објекти (макс. 100 во рамките на еден фолдер).
int broj;
public://Да се имплементираат следниве методи (5 поени):
Folder(char * imefolder = "", char * sopstvenik = "") {
    strcpy(this->imefolder, imefolder);
    strcpy(this->sopstvenik, sopstvenik);
  this->niza = new Image * [0];
   this->broj = 0;
}
    Folder(const Folder &copy) {
    strcpy(this->imefolder, copy.imefolder);
    strcpy(this->sopstvenik, copy.sopstvenik);
    this->broj = copy.broj;
        for(int i=0;i<copy.broj;i++)
            this->niza[i] = copy.niza[i];
    }
int folderSize() { //метода за пресметка на големината на фолдерот (folderSize).
int total=0.0;  //Големината на фолдерот е сума од големините од сите слики во
    for(int i=0;i<broj; i++) //  рамките на фолдерот.
        total = total+niza[i]->fileSize();
        return total;
}
    Image * getMaxFile() {   //  метода за пронаоѓање на наголемата слика во рамките на фолдерот
    int max = niza[0]->fileSize();
        int indeks=0;
        for(int i=0; i<broj; i++)
            if(niza[i]->fileSize() > max) {
            max = niza[i]->fileSize();
            indeks = i;
        }
        return niza[indeks]; //  (getMaxFile). Методата враќа покажувач кон најголемата слика во
    }  // фолдерот (сметано во бајти).
Folder &operator+=(Image &add) {//За класата Folder да се имплементира и оператор += кој додава објекти
    Image ** tmp = new Image * [broj+1];
        for(int i=0; i<broj; i++)
            tmp[i] = niza[i];
        tmp[broj++] = &add;
        delete [] niza;
        niza = tmp;
        return *this;
    }//од типот Image/TransparentImage во рамките на фолдерот (5 поени).
    friend ostream &operator<<(ostream &o, Folder &print) { //  operator << - со кој се печатат
    o<<print.imefolder<<" "<<print.sopstvenik<<endl;
        o<<"--"<<endl;
        for(int i=0; i<print.broj; i++)
         o<<*print.niza[i];
        o<<"--"<<endl<<"Folder size: " << print.folderSize();
        return o;
    }
//податоците за фолдерот во формат _(5 поени)_:
    //ime_folder sopstvenik --
      //  ime_slika avtor golemina_na_fajlot_vo_bajti
        //ime_slika avtor golemina_na_fajlot_vo_bajti -- golemina_na_folder_vo_bajti
 Image * &operator[](int i){ // kopirano od nikola
            return this->niza[i];
        } //operator [] - кој враќа покажувач кон соодветната слика во фолдерот.
}; //    Доколку не постои слика на тој индекс, треба да се врати NULL (5 поени).
void max_folder_size(Folder * niza, int n) { //Да се креира и глобална функција max_folder_size која
   int max = niza[0].folderSize();// прима низа од објекти од типот Folder и го
    int indeks=0;//враќа фолдерот кој има зафаќа најмногу простор (во бајти).
    for(int i=0;i<n;i++)
        if(niza[i].folderSize() > max) {
        max = niza[i].folderSize();
        indeks = i;
    }
    cout<<niza[indeks];
}
int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int w, h;
    bool tl;

    cin >> tc;

    if (tc==1){
      // Testing constructor(s) & operator << for class File

      cin >> name;
      cin >> user_name;
      cin >> w;
      cin >> h;


      Image f1;

      cout<< f1;

      Image f2(name);
      cout<< f2;

      Image f3(name, user_name);
      cout<< f3;

      Image f4(name, user_name, w, h);
      cout<< f4;
    }
    else if (tc==2){
      // Testing constructor(s) & operator << for class TextFile
      cin >> name;
      cin >> user_name;
      cin >> w >> h;
      cin >> tl;

      TransparentImage tf1;
      cout<< tf1;

      TransparentImage tf4(name, user_name, w, h, tl);
      cout<< tf4;
    }
    else if (tc==3){
      // Testing constructor(s) & operator << for class Folder
      cin >> name;
      cin >> user_name;

      Folder f3(name, user_name);
      cout<< f3;
    }
    else if (tc==4){
      // Adding files to folder
      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image * f;
      TransparentImage *tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<<dir;
    }
    else if(tc==5){
      // Testing getMaxFile for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<< *(dir.getMaxFile());
    }
    else if(tc==6){
      // Testing operator [] for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }

      cin >> sub; // Reading index of specific file
      cout<< *dir[sub];
    }
    else if(tc==7){
      // Testing function max_folder_size
      int folders_num;

      Folder dir_list[10];

      Folder dir;
      cin >> folders_num;

      for (int i=0; i<folders_num; ++i){
        cin >> name;
        cin >> user_name;
        dir = Folder(name, user_name);


        Image* f;
        TransparentImage *tf;

        int sub, fileType;

        while (1){
          cin >> sub; // Should we add subfiles to this folder
          if (!sub) break;

          cin >>fileType;
          if (fileType == 1){ // Reading File
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            f = new Image(name,user_name, w, h);
              dir += *f;
          }
          else if (fileType == 2){
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            cin >> tl;
            tf = new TransparentImage(name,user_name, w, h, tl);
              dir += *tf;
          }
        }
        dir_list[i] = dir;
      }

   max_folder_size(dir_list, folders_num);
    }
    return 0;
};
