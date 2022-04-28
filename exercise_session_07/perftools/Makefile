all: nbody nbody_gflag

nbody: nbody.cpp
	g++ -O3 -ffast-math -o nbody nbody.cpp

nbody_gflag: nbody.cpp
	g++ -g -O3 -ffast-math -o nbody_gflag nbody.cpp

clean:
	rm -f nbody_gflag nbody
