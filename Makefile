TARGET=a.out
OBJECTS = src/main.c src/utils/help.c src/utils/list_command.c
CC=gcc
CFLAGS= -lreadline
LDFLAGS=

all:
	$(CC) $(OBJECTS) $(CFLAGS) -o $(TARGET) 
	
clean:
	rm -r taylor

exe:

	./$(TARGET)
