
all:$(OBJFILES)

%.o:%.c
	gcc $(CFLAGS) $(DEFINEFLAGS) $(INCLUDEFLAGS) -o $@ -c $^



#=============================================
# CMD VARIABLES
#=============================================
D = 1
#==============================================
# DIRECTORY STRUCTURE VARIABLES
#==============================================
THISDIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
BINOUTPUTDIR = $(THISDIR)../../../output/bin-debug
LIBOUTPUTDIR = $(THISDIR)../../../output/lib-debug
INTERMEDIATEDIR =  $(THISDIR)intermediate
INCDIR = $(THISDIR)../../../inc/ThirdParty/glfw

#==============================================
# COMPILATION FLAGS  VARIABLES
#==============================================
CC = gcc
STDCFLAGS = -Wall -fvisibility=hidden -std=gnu99
SHAREDLIBFFLAGS = -fPIC
OPTIMAZATIONFLAGS = -g
DEFINEFLAGS = -D_GLFW_USE_CONFIG_H -Dglfw_EXPORTS
LDFLAGS = /usr/lib/x86_64-linux-gnu/librt.so -lm -ldl /usr/lib/x86_64-linux-gnu/libX11.so -lpthread

#==============================================
# CONDITIONAL ASSIGNEMENT
#==============================================
ifeq ($(D), 0)
OPTIMAZATIONFLAGS = -O2
BINOUTPUTDIR = $(THISDIR)../../../output/bin-release
LIBOUTPUTDIR = $(THISDIR)../../../output/lib-release
endif

#==============================================
# FILES
#==============================================
SRCFILES = $(wildcard *.c)
OBJFILES = $(SRCFILES:.c=.o)

#==============================================
# TARGETS
#==============================================
build:libglfw.so

#==============================================
# SHARED LIBRARY
#==============================================
libglfw.so:$(OBJFILES)
	$(CC) -shared -o $(LIBOUTPUTDIR)/$@ intermediate/*.o $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(INCDIR) $(DEFINEFLAGS) $(LDFLAGS)

#==============================================
# OBJECT FILES
#==============================================
%.o:%.c
	$(CC) -c $^ -o intermediate/$@ $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(INCDIR) $(DEFINEFLAGS)

#==============================================
# PHONIES
#==============================================
install:
	sudo cp $(LIBOUTPUTDIR)/libglfw.so /usr/lib/libglfw.so

clobber: uninstall clean
	-rm $(LIBOUTPUTDIR)/libglfw.so

uninstall:
	-sudo rm /usr/lib/libglfw.so

clean:
	-rm intermediate/*.o