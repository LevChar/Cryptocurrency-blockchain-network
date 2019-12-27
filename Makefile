.PHONY: all clean

CC:= gcc 
CFLAGS:= -std=c99 -Wall
SRCDIR:= src
SO_LINK_PARAMETERS:= -shared -fPIC

all: block_finder.out formatter.out printdb.out reloader.out

reloader.out block_finder.out formatter.out printdb.out: libbitcoin_manager.so

libbitcoin_manager.so: $(SRCDIR)/linked_list.o $(SRCDIR)/bitcoin.o $(SRCDIR)/file_handler.o
	 $(CC) $(SO_LINK_PARAMETERS) $^ -o $@
	
%.out: $(SRCDIR)/%.o libbitcoin_manager.so
	 $(CC) -Wl,-rpath,./ -o $@ $< libbitcoin_manager.so 	
	
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	 $(CC) $(CFLAGS) -c -fPIC $< -o $@

clean:
	 rm -f $(SRCDIR)/*.o *.so *.out a.csv
