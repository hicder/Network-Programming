COMPILER = g++
LINKER = g++
COMPILER_FLAGS = -c -g -O0 -Wall -Werror
chkinfo : getaddressinfo.o
	$(LINKER) getaddressinfo.o -o chkinfo
getaddressinfo.o : getaddressinfo.c
	$(COMPILER) $(COMPILER_FLAGS) getaddressinfo.c
