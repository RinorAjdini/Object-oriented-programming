#include<iostream>
#include<cstring>
using namespace std;

class Category {
  private:
  char name[20];
  public:

  Category(char *ime="unnamed")
  {
      strcpy(name,ime);
  }

  ~Category(){}
  void print()
  {
      cout<<"Category: "<<name<<endl;
  }
};

class NewsArticle
{
    private:
    Category category;
    char title[30]="untitled";
    public:
    NewsArticle(){}
    NewsArticle(Category category,char *titl="untitled")
    {
        this->category=category;
        strcpy(title,titl);
    }

    void print()
    {
        cout<<"Article title: "<<title<<endl;
        category.print();
    }

    ~NewsArticle(){}
};


class FrontPage{
  private:
  NewsArticle article;
  float price=0;
  int editionNumber=0;
  public:
  FrontPage(){}
  FrontPage(NewsArticle article,float price=0,int ed=0)
  {
      this->article=article;
      this->price=price;
      editionNumber=ed;
  }

    void print()
    {
        cout<<"Price: "<<price<<", Edition number: "<<editionNumber<<endl;
        article.print();
    }

  ~FrontPage(){}
};



int main() {
	char categoryName[20];
	char articleTitle[30];
	float price;
	int editionNumber;

	int testCase;
	cin >> testCase;


	if (testCase == 1) {
		int iter;
		cin >> iter;
		while (iter > 0) {
			cin >> categoryName;
			cin >> articleTitle;
			cin >> price;
			cin >> editionNumber;
			Category category(categoryName);
			NewsArticle article(category, articleTitle);
			FrontPage frontPage(article, price, editionNumber);
			frontPage.print();
			iter--;
		}
	}
	else if (testCase == 2) {
		cin >> categoryName;
		cin >> price;
		cin >> editionNumber;
		Category category(categoryName);
		NewsArticle article(category);
		FrontPage frontPage(article, price, editionNumber);
		frontPage.print();
	}// test case 3
	else if (testCase == 3) {
		cin >> categoryName;
		cin >> articleTitle;
		cin >> price;
		Category category(categoryName);
		NewsArticle article(category, articleTitle);
		FrontPage frontPage(article, price);
		frontPage.print();
	}
    else {
    	FrontPage frontPage = FrontPage();
        frontPage.print();
    }
	return 0;
}
