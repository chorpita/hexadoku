// EditSquareDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hexadoku.h"
#include "hexadokuDoc.h"
#include "EditSquareDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditSquareDlg dialog


CEditSquareDlg::CEditSquareDlg(CWnd* pParent, CSquare * pSquare ) : 
   CDialog(CEditSquareDlg::IDD, pParent ),
   m_pSquare( pSquare )
{
	//{{AFX_DATA_INIT(CEditSquareDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEditSquareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditSquareDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditSquareDlg, CDialog)
	//{{AFX_MSG_MAP(CEditSquareDlg)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditSquareDlg message handlers

void CEditSquareDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnChar(nChar, nRepCnt, nFlags);
}
