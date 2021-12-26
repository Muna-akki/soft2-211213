CC = gcc

BINDIR = bin
INCLUDE = include
LIBDIR = lib
SRCDIR = src

CFLAGS = -Wall -I$(INCLUDE)
LDFLAGS = -L$(LIBDIR)
LDLIBS = -lpaint

SRC = $(SRCDIR)/paintapp.c
OBJ = $(SRCDIR)/paintlib.o
LIB = $(LIBDIR)/libpaint.a

TARGET = $(BINDIR)/paint

$(TARGET): $(SRC) $(LIB)
		$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(LIB): $(OBJ)
		$(AR) rsv $@ $^


.PHONY: tmpclean clean

tmpclean:
		rm -f $(SRCDIR)/*~
clean: tmpclean
		rm -f $(TARGET) $(LIB) $(OBJ)
