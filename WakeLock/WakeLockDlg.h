
// WakeLockDlg.h : header file
//

#pragma once


// CWakeLockDlg dialog
class CWakeLockDlg : public CDialogEx
{
// Construction
public:
	CWakeLockDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WAKELOCK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
private:
	CButton m_chbDisplayNotRequired_ctl;
	CFont m_smallFont;
	BOOL m_bDisplayNotRequired;
public:
	afx_msg void OnBnClickedChbDisplayNotRequired();
};
