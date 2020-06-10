# Makefile pour Devoir 1

#Option -g pour avoir les infos de débogage
#OPTIONS = -g -O0 -Wall

#Option -O3 pour le code optimisé
OPTIONS = -O3 -Wall

#all : test_pile test_file lab4 #(je sais pas ça fait quoi)


# Syntaxe : cible : dépendance1 dépendance2 ...
# Ensuite, la ou les ligne(s) débutant par une tabulation (\t) donne les commandes pour construire une cible.

devoir1: main.cpp Constantes.hpp
	g++ $(OPTIONS) -o devoir1 main.cpp


clean :
	rm -f *.o
	rm -f devoir1

