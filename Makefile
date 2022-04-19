CC=gcc
CFLAGS=-O2 -fPIC -pedantic -Wall -Wextra -g
BINS=tail  wordcount wordcount-dynamic
LIB_OBJECTS=htab_find.o htab_init.o htab_size.o htab_erase.o htab_bucket_count.o htab_clear.o htab_for_each.o htab_free.o htab_hash_function.o htab_lookup_add.o htab_move.o


all: $(BINS)
# executables creation
wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) -o $@ $^
wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) -o $@ $^
tail: tail.o
	gcc tail.o -o tail

# libraries creation
libhtab.so: $(LIB_OBJECTS)
	$(CC) -fPIC -shared $^ -o $@
libhtab.a: $(LIB_OBJECTS)
	ar rcs $@ $^

# Object files creation
$(LIB_OBJECTS): %.o: %.c
wordcount.o: wordcount.c
	 $(CC) $(CFLAGS) -c wordcount.c -o wordcount.o
io.o: io.c
	$(CC) $(CFLAGS) -c io.c -o io.o
tail.o: tail.c
	gcc -c tail.c -o tail.o

# clear directory
clean:
	rm *.o *.a *.so $(BINS)

zip:
	zip xjarol06.zip *.c *.h Makefile
