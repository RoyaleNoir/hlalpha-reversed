# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=hl - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to hl - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "hl - Win32 Release" && "$(CFG)" != "hl - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "hl.mak" CFG="hl - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "hl - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "hl - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "hl - Win32 Debug"
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "hl - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\hl.dll"

CLEAN : 
	-@erase "$(INTDIR)\cbase.obj"
	-@erase "$(INTDIR)\client.obj"
	-@erase "$(INTDIR)\globals.obj"
	-@erase "$(INTDIR)\h_export.obj"
	-@erase "$(INTDIR)\player.obj"
	-@erase "$(INTDIR)\sound.obj"
	-@erase "$(INTDIR)\subs.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\weapons.obj"
	-@erase "$(INTDIR)\world.obj"
	-@erase "$(OUTDIR)\hl.dll"
	-@erase "$(OUTDIR)\hl.exp"
	-@erase "$(OUTDIR)\hl.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /G5 /MT /W3 /GX /Zi /O2 /I "..\engine" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "QUIVER" /D "VOXEL" /D "QUAKE2" /D "VALVE_DLL" /YX /c
CPP_PROJ=/nologo /G5 /MT /W3 /GX /Zi /O2 /I "..\engine" /D "NDEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "QUIVER" /D "VOXEL" /D "QUAKE2" /D "VALVE_DLL"\
 /Fp"$(INTDIR)/hl.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x1409 /d "NDEBUG"
# ADD RSC /l 0x1409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/hl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /def:".\hl.def"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/hl.pdb" /machine:I386 /def:".\hl.def" /out:"$(OUTDIR)/hl.dll"\
 /implib:"$(OUTDIR)/hl.lib" 
LINK32_OBJS= \
	"$(INTDIR)\cbase.obj" \
	"$(INTDIR)\client.obj" \
	"$(INTDIR)\globals.obj" \
	"$(INTDIR)\h_export.obj" \
	"$(INTDIR)\player.obj" \
	"$(INTDIR)\sound.obj" \
	"$(INTDIR)\subs.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\weapons.obj" \
	"$(INTDIR)\world.obj"

"$(OUTDIR)\hl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "hl - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\hl.dll"

CLEAN : 
	-@erase "$(INTDIR)\cbase.obj"
	-@erase "$(INTDIR)\client.obj"
	-@erase "$(INTDIR)\globals.obj"
	-@erase "$(INTDIR)\h_export.obj"
	-@erase "$(INTDIR)\player.obj"
	-@erase "$(INTDIR)\sound.obj"
	-@erase "$(INTDIR)\subs.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\weapons.obj"
	-@erase "$(INTDIR)\world.obj"
	-@erase "$(OUTDIR)\hl.dll"
	-@erase "$(OUTDIR)\hl.exp"
	-@erase "$(OUTDIR)\hl.ilk"
	-@erase "$(OUTDIR)\hl.lib"
	-@erase "$(OUTDIR)\hl.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /G5 /MTd /W3 /Gm /GX /Zi /Od /I "..\engine" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "QUIVER" /D "VOXEL" /D "QUAKE2" /D "VALVE_DLL" /YX /c
CPP_PROJ=/nologo /G5 /MTd /W3 /Gm /GX /Zi /Od /I "..\engine" /D "_DEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "QUIVER" /D "VOXEL" /D "QUAKE2" /D "VALVE_DLL"\
 /Fp"$(INTDIR)/hl.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x1409 /d "_DEBUG"
# ADD RSC /l 0x1409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/hl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /def:".\hl.def"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)/hl.pdb" /debug /machine:I386 /def:".\hl.def"\
 /out:"$(OUTDIR)/hl.dll" /implib:"$(OUTDIR)/hl.lib" 
LINK32_OBJS= \
	"$(INTDIR)\cbase.obj" \
	"$(INTDIR)\client.obj" \
	"$(INTDIR)\globals.obj" \
	"$(INTDIR)\h_export.obj" \
	"$(INTDIR)\player.obj" \
	"$(INTDIR)\sound.obj" \
	"$(INTDIR)\subs.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\weapons.obj" \
	"$(INTDIR)\world.obj"

"$(OUTDIR)\hl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "hl - Win32 Release"
# Name "hl - Win32 Debug"

!IF  "$(CFG)" == "hl - Win32 Release"

!ELSEIF  "$(CFG)" == "hl - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\cbase.cpp
DEP_CPP_CBASE=\
	"..\engine\const.h"\
	"..\engine\eiface.h"\
	"..\engine\progdefs.h"\
	".\cbase.h"\
	".\enginecallback.h"\
	".\extdll.h"\
	".\util.h"\
	".\vector.h"\
	

"$(INTDIR)\cbase.obj" : $(SOURCE) $(DEP_CPP_CBASE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\cbase.h

!IF  "$(CFG)" == "hl - Win32 Release"

!ELSEIF  "$(CFG)" == "hl - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\client.cpp
DEP_CPP_CLIEN=\
	"..\engine\const.h"\
	"..\engine\eiface.h"\
	"..\engine\progdefs.h"\
	".\cbase.h"\
	".\client.h"\
	".\enginecallback.h"\
	".\extdll.h"\
	".\player.h"\
	".\util.h"\
	".\vector.h"\
	

"$(INTDIR)\client.obj" : $(SOURCE) $(DEP_CPP_CLIEN) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\client.h

!IF  "$(CFG)" == "hl - Win32 Release"

!ELSEIF  "$(CFG)" == "hl - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\enginecallback.h

!IF  "$(CFG)" == "hl - Win32 Release"

!ELSEIF  "$(CFG)" == "hl - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\extdll.h

!IF  "$(CFG)" == "hl - Win32 Release"

!ELSEIF  "$(CFG)" == "hl - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\globals.cpp
DEP_CPP_GLOBA=\
	"..\engine\const.h"\
	"..\engine\eiface.h"\
	"..\engine\progdefs.h"\
	".\cbase.h"\
	".\enginecallback.h"\
	".\extdll.h"\
	".\util.h"\
	".\vector.h"\
	

"$(INTDIR)\globals.obj" : $(SOURCE) $(DEP_CPP_GLOBA) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\h_export.cpp
DEP_CPP_H_EXP=\
	"..\engine\const.h"\
	"..\engine\eiface.h"\
	"..\engine\progdefs.h"\
	".\cbase.h"\
	".\enginecallback.h"\
	".\extdll.h"\
	".\util.h"\
	".\vector.h"\
	

"$(INTDIR)\h_export.obj" : $(SOURCE) $(DEP_CPP_H_EXP) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\player.cpp
DEP_CPP_PLAYE=\
	"..\engine\const.h"\
	"..\engine\eiface.h"\
	"..\engine\progdefs.h"\
	".\cbase.h"\
	".\enginecallback.h"\
	".\extdll.h"\
	".\player.h"\
	".\util.h"\
	".\vector.h"\
	".\weapons.h"\
	

"$(INTDIR)\player.obj" : $(SOURCE) $(DEP_CPP_PLAYE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\player.h

!IF  "$(CFG)" == "hl - Win32 Release"

!ELSEIF  "$(CFG)" == "hl - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\sound.cpp
DEP_CPP_SOUND=\
	"..\engine\const.h"\
	"..\engine\eiface.h"\
	"..\engine\progdefs.h"\
	".\cbase.h"\
	".\enginecallback.h"\
	".\extdll.h"\
	".\player.h"\
	".\util.h"\
	".\vector.h"\
	".\weapons.h"\
	

"$(INTDIR)\sound.obj" : $(SOURCE) $(DEP_CPP_SOUND) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\subs.cpp
DEP_CPP_SUBS_=\
	"..\engine\const.h"\
	"..\engine\eiface.h"\
	"..\engine\progdefs.h"\
	".\cbase.h"\
	".\enginecallback.h"\
	".\extdll.h"\
	".\util.h"\
	".\vector.h"\
	

"$(INTDIR)\subs.obj" : $(SOURCE) $(DEP_CPP_SUBS_) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\util.cpp
DEP_CPP_UTIL_=\
	"..\engine\const.h"\
	"..\engine\eiface.h"\
	"..\engine\progdefs.h"\
	".\cbase.h"\
	".\enginecallback.h"\
	".\extdll.h"\
	".\util.h"\
	".\vector.h"\
	

"$(INTDIR)\util.obj" : $(SOURCE) $(DEP_CPP_UTIL_) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\util.h

!IF  "$(CFG)" == "hl - Win32 Release"

!ELSEIF  "$(CFG)" == "hl - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\vector.h

!IF  "$(CFG)" == "hl - Win32 Release"

!ELSEIF  "$(CFG)" == "hl - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\weapons.cpp
DEP_CPP_WEAPO=\
	"..\engine\const.h"\
	"..\engine\eiface.h"\
	"..\engine\progdefs.h"\
	".\cbase.h"\
	".\enginecallback.h"\
	".\extdll.h"\
	".\player.h"\
	".\util.h"\
	".\vector.h"\
	".\weapons.h"\
	

"$(INTDIR)\weapons.obj" : $(SOURCE) $(DEP_CPP_WEAPO) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\weapons.h

!IF  "$(CFG)" == "hl - Win32 Release"

!ELSEIF  "$(CFG)" == "hl - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\world.cpp
DEP_CPP_WORLD=\
	"..\engine\const.h"\
	"..\engine\eiface.h"\
	"..\engine\progdefs.h"\
	".\cbase.h"\
	".\enginecallback.h"\
	".\extdll.h"\
	".\util.h"\
	".\vector.h"\
	

"$(INTDIR)\world.obj" : $(SOURCE) $(DEP_CPP_WORLD) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
