CC = g++

#Linux path
#ROOTPATH = <PATH_TO_CLAPACK>/clapack-3.2.1-CMAKE
#INCDIRS = -I$(ROOTPATH)/INCLUDE
#CLAPLIB = $(ROOTPATH)/lapack_LINUX.a
#BLASLIB = $(ROOTPATH)/blas_LINUX.a
#F2CLIB = $(ROOTPATH)/F2CLIBS/libf2c.a

#Mac path
ROOTPATH = <PATH_TO_CLAPACK>/clapack-3.2.1-CMAKE
INCDIRS = -I$(ROOTPATH)/INCLUDE
CLAPLIB = $(ROOTPATH)/lapack_MAC.a
BLASLIB = $(ROOTPATH)/blas_MAC.a
F2CLIB = $(ROOTPATH)/F2CLIBS/libf2c.a

#common command
#LDLIBS  = $(CLAPLIB) $(BLASLIB) $(F2CLIB) -lm #$(BLWRLIB) -lm
LDLIBS  = $(CLAPLIB) $(BLASLIB) $(F2CLIB) -lm

CLVTreeScaper:
				$(CC) CLVmain.cpp -w randgen.cpp wstring.cpp warray.cpp wmapping.cpp wmix.cpp wfile.cpp wimport_form.cpp wDimEst.cpp wNLDR.cpp Trees.cpp TreeOPE.cpp Sparse_matrix.cpp greedy_louvain.cpp graph.cpp slicer.cpp label-map.cc community.cpp info.cpp hashfunc.cc hash.cc hungarian.c ClusterForest.cpp ClusterInstance.cpp Forest.cpp rspr.cpp SiblingPair.cpp SPRLCA.cpp SPRNode.cpp UndoMachine.cpp $(LDLIBS) $(INCDIRS) -DCOMMAND_LINE_VERSION -o CLVTreeScaper
				
CLVclean:
				rm -f CLVTreeScaper
