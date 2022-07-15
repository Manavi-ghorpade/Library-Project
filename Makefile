test_prg: Book.o Film.o Media.o Periodical.o Video.o test_prg.o SearchEngine.o
	g++ Book.o Film.o Media.o Periodical.o Video.o SearchEngine.o test_prg.o -o test_prg

test_prg.o: test_prg.cpp Book.h Film.h Media.h Periodical.h Video.h
	g++ -fno-elide-constructors -c test_prg.cpp

Media.o: Media.cpp Media.h
	g++ -fno-elide-constructors -c Media.cpp

Book.o: Book.cpp Book.h Media.h
	g++ -fno-elide-constructors -c Book.cpp

Film.o: Film.cpp Film.h Media.h
	g++ -fno-elide-constructors -c Film.cpp

Video.o: Video.cpp Video.h Media.h
	g++ -fno-elide-constructors -c Video.cpp

Periodical.o: Periodical.cpp Periodical.h Media.h
	g++ -fno-elide-constructors -c Periodical.cpp

SearchEngine.o: SearchEngine.cpp SearchEngine.h Media.h Video.h Book.h Film.h Periodical.h
	g++ -fno-elide-constructors -c SearchEngine.cpp

clean: 
	rm -f *.o test_prg
