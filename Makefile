CC = gcc

SRC = LinkedList.c Test.c
OBJ = test

build: $(SRC)
	$(CC) $(SRC) -o $(OBJ)

debug: $(SRC)
	$(CC) -g $(SRC) -o $(OBJ)
