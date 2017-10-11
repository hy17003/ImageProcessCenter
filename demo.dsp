# Microsoft Developer Studio Project File - Name="demo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=demo - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "demo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "demo.mak" CFG="demo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "demo - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "demo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "demo - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
F90=df.exe
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "demo - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
F90=df.exe
# ADD F90 /browser
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "demo - Win32 Release"
# Name "demo - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AvgDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\demo.cpp
# End Source File
# Begin Source File

SOURCE=.\demo.rc
# End Source File
# Begin Source File

SOURCE=.\demoDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\demoView.cpp
# End Source File
# Begin Source File

SOURCE=.\DIBapi.cpp
# End Source File
# Begin Source File

SOURCE=.\FFT.CPP
# End Source File
# Begin Source File

SOURCE=.\GeometryMoveDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GeometryTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\GrayTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\histogram.cpp
# End Source File
# Begin Source File

SOURCE=.\HistogramDrawDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageRestore.cpp
# End Source File
# Begin Source File

SOURCE=.\ImgCenterDib.cpp
# End Source File
# Begin Source File

SOURCE=.\ImgEnhance.cpp
# End Source File
# Begin Source File

SOURCE=.\InverseFilterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\linearStretchParamDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MaskDefineDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Match.cpp
# End Source File
# Begin Source File

SOURCE=.\MedianDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\Morphology.cpp
# End Source File
# Begin Source File

SOURCE=.\NonlinearStretchDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PhaseCorre.cpp
# End Source File
# Begin Source File

SOURCE=.\ProjectRestoreDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RegionGrowDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Register.cpp
# End Source File
# Begin Source File

SOURCE=.\RotateSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Segment.cpp
# End Source File
# Begin Source File

SOURCE=.\SpecialEffectShow.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\ThreshSegmentDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\transeform.cpp
# End Source File
# Begin Source File

SOURCE=.\transform_DCT.cpp
# End Source File
# Begin Source File

SOURCE=.\Watershed.cpp
# End Source File
# Begin Source File

SOURCE=.\WatershedParaDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WienterFilterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Zoomdlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AvgDialog.h
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\demo.h
# End Source File
# Begin Source File

SOURCE=.\demoDoc.h
# End Source File
# Begin Source File

SOURCE=.\demoView.h
# End Source File
# Begin Source File

SOURCE=.\DIBapi.h
# End Source File
# Begin Source File

SOURCE=.\FFT.H
# End Source File
# Begin Source File

SOURCE=.\FilterApi.h
# End Source File
# Begin Source File

SOURCE=.\GeometryMoveDlg.h
# End Source File
# Begin Source File

SOURCE=.\GeometryTrans.h
# End Source File
# Begin Source File

SOURCE=.\GrayTrans.h
# End Source File
# Begin Source File

SOURCE=.\histogram.h
# End Source File
# Begin Source File

SOURCE=.\HistogramDrawDlg.h
# End Source File
# Begin Source File

SOURCE=.\ImageCenterDib.h
# End Source File
# Begin Source File

SOURCE=.\ImageRestore.h
# End Source File
# Begin Source File

SOURCE=.\ImgEnhance.h
# End Source File
# Begin Source File

SOURCE=.\InverseFilterDlg.h
# End Source File
# Begin Source File

SOURCE=.\linearStretchParamDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MaskDefineDlg.h
# End Source File
# Begin Source File

SOURCE=.\Match.h
# End Source File
# Begin Source File

SOURCE=.\MedianDialog.h
# End Source File
# Begin Source File

SOURCE=.\Morphology.h
# End Source File
# Begin Source File

SOURCE=.\NonlinearStretchDlg.h
# End Source File
# Begin Source File

SOURCE=.\PhaseCorre.h
# End Source File
# Begin Source File

SOURCE=.\ProjectRestoreDlg.h
# End Source File
# Begin Source File

SOURCE=.\RegionGrowDlg.h
# End Source File
# Begin Source File

SOURCE=.\Register.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RotateSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\Segment.h
# End Source File
# Begin Source File

SOURCE=.\SpecialEffectShow.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\ThreshSegmentDlg.h
# End Source File
# Begin Source File

SOURCE=.\transeform.h
# End Source File
# Begin Source File

SOURCE=.\transform_DCT.h
# End Source File
# Begin Source File

SOURCE=.\Watershed.h
# End Source File
# Begin Source File

SOURCE=.\WatershedParaDlg.h
# End Source File
# Begin Source File

SOURCE=.\WaveletApi.h
# End Source File
# Begin Source File

SOURCE=.\WienterFilterDlg.h
# End Source File
# Begin Source File

SOURCE=.\Zoomdlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\demo.ico
# End Source File
# Begin Source File

SOURCE=.\res\demo.rc2
# End Source File
# Begin Source File

SOURCE=.\res\demoDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\OK.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
