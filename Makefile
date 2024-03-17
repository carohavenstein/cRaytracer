all: raytracer img

raytracer:
	g++ img.cpp
# g++ -c camara.cpp
# g++ img.o camara.o

img:
	./a.out > img.ppm
	open img.ppm