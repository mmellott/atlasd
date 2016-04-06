SRC = atlasd.c
OBJ = $(SRC:.c=.o)

CFLAGS += $(shell pkg-config --cflags libnl-3.0)
LDLIBS += $(shell pkg-config --libs libnl-3.0)

atlasd : $(OBJ)

clean:
	@rm -rf $(OBJ) atlasd

.PHONY: clean
