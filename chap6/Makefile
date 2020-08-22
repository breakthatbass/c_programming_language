
CC = gcc
CFLAGS = -g -lm -pedantic
BT_FILES = btree.c helpers.c

btree: $(BT_FILES)
	$(CC) -o btree  $(BT_FILES) $(CFLAGS)

clean:
	rm btree
