Креирајте класа Rabotnik која во себе содржи:

ime (низа од максимум 30 знаци)
prezime (низа од максимум 30 знаци)
plata (целобројна вредност)
За оваа класа да се креираат default конструктор и конструктор со аргументи. Да се имплементираат и следните методи:

getPlata() која ја враќа платата на работникот
pecati() која ги печати името, презимето и платата.
Креирајте класа Fabrika во која има:

rabotnik [100] (низа од вработени)
brojVraboteni (целобројна вредност)
Во класата имплементирајте ги следните методи:

pecatiVraboteni() ги печати сите вработени
pecatiSoPlata(int plata) ги печати сите вработени со плата поголема или еднаква на дадената во аргументот(int plata).
Во главната функција се внесуваат податоци за n вработени. Притоа прво се внесува n, па податоците за сите n вработени. Во последниот ред се чита минималната плата.

На излез да се прикажат прво сите вработени, а потоа само оние со поголема плата од минималната. Треба да се корисатат методите pecatiVraboteni и pecatiSoPlata!

For example:

Input				
6
Mile Palkovski 20000
Kalina Saleska 9530
Aco Noveski 66320
Kalina Saleska 10720
Ilinka Ilieska 30220
Vesna Petkova 10500
23000

Result
Site vraboteni:
Mile Palkovski 20000
Kalina Saleska 9530
Aco Noveski 66320
Kalina Saleska 10720
Ilinka Ilieska 30220
Vesna Petkova 10500
Vraboteni so plata povisoka od 23000 :
Aco Noveski 66320
Ilinka Ilieska 30220