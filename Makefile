# Makefile pour Devoir 1
NOM=Principale
FLAGS=
CC= g++
OBJ=Chaine.o\
	Direct.o\
	Composante.o\
	Engrenage.o\
	Essieu.o\
	LectureFichier.o\
	Lien.o\
	Objet.o\
	Vis.o\
	$(NOM).o

.cpp.o :
	$(CC) $(FLAGS) -c $<

$(NOM) : $(OBJ)
		$(CC) -o $(NOM) $(OBJ)

Chaine.cpp : Chaine.hpp

Direct.cpp : Direct.hpp

Engrenage.cpp : Engrenage.hpp

Composante.cpp : Composante.hpp

Essieu.cpp : Essieu.hpp

LectureFichier.cpp : LectureFichier.hpp

Lien.cpp : Lien.hpp

Objet.cpp : Objet.hpp

Vis.cpp : Vis.hpp

$(NOM).cpp : Principale.hpp Constantes.hpp Engrenage.hpp Vis.hpp Essieu.hpp Direct.hpp Chaine.hpp



clean :
	rm -f *.o
	rm -f $(NOM)

