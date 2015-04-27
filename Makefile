.PHONY:: all submodules submodules-init submoules-sync \
				generate compile symlinks clean clean-symlinks \
				clean-build
.DEFAULT:: all

all::
	@echo "-- Starting Build"

#### Submodules

all submodules::
	@echo "-- Updating submodules"
submodules:: submodules-init submodules-sync submodules-update
all submodules-init::
	@git submodule init
all submodules-sync::
	@git submodule sync
all submodules-update::
	@git submodule update

#### CMake and Compiling

all generate::
	@mkdir -p build && cd build && cmake ..
all compile::
	@make -s -C build

#### Symlinking

all symlinks::
	@echo "-- Making Symlinks"
	@ln -sf build/connect-four connect-four

all::
	@echo "-- Done"

#### Cleaning

clean::
	@echo "-- Cleaning"
clean clean-symlinks::
	@echo "-- Removing Symlinks"
	@rm connect-four
clean clean-build::
	@echo "-- Removing Build"
	@rm -rf build
clean::
	@echo "-- Done"
