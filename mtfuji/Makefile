CC = gcc

BINDIR = bin
INCLUDE = include
LIBDIR = lib
SRCDIR = src

CFLAGS = -Wall -I$(INCLUDE)
LDFLAGS = -L$(LIBDIR)
LDLIBS = -lfunc -loptimize -lcompare

SRC = $(SRCDIR)/mtfuji.c

OBJ1 = $(SRCDIR)/funclib.o
LIB1 = $(LIBDIR)/libfunc.a

OBJ2 = $(SRCDIR)/optimizelib.o
LIB2 = $(LIBDIR)/liboptimize.a

OBJ3 = $(SRCDIR)/comparelib.o
LIB3 = $(LIBDIR)/libcompare.a


TARGET = $(BINDIR)/mtfuji

$(TARGET): $(SRC) $(LIB1) $(LIB2) $(LIB3)
		$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(LIB1): $(OBJ1)
		$(AR) rsv $@ $^

$(LIB2): $(OBJ2)
		$(AR) rsv $@ $^

$(LIB3): $(OBJ3)
		$(AR) rsv $@ $^

.PHONY: tmpclean clean

tmpclean:
		rm -f $(SRCDIR)/*~
clean: tmpclean
		rm -f $(TARGET) $(LIB1) $(OBJ1) $(LIB2) $(OBJ2) $(LIB3) $(OBJ3)

