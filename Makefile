BIN_DIR=bin
PROJECT=Parfeen
TARGET=output
OBJ_DIR=build
INCLUDE=include
CXXFLAGS=-I $(INCLUDE)
CXX=g++

output: $(OBJ_DIR)/main.o $(OBJ_DIR)/particle.o
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/particle.o -o $(BIN_DIR)/$(TARGET).out

$(OBJ_DIR)/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/particle.o: src/particle.cpp $(INCLUDE)/$(PROJECT)/particle.h
	$(CXX) $(CXXFLAGS) -c src/particle.cpp -o $(OBJ_DIR)/particle.o

clean:
	rm $(OBJ_DIR)/*.o $(BIN_DIR)/$(TARGET).out
