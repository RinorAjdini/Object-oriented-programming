Да се дефинира класа Film, во која ќе се чуваат информации за:

име низа од 100 знаци
режисер низа од 50 знаци
жанр низа од 50 знаци
година цел број
Сите променливи треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:

default конструктор и конструктор со аргументи
метод за печатење на информациите за филмот
Дополнително да се реализира надворешна функција:

void pecati_po_godina(Film *f, int n, int godina) која ќе прима аргумент низа од филмови, вкупниот број на филмови и година, а треба да ги отпечати само филмовите кои се направени во дадената година.
For example:

Input			Result
4			Ime: Wall-E
Frankenweenie		Reziser: Andrew_Stanton			
Tim_Burton 		Zanr: Animation	
Animation		Godina: 2008
2012
Lincoln
Steven_Spielberg
History
2012
Wall-E
Andrew_Stanton
Animation
2008
Avatar
James_Cameron
Fantasy
2009
2008
