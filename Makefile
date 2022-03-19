#=============================================
# CMD VARIABLES
#=============================================
D = 1

#==============================================
# DIRECTORY STRUCTURE VARIABLES
#==============================================
THISDIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
BINOUTPUTDIR = $(THISDIR)output/bin-release
LIBOUTPUTDIR = $(THISDIR)output/lib-release
INTERMEDIATEDIR = $(THISDIR)intermediate
HAZELSRCDIR = $(THISDIR)src/Hazel
APPSRCDIR = $(THISDIR)src/Application
INCDIR = $(THISDIR)inc
HAZELINCDIR = $(INCDIR)/Hazel

#==============================================
# COMPILATION FLAGS  VARIABLES
#==============================================
CC = g++
STDCFLAGS = -std=c++17
SHAREDLIBFFLAGS = -fPIC
OPTIMAZATIONFLAGS = -O2
LDFLAGS = -lHazel

ifneq ($(D), 0)
OPTIMAZATIONFLAGS = -g
BINOUTPUTDIR = $(THISDIR)output/bin-debug
LIBOUTPUTDIR = $(THISDIR)output/lib-debug
endif

all: build-lib install build-bin

#==============================================
# HAZEL LIB SPECIFIC
#==============================================

HAZELOBJS = Application.o

build-lib:$(HAZELOBJS)
	$(CC) -shared -o $(LIBOUTPUTDIR)/libHazel.so $(INTERMEDIATEDIR)/*.o $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(HAZELINCDIR)

Application.o:
	$(CC) -c $(HAZELSRCDIR)/Application.cpp -o $(INTERMEDIATEDIR)/$@ $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(HAZELINCDIR)

#==============================================
# APP SPECIFIC
#==============================================

build-bin:
	$(CC) -o $(BINOUTPUTDIR)/HazelSandBox.out $(APPSRCDIR)/SandBox.cpp $(STDCFLAGS) $(OPTIMAZATIONFLAGS) -I $(INCDIR) $(LDFLAGS)

#==============================================
# COMMON
#==============================================

install:
	sudo cp $(LIBOUTPUTDIR)/libHazel.so /usr/lib/libHazel.so

clean:
	rm $(INTERMEDIATEDIR)/*
	rm $(BINOUTPUTDIR)/*
	rm $(LIBOUTPUTDIR)/*
	sudo rm /usr/lib/libHazel.so