gymsystem:	gymsystem.out
	g++ gymsystem.out -o gymsystem
gymsystem.out: gymsystem.cpp
	g++ -c gymsystem.cpp -o gymsystem.out
clean:
	rm -rf *.out gymsystem