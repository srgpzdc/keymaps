USER = srgpzdc
KEYBOARDS = crkbd

# keymap paths
PATH_crkbd = crkbd

# keyboard names
NAME_crkbd = crkbd

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	git submodule update --init --recursive
	git submodule foreach git pull origin master
	git submodule foreach make git-submodule

	# cleanup old symlinks
	rm -rf qmk_firmware/users/$(USER)
	rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)

	# add new symlinks
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)

	# run lint check
	#cd qmk_firmware; qmk lint -km $(USER) -kb $(NAME_$@) --strict

	# run build
	make BUILD_DIR=$(shell pwd)/build -j1 -C qmk_firmware $(NAME_$@):$(USER)

	# cleanup symlinks
	rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)
	rm -rf qmk_firmware/users/$(USER)

clean:
	rm -rf ./qmk_firmware
	mkdir qmk_firmware
	rm -rf ./build/
