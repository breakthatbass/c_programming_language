
CC = gcc
CFLAGS = -g -lm -pedantic
BT_FILES = btree.c helpers.c

btree: $(BT_FILES)
	$(CC) -o btree  $(BT_FILES) $(CFLAGS)

ex2: helpers.c 6-2.c
	$(CC) -o btree helpers.c 6-2.c $(CFLAGS)

clean:
	rm btree
