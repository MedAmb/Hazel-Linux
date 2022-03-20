#=============================================
# TOP LEVEL MAKEFILE
#=============================================
export
#=============================================
# CMD VARIABLES
#=============================================
D = 1
#==============================================
# DIRECTORY VARIABLES
#==============================================
unexport THISDIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
SRCDIR = $(THISDIR)src

#==============================================
# TARGETS
#==============================================
all: dependencies Application
	
dependencies: ThirdParty Hazel
	$(MAKE) -C $(SRCDIR)/ThirdParty install
	$(MAKE) -C $(SRCDIR)/Hazel install

Hazel:
	$(MAKE) -C $(SRCDIR)/Hazel all

ThirdParty:
	$(MAKE) -C $(SRCDIR)/ThirdParty all

Application:
	$(MAKE) -C $(SRCDIR)/Application all

install:
	$(MAKE) -C $(SRCDIR)/ThirdParty install
	$(MAKE) -C $(SRCDIR)/Hazel install
	$(MAKE) -C $(SRCDIR)/Application install

clobber:
	$(MAKE) -C $(SRCDIR)/ThirdParty clobber
	$(MAKE) -C $(SRCDIR)/Hazel clobber
	$(MAKE) -C $(SRCDIR)/Application clobber
	-rm -rf logs

uninstall:
	$(MAKE) -C $(SRCDIR)/ThirdParty uninstall
	$(MAKE) -C $(SRCDIR)/Hazel uninstall
	$(MAKE) -C $(SRCDIR)/Application uninstall

clean:
	$(MAKE) -C $(SRCDIR)/ThirdParty clean
	$(MAKE) -C $(SRCDIR)/Hazel clean
	$(MAKE) -C $(SRCDIR)/Application clean