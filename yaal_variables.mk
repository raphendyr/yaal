# This file contains yaal specific variables for yaamake.

# ! Do not include this file !
# instead include yaal/makefile.ext or $(shell yaamake --include-path)

# FIXME: use automated dependency files for YAAL_NO_INIT
YAAL_NO_INIT ?= $(NO_YAAL)


# Add yaal sources to be build
SRC += $(if $(YAAL_NO_INIT),,yaal/core/init.cpp)

# Define macro if init is not used
CPPFLAGS += $(if $(YAAL_NO_INIT),-DYAAL_NO_INIT,)

# Add yaal to header search path
CIFLAGS += $(if $(YAAL),-I$(YAAL)/include,)
