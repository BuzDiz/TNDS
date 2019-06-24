esercizio7.2: esercizio7.2.cpp FunzioneBase.o Solutore.o
	g++ esercizio7.2.cpp FunzioneBase.o Solutore.o -o esercizio7.2
FunzioneBase.o: FunzioneBase.cc FunzioneBase.h
	g++ -c FunzioneBase.cc -o FunzioneBase.o
Solutore.o: Solutore.cc Solutore.h FunzioneBase.o
	g++ -c Solutore.cc -o Solutore.o

clean:
	rm *.o
