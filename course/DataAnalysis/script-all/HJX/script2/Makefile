OBJ = ppac #生成的可执行文件名字

# ------------------
SourceFile = main.cpp ppac.h ppac.cpp
#SourceFile := $(wildcard $(shell pwd)/*.c $(shell pwd)/*.cc $(shell pwd)/*.C $(shell pwd)/*.cpp $(shell pwd)/*.cxx)
#OBJ = $(subst,.cpp,.o,$(filter %.cpp,$(sourcefile)))

# ------------------

GXX = g++ -Wl,--no-as-needed
#-std=c++0x

ROOTCFLAGS  = $(shell root-config --cflags) # -pthread -std=c++11 -m64 -I$(ROOTSYS)/include
DIR_INC = -I$(shell pwd)/include $(ROOTCFLAGS)

CFLAGS  = -g -Wall -O2  -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -lXMLParser

ROOTLIBS    = $(shell root-config --libs)  # -L$(ROOTSYS)/lib -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -pthread -lm -ldl -rdynamic
ROOTGLIBS   = $(shell root-config --glibs) # -L$(ROOTSYS)/lib -lGui -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -pthread -lm -ldl -rdynamic
ROOTADDLIBS = -lSpectrum
DIR_LIB = $(ROOTLIBS) $(ROOTGLIBS) $(ROOTADDLIBS)

# ------------------

all:$(OBJ)

$(OBJ): $(SourceFile)
	$(GXX) $(DIR_INC) $(CFLAGS) $(DIR_LIB) -o $@ $(SourceFile)
	@echo "=============================================================="
	@echo "$@ done !"
	@echo "=============================================================="
clean:
	@echo "Removing linked and compiled files......" 
	rm -f *.o *~ $(OBJ)



######################################################################
### Makefile ends here
