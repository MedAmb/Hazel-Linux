
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

#==============================================
# CONDITIONAL ASSIGNEMENT
#==============================================
ifeq ($(D), 0)
OPTIMAZATIONFLAGS = -O2
BINOUTPUTDIR = $(THISDIR)../../../output/bin-release
LIBOUTPUTDIR = $(THISDIR)../../../output/lib-release
endif


SPDLOGOBJS = async.o  cfg.o color_sinks.o file_sinks.o fmt.o spdlog.o stdout_sink.o
DEFINEFLAGS = -DSPDLOG_COMPILED_LIB

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
async.o:
	$(CC) -c async.cpp -o intermediate/$@ $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(THIRDPARTYINCDIR) $(DEFINEFLAGS)

cfg.o:
	$(CC) -c cfg.cpp -o intermediate/$@ $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(THIRDPARTYINCDIR) $(DEFINEFLAGS)

color_sinks.o:
	$(CC) -c color_sinks.cpp -o intermediate/$@ $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(THIRDPARTYINCDIR) $(DEFINEFLAGS)

file_sinks.o:
	$(CC) -c file_sinks.cpp -o intermediate/$@ $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(THIRDPARTYINCDIR) $(DEFINEFLAGS)

fmt.o:
	$(CC) -c fmt.cpp -o intermediate/$@ $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(THIRDPARTYINCDIR) $(DEFINEFLAGS)

spdlog.o:
	$(CC) -c spdlog.cpp -o intermediate/$@ $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(THIRDPARTYINCDIR) $(DEFINEFLAGS)

stdout_sink.o:
	$(CC) -c stdout_sinks.cpp -o intermediate/$@ $(STDCFLAGS) $(SHAREDLIBFFLAGS) $(OPTIMAZATIONFLAGS) -I $(THIRDPARTYINCDIR) $(DEFINEFLAGS)

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