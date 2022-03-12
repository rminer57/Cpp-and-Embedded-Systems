# Microsoft Developer Studio Project File - Name="SequenceGenerator" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=SequenceGenerator - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SequenceGenerator.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SequenceGenerator.mak" CFG="SequenceGenerator - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SequenceGenerator - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SequenceGenerator - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "SequenceGenerator"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SequenceGenerator - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "SequenceGenerator - Win32 Debug"

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
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "SequenceGenerator - Win32 Release"
# Name "SequenceGenerator - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "rfasm"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\actions.cpp
# End Source File
# Begin Source File

SOURCE=.\actions.h
# End Source File
# Begin Source File

SOURCE=.\actionsent.cpp
# End Source File
# Begin Source File

SOURCE=.\argument.cpp
# End Source File
# Begin Source File

SOURCE=.\argument.h
# End Source File
# Begin Source File

SOURCE=.\asminstruction.cpp
# End Source File
# Begin Source File

SOURCE=.\asminstruction.h
# End Source File
# Begin Source File

SOURCE=.\assemble.cpp
# End Source File
# Begin Source File

SOURCE=.\exception.h
# End Source File
# Begin Source File

SOURCE=.\execinstruction.cpp
# End Source File
# Begin Source File

SOURCE=.\execinstruction.h
# End Source File
# Begin Source File

SOURCE=.\jumpinstruction.cpp
# End Source File
# Begin Source File

SOURCE=.\jumpinstruction.h
# End Source File
# Begin Source File

SOURCE=.\keyword.h
# End Source File
# Begin Source File

SOURCE=.\lexana.cpp
# End Source File
# Begin Source File

SOURCE=.\LexAna.h
# End Source File
# Begin Source File

SOURCE=.\RegularExpression.cpp
# End Source File
# Begin Source File

SOURCE=.\RegularExpression.h
# End Source File
# Begin Source File

SOURCE=.\rfinstruction.cpp
# End Source File
# Begin Source File

SOURCE=.\rfInstruction.h
# End Source File
# Begin Source File

SOURCE=.\statemachine.cpp
# End Source File
# Begin Source File

SOURCE=.\statemachine.h
# End Source File
# Begin Source File

SOURCE=.\symboltable.cpp
# End Source File
# Begin Source File

SOURCE=.\symboltable.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\AddToDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\ComponentExecDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\DataStorageDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\DefaultHelpDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\EditCommandDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\EnterComponentDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\EnterInterfaceDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\ErrorMessageDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\ExtendedHelpDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\InterfaceExecDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\Jump2OffsetDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\JumpComparisonDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\JumpOffsetDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\LabelCommentDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MiscOperationDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\MoveDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\ommandHelpDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\OperationManipDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectDataDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectRRegisterExecDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\SequenceCommandBaseClass.cpp
# End Source File
# Begin Source File

SOURCE=.\SequenceExecuteClass.cpp
# End Source File
# Begin Source File

SOURCE=.\SequenceGenerator.cpp
# End Source File
# Begin Source File

SOURCE=.\SequenceGenerator.rc
# End Source File
# Begin Source File

SOURCE=.\SequenceGeneratorDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\SequenceGeneratorView.cpp
# End Source File
# Begin Source File

SOURCE=.\SequenceJumpClass.cpp
# End Source File
# Begin Source File

SOURCE=.\SequenceManipulate.cpp
# End Source File
# Begin Source File

SOURCE=.\SequenceMiscClass.cpp
# End Source File
# Begin Source File

SOURCE=.\SequencerList.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AddToDialog.h
# End Source File
# Begin Source File

SOURCE=.\ComponentExecDialog.h
# End Source File
# Begin Source File

SOURCE=.\DataStorageDialog.h
# End Source File
# Begin Source File

SOURCE=.\DefaultHelpDialog.h
# End Source File
# Begin Source File

SOURCE=.\EditCommandDialog.h
# End Source File
# Begin Source File

SOURCE=.\EnterComponentDialog.h
# End Source File
# Begin Source File

SOURCE=.\EnterInterfaceDialog.h
# End Source File
# Begin Source File

SOURCE=.\ErrorMessageDialog.h
# End Source File
# Begin Source File

SOURCE=.\ExtendedHelpDialog.h
# End Source File
# Begin Source File

SOURCE=.\InterfaceExecDialog.h
# End Source File
# Begin Source File

SOURCE=.\Jump2OffsetDialog.h
# End Source File
# Begin Source File

SOURCE=.\JumpComparisonDialog.h
# End Source File
# Begin Source File

SOURCE=.\JumpOffsetDialog.h
# End Source File
# Begin Source File

SOURCE=.\LabelCommentDialog.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MiscOperationDialog.h
# End Source File
# Begin Source File

SOURCE=.\MoveDialog.h
# End Source File
# Begin Source File

SOURCE=.\ommandHelpDialog.h
# End Source File
# Begin Source File

SOURCE=.\OperationManipDialog.h
# End Source File
# Begin Source File

SOURCE=.\RegisterType.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SelectDataDialog.h
# End Source File
# Begin Source File

SOURCE=.\SelectRRegisterExecDialog.h
# End Source File
# Begin Source File

SOURCE=.\SequenceCommandBaseClass.h
# End Source File
# Begin Source File

SOURCE=.\SequenceExecuteClass.h
# End Source File
# Begin Source File

SOURCE=.\SequenceGenerator.h
# End Source File
# Begin Source File

SOURCE=.\SequenceGeneratorDoc.h
# End Source File
# Begin Source File

SOURCE=.\SequenceGeneratorView.h
# End Source File
# Begin Source File

SOURCE=.\SequenceJumpClass.h
# End Source File
# Begin Source File

SOURCE=.\SequenceManipulate.h
# End Source File
# Begin Source File

SOURCE=.\SequenceMiscClass.h
# End Source File
# Begin Source File

SOURCE=.\SequencerList.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\RES\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\RES\icon2.ico
# End Source File
# Begin Source File

SOURCE=.\RES\question.cur
# End Source File
# Begin Source File

SOURCE=.\res\SequenceGenerator.ico
# End Source File
# Begin Source File

SOURCE=.\res\SequenceGenerator.rc2
# End Source File
# Begin Source File

SOURCE=.\res\SequenceGeneratorDoc.ico
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
