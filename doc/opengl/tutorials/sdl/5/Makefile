CXX = g++

SDL_LIB = -L/usr/local/lib -lSDL2 -lSDL2_image
SDL_INCLUDE = -I/usr/local/include

CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
EXE = SDL_Lesson5

all: $(EXE)

$(EXE): main.o
		$(CXX) $< $(LDFLAGS) -o $@

main.o: main.cpp
		$(CXX) $(CXXFLAGS) $< -o $@

clean:
		rm *.o && rm $(EXE)
