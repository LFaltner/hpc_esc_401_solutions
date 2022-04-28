all: nbody nbody_gflag

nbody: nbody_gflag.cpp
	g++ -O3 -ffast-math -o nbody nbody_gflag.cpp

nbody_gflag: nbody_gflag.cpp
	g++ -g -O3 -ffast-math -o nbody_gflag nbody_gflag.cpp

clean:
	rm -f nbody_gflag nbody