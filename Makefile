SRC = atlasd.c
OBJ = $(SRC:.c=.o)

PKG = libnl-3.0 libnl-genl-3.0
CFLAGS += $(shell pkg-config --cflags $(PKG))
LDLIBS += $(shell pkg-config --libs $(PKG))

atlasd : $(OBJ)

clean:
	@rm -rf $(OBJ) atlasd

.PHONY: clean
