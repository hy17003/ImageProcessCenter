; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDemoView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "demo.h"
LastPage=0

ClassCount=22
Class1=CDemoApp
Class2=CDemoDoc
Class3=CDemoView
Class4=CMainFrame

ResourceCount=39
Resource1=IDD_Dlg_RotateSet
Resource2=IDD_Dlg_MaskDefine
Class5=CChildFrame
Class6=CAboutDlg
Resource3=IDD_Dlg_ThreshSegment
Class7=linearStretchParamDlg
Resource4=IDD_Dlg_ProjectionRes (Chinese (P.R.C.))
Class8=HistogramDrawDlg
Class9=morphologyDlg
Resource5=IDD_Dlg_MaskDefine (Chinese (P.R.C.))
Class10=BinaryMorphMaskSelect
Resource6=IDD_ABOUTBOX
Class11=MaskDefineDlg
Resource7=IDD_Dlg_Move
Class12=ThreshSegmentDlg
Resource8=IDD_Dlg_InverseFilter
Class13=Zoomdlg
Resource9=IDD_Dlg_ProjectionRes
Class14=RotateSetDlg
Resource10=IDD_Dlg_InverseFilter (English (U.S.))
Class15=DuiShuStretchDlg
Class16=NonlinearStretchDlg
Resource11=IDD_Dlg_Zoom
Class17=GeometryMoveDlg
Resource12=IDD_Dlg_Watershed
Class18=RegionGrowDlg
Class19=WatershedParaDlg
Resource13=IDD_Dlg_WienerFilter (English (U.S.))
Resource14=IDR_DEMOTYPE (Chinese (P.R.C.))
Resource15=IDD_Dlg_RotateSet (Chinese (P.R.C.))
Resource16=IDD_Dlg_Move (Chinese (P.R.C.))
Resource17=IDD_Dlg_WienerFilter
Resource18=IDD_Dlg_HistogramDraw (Chinese (P.R.C.))
Resource19=IDD_Dlg_RegionGrow (Chinese (P.R.C.))
Resource20=IDD_Dlg_ThreshSegment (Chinese (P.R.C.))
Resource21=IDR_MAINFRAME (Chinese (P.R.C.))
Resource22=IDD_MEDIANDIALOG
Resource23=IDD_Dlg_Watershed (Chinese (P.R.C.))
Resource24=IDD_Dlg_WienerFilter (Chinese (P.R.C.))
Resource25=IDD_Dlg_InverseFilter (Chinese (P.R.C.))
Resource26=IDD_MEDIANDIALOG (Chinese (P.R.C.))
Resource27=IDD_DlgLinearStretch (Chinese (P.R.C.))
Resource28=IDD_Dlg_NonlinearStretch (Chinese (P.R.C.))
Class20=ProjectRestoreDlg
Class21=WienterFilterDlg
Class22=InverseFilterDlg
Resource29="IDD_AVGDIALOG" (Chinese (P.R.C.))
Resource30=IDD_DlgLinearStretch
Resource31=IDD_Dlg_RegionGrow
Resource32="IDD_AVGDIALOG"
Resource33=IDD_Dlg_ProjectionRes (English (U.S.))
Resource34=IDD_Dlg_Zoom (Chinese (P.R.C.))
Resource35=IDD_ABOUTBOX (Chinese (P.R.C.))
Resource36=IDD_Dlg_NonlinearStretch
Resource37=IDD_Dlg_HistogramDraw
Resource38=IDR_MAINFRAME
Resource39=IDR_DEMOTYPE

[CLS:CDemoApp]
Type=0
HeaderFile=demo.h
ImplementationFile=demo.cpp
Filter=N

[CLS:CDemoDoc]
Type=0
HeaderFile=demoDoc.h
ImplementationFile=demoDoc.cpp
Filter=N

[CLS:CDemoView]
Type=0
HeaderFile=demoView.h
ImplementationFile=demoView.cpp
Filter=C
LastObject=id_MatchTemplet
BaseClass=CScrollView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=demo.cpp
ImplementationFile=demo.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_DEMOTYPE]
Type=1
Class=CDemoView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_SCAN
Command12=ID_SLIDE
Command13=ID_FADEIN
Command14=ID_MOSAIK
Command15=id_ColorToGray
Command16=id_GrayToColor
Command17=id_ImgReverse
Command18=id_Binary
Command19=id_LinearStrecth
Command20=id_DuiShuStretch
Command21=id_ZhiShuStretch
Command22=id_HistogramDraw
Command23=id_HistgramAver
Command24=id_Move
Command25=id_ZhuanZhi
Command26=id_HorizontalMirror
Command27=id_VerticalMirror
Command28=id_Zoom
Command29=id_Clockwise90
Command30=id_Anticlockwise90
Command31=id_Rotate180
Command32=id_Rotate
Command33=ID_FFT
Command34=id_IFFT
Command35=id_FFTEx
Command36=id_IFFTEx
Command37=id_HarrWaveletTrans
Command38=id_HarrWaveletITrans
Command39=ID_SET2ZERO_DENOISE
Command40=ID__HARDTHRESHOLD
Command41=ID_SOFTTHRESHOLD
Command42=ID_DCT
Command43=id_IDCT
Command44=id_OtusThreshold
Command45=id_InteractiveThresh
Command46=id_Robert
Command47=ID_SOBEL
Command48=id_Prewitt
Command49=id_Laplacian
Command50=id_Gauss_laplacian
Command51=id_Krisch
Command52=id_EdgeSelectTemplete
Command53=id_RegionGrow
Command54=id_ContourExtract
Command55=id_ContourTrace
Command56=id_HoughTransform
Command57=id_LineDetectByHough
Command58=ID_Random
Command59=ID_PepperSaltNoise
Command60=ID_AveSmooth
Command61=id_MiddleSmooth
Command62=ID_POWER_SMOOTH
Command63=ID_CHOOSE_MASK
Command64=ID_GRADESHARP
Command65=ID_LaplacienSharp
Command66=ID_SNR
Command67=ID_InverseFilter
Command68=ID_WienerFilter
Command69=ID_ProjRestore
Command70=ID_FIRSTIMAGE
Command71=ID_SECONDIMAGE
Command72=id_MatchTemplet
Command73=id_ConnerDetect
Command74=ID_FIRSTIMAGE
Command75=ID_SECONDIMAGE
Command76=id_MatchConner
Command77=id_ErosionForBinary
Command78=ID__DilationForBinary
Command79=id_OpenForBinary
Command80=id_CloseForBinary
Command81=id_InnerEdgeForBinary
Command82=id_OuterEdgeForBinary
Command83=id_MorphoContourForBinary
Command84=id_HitMissThinning
Command85=id_ErosionForGray
Command86=id_DilationForGray
Command87=id_OpenForGray
Command88=id_CloseForGray
Command89=id_MorphoGradientForGray
Command90=id_TopHatPeak
Command91=id_TopHatVally
Command92=id_TopHatPeakAndVally
Command93=id_WatershedSegment
Command94=ID_MOTION_FOPEN1
Command95=ID_MOTION_FOPEN2
Command96=ID_MOTION_FEST
Command97=ID_MOTION_FOPEN1
Command98=ID_MOTION_FOPEN2
Command99=ID_MITON_DEST
Command100=ID_APP_ABOUT
CommandCount=100

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

[DLG:IDD_DlgLinearStretch]
Type=1
Class=linearStretchParamDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287
Control8=IDC_EditPointFirstX,edit,1350631552
Control9=IDC_EditPointFirstY,edit,1350631552
Control10=IDC_EditPointSecondX,edit,1350631552
Control11=IDC_EditPointSecondY,edit,1350631552

[CLS:linearStretchParamDlg]
Type=0
HeaderFile=linearStretchParamDlg.h
ImplementationFile=linearStretchParamDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EditPointFirstX
VirtualFilter=dWC

[DLG:IDD_Dlg_HistogramDraw]
Type=1
Class=HistogramDrawDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_BmpBar,static,1342177294
Control3=IDC_STATIC_HistRect,static,1207959559
Control4=IDC_STATIC_Deviation,static,1342308352
Control5=IDC_STATIC_Average,static,1342308352
Control6=IDC_STATIC_ZHK,button,1342177287
Control7=IDC_COMBO_colorSelect,combobox,1344339971

[CLS:HistogramDrawDlg]
Type=0
HeaderFile=HistogramDrawDlg.h
ImplementationFile=HistogramDrawDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO_colorSelect
VirtualFilter=dWC

[CLS:morphologyDlg]
Type=0
HeaderFile=morphologyDlg.h
ImplementationFile=morphologyDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIO4

[CLS:BinaryMorphMaskSelect]
Type=0
HeaderFile=BinaryMorphMaskSelect.h
ImplementationFile=BinaryMorphMaskSelect.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_Dlg_MaskDefine]
Type=1
Class=MaskDefineDlg
ControlCount=27
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_Edit40,edit,1350631552
Control4=IDC_Edit41,edit,1350631552
Control5=IDC_Edit42,edit,1350631552
Control6=IDC_Edit43,edit,1350631552
Control7=IDC_Edit44,edit,1350631552
Control8=IDC_Edit30,edit,1350631552
Control9=IDC_Edit31,edit,1350631552
Control10=IDC_Edit32,edit,1350631552
Control11=IDC_Edit33,edit,1350631552
Control12=IDC_Edit34,edit,1350631552
Control13=IDC_Edit20,edit,1350631552
Control14=IDC_Edit21,edit,1350631552
Control15=IDC_Edit22,edit,1350631552
Control16=IDC_Edit23,edit,1350631552
Control17=IDC_Edit24,edit,1350631552
Control18=IDC_Edit10,edit,1350631552
Control19=IDC_Edit11,edit,1350631552
Control20=IDC_Edit12,edit,1350631552
Control21=IDC_Edit13,edit,1350631552
Control22=IDC_Edit14,edit,1350631552
Control23=IDC_Edit00,edit,1350631552
Control24=IDC_Edit01,edit,1350631552
Control25=IDC_Edit02,edit,1350631552
Control26=IDC_Edit03,edit,1350631552
Control27=IDC_Edit04,edit,1350631552

[CLS:MaskDefineDlg]
Type=0
HeaderFile=MaskDefineDlg.h
ImplementationFile=MaskDefineDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID__DilationForBinary

[DLG:IDD_Dlg_ThreshSegment]
Type=1
Class=ThreshSegmentDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_BmpBar,static,1342177294
Control3=IDC_STATIC_HistRect,static,1207959559
Control4=IDC_STATIC_Deviation,static,1342308352
Control5=IDC_STATIC_Average,static,1342308352
Control6=IDC_STATIC_ZHK,button,1342177287
Control7=IDC_COMBO_colorSelect,combobox,1344339971
Control8=IDC_Slider_ThreshSelect,msctls_trackbar32,1342242820
Control9=IDC_STATIC_thresh,static,1342308352
Control10=IDCANCEL,button,1342242816

[CLS:ThreshSegmentDlg]
Type=0
HeaderFile=ThreshSegmentDlg.h
ImplementationFile=ThreshSegmentDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ThreshSegmentDlg

[DLG:IDD_Dlg_Zoom]
Type=1
Class=Zoomdlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_Edit_newH,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_Edit_newW,edit,1350631552
Control7=IDC_Static_OldH,static,1342308352
Control8=IDC_Static_OldW,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,button,1342177287
Control12=IDC_RADIO1,button,1342373897
Control13=IDC_RADIO2,button,1342242825
Control14=IDC_RADIO3,button,1342242825

[CLS:Zoomdlg]
Type=0
HeaderFile=Zoomdlg.h
ImplementationFile=Zoomdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_Edit_newH
VirtualFilter=dWC

[DLG:IDD_Dlg_RotateSet]
Type=1
Class=RotateSetDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_Edit_Angle,edit,1350631552
Control5=IDC_STATIC,button,1342177287
Control6=IDC_RADIO1,button,1342373897
Control7=IDC_RADIO2,button,1342242825
Control8=IDC_RADIO3,button,1342242825

[CLS:RotateSetDlg]
Type=0
HeaderFile=RotateSetDlg.h
ImplementationFile=RotateSetDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_Edit_Angle
VirtualFilter=dWC

[CLS:DuiShuStretchDlg]
Type=0
HeaderFile=DuiShuStretchDlg.h
ImplementationFile=DuiShuStretchDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EditA
VirtualFilter=dWC

[DLG:IDD_Dlg_NonlinearStretch]
Type=1
Class=NonlinearStretchDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EditA,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EditB,edit,1350631552
Control8=IDC_EditC,edit,1350631552

[CLS:NonlinearStretchDlg]
Type=0
HeaderFile=NonlinearStretchDlg.h
ImplementationFile=NonlinearStretchDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_Dlg_Move]
Type=1
Class=GeometryMoveDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_Edit_OffsetX,edit,1350631552
Control6=IDC_Edit_OffsetY,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:GeometryMoveDlg]
Type=0
HeaderFile=GeometryMoveDlg.h
ImplementationFile=GeometryMoveDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_Edit_OffsetX
VirtualFilter=dWC

[DLG:IDD_Dlg_RegionGrow]
Type=1
Class=RegionGrowDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_Edit_SeedX,edit,1350631552
Control6=IDC_Edit_seedY,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_Edit_Thresh,edit,1350631552

[CLS:RegionGrowDlg]
Type=0
HeaderFile=RegionGrowDlg.h
ImplementationFile=RegionGrowDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_Edit_SeedX
VirtualFilter=dWC

[DLG:IDD_Dlg_Watershed]
Type=1
Class=WatershedParaDlg
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_Edit_ObjectCount,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_Edit_Point1X,edit,1350631552
Control8=IDC_Edit_Point1Y,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_Edit_Point2X,edit,1350631552
Control12=IDC_Edit_Point2Y,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_Edit_Point3X,edit,1350631552
Control16=IDC_Edit_Point3Y,edit,1350631552
Control17=IDC_Check_Contour,button,1342242819

[CLS:WatershedParaDlg]
Type=0
HeaderFile=WatershedParaDlg.h
ImplementationFile=WatershedParaDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID__DilationForBinary
VirtualFilter=dWC

[DLG:IDD_Dlg_NonlinearStretch (Chinese (P.R.C.))]
Type=1
Class=NonlinearStretchDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EditA,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EditB,edit,1350631552
Control8=IDC_EditC,edit,1350631552

[DLG:IDD_Dlg_RotateSet (Chinese (P.R.C.))]
Type=1
Class=RotateSetDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_Edit_Angle,edit,1350631552
Control5=IDC_STATIC,button,1342177287
Control6=IDC_RADIO1,button,1342373897
Control7=IDC_RADIO2,button,1342242825
Control8=IDC_RADIO3,button,1342242825

[DLG:IDD_DlgLinearStretch (Chinese (P.R.C.))]
Type=1
Class=linearStretchParamDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287
Control8=IDC_EditPointFirstX,edit,1350631552
Control9=IDC_EditPointFirstY,edit,1350631552
Control10=IDC_EditPointSecondX,edit,1350631552
Control11=IDC_EditPointSecondY,edit,1350631552

[DLG:IDD_Dlg_Zoom (Chinese (P.R.C.))]
Type=1
Class=Zoomdlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_Edit_newH,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_Edit_newW,edit,1350631552
Control7=IDC_Static_OldH,static,1342308352
Control8=IDC_Static_OldW,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,button,1342177287
Control12=IDC_RADIO1,button,1342373897
Control13=IDC_RADIO2,button,1342242825
Control14=IDC_RADIO3,button,1342242825

[DLG:IDD_Dlg_ThreshSegment (Chinese (P.R.C.))]
Type=1
Class=ThreshSegmentDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_BmpBar,static,1342177294
Control3=IDC_STATIC_HistRect,static,1207959559
Control4=IDC_STATIC_Deviation,static,1342308352
Control5=IDC_STATIC_Average,static,1342308352
Control6=IDC_STATIC_ZHK,button,1342177287
Control7=IDC_COMBO_colorSelect,combobox,1344339971
Control8=IDC_Slider_ThreshSelect,msctls_trackbar32,1342242820
Control9=IDC_STATIC_thresh,static,1342308352
Control10=IDCANCEL,button,1342242816

[DLG:IDD_Dlg_RegionGrow (Chinese (P.R.C.))]
Type=1
Class=RegionGrowDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_Edit_SeedX,edit,1350631552
Control6=IDC_Edit_seedY,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_Edit_Thresh,edit,1350631552

[DLG:IDD_Dlg_Watershed (Chinese (P.R.C.))]
Type=1
Class=WatershedParaDlg
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_Edit_ObjectCount,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_Edit_Point1X,edit,1350631552
Control8=IDC_Edit_Point1Y,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_Edit_Point2X,edit,1350631552
Control12=IDC_Edit_Point2Y,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_Edit_Point3X,edit,1350631552
Control16=IDC_Edit_Point3Y,edit,1350631552
Control17=IDC_Check_Contour,button,1342242819

[DLG:IDD_Dlg_HistogramDraw (Chinese (P.R.C.))]
Type=1
Class=HistogramDrawDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_BmpBar,static,1342177294
Control3=IDC_STATIC_HistRect,static,1207959559
Control4=IDC_STATIC_Deviation,static,1342308352
Control5=IDC_STATIC_Average,static,1342308352
Control6=IDC_STATIC_ZHK,button,1342177287
Control7=IDC_COMBO_colorSelect,combobox,1344339971

[DLG:IDD_Dlg_Move (Chinese (P.R.C.))]
Type=1
Class=GeometryMoveDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_Edit_OffsetX,edit,1350631552
Control6=IDC_Edit_OffsetY,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[DLG:IDD_Dlg_MaskDefine (Chinese (P.R.C.))]
Type=1
Class=MaskDefineDlg
ControlCount=27
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_Edit40,edit,1350631552
Control4=IDC_Edit41,edit,1350631552
Control5=IDC_Edit42,edit,1350631552
Control6=IDC_Edit43,edit,1350631552
Control7=IDC_Edit44,edit,1350631552
Control8=IDC_Edit30,edit,1350631552
Control9=IDC_Edit31,edit,1350631552
Control10=IDC_Edit32,edit,1350631552
Control11=IDC_Edit33,edit,1350631552
Control12=IDC_Edit34,edit,1350631552
Control13=IDC_Edit20,edit,1350631552
Control14=IDC_Edit21,edit,1350631552
Control15=IDC_Edit22,edit,1350631552
Control16=IDC_Edit23,edit,1350631552
Control17=IDC_Edit24,edit,1350631552
Control18=IDC_Edit10,edit,1350631552
Control19=IDC_Edit11,edit,1350631552
Control20=IDC_Edit12,edit,1350631552
Control21=IDC_Edit13,edit,1350631552
Control22=IDC_Edit14,edit,1350631552
Control23=IDC_Edit00,edit,1350631552
Control24=IDC_Edit01,edit,1350631552
Control25=IDC_Edit02,edit,1350631552
Control26=IDC_Edit03,edit,1350631552
Control27=IDC_Edit04,edit,1350631552

[MNU:IDR_MAINFRAME (Chinese (P.R.C.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_DEMOTYPE (Chinese (P.R.C.))]
Type=1
Class=CDemoView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_SCAN
Command12=ID_SLIDE
Command13=ID_FADEIN
Command14=ID_MOSAIK
Command15=id_ColorToGray
Command16=id_GrayToColor
Command17=id_ImgReverse
Command18=id_Binary
Command19=id_LinearStrecth
Command20=id_DuiShuStretch
Command21=id_ZhiShuStretch
Command22=id_HistogramDraw
Command23=id_HistgramAver
Command24=id_Move
Command25=id_ZhuanZhi
Command26=id_HorizontalMirror
Command27=id_VerticalMirror
Command28=id_Zoom
Command29=id_Clockwise90
Command30=id_Anticlockwise90
Command31=id_Rotate180
Command32=id_Rotate
Command33=ID_FFT
Command34=id_IFFT
Command35=id_FFTEx
Command36=id_IFFTEx
Command37=id_HarrWaveletTrans
Command38=id_HarrWaveletITrans
Command39=ID_SET2ZERO_DENOISE
Command40=ID__HARDTHRESHOLD
Command41=ID_SOFTTHRESHOLD
Command42=ID_DCT
Command43=id_IDCT
Command44=id_OtusThreshold
Command45=id_InteractiveThresh
Command46=id_Robert
Command47=ID_SOBEL
Command48=id_Prewitt
Command49=id_Laplacian
Command50=id_Gauss_laplacian
Command51=id_Krisch
Command52=id_EdgeSelectTemplete
Command53=id_RegionGrow
Command54=id_ContourExtract
Command55=id_ContourTrace
Command56=id_HoughTransform
Command57=id_LineDetectByHough
Command58=id_WatershedSegment
Command59=ID_Random
Command60=ID_PepperSaltNoise
Command61=ID_AveSmooth
Command62=id_MiddleSmooth
Command63=ID_POWER_SMOOTH
Command64=ID_CHOOSE_MASK
Command65=ID_GRADESHARP
Command66=ID_LaplacienSharp
Command67=ID_SNR
Command68=ID_InverseFilter
Command69=ID_WienerFilter
Command70=ID_ProjRestore
Command71=ID_FIRSTIMAGE
Command72=ID_SECONDIMAGE
Command73=id_MatchTemplet
Command74=id_ConnerDetect
Command75=ID_FIRSTIMAGE
Command76=ID_SECONDIMAGE
Command77=id_MatchConner
Command78=id_ErosionForBinary
Command79=ID__DilationForBinary
Command80=id_OpenForBinary
Command81=id_CloseForBinary
Command82=id_InnerEdgeForBinary
Command83=id_OuterEdgeForBinary
Command84=id_MorphoContourForBinary
Command85=id_HitMissThinning
Command86=id_ErosionForGray
Command87=id_DilationForGray
Command88=id_OpenForGray
Command89=id_CloseForGray
Command90=id_MorphoGradientForGray
Command91=id_TopHatPeak
Command92=id_TopHatVally
Command93=id_TopHatPeakAndVally
Command94=ID_MOTION_FOPEN1
Command95=ID_MOTION_FOPEN2
Command96=ID_MOTION_FEST
Command97=ID_MOTION_FOPEN1
Command98=ID_MOTION_FOPEN2
Command99=ID_MITON_DEST
Command100=ID_APP_ABOUT
CommandCount=100

[TB:IDR_MAINFRAME (Chinese (P.R.C.))]
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

[ACL:IDR_MAINFRAME (Chinese (P.R.C.))]
Type=1
Class=?
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

[DLG:IDD_ABOUTBOX (Chinese (P.R.C.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:ProjectRestoreDlg]
Type=0
HeaderFile=ProjectRestoreDlg.h
ImplementationFile=ProjectRestoreDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_Edit_pAngle
VirtualFilter=dWC

[CLS:WienterFilterDlg]
Type=0
HeaderFile=WienterFilterDlg.h
ImplementationFile=WienterFilterDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_wAngle
VirtualFilter=dWC

[CLS:InverseFilterDlg]
Type=0
HeaderFile=InverseFilterDlg.h
ImplementationFile=InverseFilterDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_Dlg_ProjectionRes (English (U.S.))]
Type=1
Class=?
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_Edit_pAngle,edit,1350631552
Control7=IDC_Edit_pLength,edit,1350631552
Control8=IDC_Edit_pCyCount,edit,1350631552

[DLG:IDD_Dlg_WienerFilter (English (U.S.))]
Type=1
Class=?
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_wAngle,edit,1350631552
Control7=IDC_EDIT_wLength,edit,1350631552
Control8=IDC_EDIT_wK,edit,1350631552

[DLG:IDD_Dlg_InverseFilter (English (U.S.))]
Type=1
Class=?
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_iLength,edit,1350631552
Control6=IDC_EDIT_iAngle,edit,1350631552

[DLG:IDD_MEDIANDIALOG]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDC_MedianCombo,combobox,1344340226

[DLG:IDD_MEDIANDIALOG (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDC_MedianCombo,combobox,1344340226

[DLG:"IDD_AVGDIALOG" (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDC_AvgCombo,combobox,1344340226

[DLG:IDD_Dlg_WienerFilter (Chinese (P.R.C.))]
Type=1
Class=WienterFilterDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_wAngle,edit,1350631552
Control6=IDC_EDIT_wLength,edit,1350631552
Control7=IDC_EDIT_wK,edit,1350631552
Control8=IDC_STATIC,static,1342308352

[DLG:IDD_Dlg_InverseFilter (Chinese (P.R.C.))]
Type=1
Class=InverseFilterDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_iLength,edit,1350631552
Control6=IDC_EDIT_iAngle,edit,1350631552

[DLG:IDD_Dlg_ProjectionRes (Chinese (P.R.C.))]
Type=1
Class=ProjectRestoreDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_Edit_pAngle,edit,1350631552
Control7=IDC_Edit_pLength,edit,1350631552
Control8=IDC_Edit_pCyCount,edit,1350631552

[DLG:IDD_Dlg_WienerFilter]
Type=1
Class=?
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_wAngle,edit,1350631552
Control6=IDC_EDIT_wLength,edit,1350631552
Control7=IDC_EDIT_wK,edit,1350631552
Control8=IDC_STATIC,static,1342308352

[DLG:IDD_Dlg_InverseFilter]
Type=1
Class=?
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_iLength,edit,1350631552
Control6=IDC_EDIT_iAngle,edit,1350631552

[DLG:IDD_Dlg_ProjectionRes]
Type=1
Class=?
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_Edit_pAngle,edit,1350631552
Control7=IDC_Edit_pLength,edit,1350631552
Control8=IDC_Edit_pCyCount,edit,1350631552

[DLG:"IDD_AVGDIALOG"]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDC_AvgCombo,combobox,1344340226

