# This file contains yaal specific targets for yaamake.

# ! Do not include this file !
# instead include yaal/makefile.ext or $(shell yaamake --include-path)


$(OBJDIR)/yaal/%.o : $(YAAL)/%.cpp
	$(BUILD_REQUIRE)
	$(call require,YAAL)
	@echo
	@echo $(MSG_COMPILING_YAAL) $<
	@mkdir -p $(dir $@)
	$(COMPILE.cc) -c -o $@ $<
