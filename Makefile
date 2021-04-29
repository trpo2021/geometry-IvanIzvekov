CXX=g++
CFLAGS= -c -Wall -Werror
LIBG = obj/src/libgeometry
GEO = obj/src/geometry

all: bin/geometry.exe

bin/geometry.exe: $(GEO)/geometry.o $(LIBG)/infoOutput.o $(LIBG)/inputProcessing.o 
	$(CXX) -I src -Wall -Werror -o bin/geometry.exe $(GEO)/geometry.o $(LIBG)/infoOutput.o $(LIBG)/inputProcessing.o

$(LIBG)/infoOutput.o: src/libgeometry/infoOutput.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBG)/infoOutput.o src/libgeometry/infoOutput.cpp

$(LIBG)/inputProcessing.o: src/libgeometry/inputProcessing.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBG)/inputProcessing.o src/libgeometry/inputProcessing.cpp

$(GEO)/geometry.o: src/geometry/geometry.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(GEO)/geometry.o src/geometry/geometry.cpp

-include geometry.d inputProcessing.d infoOutput.d Circle.d catch.d

test: bin/test

bin/test: $(LIBG)/inputProcessing.o obj/test/test.o $(LIBG)/infoOutput.o
	$(CXX) -I src -Wall -Werror -o bin/test $(LIBG)/inputProcessing.o obj/test/test.o $(LIBG)/infoOutput.o

obj/test/test.o: test/test.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o obj/test/test.o test/test.cpp

-include geometry.d inputProcessing.d infoOutput.d Circle.d ../thirdparty/catch.d

.PHONY: clean

clean: 
	rm -rf $(GEO)/*.o $(GEO)/*.d $(LIBG)/*.o $(LIBG)/*.d bin/*.exe
