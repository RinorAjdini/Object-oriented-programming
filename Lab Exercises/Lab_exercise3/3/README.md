Во оваа задача потребно е да се внесат податоци за насловна страница на списание.

За претставување на насловната страница напишете класа FrontPage која ќе содржи:

објект од класата NewsArticle која ја претставува насловната вест на страницата
цена (float price) со предодредена вредност 0
број на издание на списанието (int editionNumber) со предодредена вредност 0
За класата FrontPage напишете предодреден (default) конструктор и конструктор со параметри. Класата NewsArticle треба да содржи:

објект од класата Category која ја претставува категоријата во која спаѓа веста
наслов од максимум 30 знаци (char title[30]) со предодредена вредност untitled
За класата NewsArticle напишете предодреден конструктор и конструктор со параметри.

Класата Category треба да содржи име од максимум 20 знаци (char name[20]) со предодредена вредност unnamed.

За сите класи треба да напишете соодветен метод за печатење print().

Внимајте на редоследот на параметрите во конструкторите. Не го менувајте main методот.

За категоријата се печати само името: Category: [name].

За веста се печати насловот, па категоријата во нов ред:

Title: [title]

category.print()

За насловната страница се печати цената и изданието во прв ред, па веста во втор:

Price: [price], Edition number: [editionNumber]

article.print()

For example:

Input		Result
2		Price: 120, Edition number: 2
sport		Article title: untitled
120		Category: sport
2