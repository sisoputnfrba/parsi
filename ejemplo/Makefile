RM=rm -rf
CC=gcc -Wall


C_SRCS=$(shell find . -iname "*.c" | tr '\n' ' ')
OBJS=$(C_SRCS:./%.c=build/%.o)

all: build/ejemplo

create-dirs:
	mkdir -p build

build/ejemplo: dependents create-dirs $(OBJS)
	$(CC) -L"../so-commons-library/src/build" -L"../src/build" -o "build/ejemplo" $(OBJS) -lcommons -lparsi

build/%.o: ./%.c
	$(CC) -I"../so-commons-library/src" -I"../src" -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"

debug: CC += -DDEBUG -g
debug: all

clean:
	$(RM) build

run: all
	LD_LIBRARY_PATH="../src/build/:../so-commons-library/src/build" build/ejemplo

dependents: install-commons
	-cd ../src && $(MAKE) all

install-commons: submodules
	-cd ../so-commons-library && $(MAKE) all

submodules:
	-git submodule init && git submodule update

try-it: all
	-LD_LIBRARY_PATH="../src/build/:../so-commons-library/src/build/" build/ejemplo ./script.esi

.PHONY: all create-dirs clean dependents install-commons submodules