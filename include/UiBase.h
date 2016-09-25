#ifndef _UI_CBASE_H
#define _UI_CBASE_H


/*****************************************************************************************************************
 *
 * CUiBase: This is the Library Base Class, You don't want to process WM_PAINT & WM_ERASEBKGND message. The Control
 *          Class rewrited 'virtual void Draw(CDC* pDC, CRect rcCli)' by itself.
 *
 *****************************************************************************************************************/
class CUiBase : public CWnd
{
	DECLARE_DYNAMIC(CUiBase)

public:
	CUiBase();
	virtual ~CUiBase();
	
public:
	virtual  BOOL  Create(CWnd* pParent, UINT nId, RECT rect=CRect(0, 0, 0, 0), DWORD dwStyle=WS_CHILD|WS_VISIBLE); 

	virtual  DWORD GetCtrlStyle();         
	virtual  void  ModifyCtrlStyle(DWORD dwRemove, DWORD dwAdd);

	CDC*     GetBkDC();                    
	COLORREF GetBkColor();                 
	CBrush*  GetBkBrush();                 
	void     SetBkColor(COLORREF clrBk);   
	void     SetBkBrush(CBrush* pBrush);   
	void     SetBkBitmap(UINT uBkBmpId, COLORREF clrMask=CLR_NONE, int nWinPosX=0, int nWinPosY=0, bool bAutoMoveWin=false);  

	static   HRGN CreateRgn(UINT uBitmapId, COLORREF clrMask);     // Create transparent rect by the bitmap
	static   HRGN CreateRgn(CDC* pDC, COLORREF clrMask);           // Create transparent rect by the DC

protected:
	virtual  void RecalLayout();                          // rewrite this funtion to re layout when the window change size
	virtual  void Draw(CDC* pDC, CRect rcCli) = 0;        // rewrite this function to draw the control
	
private:
	void     Refresh(CDC* pDC, CRect rcCli);
	static   HRGN CreateRgn(CBitmap* pBitmap, COLORREF clrMask);

private:
	CDC      m_BkDC;
	bool     m_bStoredBkDc;
	COLORREF m_clrBk;
	CBrush*  m_pBkBrush;
	UINT     m_uBkBmpId;
	COLORREF m_clrBkBmpMask;
	DWORD    m_dwStyle;

protected:
	//{{AFX_MSG(CUiBase)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
};

#endif 
