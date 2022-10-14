main: main.o caesar.o vigenere.o decrypt.o
	g++ -o main main.o caesar.o vigenere.o decrypt.o

tests: tests.o caesar.o vigenere.o decrypt.o
	g++ -o tests tests.o caesar.o vigenere.o decrypt.o

test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.o

test-ascii.o: test-ascii.cpp

caesar.o: caesar.cpp caesar.h

vigenere.o: vigenere.cpp vigenere.h

decrypt.o: decrypt.cpp decrypt.h

main.o: main.cpp caesar.h

tests.o: tests.cpp doctest.h caesar.h

clean:
	rm -f main.o tests.o caesar.o decrypt.o vigenere.o test-ascii.o main tests test-ascii 
