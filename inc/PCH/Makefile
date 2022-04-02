PCHFILES := $(wildcard *.h)
PCHOUTPUTFILES := $(PCHFILES:.h=.h.gch)
INCDIR = ../

build:$(PCHOUTPUTFILES)
	mv ./spdlogPCH.h.gch ../ThirdParty
	mv ./STLPCH.h.gch ../Hazel

%.h.gch:%.h
	g++ -std=c++17 $^ -o $@ -I $(INCDIR)Hazel -I $(INCDIR)ThirdParty

clean:
	-rm ../Hazel/*.gch ../ThirdParty/*.gch