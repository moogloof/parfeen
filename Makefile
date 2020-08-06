BIN_DIR=bin
PROJECT=Parfeen
TARGET=output
OBJ_DIR=build
INCLUDE=include
CXXFLAGS=-I $(INCLUDE)
CXX=g++

output: $(OBJ_DIR)/main.o $(OBJ_DIR)/particle.o $(OBJ_DIR)/system.o $(OBJ_DIR)/display.o | bin
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/particle.o $(OBJ_DIR)/system.o $(OBJ_DIR)/display.o -o $(BIN_DIR)/$(TARGET).out

$(OBJ_DIR)/main.o: src/main.cpp | build
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/particle.o: src/particle.cpp $(INCLUDE)/$(PROJECT)/particle.h | build
	$(CXX) $(CXXFLAGS) -c src/particle.cpp -o $(OBJ_DIR)/particle.o

$(OBJ_DIR)/system.o: src/system.cpp $(INCLUDE)/$(PROJECT)/system.h $(INCLUDE)/$(PROJECT)/constants.h | build
	$(CXX) $(CXXFLAGS) -c src/system.cpp -o $(OBJ_DIR)/system.o

$(OBJ_DIR)/display.o: src/utils/display.cpp $(INCLUDE)/utils/display.h | build
	$(CXX) $(CXXFLAGS) -c src/utils/display.cpp -o $(OBJ_DIR)/display.o

bin:
	mkdir $@

build:
	mkdir $@

clean:
	rm $(OBJ_DIR)/*.o $(BIN_DIR)/$(TARGET).out
