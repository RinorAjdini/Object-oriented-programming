Да се креира класа Transakcija во која што ќе се чуваат информации за:

датумот на реализирање на банкарската трансакција:
ден (int)
месец (int)
година (int)
паричниот износ кој се однесува на трансакцијата (позитивен или негативен, тип double)
моменталната вредност на еврото во денари (static double EUR), иницијално поставен на 61
моменталната вредност на доларот во денари (static double USD), иницијално поставен на 50
За класата да се имплемтнираат соодветните конструктори, како и да се дефинираат следните четири чисто виртуелни методи:

double voDenari()
double voEvra()
double voDolari()
void pecati()
Трансакциите можат да бидат денарски и девизни (DenarskaTransakcija и DeviznaTransakcija). За девизните трансакции се чува дополнителна информација за валутата на трансакцијата (низа од три знаци). Дозволени валути за девизните транскации се USD и EUR.

За двете изведени класи да се напишат соодветните конструктори, деструктори и да се препокријат потребните методи.

Да се дефинира класа Smetka во која што ќе се чуваат информации за:

извршените трансакции (динамички алоцирана низа од покажувачи кон класата Transakcija)
број на извршените трансакции (int)
број на сметката (низа од 15 знаци)
почетно салдо во денари (double)
За класата Smetka да се имплементираат:

потребен конструктор (со два аргументи, видете во main), деструктор
оператор за додавање на нова трансакција во низата од трансакции +=
void izvestajVoDenari() - функција што печати информации за сметката во форматот:

Korisnikot so smetka: [број на сметката] ima momentalno saldo od [салдо на сметката пресметано во денари] MKD

void izvestajVoEvra() - функција што печати информации за сметката во форматот:

Korisnikot so smetka: [број на сметката] ima momentalno saldo od [салдо на сметката пресметано во евра] EUR

void izvestajVoDolari() - функција што печати информации за сметката во форматот:

Korisnikot so smetka: [број на сметката] ima momentalno saldo od [салдо на сметката пресметано во долари] УСД

void pecatiTransakcii() - функција што ги печати сите внесени трансакции
Да се креираат класи за следните исклучоци:

InvalidDateException којшто се фрла доколку при креирање на трансакција не се испочитувани правилата 1<=ден<=31 и 1<=месец<=12
NotSupportedCurrencyException којшто се фрла доколку при креирање на девизна трансакција се внесува вредност за валута што не е дозволена
Овие исклучоци да се фрлат и да се фатат таму каде што е потребно. Истите при фаќање треба да печатат пораки од следниот формат:

Invalid Date 32/12/2018
GBP is not a supported currency
For example:

Input	
5
1 20 04 2018 1857.55 
2 21 04 2018 1234.55 GBP
2 21 04 2018 1000 EUR
1 22 14 2018 1200
1 22 04 2018 13155.50
62.1 49.8

Result
===VNESUVANJE NA TRANSAKCIITE I SPRAVUVANJE SO ISKLUCOCI===
GBP is not a supported currency
Invalid Date 22/14/2018
===PECHATENJE NA SITE TRANSAKCII===
20/4/2018 1857.55 MKD
21/4/2018 1000 EUR
22/4/2018 13155.5 MKD
===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI===
Korisnikot so smetka: 300047024112789 ima momentalno saldo od 77513.1 MKD
===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA===
Korisnikot so smetka: 300047024112789 ima momentalno saldo od 1270.71 EUR
===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI===
Korisnikot so smetka: 300047024112789 ima momentalno saldo od 1550.26 USD

===PROMENA NA KURSOT NA EVROTO I DOLAROT===

===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI===
Korisnikot so smetka: 300047024112789 ima momentalno saldo od 78613.1 MKD
===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA===
Korisnikot so smetka: 300047024112789 ima momentalno saldo od 1265.91 EUR
===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI===
Korisnikot so smetka: 300047024112789 ima momentalno saldo od 1578.58 USD
