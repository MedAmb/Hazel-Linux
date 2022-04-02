#=============================================
# CMD VARIABLES
#=============================================
D = 1
#==============================================
# DIRECTORY STRUCTURE VARIABLES
#==============================================
THISDIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
BINOUTPUTDIR = $(THISDIR)../../output/bin-debug
LIBOUTPUTDIR = $(THISDIR)../../output/lib-debug
INTERMEDIATEDIR =  $(THISDIR)intermediate
INCDIR = $(THISDIR)../../inc
THIRDPARTYINCDIR = $(INCDIR)/ThirdParty

#==============================================
# COMPILATION FLAGS  VARIABLES
#==============================================
CC = g++
STDCFLAGS = -std=c++17
SHAREDLIBFFLAGS = -fPIC
OPTIMAZATIONFLAGS = -g
LDFLAGS = -lHazel -lspdlog -lpthread

#==============================================
# FILES
#==============================================
SRC = $(wildcard *.cpp)

#==============================================
# CONDITIONAL ASSIGNEMENT
#==============================================
ifeq ($(D), 0)
OPTIMAZATIONFLAGS = -O2
BINOUTPUTDIR = $(THISDIR)../../output/bin-release
LIBOUTPUTDIR = $(THISDIR)../../output/lib-release
endif

#==============================================
# TARGETS
#==============================================
all:Sandbox.out

#==============================================
# BINARY
#==============================================
Sandbox.out:$(SRC)
	$(CC) -o $(BINOUTPUTDIR)/$@ $^ $(STDCFLAGS) $(OPTIMAZATIONFLAGS) -I $(INCDIR) -I $(INCDIR)/PCH -I $(INCDIR)/ThirdParty $(LDFLAGS)

#==============================================
# PHONIES
#==============================================

install:
	sudo cp $(BINOUTPUTDIR)/Sandbox.out /usr/bin/Sandbox.out

clobber: uninstall clean
	-rm $(BINOUTPUTDIR)/Sandbox.out

uninstall:
	-sudo rm /usr/bin/Sandbox.out

clean:
	-rm intermediate/*.o