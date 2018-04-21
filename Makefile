all: 
	-cd src && $(MAKE) all
	-cd tests && $(MAKE) all

clean:
	-cd ejemplo && $(MAKE) clean
	-cd src && $(MAKE) clean
	-cd tests && $(MAKE) clean

test: all
	-cd tests && $(MAKE) test