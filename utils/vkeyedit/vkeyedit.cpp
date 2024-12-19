//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//
//=============================================================================//
// vkeyedit.cpp : Defines the class behaviors for the application.
//

#include "vkeyedit.h"
#include "stdafx.h"

#include "MainFrm.h"
#include "vkeyeditDoc.h"
#include "vkeyeditView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IFileSystem *g_pFileSystem;

static CSysModule *g_pFileSystemModule = 0;
CreateInterfaceFn g_FileSystemFactory = 0;

CreateInterfaceFn GetFileSystemFactory() { return g_FileSystemFactory; }

//-----------------------------------------------------------------------------
// Loads, unloads the file system DLL
//-----------------------------------------------------------------------------
bool FileSystem_LoadFileSystemModule(void) {
  char *sFileSystemModuleName = "filesystem_stdio.dll";

  g_pFileSystemModule = Sys_LoadModule(sFileSystemModuleName);
  Assert(g_pFileSystemModule);
  if (!g_pFileSystemModule) {
    Error("Unable to load %s", sFileSystemModuleName);
    return false;
  }

  g_FileSystemFactory = Sys_GetFactory(g_pFileSystemModule);
  if (!g_FileSystemFactory) {
    Error("Unable to get filesystem factory");
    return false;
  }
  g_pFileSystem =
      (IFileSystem *)g_FileSystemFactory(FILESYSTEM_INTERFACE_VERSION, NULL);
  Assert(g_pFileSystem);
  if (!g_pFileSystem) {
    Error("Unable to get IFileSystem interface from filesystem factory");
    return false;
  }
  return true;
}

void FileSystem_UnloadFileSystemModule(void) {
  if (!g_pFileSystemModule)
    return;

  g_FileSystemFactory = NULL;

  Sys_UnloadModule(g_pFileSystemModule);
  g_pFileSystemModule = 0;
}

//-----------------------------------------------------------------------------
// Initialize, shutdown the file system
//-----------------------------------------------------------------------------
bool FileSystem_Init() {
  if (!g_pFileSystem)
    return false;

  if (g_pFileSystem->Init() != INIT_OK)
    return false;

  g_pFileSystem->AddSearchPath("", "root");

  return true;
}

void FileSystem_Shutdown(void) { g_pFileSystem->Shutdown(); }

/////////////////////////////////////////////////////////////////////////////
// CVkeyeditApp

BEGIN_MESSAGE_MAP(CVkeyeditApp, CWinApp)
//{{AFX_MSG_MAP(CVkeyeditApp)
ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
// NOTE - the ClassWizard will add and remove mapping macros here.
//    DO NOT EDIT what you see in these blocks of generated code!
//}}AFX_MSG_MAP
// Standard file based document commands
ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
// Standard print setup command
ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVkeyeditApp construction

CVkeyeditApp::CVkeyeditApp() {
  // TODO: add construction code here,
  // Place all significant initialization in InitInstance

  // Start up the file system
  //
}

CVkeyeditApp::~CVkeyeditApp() {
  //	FileSystem_Shutdown();
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CVkeyeditApp object

CVkeyeditApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CVkeyeditApp initialization

BOOL CVkeyeditApp::InitInstance() {
  AfxEnableControlContainer();

  // Standard initialization
  // If you are not using these features and wish to reduce the size
  //  of your final executable, you should remove from the following
  //  the specific initialization routines you do not need.

#ifdef _AFXDLL
  Enable3dControls(); // Call this when using MFC in a shared DLL
#else
  Enable3dControlsStatic(); // Call this when linking to MFC statically
#endif

  // Change the registry key under which our settings are stored.
  // TODO: You should modify this string to be something appropriate
  // such as the name of your company or organization.
  SetRegistryKey(_T("Local AppWizard-Generated Applications"));

  LoadStdProfileSettings(); // Load standard INI file options (including MRU)

  // Register the application's document templates.  Document templates
  //  serve as the connection between documents, frame windows and views.

  CSingleDocTemplate *pDocTemplate;
  pDocTemplate =
      new CSingleDocTemplate(IDR_MAINFRAME, RUNTIME_CLASS(CVkeyeditDoc),
                             RUNTIME_CLASS(CMainFrame), // main SDI frame window
                             RUNTIME_CLASS(CVkeyeditView));
  AddDocTemplate(pDocTemplate);

  FileSystem_LoadFileSystemModule();
  FileSystem_Init();

  // Parse command line for standard shell commands, DDE, file open
  CCommandLineInfo cmdInfo;
  ParseCommandLine(cmdInfo);

  // Dispatch commands specified on the command line
  if (!ProcessShellCommand(cmdInfo))
    return FALSE;

  // The one and only window has been initialized, so show and update it.
  m_pMainWnd->ShowWindow(SW_SHOW);
  m_pMainWnd->UpdateWindow();

  return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog {
public:
  CAboutDlg();

  // Dialog Data
  //{{AFX_DATA(CAboutDlg)
  enum { IDD = IDD_ABOUTBOX };
  //}}AFX_DATA

  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CAboutDlg)
protected:
  virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV support
                                                   //}}AFX_VIRTUAL

  // Implementation
protected:
  //{{AFX_MSG(CAboutDlg)
  // No message handlers
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD) {
  //{{AFX_DATA_INIT(CAboutDlg)
  //}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange *pDX) {
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CAboutDlg)
  //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CVkeyeditApp::OnAppAbout() {
  CAboutDlg aboutDlg;
  aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CVkeyeditApp message handlers

int CVkeyeditApp::ExitInstance() {
  // TODO: Add your specialized code here and/or call the base class

  return CWinApp::ExitInstance();
}