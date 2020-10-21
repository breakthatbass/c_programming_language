# for 8-6.c
CC=gcc
CFLAGS=-g -lm -std=c99 -pedantic
SRC_FILES=malloc.c 8-6.c

ifndef NAME
    NAME=calloc
endif

$(NAME): $(SRC_FILES)
	$(CC) -o $(NAME) $(SRC_FILES) $(CFLAGS)

clean:
	rm $(NAME)
