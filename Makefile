TARGET=taylor
OBJECTS = src/help.c src/main.c src/modes.c src/utils.c
CC=gcc
CFLAGS=
LDFLAGS=

all:
	$(CC) $(OBJECTS)  -o $(TARGET)
	
clean:
	rm -r taylor

exe:

	./$(TARGET)
