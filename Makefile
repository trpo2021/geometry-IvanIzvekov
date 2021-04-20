CXX=g++
CFLAGS= -c -Wall -Werror
LIBG = obj/src/libgeometry
GEO = obj/src/geometry

bin/geometry.exe: $(GEO)/geometry.o $(LIBG)/infoOutput.o $(LIBG)/inputProcessing.o 
	$(CXX) -I src -Wall -Werror -o bin/geometry.exe $(GEO)/geometry.o $(LIBG)/infoOutput.o $(LIBG)/inputProcessing.o

$(LIBG)/infoOutput.o: src/libgeometry/infoOutput.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBG)/infoOutput.o src/libgeometry/infoOutput.cpp

$(LIBG)/inputProcessing.o: src/libgeometry/inputProcessing.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBG)/inputProcessing.o src/libgeometry/inputProcessing.cpp

$(GEO)/geometry.o: src/geometry/geometry.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(GEO)/geometry.o src/geometry/geometry.cpp

-include geometry.d inputProcessing.d infoOutput.d Circle.d

.PHONY: clean

clean: 
	rm -rf $(GEO)/*.o $(GEO)/*.d $(LIBG)/*.o $(LIBG)/*.d bin/*.exe
