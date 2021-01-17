CC:=g++
CFLAGS:=-g -Wall -Werror --std=c++17
IN_CPP_DIR:=src
OUT_O_DIR:=build

headers= \
	FSM.hpp \
	FSM_Moore.hpp \
	FSM_Mealy.hpp \
	State.hpp \
	State_Moore.hpp \
	State_Mealy.hpp

headerPaths=$(addprefix $(IN_CPP_DIR)/,$(headers))

all: manual.pdf $(OUT_O_DIR)/main

manual.pdf:
	$(MAKE) -C manual

$(OUT_O_DIR)/main: $(IN_CPP_DIR)/main.cpp $(headerPaths)
	mkdir -p $(OUT_O_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OUT_O_DIR)