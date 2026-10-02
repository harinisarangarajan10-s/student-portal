CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lxlsxwriter

TARGET = a.out

SRCS = main.c student.c file.c
OBJS = main.o student.o file.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

main.o: main.c student.h file.h
	$(CC) $(CFLAGS) -c main.c

student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

file.o: file.c student.h file.h
	$(CC) $(CFLAGS) -c file.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean