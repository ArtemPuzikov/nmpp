include $(ROOT)/global.mk
# BUILD AND RUN MAKEFILE
# This makefile builds simple nmc-application containing single cpp-file  
# Rule 'run' executes the application on MB7707 board and stores return code in ".exitcode"  file

.SUFFIXES:



ifndef MB7707
$(warning*** WARNING: 'MB7707' environment variable is not defined! Board SDK might not have installed correctly. )
endif 

ifndef NMPP
$(error *** ERROR: 'NMPP' environment variable is not defined!  )
endif 

PATH:=$(MB7707)/bin;$(PATH)

INC_DIRS = -I"$(NMPP)/include" -I"$(MB7707)/include"
LIB_DIRS = -L"$(NMPP)/lib"  -L"$(MB7707)/lib" -L$(NM_IO)/lib
LIBS     = mb7707lib.lib nmpp-nmc3d.lib libint_soc.lib libc05.lib cppnew05.lib 
TARGET   = main.abs
CFG      = mb7707brd.cfg
SRC_CPP  = $(wildcard $(addsuffix /*.cpp,..))
SRC_ASM  = $(wildcard $(addsuffix /*.asm,..))

VPATH    = $(subst -L,,$(LIB_DIRS)) $(NEURO)/lib

$(TARGET): $(SRC_CPP)  $(CFG)   Makefile $(NMPP)/lib/nmpp-nmc3d.lib
	@echo $(CURDIR)>> $(ROOT)/app/test/build-mb7707.txt
	nmcc -o$(TARGET) -m.main.map $(SRC_CPP) $(SRC_ASM) -soc -g -O0 $(INC_DIRS) $(LIB_DIRS) $(LIBS) -c$(CFG) -heap=14384 -heap1=16384 -heap2=16384 -heap3=16384
	@echo -OK>> $(ROOT)/app/test/build-mb7707.txt
#                                                                                         [L00]:64kB   [L01]:64kB  [G00]:64kB   [G01]:64kB

run: .exitcode

ifeq ($(OS),Windows_NT)	
.exitcode: $(TARGET) .exitrun.bat
	.exitrun.bat 
	
.exitrun.bat: 
	@echo "$(MB7707)/bin/mb7707run" -a$(MB7707_MAC) $(TARGET) >.exitrun.bat
	@echo @echo %%errorlevel%% ^>.exitcode >>.exitrun.bat
else 
.exitcode: $(TARGET)
	mb7707run ./$(TARGET) ; echo $$? > .exitcode
endif

		
include $(ROOT)/clean.mk	

	

