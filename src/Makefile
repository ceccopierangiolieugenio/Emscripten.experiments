TEST_DIRS = $(sort $(wildcard test.*))

.PHONY: test_dirs $(TEST_DIRS)

test_dirs: $(TEST_DIRS)

$(TEST_DIRS):
	$(MAKE) -C $@

