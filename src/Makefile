RM=rm -rf
CC=gcc -Wall

C_SRCS=$(shell find . -iname "*.c" | tr '\n' ' ')
H_SRCS=$(shell find . -iname "*.h" | tr '\n' ' ')
OBJS=$(C_SRCS:./%.c=build/%.o)

# Clean and compile .so
all: build/libparsi.so

create-dirs:
	mkdir -p build/parsi/

build/libparsi.so: dependents create-dirs $(OBJS)
	$(CC) -L"../so-commons-library/src/build" -shared -o "build/libparsi.so" $(OBJS) -lcommons

build/parsi/%.o: parsi/%.c
	$(CC) -I"../so-commons-library/src" -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"

# Add debug parameters and compile
debug: CC += -DDEBUG -g
debug: all

# Clean build files
clean:
	$(RM) build

install: all
	cp -u build/libparsi.so /usr/lib
	cp --parents -u $(H_SRCS) /usr/include

uninstall:
	rm -f /usr/lib/libparsi.so
	rm -rf /usr/include/parsi

dependents: install-commons

install-commons: submodules
	-cd ../so-commons-library && $(MAKE) all

submodules:
	-git submodule init && git submodule update

.PHONY: all create-dirs clean install uninstall dependents install-commons submodules
