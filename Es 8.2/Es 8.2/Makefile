LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio8.2: esercizio8.2.cpp FunzioneBase.o Integral.o
	g++ esercizio8.2.cpp FunzioneBase.o Integral.o -o esercizio8.2 ${INCS} ${LIBS}
FunzioneBase.o: FunzioneBase.cc FunzioneBase.h
	g++ -c FunzioneBase.cc -o FunzioneBase.o
Integral.o: Integral.cc Integral.h FunzioneBase.h
	g++ -c Integral.cc -o Integral.o

clean:
	rm *.o