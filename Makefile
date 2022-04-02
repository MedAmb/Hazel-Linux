#=============================================
# TOP LEVEL MAKEFILE
#=============================================
export
#=============================================
# CONTROL VARIABLES
#=============================================
D = 1
CI = 0
#==============================================
# DIRECTORY VARIABLES
#==============================================
unexport THISDIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
SRCDIR = $(THISDIR)src

#==============================================
# TARGETS
#==============================================
.PHONY : all dependencies Hazel ThirdParty Application install uninstall clean clobber

all: dependencies Application


dependencies: ThirdParty Hazel
	@echo "Installing Shared libraries"
	$(MAKE) -C $(SRCDIR)/ThirdParty install
	$(MAKE) -C $(SRCDIR)/Hazel install

Hazel:
	@echo "Building the Hazel engine"
	$(MAKE) -C $(SRCDIR)/Hazel all

ThirdParty:
	@echo "Building third party dependencies"
	$(MAKE) -C $(SRCDIR)/ThirdParty all

Application:
	@echo "Building the Application"
	$(MAKE) -C $(SRCDIR)/Application all

install:
	$(MAKE) -C $(SRCDIR)/ThirdParty install
	$(MAKE) -C $(SRCDIR)/Hazel install
	$(MAKE) -C $(SRCDIR)/Application install

uninstall:
	$(MAKE) -C $(SRCDIR)/ThirdParty uninstall
	$(MAKE) -C $(SRCDIR)/Hazel uninstall
	$(MAKE) -C $(SRCDIR)/Application uninstall

clean:
	$(MAKE) -C $(SRCDIR)/ThirdParty clean
	$(MAKE) -C $(SRCDIR)/Hazel clean
	$(MAKE) -C $(SRCDIR)/Application clean

clobber:
	$(MAKE) -C $(SRCDIR)/ThirdParty clobber
	$(MAKE) -C $(SRCDIR)/Hazel clobber
	$(MAKE) -C $(SRCDIR)/Application clobber
	-rm -rf logs