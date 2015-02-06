#if !defined(AFX_EDITSQUAREDLG_H__FDB4D180_8A30_11DA_B4C8_444553540000__INCLUDED_)
#define AFX_EDITSQUAREDLG_H__FDB4D180_8A30_11DA_B4C8_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditSquareDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditSquareDlg dialog

class CEditSquareDlg : public CDialog
{
// Construction
public:
	CEditSquareDlg(CWnd* pParent, CSquare * pSquare );   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditSquareDlg)
	enum { IDD = IDD_EDITSQUARE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditSquareDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CSquare * m_pSquare;
	// Generated message map functions
	//{{AFX_MSG(CEditSquareDlg)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITSQUAREDLG_H__FDB4D180_8A30_11DA_B4C8_444553540000__INCLUDED_)
