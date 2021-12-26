CC = gcc

BINDIR = bin
INCLUDE = include
LIBDIR = lib
SRCDIR = src

CFLAGS = -Wall -I$(INCLUDE) 
LDFLAGS = -L$(LIBDIR)
LDLIBS = -linteger 

SRC = $(SRCDIR)/main.c
OBJ = $(SRCDIR)/intlib.o
LIB = $(LIBDIR)/libinteger.a

TARGET = $(BINDIR)/qsort

$(TARGET): $(SRC) $(LIB)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(LIB): $(OBJ)
	$(AR) rsv $@ $^

.PHONY: tmpclean clean

tmpclean:
	rm -f $(SRCDIR)/*~
clean: tmpclean
	rm -f $(TARGET) $(LIB) $(OBJ)