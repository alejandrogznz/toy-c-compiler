COMPILER = g++ -std=c++17
COMPILE_FLAGS = 
COMPILE = $(COMPILER) $(COMPILE_FLAGS)
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o) 

EXE = tcc

all: $(EXE)

$(EXE): $(OBJECTS)
	$(COMPILER) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)/
	$(COMPILER) -c $< -o $@

$(OBJ_DIR)/:
	mkdir $(OBJ_DIR)

clean:
	rm -f $(EXE) *.o
	rm -rf $(OBJ_DIR)
	echo $(SOURCES)
	echo $(OBJECTS)

