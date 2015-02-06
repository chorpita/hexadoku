// hexadokuDoc.cpp : implementation of the CHexadokuDoc class
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

BOOL CSquare::Increment( CWnd * pWnd, CPoint & point, int nRow )
{
	BOOL b = GetHit( point );
	if( b )
	{
		m_nVal++;
		if( m_nBits != SQ_UNKNOWN )
			while(  ( ( 1 << m_nVal ) & m_nBits )  > 0 )
				m_nVal++;
		if( m_nVal == ( nRow * nRow ) )
			m_nVal = SQ_UNKNOWN;
		pWnd->InvalidateRect( this );
		pWnd->SendMessage( WM_PAINT );
	}
	return b;
}


BOOL CSquare::Decrement( CWnd * pWnd, CPoint & point, int nRow )
{
	BOOL b = GetHit( point );
	if( b )
	{
		if( m_nVal == SQ_UNKNOWN )
			m_nVal = nRow * nRow;
		m_nVal--;
		if( m_nBits != SQ_UNKNOWN )
			while( (  ( ( 1 << m_nVal ) & m_nBits )  > 0 ) && ( m_nVal != SQ_UNKNOWN ) )
				m_nVal--;
		pWnd->InvalidateRect( this );
		pWnd->SendMessage( WM_PAINT );
	}
	return b;
}

/////////////////////////////////////////////////////////////////////////////
// CHexadokuDoc

IMPLEMENT_DYNCREATE(CHexadokuDoc, CDocument)

BEGIN_MESSAGE_MAP(CHexadokuDoc, CDocument)
	//{{AFX_MSG_MAP(CHexadokuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHexadokuDoc construction/destruction

CHexadokuDoc::CHexadokuDoc()
{
	// TODO: add one-time construction code here
	m_nRows = 4;	
	m_nStart = 0;
}

CHexadokuDoc::~CHexadokuDoc()
{
}

BOOL CHexadokuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	for( int i1 = 0; i1 < m_nRows; i1++ )
		for( int i2 = 0; i2 < m_nRows; i2++ )
			for( int i3 = 0; i3 < m_nRows; i3++ )
					for( int i4 = 0; i4 < m_nRows; i4++ )
					{
					CRect r;
					r.left = LEFT_MARGIN + SQUARE_LEN *  (i3 * m_nRows + i4) + SQUARE_GAPPER * i3;
					r.top = TOP_MARGIN + SQUARE_LEN  * (i1 * m_nRows + i2) + SQUARE_GAPPER * i1;	
					r.right = r.left + SQUARE_LEN;
					r.bottom = r.top + SQUARE_LEN;
					m_g.m_sq[ i1] [ i2 ] [ i3 ] [ i4 ].Setup( r );
					}

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CHexadokuDoc serialization

void CHexadokuDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHexadokuDoc diagnostics

#ifdef _DEBUG
void CHexadokuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHexadokuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHexadokuDoc commands
