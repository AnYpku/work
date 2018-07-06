### Makefile --- 
## 
## Description: 
## Author: Hongyi Wu(吴鸿毅)
## Email: wuhongyi@qq.com 
## Created: 五 1月 19 12:14:48 2018 (+0800)
## Last-Updated: 日 3月 11 17:19:11 2018 (+0800)
##           By: Hongyi Wu(吴鸿毅)
##     Update #: 11
## URL: http://wuhongyi.cn 


OBJ = ppac #生成的可执行文件名字

# ------------------

SourceFile := $(wildcard $(shell pwd)/*.c $(shell pwd)/*.cc $(shell pwd)/*.C $(shell pwd)/*.cpp $(shell pwd)/*.cxx)

# ------------------

GXX = g++ 

ROOTCFLAGS  = $(shell root-config --cflags) # -pthread -std=c++11 -m64   dir include
ROOTLIBS    = $(shell root-config --libs)  # dir lib   -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -pthread -lm -ldl -rdynamic
ROOTGLIBS   = $(shell root-config --glibs) # dir lib   -lGui -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -pthread -lm -ldl -rdynamic
ROOTADDLIBS = -lSpectrum

# ------------------

## 用户补充需要加载的库
DIR_INC = -I$(shell pwd)/include $(ROOTCFLAGS)
DIR_LIB = $(ROOTLIBS) $(ROOTGLIBS) $(ROOTADDLIBS)
CFLAGS  = -g -Wall -O2  -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64

# ------------------

all:$(OBJ)

$(OBJ): $(SourceFile)
	$(GXX) $(DIR_INC) $(CFLAGS) $(DIR_LIB) -o $@ $(SourceFile)
	@echo "=============================================================="
	@echo "$@ done !"
	@echo "=============================================================="
clean:
	@echo "Removing linked and compiled files......" 
	rm -rf *.o *~ $(OBJ)
    



######################################################################
### Makefile ends here
