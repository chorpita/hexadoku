// hexadokuDoc.h : interface of the CHexadokuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HEXADOKUDOC_H__E80FBF8A_89D0_11DA_B4C8_444553540000__INCLUDED_)
#define AFX_HEXADOKUDOC_H__E80FBF8A_89D0_11DA_B4C8_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define LEFT_MARGIN 10
#define TOP_MARGIN 10
#define SQUARE_LEN 36
#define SQUARE_GAPPER 4
#define SCREEN_COLOR 0x0000AF00
#define SQ_UNKNOWN -1
#define MAX_ROWS 4

class CSquare : public CRect
{
public:
	int m_nFixLevel;
	int m_nTrialLevel;
	int m_nVal;
	int m_nBits;

	void Init()
	{
		  m_nFixLevel = 0;
		  m_nTrialLevel = 0;
		  m_nVal = SQ_UNKNOWN;
	      m_nBits = SQ_UNKNOWN;
	}

	void Setup( CRect & r )
	{
		 Init();
		 left = r.left;
		 right = r.right;
		 top = r.top;
		 bottom = r.bottom;
	}

	BOOL GetHit( CPoint & point )
	{
		if( m_nFixLevel )
			return FALSE;
		else
			return PtInRect( point );
	}

	void Fix( int nGameLevel, int nTrialLevel )
	{
		if( ( m_nFixLevel == 0 ) && (m_nVal != SQ_UNKNOWN ) )
		{
			m_nFixLevel = nGameLevel;
			m_nTrialLevel = nTrialLevel;
		}
	}

	void Undo( int nGameLevel )
	{
		if( m_nFixLevel == nGameLevel )
			Init();
	}

	void UndoTrial( int nTrialLevel )
	{
		if( m_nTrialLevel == nTrialLevel )
			Init();
	}

	BOOL Decrement( CWnd * pWnd,  CPoint & point, int nRow );

	BOOL Increment( CWnd * pWnd,  CPoint & point, int nRow );

	void Draw( CDC * pDC, CFont & fontBig, CFont & fontMed, int nRow )
	{		
		int nSquared = nRow * nRow;
		int nOffset = 0;
		if( nRow < 4 )
			nOffset = 1;
		pDC->Rectangle( left , top, right, bottom );
		CString str1;
		CString str2;
		if( ( m_nVal == SQ_UNKNOWN ) && ( m_nBits != SQ_UNKNOWN ) )
		{
			int nCount = 0;
			for( int i = 0; i < nSquared; i++ )
				if( ( ( 1 << i ) & m_nBits ) == 0 )
				{
					nCount ++;
					switch( nCount )
					{
					case 1:
					case 2:
						str1 += GetCode( i, nOffset );
						str1 += ' ';
						break;
					case 3:
						str1 += GetCode( i, nOffset );
						break;
					case 4:
					case 5:
						str2 += GetCode( i, nOffset );
						str2 += ' ';
						break;
					case 6:
						str2 += GetCode( i, nOffset );
						break;
					case 7:
						str2 = str2.GetAt( 0 );
						str2 += " ...";
						break;
					}
				}
			if( nCount < nSquared )
			{
				pDC->SelectObject( & fontMed );
				pDC->TextOut( left + 3, top + 1, str1 );
				pDC->TextOut( left + 3, top + 17, str2 );
			}
		}
		else
		{
			str1 = GetCode( m_nVal, nOffset );
			if( m_nTrialLevel > 0 )
				switch( m_nTrialLevel )
				{
				case 1: str1 += '\''; break;
				case 2: str1 += '\"'; break;
				case 3: str1 += '!'; break;
				case 4: str1 += '|'; break;
				}
			pDC->SelectObject( & fontBig );
			pDC->TextOut( left + SQUARE_LEN / 3 - 3, top +SQUARE_LEN / 8 - 2, str1 );
		}
	}

	 char GetCode( int nVal, int nOffset )
	{
		if( nVal == SQ_UNKNOWN )
			return ' ';
		else
		{
			if( nVal < 10 )
				return char( byte( '0' ) + nVal + nOffset );
			else
				return char( byte( 'a' ) + nVal  - 10 + nOffset );
		}
	}

};

class CDokugame
{
public:
	CDokugame() : m_nFixLevel( 0 ), m_nTrialLevel( 0 ) { }

	CSquare m_sq[ MAX_ROWS ] [ MAX_ROWS ] [ MAX_ROWS ] [ MAX_ROWS ];

	int m_nFixLevel;
	int m_nTrialLevel;

	void Fix( int nRows )
	{
		m_nFixLevel++;
		for( int i1 = 0; i1 < nRows; i1++ )
			for( int i2 = 0; i2 < nRows; i2++ )
				for( int i3 = 0; i3 < nRows; i3++ )
						for( int i4 = 0; i4 < nRows; i4++ )
							m_sq [ i1 ] [ i2 ] [ i3 ] [ i4 ].Fix( m_nFixLevel, m_nTrialLevel ); 
	}

	void Calc( int nRows )
	{
		for( int i1 = 0; i1 < nRows; i1++ )
			for( int i2 = 0; i2 < nRows; i2++ )
				for( int i3 = 0; i3 < nRows; i3++ )
						for( int i4 = 0; i4 < nRows; i4++ )
						{
							CSquare & sqW = m_sq [ i1 ] [ i2 ] [ i3 ] [ i4 ];
							if( sqW.m_nFixLevel == 0 )
							{
								int nResult = 0;
								int j1, j2;
								for( j1 = 0; j1 < nRows; j1++ )
									for( j2 = 0; j2 < nRows; j2++ )
									{
										CSquare & sqR = m_sq [ i1] [ i2 ] [ j1 ] [ j2 ];
										if( sqR.m_nFixLevel )	
											nResult  |= ( 1 << sqR.m_nVal );
									}
								for( j1 = 0; j1 < nRows; j1++ )
									for( j2 = 0; j2 < nRows; j2++ )
									{
										CSquare & sqR = m_sq [ i1] [ j1 ] [ i3 ] [ j2 ];
										if( sqR.m_nFixLevel )	
											nResult  |= ( 1 << sqR.m_nVal );
									}
								for( j1 = 0; j1 < nRows; j1++ )
									for( j2 = 0; j2 < nRows; j2++ )
									{
										CSquare & sqR = m_sq [ j1] [ j2 ] [ i3 ] [ i4 ];
										if( sqR.m_nFixLevel )	
											nResult  |= ( 1 << sqR.m_nVal );
									}
								sqW.m_nBits = nResult;
							}
						}
	}
};

class CHexadokuDoc : public CDocument
{
protected: // create from serialization only
	CHexadokuDoc();
	DECLARE_DYNCREATE(CHexadokuDoc)

// Attributes
public:
	CDokugame m_g;
	int m_nRows; 
	int m_nStart; 

// Operations
public:
	void Fix() { m_g.Fix( m_nRows ); }
	void Calc() { m_g.Calc( m_nRows ); }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHexadokuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHexadokuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHexadokuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEXADOKUDOC_H__E80FBF8A_89D0_11DA_B4C8_444553540000__INCLUDED_)
