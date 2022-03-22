#==============================================
# DIRECTORY VARIABLES
#==============================================
THISDIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
BINOUTPUTDIR = $(THISDIR)../output/bin-debug
LIBOUTPUTDIR = $(THISDIR)../output/lib-debug

#==============================================
# CONDITIONAL ASSIGNEMENT
#==============================================
ifeq ($(D), 0)
BINOUTPUTDIR = $(THISDIR)../output/bin-release
LIBOUTPUTDIR = $(THISDIR)../output/lib-release
endif

#==============================================
# TARGETS
#==============================================
genFolder:
	mkdir ../output
	mkdir $(BINOUTPUTDIR)
	mkdir $(LIBOUTPUTDIR)
	mkdir ../src/Application/intermediate
	mkdir ../src/ThirdParty/spdlog/intermediate
	mkdir ../src/Hazel/intermediate