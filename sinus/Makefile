CC = g++
CTAGS = -c -W -Wall -O2 -g -pg
GL = -lGL -lglut

sinus: sinus.o glutFunctions.o
	$(CC) $(GL) -g -pg -o sinus sinus.o glutFunctions.o

sinus.o: sinus.cpp 
	$(CC) $(CTAGS) sinus.cpp

glutFunctions.o: glutFunctions.cpp 
	$(CC) $(CTAGS) glutFunctions.cpp

clean:
	rm -rf *.o
