BUILD_DIR=_build

all:
	+make -C $(BUILD_DIR)

distclean:
	rm -rf $(DIRS) $(BUILD_DIR)

%:
	+make -C $(BUILD_DIR) $@
