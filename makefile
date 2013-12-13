SRC= Cantor.cpp Fractal.cpp Koch.cpp main.cpp Peano.cpp
HDR= Cantor.h Fractal.h Koch.h KochSquare.h KochTriangle.h Line.h Peano.h Point.h



.PHONY: all run clear
all: fractal

fractal: $(SRC) $(HDR)
	g++ $(SRC) -lGL -lglut -o $@

run: fractal
	./fractal

clear:
	$(RM) fractal

