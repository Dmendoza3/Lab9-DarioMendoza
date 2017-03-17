main:	AirBender.o WaterBender.o EarthBender.o FireBender.o Bender.o main.o
	g++ AirBender.o WaterBender.o EarthBender.o FireBender.o Bender.o main.o -o main

main.o:	AirBender.h WaterBender.h EarthBender.h FireBender.h Bender.h main.cpp
	g++ AirBender.cpp WaterBender.cpp EarthBender.cpp FireBender.cpp Bender.cpp main.cpp -c

Bender.o: Bender.h
	g++ Bender.cpp -c

AirBender.o:	AirBender.h Bender.h
	g++ AirBender.cpp -c

WaterBender.o:	WaterBender.h Bender.h
	g++ WaterBender.cpp -c

EarthBender.o:	EarthBender.h Bender.h
	g++ EarthBender.cpp -c

FireBender.o:	FireBender.h Bender.h
	g++ FireBender.cpp -c

clean:
	rm *.o main
