.PHONY:: all submodules submodules-init submoules-sync \
				generate compile symlinks clean clean-symlinks \
				clean-build
.DEFAULT:: all

all::
	@echo "-- Starting Build"

#### Submodules

all submodules::
	@echo "-- Checking submodules..."
all submodules:: .touch-submodules
.touch-submodules:
	@printf -- "-- Updating submodules"
	@git submodule --quiet init
	@git submodule --quiet sync
	@git submodule --quiet update
	@touch .touch-submodules
	@printf " done\n"

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
