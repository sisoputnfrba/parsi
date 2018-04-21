RM=rm -rf
CC=gcc -Wall


C_SRCS=$(shell find . -iname "*.c" | tr '\n' ' ')
OBJS=$(C_SRCS:./%.c=build/%.o)

all: build/tests

create-dirs:
	mkdir -p build

build/tests: dependents create-dirs $(OBJS)
	$(CC) -L"../src/build" -L"../so-commons-library/src/build" -L"../cspec/release" -o "build/tests" $(OBJS) -lparsi -lcommons -lcspecs

build/%.o: ./%.c
	$(CC) -I"../src" -I"../so-commons-library/src" -I"../cspec" -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"

debug: CC += -DDEBUG -g
debug: all

clean:
	$(RM) build

test: all
	LD_LIBRARY_PATH="../src/build/:../so-commons-library/src/build/:../cspec/release" build/tests

dependents: install-deps
	-cd ../src/ && $(MAKE) all

install-deps: install-cspec install-commons

install-cspec: submodules
	-cd ../cspec && $(MAKE) all

install-commons: submodules
	-cd ../so-commons-library && $(MAKE) all

submodules:
	-git submodule init && git submodule update

.PHONY: all create-dirs clean submodules dependents install-deps install-cspec install-commons submodules