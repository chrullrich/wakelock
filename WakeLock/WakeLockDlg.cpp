
// WakeLockDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WakeLock.h"
#include "WakeLockDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWakeLockDlg dialog



CWakeLockDlg::CWakeLockDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WAKELOCK_DIALOG, pParent)
	, m_bDisplayNotRequired(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWakeLockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHB_DISPLAY_NOT_REQUIRED, m_chbDisplayNotRequired_ctl);
	DDX_Check(pDX, IDC_CHB_DISPLAY_NOT_REQUIRED, m_bDisplayNotRequired);
}

BEGIN_MESSAGE_MAP(CWakeLockDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHB_DISPLAY_NOT_REQUIRED, &CWakeLockDlg::OnBnClickedChbDisplayNotRequired)
END_MESSAGE_MAP()


// CWakeLockDlg message handlers

BOOL CWakeLockDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	LOGFONT dlgfont;
	GetFont()->GetLogFont(&dlgfont);
	dlgfont.lfHeight = MulDiv(dlgfont.lfHeight, 3, 5);
	m_smallFont.CreateFontIndirectW(&dlgfont);
	m_chbDisplayNotRequired_ctl.SetFont(&m_smallFont);

	// TODO: Add extra initialization here
	SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED
									      | ES_DISPLAY_REQUIRED);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWakeLockDlg::OnBnClickedChbDisplayNotRequired()
{
	UpdateData();
	EXECUTION_STATE es = ES_SYSTEM_REQUIRED | (m_bDisplayNotRequired ? 0 : ES_DISPLAY_REQUIRED);
	SetThreadExecutionState(ES_CONTINUOUS | es);
}
