# Makefile pour Devoir 1
NOM=main
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
	#main.o\
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

LectureFichier.cpp : LectureFichier.hpp Engrenage.cpp Vis.hpp Essieu.hpp Direct.hpp Chaine.hpp

Lien.cpp : Lien.hpp

Objet.cpp : Objet.hpp

Vis.cpp : Vis.hpp

main.cpp : main.hpp Constantes.hpp Engrenage.hpp Vis.hpp Essieu.hpp Direct.hpp Chaine.hpp

$(NOM) : main.hpp Constantes.hpp Engrenage.hpp Vis.hpp Essieu.hpp Direct.hpp Chaine.hpp



clean :
	rm -f *.o
	rm -f $(NOM)

