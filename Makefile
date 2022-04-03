#=============================================
# TOP LEVEL MAKEFILE
#=============================================
export
#=============================================
# CONTROL VARIABLES
#=============================================
D = 1
#==============================================
# DIRECTORY VARIABLES
#==============================================
unexport THISDIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
PCHDIR = $(THISDIR)inc/PCH
SRCDIR = $(THISDIR)src

#==============================================
# TARGETS
#==============================================
.PHONY : all Hazel ThirdParty Application install uninstall clean clobber

all: PCH-build ThirdParty Hazel Application

#==============================================
# TARGETS Precompiled Headers
#==============================================
PCH-build:
	$(MAKE) -C $(PCHDIR) build

#==============================================
# TARGETS Third Party software
#==============================================
ThirdParty: ThirdParty-build ThirdParty-install

ThirdParty-build: spldlog-build glfw-build

ThirdParty-install: spldlog-install glfw-install

spldlog-build:
	$(MAKE) -C $(SRCDIR)/ThirdParty spdlog-build

spldlog-install:
	$(MAKE) -C $(SRCDIR)/ThirdParty spdlog-install

glfw-build:
	$(MAKE) -C $(SRCDIR)/ThirdParty glfw-build

glfw-install:
	$(MAKE) -C $(SRCDIR)/ThirdParty glfw-install

#==============================================
# TARGETS Hazel
#==============================================
Hazel: Hazel-build Hazel-install

Hazel-build:
	$(MAKE) -C $(SRCDIR)/Hazel build

Hazel-install:
	$(MAKE) -C $(SRCDIR)/Hazel install

#==============================================
# TARGETS Application
#==============================================
Application: Application-build Application-install

Application-build:
	$(MAKE) -C $(SRCDIR)/Application build

Application-install:
	$(MAKE) -C $(SRCDIR)/Application install
	

#==============================================
# TARGETS uninstallation
#==============================================
uninstall: ThirdParty-uninstall Hazel-uninstall Application-uninstall

ThirdParty-uninstall: spdlog-uninstall glfw-uninstall

spdlog-uninstall:
	$(MAKE) -C $(SRCDIR)/ThirdParty spdlog-uninstall

glfw-uninstall:
	$(MAKE) -C $(SRCDIR)/ThirdParty glfw-uninstall

Hazel-uninstall:
	$(MAKE) -C $(SRCDIR)/Hazel uninstall

Application-uninstall:
	$(MAKE) -C $(SRCDIR)/Application uninstall
	
#==============================================
# TARGETS cleaning
#==============================================	
clobber:PCH-clobber ThirdParty-clobber Hazel-clobber Application-clobber
	-rm -rf logs

PCH-clobber:
	$(MAKE) -C $(PCHDIR) clobber

ThirdParty-clobber: spdlog-clobber glfw-clobber

spdlog-clobber:
	$(MAKE) -C $(SRCDIR)/ThirdParty spdlog-clobber

glfw-clobber:
	$(MAKE) -C $(SRCDIR)/ThirdParty glfw-clobber

Hazel-clobber:
	$(MAKE) -C $(SRCDIR)/Hazel clobber

Application-clobber:
	$(MAKE) -C $(SRCDIR)/Application clobber
