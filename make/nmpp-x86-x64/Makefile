ROOT             = ../..
include          $(ROOT)/global.mk
VS8       = Visual_Studio_8_2005
VS12      = Visual_Studio_12_2013
VS12X64   = Visual_Studio_12_2013_Win64
VS14      = Visual_Studio_14_2014
VS14X64   = Visual_Studio_14_2014_Win64
MINGW     = d:/SDK/MinGW

.PHONY: mingw unix;

ifeq ($(OS),Windows_NT)
  SHELL = cmd
  WHICH = where
  RMALL = del /Q /A:A                  
  RMDIR = rmdir /Q /S
  MKDIR = mkdir  
  CPDIR = xcopy /e /y
  CP    = copy                
  MV    = move                 
  ECHO  = echo  
  define OSX
	$(subst /,\,$(1))
  endef  
  export CC = gcc
else
  WHICH = which
  RMALL = rm -f                 
  RMDIR = rm -fr               
  MKDIR = mkdir -p             
  CPDIR = cp -r                
  CP    = cp                   
  MV    = mv                   
  ECHO  = echo    
  define OSX
	$(subst \,/,$(1))
  endef  
endif
#	$(CP)		$(call OSX,$(VS8)/Debug/*.lib) 	$(call OSX,../../lib/)
#	$(CP)  		$(call OSX,$(VS8)/Release/*.lib) $(call OSX,../../lib/)


all: vs2015

#vs8 vs12 vs12x64 vs12x64 unix mingw
					   
configure-vs8   $(VS8)/nmpp-x86.vcproj: 
	-$(RMDIR)	$(VS8)
	$(MKDIR) 	$(VS8)
	cd    		$(VS8) &&	cmake .. -G "Visual Studio 8 2005"
            
#vs8:            $(VS8)/nmpp-x86.vcproj
#	cd    		$(VS8) && "$(VS80COMNTOOLS)vsvars32" && vcbuild nmpp-x86.vcproj
	

	
configure-vs12 $(VS12)/nmpp-x86.vcxproj:
	-$(RMDIR)	$(VS12)
	$(MKDIR)	$(VS12)
	cd    		$(VS12) &&	cmake .. -G "Visual Studio 12 2013"

	
vs12: 			$(VS12)/nmpp-x86.vcxproj
	cd    		$(VS12) && "$(VS120COMNTOOLS)vsvars32" && msbuild nmpp-x86.vcxproj
	cd    		$(VS12) && "$(VS120COMNTOOLS)vsvars32" && msbuild nmpp-x86.vcxproj /p:Configuration=Release

configure-vs12x64 $(VS12X64)/nmpp-x64.vcxproj:
	-$(RMDIR) 	$(VS12X64)
	$(MKDIR) 	$(VS12X64)
	cd    		$(VS12X64) &&	cmake .. -G  "Visual Studio 12 2013 Win64"

vs12x64:        $(VS12X64)/nmpp-x64.vcxproj
	cd    		$(VS12X64) && "$(VS120COMNTOOLS)vsvars32" && msbuild nmpp-x64.vcxproj
	cd    		$(VS12X64) && "$(VS120COMNTOOLS)vsvars32" && msbuild nmpp-x64.vcxproj /p:Configuration=Release

configure-vs14  $(VS14)/nmpp-x86.vcxproj:
	-$(RMDIR)   $(VS14)
	$(MKDIR) 	$(VS14)
	cd    		$(VS14) &&	cmake .. -G  "Visual Studio 14 2015"

vs14:           $(VS14)/nmpp-x86.vcxproj
	cd    		$(VS14) && "$(VS140COMNTOOLS)vsvars32" && msbuild nmpp-x86.vcxproj
	cd    		$(VS14) && "$(VS140COMNTOOLS)vsvars32" && msbuild nmpp-x86.vcxproj /p:Configuration=Release

configure-vs14x64 		$(VS14X64)/nmpp-x64.vcxproj:
	-$(RMDIR)   $(VS14X64)
	$(MKDIR) 	$(VS14X64)
	cd   		$(VS14X64) &&	cmake .. -G  "Visual Studio 14 2015 Win64"

vs14x64:        $(VS14X64)/nmpp-x64.vcxproj
	cd    		$(VS14X64) && "$(VS140COMNTOOLS)vsvars32" && msbuild nmpp-x64.vcxproj
	cd    		$(VS14X64) && "$(VS140COMNTOOLS)vsvars32" && msbuild nmpp-x64.vcxproj /p:Configuration=Release
	
configure-mingw MinGW/Makefile:
	-$(RMDIR)   MinGW	
	$(MKDIR) 	MinGW
	cd    		MinGW && cmake .. -G "MinGW Makefiles"
#	cd    		MinGW && set path=$(MINGW)/bin;$(PATH) &&	cmake .. -G "MinGW Makefiles" 

mingw: MinGW/Makefile
	$(MAKE) -C MinGW 
	
configure-unix Unix/Makefile:     
	-$(RMDIR)   Unix	
	$(MKDIR)    Unix
	cd          Unix &&  cmake .. -G "Unix Makefiles" 
#	cd          Unix &&  set path=$(MINGW)/bin;$(PATH) && cmake .. -G "Unix Makefiles" -DCMAKE_POSITION_INDEPENDENT_CODE=ON
	
unix: Unix/Makefile
	$(MAKE) -C Unix
#	-DCMAKE_C_COMPILER="d:/SDK/MinGW/bin/gcc" -DCMAKE_CXX_COMPILER="d:/SDK/MinGW/bin/g++"  -DCMAKE_MAKE_PROGRAM="d:/SDK/MinGW/bin/mingw32-make" 



gmake:
	$(CP) Makefile .Makefile.origin
	premake5 gmake
	$(CP) Makefile .Makefile.premake
	$(CP) .Makefile.origin Makefile
	$(MAKE) -f .Makefile.premake nmpp-x86
	
	

vs2005:    	nmpp-x86.vcproj
	"$(VS80COMNTOOLS)vsvars32" && vcbuild nmpp-x86.vcproj

vs2015:    	nmpp-x86.vcxproj
	"$(VS140COMNTOOLS)vsvars32" && msbuild nmpp-x86.vcxproj /p:Configuration=Debug
	


nmpp-x86.vcxproj :	premake5.lua 
	premake5 vs2015

	
nmpp-x86.vcproj :	premake5.lua 
	premake5 vs2005

include $(ROOT)/clean.mk
	