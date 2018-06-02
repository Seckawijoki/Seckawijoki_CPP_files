// one more time for mfcDlg.h : header file
//

#if !defined(AFX_ONEMORETIMEFORMFCDLG_H__CB3FEB10_0CFF_4811_807A_23E9C9351634__INCLUDED_)
#define AFX_ONEMORETIMEFORMFCDLG_H__CB3FEB10_0CFF_4811_807A_23E9C9351634__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COnemoretimeformfcDlg dialog

class COnemoretimeformfcDlg : public CDialog
{
// Construction
public:
	COnemoretimeformfcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COnemoretimeformfcDlg)
	enum { IDD = IDD_ONEMORETIMEFORMFC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COnemoretimeformfcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COnemoretimeformfcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEdit3();
	afx_msg void OnChangeEdit5();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONEMORETIMEFORMFCDLG_H__CB3FEB10_0CFF_4811_807A_23E9C9351634__INCLUDED_)
