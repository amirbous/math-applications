TARGET=a.out
OBJECTS = src/main.c src/utils/help.c src/utils/list_command.c
CC=gcc
CFLAGS=
LDFLAGS=

all:
	$(CC) $(OBJECTS)  -o $(TARGET)
	
clean:
	rm -r taylor

exe:

	./$(TARGET)
