; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "hexadoku.h"
LastPage=0

ClassCount=6
Class1=CHexadokuApp
Class2=CHexadokuDoc
Class3=CHexadokuView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CEditSquareDlg
Resource2=IDD_ABOUTBOX

[CLS:CHexadokuApp]
Type=0
HeaderFile=hexadoku.h
ImplementationFile=hexadoku.cpp
Filter=N

[CLS:CHexadokuDoc]
Type=0
HeaderFile=hexadokuDoc.h
ImplementationFile=hexadokuDoc.cpp
Filter=N

[CLS:CHexadokuView]
Type=0
HeaderFile=hexadokuView.h
ImplementationFile=hexadokuView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CHexadokuView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=hexadoku.cpp
ImplementationFile=hexadoku.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_VIEW_HEX
Command3=ID_APP_EXIT
Command4=ID_CALC
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_SETLEVEL
Command7=ID_EDIT_KILLLEVEL
Command8=ID_APP_ABOUT
CommandCount=8

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CEditSquareDlg]
Type=0
HeaderFile=EditSquareDlg.h
ImplementationFile=EditSquareDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CEditSquareDlg

