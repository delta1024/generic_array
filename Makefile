SHELL = /bin/sh
CC ?= cc
AR ?= ar
prefix ?= /usr/local
includedir ?= $(prefix)/include
libdir ?= $(prefix)/lib
srcdir ?= .

TARGET ?= libgeneric_array

.SUFFIXES:
.SUFFIXES: .c .o

.PHONY: all clean distclean sharedlib install uninstall help

all: ./$(TARGET).a

./$(TARGET).a: ./array.o $(srcdir)/generic_array.h	
	$(AR) rcs $@ $<

./%.o: $(srcdir)/%.c $(srcdir)/generic_array.h
	$(CC) $(CFLAGS) -c $< -o $@ 

sharedlib: $(srcdir)/array.c $(srcdir)/generic_array.h
	$(CC) $(CFLAGS) -shared -o $(TARGET).so  $<

clean:
	rm *.o

distclean:
	rm *.o *.so *.a

install: sharedlib
	install $(TARGET).so $(DESTDIR)$(libdir)
	install $(srcdir)/generic_array.h $(DESTDIR)$(includedir)

uninstall:
	rm $(DESTDIR)$(libdir)/$(TARGET).so
	rm $(DESTDIR)$(includedir)/generic_array.h

help:
	@echo "commands:"
	@echo "	all:         Build ./$(TARGET).a"
	@echo ""
	@echo "	sharedlib:   Build libraray as a shared library instead of a static one."
	@echo ""
	@echo "	install:     Install ./$(TARGET).so to $(DESTDIR)$(libdir) and"
	@echo "		     $(srcdir)/generic_array.h to $(DESTDIR)$(includedir)."
	@echo ""
	@echo "	uninstall:   Remove $(DESTDIR)$(libdir)/$(TARGET).so and"
	@echo "	             $(DESTDIR)$(includedir)/generic_array.h."
	@echo ""
	@echo "	clean:	     Remove all .o files from build directory."
	@echo ""
	@echo "	distclean:   Remove all .o .so and .a files from build directory."
	@echo ""
	@echo "variables:"
	@echo "	TARGET     = \"$(TARGET)\""
	@echo "	SHELL      = \"$(SHELL)\""
	@echo "	CC         = \"$(CC)\""
	@echo "	AR         = \"$(AR)\""
	@echo "	prefix     = \"$(prefix)\""
	@echo "	includedir = \"$(includedir)\""
	@echo "	libdir     = \"$(libdir)\""
	@echo "	srcdir     = \"$(srcdir)\""

