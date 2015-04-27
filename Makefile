.PHONY: all compile generate symlinks clean
.DEFAULT: all

all: compile

compile: submodules generate symlinks
	make -C build
generate:
	mkdir -p build && cd build && cmake ..

symlinks:
	ln -sf build/connect-four connect-four

submodules: submodules-init submodules-sync submodules-update
submodules-init:
	git submodule init
submodules-sync:
	git submodule sync
submodules-update:
	git submodule update

clean: clean-symlinks clean-build
clean-symlinks:
	rm connect-four
clean-build:
	rm -rf build
