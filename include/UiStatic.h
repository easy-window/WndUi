#ifndef _UI_CSTATIC_H
#define _UI_CSTATIC_H

#include "UiBase.h"

#define ST_TOP          0x00000001
#define ST_LEFT         0x00000002
#define ST_CENTER       0x00000004
#define ST_RIGHT        0x00000008
#define ST_VCENTER      0x00000010
#define ST_BOTTOM       0x00000020
#define ST_SINGLELINE   0x00000040

struct UI_STATIC
{
	CWnd*       pParent;
	UINT        uId;
	CRect       rect;
	DWORD       dwStyle;
	CString     sCaption;
	UINT        uBitmap;
	COLORREF    clrMask;
	
	UI_STATIC();
	// 父指针，控件id，坐标，字符串，背景图，透明色
	UI_STATIC(CWnd* parent, UINT id, CRect rcWin, CString caption, UINT bmp=0, COLORREF mask=CLR_NONE, DWORD style=WS_CHILD|WS_VISIBLE);
	UI_STATIC& operator = (const UI_STATIC* pStatic);
};

class CUiStatic : public CUiBase
{
public:
	CUiStatic();
	virtual ~CUiStatic();

public:
	void    CreateStatic(UI_STATIC uiStatic);
	void    SetStaticBitmap(UINT nBitmap, COLORREF clrMask=CLR_NONE); 
	void    SetCaption(CString sCaption);
	CString GetCaption();
	void    SetBkColor(COLORREF clrBk); 
	void    SetFont(CFont* pFont, COLORREF clrFont=CLR_NONE);
	void    SetToolTip(CString sTip, int nMaxTipWidth=0);	// set nMaxTipWidth to show mutilline text.

	CToolTipCtrl* GetToolTipCtrl();

	virtual DWORD GetCtrlStyle();
	virtual void  ModifyCtrlStyle(DWORD dwRemove, DWORD dwAdd);
	void UpdateBkBitmap();

protected:
	void    DrawStatic(CDC* pDC, CRect rcCli);
	virtual void  Draw(CDC* pDC, CRect rcCli); 

protected:
	UINT       m_uNormal;
	COLORREF   m_clrMask;
	COLORREF   m_clrText;
	CFont*     m_pFont;
	CString    m_sCaption;
	DWORD      m_dwFlags;
	CToolTipCtrl m_toolTip;

protected:
	//{{AFX_MSG(CUiStatic)
	afx_msg LRESULT OnNcHitTest(CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	virtual BOOL	PreTranslateMessage(MSG* pMsg);
};

#endif 
