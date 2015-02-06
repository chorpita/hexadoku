// hexadokuView.cpp : implementation of the CHexadokuView class
//

#include "stdafx.h"
#include "hexadoku.h"

#include "hexadokuDoc.h"
#include "hexadokuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHexadokuView

IMPLEMENT_DYNCREATE(CHexadokuView, CView)

BEGIN_MESSAGE_MAP(CHexadokuView, CView)
	//{{AFX_MSG_MAP(CHexadokuView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_CALC, OnCalc)
	ON_UPDATE_COMMAND_UI(ID_CALC, OnUpdateCalc)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
	ON_COMMAND(ID_VIEW_HEX, OnViewHex)
	ON_UPDATE_COMMAND_UI(ID_VIEW_HEX, OnUpdateViewHex)
	ON_COMMAND(ID_EDIT_KILLLEVEL, OnEditKilllevel)
	ON_UPDATE_COMMAND_UI(ID_EDIT_KILLLEVEL, OnUpdateEditKilllevel)
	ON_COMMAND(ID_EDIT_SETLEVEL, OnEditSetlevel)
	ON_UPDATE_COMMAND_UI(ID_EDIT_SETLEVEL, OnUpdateEditSetlevel)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHexadokuView construction/destruction

CHexadokuView::CHexadokuView()
{
	// TODO: add construction code here

}

CHexadokuView::~CHexadokuView()
{
}

BOOL CHexadokuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHexadokuView drawing

void CHexadokuView::OnDraw(CDC* pDC)
{
	CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);


	// create fonts
	CFont fontBig;
	fontBig.CreateFont( 28, 12, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, "MS Reference Serif" );
	pDC->SelectObject( fontBig );
	CFont fontMed;
	fontMed.CreateFont( 18, 5, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, "MS Reference Serif" );	

	// paint screen
	CRect r;
	pDC->GetWindow()->GetWindowRect( & r );
	pDC->FillSolidRect( 0, 0, r.Width(), r.Height(), SCREEN_COLOR );
	pDC->FillSolidRect( 20,20, 20, 20, 0x00ffffff );

	int n = pDoc->m_nRows;

	// paint screen structure
	for( int i1 = 0; i1 < n; i1++ )
		for( int i2 = 0; i2 < n; i2++ )
			for( int i3 = 0; i3 < n; i3++ )
					for( int i4 = 0; i4 < n; i4++ )
						pDoc->m_g.m_sq[ i1] [ i2 ] [ i3 ] [ i4 ].Draw( pDC, fontBig, fontMed, pDoc->m_nRows );

   // delete GDI objects used

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CHexadokuView printing

BOOL CHexadokuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHexadokuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHexadokuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHexadokuView diagnostics

#ifdef _DEBUG
void CHexadokuView::AssertValid() const
{
	CView::AssertValid();
}

void CHexadokuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHexadokuDoc* CHexadokuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHexadokuDoc)));
	return (CHexadokuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHexadokuView message handlers

void CHexadokuView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: Add your message handler code here and/or call default

	BOOL bHit = FALSE;
	int n = pDoc->m_nRows;
	for( int i1 = 0; i1 < n && ! bHit; i1++ )
		for( int i2 = 0; i2 < n && ! bHit; i2++ )
			for( int i3 = 0; i3 < n && ! bHit; i3++ )
					for( int i4 = 0; i4 < n && ! bHit; i4++ )
						bHit = pDoc->m_g.m_sq [ i1 ] [ i2 ] [ i3 ] [ i4 ].GetHit( point ); 
					::SetCursor(::LoadCursor(NULL, bHit ? MAKEINTRESOURCE(32649) : IDC_IBEAM ) );
	CView::OnMouseMove(nFlags, point);
}


void CHexadokuView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	BOOL bHit = FALSE;
	int n = pDoc->m_nRows;
	for( int i1 = 0; i1 < n && ! bHit; i1++ )
		for( int i2 = 0; i2 < n && ! bHit; i2++ )
			for( int i3 = 0; i3 < n && ! bHit; i3++ )
					for( int i4 = 0; i4 < n && ! bHit; i4++ )
						bHit = pDoc->m_g.m_sq [ i1 ] [ i2 ] [ i3 ] [ i4 ].Increment( this, point, pDoc->m_nRows ); 	
	CView::OnLButtonDown(nFlags, point);
}

void CHexadokuView::OnCalc() 
{
	// TODO: Add your command handler code here
	CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);	
	pDoc->Fix(); 	
	pDoc->Calc(); 
	Invalidate();
	SendMessage( WM_PAINT );
}

void CHexadokuView::OnUpdateCalc(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CHexadokuView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	BOOL bHit = FALSE;
	int n = pDoc->m_nRows;
	for( int i1 = 0; i1 < n && ! bHit; i1++ )
		for( int i2 = 0; i2 < n && ! bHit; i2++ )
			for( int i3 = 0; i3 < n && ! bHit; i3++ )
					for( int i4 = 0; i4 < n && ! bHit; i4++ )
						bHit = pDoc->m_g.m_sq [ i1 ] [ i2 ] [ i3 ] [ i4 ].Decrement( this, point, pDoc->m_nRows ); 	
	CView::OnRButtonDown(nFlags, point);
}

void CHexadokuView::OnEditUndo() 
{
	// TODO: Add your command handler code here
    CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);	
	int n = pDoc->m_nRows;
	for( int i1 = 0; i1 < n; i1++ )
		for( int i2 = 0; i2 < n; i2++ )
			for( int i3 = 0; i3 < n; i3++ )
					for( int i4 = 0; i4 < n; i4++ )
						pDoc->m_g.m_sq[ i1] [ i2 ] [ i3 ] [ i4 ].Undo( pDoc->m_g.m_nFixLevel );	
	pDoc->m_g.m_nFixLevel--;
	pDoc->Calc(); 
	Invalidate();
	SendMessage( WM_PAINT );
}

void CHexadokuView::OnUpdateEditUndo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pCmdUI->Enable( pDoc->m_g.m_nFixLevel > 0 );
}

void CHexadokuView::OnViewHex() 
{
	// TODO: Add your command handler code here
	CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if( pDoc->m_nRows == 4 )
		pDoc->m_nRows = 3;	
	else
		pDoc->m_nRows = 4;
	pDoc->OnNewDocument();  
	Invalidate();
	SendMessage( WM_PAINT );
}

void CHexadokuView::OnUpdateViewHex(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pCmdUI->SetCheck( pDoc->m_nRows == 4 );
}

void CHexadokuView::OnEditKilllevel() 
{
	// TODO: Add your command handler code here
	CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int n = pDoc->m_nRows;
	for( int i1 = 0; i1 < n; i1++ )
		for( int i2 = 0; i2 < n; i2++ )
			for( int i3 = 0; i3 < n; i3++ )
					for( int i4 = 0; i4 < n; i4++ )
						pDoc->m_g.m_sq[ i1] [ i2 ] [ i3 ] [ i4 ].UndoTrial( pDoc->m_g.m_nTrialLevel );	
	pDoc->m_g.m_nTrialLevel--;
	pDoc->Calc(); 
	Invalidate();
	SendMessage( WM_PAINT );
}

void CHexadokuView::OnUpdateEditKilllevel(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pCmdUI->Enable(  pDoc->m_g.m_nTrialLevel > 0  );
}

void CHexadokuView::OnEditSetlevel() 
{
	CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->m_g.m_nTrialLevel++;
}

void CHexadokuView::OnUpdateEditSetlevel(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CHexadokuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pCmdUI->Enable( ( pDoc->m_g.m_nFixLevel > 1 ) && ( pDoc->m_g.m_nTrialLevel < 4 ) );
}
