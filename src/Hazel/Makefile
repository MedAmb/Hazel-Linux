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
DEBUGDEFINE = -DDEBUG

#==============================================
# COMPILATION FLAGS  VARIABLES
#==============================================
CC = g++
STDCFLAGS = -std=c++17
SHAREDLIBFFLAGS = -fPIC
OPTIMAZATIONFLAGS = -g
LDFLAGS = -lspdlog -lpthread

#==============================================
# CONDITIONAL ASSIGNEMENT
#==============================================
ifeq ($(D), 0)
OPTIMAZATIONFLAGS = -O2
BINOUTPUTDIR = $(THISDIR)../../output/bin-release
LIBOUTPUTDIR = $(THISDIR)../../output/lib-release
DEBUGDEFINE =
endif

#==============================================
# FILES
#==============================================
HAZELSRC = $(wildcard *.cpp)
HAZELOBJS = $(HAZELSRC:.cpp=.o)

#==============================================
# TARGETS
#==============================================
build:libHazel.so

#==============================================
# SHARED LIBRARY
#==============================================
libHazel.so:$(HAZELOBJS)
	$(CC) -shared -o $(LIBOUTPUTDIR)/$@ intermediate/* $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) $(LDFLAGS) -I $(INCDIR) -I $(INCDIR)/Hazel -I $(INCDIR)/PCH  -I $(INCDIR)/ThirdParty -I $(THIRDPARTYINCDIR) $(DEBUGDEFINE)

#==============================================
# OBJECT FILES
#==============================================
%.o:%.cpp
	$(CC) -c $^ -o intermediate/$@ $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(INCDIR) -I $(INCDIR)/Hazel -I $(INCDIR)/PCH -I $(INCDIR)/ThirdParty $(DEBUGDEFINE)

#==============================================
# PHONIES
#==============================================
install:
	sudo cp $(LIBOUTPUTDIR)/libHazel.so /usr/lib/libHazel.so

clobber:
	-rm $(LIBOUTPUTDIR)/libHazel.so
	-rm -rf intermediate/*.o
	
uninstall:
	-sudo rm /usr/lib/libHazel.so

