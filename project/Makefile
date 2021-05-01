#간편하게 하도록 만들어 놓았습니다.
CC = gcc
TARGET = bookshop
OBJECTS = main.c manager.o product.o

$(TARGET) : $(OBJECTS)
	$(CC) $^ -I./ -o $@

clean:
	rm *.o *.exe