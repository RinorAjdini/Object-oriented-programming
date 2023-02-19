Да се дефинира класа Potpisuvac во која се чуваат информации за:

име (низа од максимум 20 знаци)
презиме (низа од максимум 20 знаци)
ЕМБГ (низа од максимум 14 знаци)
За класата да се дефинира copy конструктор, default конструктор и конструктор со аргументи.

Да се дефинира класа Dogovor, во која се чуваат информации за:

број на договор (int),
категорија на договор (низа од 50 знаци),
поле од 3 потпишувачи на договорот (објекти од класата Potpisuvac)
Во класата да се додаде метод кој ќе проверува дали постојат два исти потпишувачи (имаат ист ЕМБГ).

For example:

Input					Result
2					Dogovor 1:
0101988450001 Alek Aleksov		Postojat potpishuvaci so ist EMBG
0101988450001 Alek Aleksov		Dogovor 2:
0202987440022 Marko Markov		Ne postojat potpishuvaci so ist EMBG
1 Osiguruvanje
0101988450001 Alek Aleksov
0101988450011 Tome Tomov
0202987440022 Marko Markov
2 Kreditiranje