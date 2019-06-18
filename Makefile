CXX = g++
CXXFLAGS = -c -std=c++11 -w -lSDL2
LDFLAGS = $(shell sdl2-config --libs) 

BIN_DIR = bin
EXE = pircle

SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_DIR = obj
OBJECTS = $(subst $(SRC_DIR)/, $(OBJ_DIR)/, $(patsubst %.cpp, %.o, $(SOURCES)))

.PHONY: all clean run

all: $(EXE)

$(EXE): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(BIN_DIR)/$(EXE) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $< -o $@ $(CXXFLAGS)

clean:
	rm -rf obj bin

run:
	./$(BIN_DIR)/$(EXE)
