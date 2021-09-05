# Download dependencies to the dependencies directory
CC = gcc
SRC = $(shell find . -type f -name "*.c")
OBJ = $(SRC:.c=.o)
REVOLTC_SRC = $(wildcard src/*.c)
REVOLTC_OBJ = $(REVOLTC_SRC:.c=.o)
FLAGS = -g -O2
DEST = /usr/local/include/revoltc/

all: build

build: $(OBJ)

%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@

load:
	@mkdir -p src/deps/ulid
	@mkdir -p src/deps/cee-utils
	@curl https://raw.githubusercontent.com/skeeto/ulid-c/master/ulid.c > src/deps/ulid/ulid.c
	@curl https://raw.githubusercontent.com/skeeto/ulid-c/master/ulid.h > src/deps/ulid/ulid.h
	@git clone https://github.com/cee-studio/cee-utils.git src/deps/cee-utils
	@sudo rm -r src/deps/cee-utils/.git/

install:
	@mkdir -pv $(DEST)
	@cp -v $(REVOLTC_SRC) $(DEST)
	@echo Installed!

uninstall:
	@rm -rfv $(DEST)
	@echo Uninstalled!

clean:
	rm -rfv $(OBJ)

