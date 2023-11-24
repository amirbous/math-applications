TARGET=a.out
OBJECTS = src/main.c
CC=gcc
CFLAGS=
LDFLAGS=

all:
	$(CC) $(OBJECTS)  -o $(TARGET)
	
clean:
	rm -r taylor

exe:

	./$(TARGET)
