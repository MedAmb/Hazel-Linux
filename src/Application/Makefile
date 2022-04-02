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
LDFLAGS = -lHazel -lglfw  -lm
DEBUGDEFINE = -DDEBUG

#==============================================
# FILES
#==============================================
SRCFILES = $(wildcard *.cpp)
OBJECTFILES = $(SRCFILES:.cpp=.o)

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
# TARGETS
#==============================================
build:$(OBJECTFILES)
	$(CC) -o $(BINOUTPUTDIR)/Sandbox $(INTERMEDIATEDIR)/*.o $(STDCFLAGS) $(OPTIMAZATIONFLAGS) -I $(INCDIR) -I $(INCDIR)/PCH -I $(INCDIR)/ThirdParty $(LDFLAGS) $(DEBUGDEFINE)

#==============================================
# BINARY
#==============================================
%.o:%.cpp
	$(CC) -o $(INTERMEDIATEDIR)/$@ -c $^ $(STDCFLAGS) $(OPTIMAZATIONFLAGS) -I $(INCDIR) -I $(INCDIR)/PCH -I $(INCDIR)/ThirdParty -I $(INCDIR)/ThirdParty/glfw $(DEBUGDEFINE)

#==============================================
# PHONIES
#==============================================
install:
	sudo cp $(BINOUTPUTDIR)/Sandbox /usr/bin/Sandbox

clobber:
	-rm $(INTERMEDIATEDIR)/*.o
	-rm $(BINOUTPUTDIR)/Sandbox

uninstall:
	-sudo rm /usr/bin/Sandbox