Со цел да се подобри системот Мој Термин, со воведување функционалност за пресметување плати за лекарите за еден месец, од Министерството за здравство на Република Македонија, ги добивате следните задачи:

Да се креира класа Lekar во која што ќе се чуваат:

факсимил на докторот (цел број)
име (низа од максимум 10 знаци)
презиме (низа од максимум 10 знаци)
почетна плата (децимален број)
За класата да се имплементираат методите:

void pecati(): Печати информации за лекарот во формат Факсимил: име презиме

double plata(): ја враќа платата на лекарот

Да се креира класа MaticenLekar која што наследува од Lekar и во неа се чуваат дополнителни информации за:

број на пациенти со којшто лекарот соработувал во текот на месецот (цел број)
котизации наплатени од пациентите во текот на месецот (динамички алоцирана низа од децимални броеви)
За класата да се препокријат методитe:

void pecati() : ги печати основните информации за лекарот, а во нов ред го печати и просекот од наплатените котизации

double plata(): ја враќа платата на матичниот лекар

Платата на матичниот лекар се пресметува со зголемување на основната плата за 30% од просекот од наплатените котизации за месецот
For example:

Input	
7
766433 Cvetanka Cvetkova 27899.90
123122 Stefan Stefanov 31789.50
454323 Trajce Trajkov 19458.30
343989 Goran Trajkov 28945.10
515788 Nikola Nikolov 36985.50
784512 Viktorija Stojanovska 37855.00
985623 Ivana Ivanova 38745.70
5
1000 2000 2500 7800 5560
4
1000 2000 3000 10000
6
7800 7800 8000 9000 900 1000
5
1000 1500 2000 2300 2400
3
15000 10000 7580
4
10000 7000 8000 1000
3
1000 2000 3000 
1
1

Result
===TESTIRANJE NA KLASATA LEKAR===
766433: Cvetanka Cvetkova
Osnovnata plata na gorenavedeniot lekar e: 27899.9
123122: Stefan Stefanov
Osnovnata plata na gorenavedeniot lekar e: 31789.5
454323: Trajce Trajkov
Osnovnata plata na gorenavedeniot lekar e: 19458.3
343989: Goran Trajkov
Osnovnata plata na gorenavedeniot lekar e: 28945.1
515788: Nikola Nikolov
Osnovnata plata na gorenavedeniot lekar e: 36985.5
784512: Viktorija Stojanovska
Osnovnata plata na gorenavedeniot lekar e: 37855
985623: Ivana Ivanova
Osnovnata plata na gorenavedeniot lekar e: 38745.7