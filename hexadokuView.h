// hexadokuView.h : interface of the CHexadokuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HEXADOKUVIEW_H__E80FBF8C_89D0_11DA_B4C8_444553540000__INCLUDED_)
#define AFX_HEXADOKUVIEW_H__E80FBF8C_89D0_11DA_B4C8_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHexadokuView : public CView
{
protected: // create from serialization only
	CHexadokuView();
	DECLARE_DYNCREATE(CHexadokuView)

// Attributes
public:
	CHexadokuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHexadokuView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHexadokuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHexadokuView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnCalc();
	afx_msg void OnUpdateCalc(CCmdUI* pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);
	afx_msg void OnViewHex();
	afx_msg void OnUpdateViewHex(CCmdUI* pCmdUI);
	afx_msg void OnEditKilllevel();
	afx_msg void OnUpdateEditKilllevel(CCmdUI* pCmdUI);
	afx_msg void OnEditSetlevel();
	afx_msg void OnUpdateEditSetlevel(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in hexadokuView.cpp
inline CHexadokuDoc* CHexadokuView::GetDocument()
   { return (CHexadokuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEXADOKUVIEW_H__E80FBF8C_89D0_11DA_B4C8_444553540000__INCLUDED_)
