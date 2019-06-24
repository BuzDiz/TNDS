LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio10.2: esercizio10.2.cpp RandomGen.o Integral.o FunzioneBase.o
	g++ esercizio10.2.cpp RandomGen.o Integral.o FunzioneBase.o Gauss.o -o esercizio10.2 ${INCS} ${LIBS}
Integral.o: Integral.cc Integral.h RandomGen.h FunzioneBase.h
	g++ -c Integral.cc -o Integral.o
RandomGen.o: RandomGen.cc RandomGen.h Gauss.o
	g++ -c RandomGen.cc -o RandomGen.o
FunzioneBase.o: FunzioneBase.cc FunzioneBase.h
	g++ -c FunzioneBase.cc -o FunzioneBase.o
Gauss.o: Gauss.cc Gauss.h
	g++ -c Gauss.cc -o Gauss.o
clean:
	rm *.o
cleanall: clean
	rm *.o
