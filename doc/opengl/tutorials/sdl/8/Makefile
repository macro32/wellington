CXX = g++

SDL_LIB = -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf
SDL_INCLUDE = -I/usr/include/SDL2

CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
EXE = SDL_Lesson8

all: $(EXE)

$(EXE): main.o window.o timer.o
		$(CXX) main.o window.o timer.o $(LDFLAGS) -o $@

main.o: main.cpp
		$(CXX) $(CXXFLAGS) $< -o $@

window.o: window.cpp
		$(CXX) $(CXXFLAGS) $< -o $@

timer.o: timer.cpp
		$(CXX) $(CXXFLAGS) $< -o $@

clean:
		rm *.o && rm $(EXE)
