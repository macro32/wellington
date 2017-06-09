CXX = g++

SDL_LIB = -L/usr/local/lib -lSDL2 
SDL_INCLUDE = -I/usr/local/include

CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
EXE = SDL_Lesson2

all: $(EXE)

$(EXE): main.o
		$(CXX) $< $(LDFLAGS) -o $@

main.o: main.cpp
		$(CXX) $(CXXFLAGS) $< -o $@

clean:
		rm *.o && rm $(EXE)
