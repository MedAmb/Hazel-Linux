#==============================================
# DIRECTORY VARIABLES
#==============================================
PCHFILES := $(wildcard *.h)
PCHOUTPUTFILES := $(PCHFILES:.h=.h.gch)
INCDIR = ../

#==============================================
# DIRECTORY VARIABLES
#==============================================
.PHONY : build clobber

build:$(PCHOUTPUTFILES)

%.h.gch:%.h
	g++ -std=c++17 $^ -o $@ -I $(INCDIR)Hazel -I $(INCDIR)ThirdParty

clobber:
	-rm *.gch