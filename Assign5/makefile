CC = g++
objects = 1 2 3 4 5
CFLAGS = -O2
LFLAGS =   
all : $(objects)

$(objects): % : src/%.cpp
	$(CC) $(CFLAGS) $(LFLAGS) $<  -o bin/$@.o