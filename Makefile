SOURCES := src/*.cpp
HEADERS := src/*.h
ASSETS 	:= assets/map/map.png

CXXFLAGS := -std=c++20 -I/opt/homebrew/Cellar/sfml/2.6.1/include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

EXE := game

.PHONY: game clean

game:
	$(CXX) $(SOURCES) $(CXXFLAGS) -o $(EXE)

clean:
	rm -f $(EXE)
