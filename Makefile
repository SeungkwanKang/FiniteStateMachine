CC:=g++
CFLAGS:=-g -Wall -Werror --std=c++17
IN_CPP_DIR:=src
OUT_O_DIR:=build

programs= \
	FSM.o

results=$(addprefix $(OUT_O_DIR)/,$(programs))

all: manual.pdf $(OUT_O_DIR)/main

manual.pdf:
	$(MAKE) -C manual

$(OUT_O_DIR)/main: $(IN_CPP_DIR)/main.cpp $(results)
	$(CC) $(CFLAGS) $< -o $@

$(OUT_O_DIR)/%.o: $(IN_CPP_DIR)/%.cpp
	mkdir -p $(OUT_O_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OUT_O_DIR)