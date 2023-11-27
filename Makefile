TARGET=a.out
OBJECTS = src/main.c src/help.c
CC=gcc
CFLAGS=
LDFLAGS=

all:
	$(CC) $(OBJECTS)  -o $(TARGET)
	
clean:
	rm -r taylor

exe:

	./$(TARGET)
