CC = gcc

CFLAGS = -Wall -Werror -Wextra -pedantic

TARGET = *.c

OUTPUT = hls

all: $(TARGET)
	$(CC) $(CFLAGS) $(TARGET) -o $(OUTPUT)

clean:
	$(RM) $(OUTPUT)