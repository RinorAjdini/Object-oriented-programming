#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class ExistingGame
{
private:
    char ime[100];
public:
    ExistingGame(const char *ime="")
    {
        strcpy(this->ime,ime);
    }
    void message()
    {
        cout<<"The game is already in the collection"<<endl;
    }
};
class Game
{
protected:
    char ime[100];
    double cena;
    bool rasprodazba;
public:
    Game(const char *ime="",double cena=0,bool rasprodazba=false)
    {
        strcpy(this->ime,ime);
        this->cena=cena;
        this->rasprodazba=rasprodazba;
    }
    friend ostream&operator<<(ostream &out,Game &g)
    {
        out<<"Game: "<<g.ime<<", regular price: $"<<g.cena;
        if(g.rasprodazba == 1)
        {
            out<<", bought on sale"<<endl;
        }
        return out;
    }
    char *getIme()
    {
        return ime;
    }
    double getCena()
    {
        return cena;
    }
    bool getRasprodazba()
    {
        return rasprodazba;
    }
    friend istream&operator>>(istream &in,Game &g)
    {
        in.get();
        in.getline(g.ime,100);
        in>>g.cena>>g.rasprodazba;
        return in;
    }
    bool operator == (Game &g)
    {
        return strcmp(ime,g.ime);
    }
    virtual double getPrice()
    {
        if(rasprodazba == true)
        {
            return cena*0.3;
        }
        return cena*1.0;
    }
};
class SubscriptionGame : public Game
{
private:
    double mesecen;
    int mesec;
    int godina;
public:
    SubscriptionGame(const char *ime="",double cena=0,bool rasprodazba=false,double mesecen=0,int mesec=0,int godina=0) : Game(ime,cena,rasprodazba)
    {
        this->mesecen=mesecen;
        this->mesec=mesec;
        this->godina=godina;
    }
    friend ostream&operator<<(ostream &out,SubscriptionGame &sg)
    {
        out<<"Game: "<<sg.ime<<", regular price: $"<<sg.cena;
        if(sg.rasprodazba == true)
        {
            out<<", bought on sale";
        }
        out<<", monthly fee: $"<<sg.mesecen<<", purchased: "<<sg.mesec<<"-"<<sg.godina<<endl;
        return out;
    }
    double getMesecen()
    {
        return mesecen;
    }
    double getMesec()
    {
        return mesec;
    }
    int getGodina()
    {
        return godina;
    }
    friend istream&operator>>(istream &in,SubscriptionGame &sg)
    {
        in.get();
        in.getline(sg.ime,100);
        in>>sg.cena>>sg.rasprodazba>>sg.mesecen>>sg.mesec>>sg.godina;
        return in;
    }
    double getPrice()
    {
        if(2018 == godina)
        {
            int tempMesec = mesec;
            int brojac=0;
            while(tempMesec < 5)
            {
                brojac++;
                tempMesec++;
            }
            return (brojac*mesecen) + cena;
        }
        else
        {
            int brojac=1;
            int tempMesec=mesec;
            int tempGodina=godina;
            while(tempMesec<=12)
            {
                if(tempMesec == 12)
                {
                    tempGodina+=1;
                    if(tempGodina != 2018)
                    {
                        tempMesec=1;
                    }
                    else
                    {
                        tempMesec=1;
                        while(tempMesec<5)
                        {
                            brojac++;
                            tempMesec++;
                        }
                        return (brojac*mesecen) + cena;
                    }
                }
                brojac++;
                tempMesec++;
            }
        }
    }
};
class User
{
private:
    char ime[100];
    Game **niza;
    int broj;

    void copy(const User &u)
    {
        strcpy(ime,u.ime);
        broj=u.broj;
        niza = new Game*[broj];
        for(int i=0;i<broj;i++)
        {
            niza[i]=u.niza[i];
        }
    }
public:
    User(const char *ime="")
    {
        strcpy(this->ime,ime);
        niza=new Game*[0];
        broj=0;
    }
    User(const User &u)
    {
        copy(u);
    }
    User&operator=(const User &u)
    {
        if(this!=&u)
        {
            delete[]niza;
            copy(u);
        }
        return *this;
    }
    ~User()
    {
        delete[]niza;
    }
    User&operator+=(Game &g)
    {
        for(int i=0;i<broj;i++)
        {
            if(((*niza[i]) == g) == 0)
                throw ExistingGame();
        }
        Game **temp=new Game*[broj+1];
        for(int i=0;i<broj;i++)
        {
            temp[i]=niza[i];
        }
        temp[broj++]=&g;
        delete[]niza;
        niza=temp;
        return *this;
    }
    double total_spent()
    {
        double total=0;
        for(int i=0;i<broj;i++)
        {
            total+=niza[i]->getPrice();
        }
        return total;

    }
    friend ostream&operator<<(ostream &out, User &u)
    {
        out<<endl;
        out<<"User: "<<u.ime<<endl;
        for(int i=0;i<u.broj;i++)
        {
            out<<"- Game: "<<u.niza[i]->getIme()<<", regular price: $"<<u.niza[i]->getCena();
            if(u.niza[i]->getRasprodazba() == true)
            {
                out<<", bought on sale";
            }
            SubscriptionGame *temp = dynamic_cast<SubscriptionGame*>(u.niza[i]);
            if(temp != 0)
            {
               out<<", monthly fee: $"<<temp->getMesecen()<<", purchased: "<<temp->getMesec()<<"-"<<temp->getGodina()<<endl;
            }
            out<<endl;
        }
        return out;
    }

};
int main ()
{
 int test_case_num;

  cin>>test_case_num;

  // for Game
  char game_name[100];
  float game_price;
  bool game_on_sale;

  // for SubscritionGame
  float sub_game_monthly_fee;
  int sub_game_month, sub_game_year;

  // for User
  char username[100];
  int num_user_games;

  if (test_case_num == 1){
    cout<<"Testing class Game and operator<< for Game"<<std::endl;
    cin.get();
    cin.getline(game_name,100);
    //cin.get();
    cin>>game_price>>game_on_sale;

    Game g(game_name, game_price, game_on_sale);

    cout<<g;
  }
  else if (test_case_num == 2){
    cout<<"Testing class SubscriptionGame and operator<< for SubscritionGame"<<std::endl;
    cin.get();
    cin.getline(game_name, 100);

    cin>>game_price>>game_on_sale;

    cin>>sub_game_monthly_fee;
    cin>>sub_game_month>>sub_game_year;

    SubscriptionGame sg(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
    cout<<sg;
  }
  else if (test_case_num == 3){
    cout<<"Testing operator>> for Game"<<std::endl;
    Game g;

    cin>>g;

    cout<<g;
  }
  else if (test_case_num == 4){
    cout<<"Testing operator>> for SubscriptionGame"<<std::endl;
    SubscriptionGame sg;

    cin>>sg;

    cout<<sg;
  }
  else if (test_case_num == 5){
    cout<<"Testing class User and operator+= for User"<<std::endl;
    cin.get();
    cin.getline(username,100);
    User u(username);

    int num_user_games;
    int game_type;
    cin >>num_user_games;

    try {

      for (int i=0; i<num_user_games; ++i){

        cin >> game_type;

        Game *g;
        // 1 - Game, 2 - SubscriptionGame
        if (game_type == 1){
          cin.get();
          cin.getline(game_name, 100);

          cin>>game_price>>game_on_sale;
          g = new Game(game_name, game_price, game_on_sale);
        }
        else if (game_type == 2){
          cin.get();
          cin.getline(game_name, 100);

          cin>>game_price>>game_on_sale;

          cin>>sub_game_monthly_fee;
          cin>>sub_game_month>>sub_game_year;
          g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
        }

        //cout<<(*g);


        u+=(*g);
      }
    }catch(ExistingGame &ex){
      ex.message();
    }

    cout<<u;

//    cout<<"\nUser: "<<u.get_username()<<"\n";

//    for (int i=0; i < u.get_games_number(); ++i){
//        Game * g;
//        SubscriptionGame * sg;
//        g = &(u.get_game(i));

//        sg = dynamic_cast<SubscriptionGame *> (g);

//        if (sg){
//          cout<<"- "<<(*sg);
//        }
//        else {
//          cout<<"- "<<(*g);
//        }
//        cout<<"\n";
//    }

  }
  else if (test_case_num == 6){
      cout<<"Testing exception ExistingGame for User"<<std::endl;
      cin.get();
      cin.getline(username,100);
      User u(username);

      int num_user_games;
      int game_type;
      cin >>num_user_games;

      for (int i=0; i<num_user_games; ++i){

          cin >> game_type;

          Game *g;
          // 1 - Game, 2 - SubscriptionGame
          if (game_type == 1){
            cin.get();
            cin.getline(game_name, 100);

            cin>>game_price>>game_on_sale;
            g = new Game(game_name, game_price, game_on_sale);
          }
          else if (game_type == 2){
            cin.get();
            cin.getline(game_name, 100);

            cin>>game_price>>game_on_sale;

            cin>>sub_game_monthly_fee;
            cin>>sub_game_month>>sub_game_year;
            g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
          }

          //cout<<(*g);

          try {
            u+=(*g);
          }
          catch(ExistingGame &ex){
            ex.message();
          }
        }

      cout<<u;

//      for (int i=0; i < u.get_games_number(); ++i){
//          Game * g;
//          SubscriptionGame * sg;
//          g = &(u.get_game(i));

//          sg = dynamic_cast<SubscriptionGame *> (g);

//          if (sg){
//            cout<<"- "<<(*sg);
//          }
//          else {
//            cout<<"- "<<(*g);
//          }
//          cout<<"\n";
//      }
  }
  else if (test_case_num == 7){
      cout<<"Testing total_spent method() for User"<<std::endl;
      cin.get();
      cin.getline(username,100);
      User u(username);

      int num_user_games;
      int game_type;
      cin >>num_user_games;

      for (int i=0; i<num_user_games; ++i){

          cin >> game_type;

          Game *g;
          // 1 - Game, 2 - SubscriptionGame
          if (game_type == 1){
            cin.get();
            cin.getline(game_name, 100);

            cin>>game_price>>game_on_sale;
            g = new Game(game_name, game_price, game_on_sale);
          }
          else if (game_type == 2){
            cin.get();
            cin.getline(game_name, 100);

            cin>>game_price>>game_on_sale;

            cin>>sub_game_monthly_fee;
            cin>>sub_game_month>>sub_game_year;
            g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
          }

          //cout<<(*g);


          u+=(*g);
        }

      cout<<u;

      cout<<"Total money spent: $"<<u.total_spent()<<endl;
  }
}
