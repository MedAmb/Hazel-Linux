
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
INCDIR = $(THISDIR)../../../inc
THIRDPARTYINCDIR = $(INCDIR)/ThirdParty

#==============================================
# COMPILATION FLAGS  VARIABLES
#==============================================
CC = g++
STDCFLAGS = -std=c++11
SHAREDLIBFFLAGS = -fPIC
OPTIMAZATIONFLAGS = -g
DEFINEFLAGS = -DSPDLOG_COMPILED_LIB

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
SPDLOGSRC = $(wildcard *.cpp)
SPDLOGOBJS = $(SPDLOGSRC:.cpp=.o)

#==============================================
# TARGETS
#==============================================
all:libspdlog.so

#==============================================
# SHARED LIBRARY
#==============================================
libspdlog.so:$(SPDLOGOBJS)
	$(CC) -shared -o $(LIBOUTPUTDIR)/$@ intermediate/*.o $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(THIRDPARTYINCDIR) $(DEFINEFLAGS)

#==============================================
# OBJECT FILES
#==============================================
%.o:%.cpp
	$(CC) -c $^ -o intermediate/$@ $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(THIRDPARTYINCDIR) $(DEFINEFLAGS)

#==============================================
# PHONIES
#==============================================
install:
	sudo cp $(LIBOUTPUTDIR)/libspdlog.so /usr/lib/libspdlog.so

clobber: uninstall clean
	-rm $(LIBOUTPUTDIR)/libspdlog.so

uninstall:
	-sudo rm /usr/lib/libspdlog.so

clean:
	-rm intermediate/*.o