#include "stdafx.h"
#include "UiButton.h"
#include "UiMessage.h"

#define  ST_MOVEIN      0
#define  ST_MOVEOUT     1
#define  ST_MOUSEUP     2
#define  ST_MOUSEDOWN   3


#define TIMER_START		500
#define TIMER_SENDMSG	100


UIBTN_IMAGE::UIBTN_IMAGE()
{
	clrMask = CLR_NONE;
	c.uUncheckNormal  = 0;
	c.uUncheckMouseIn = 0;
	c.uUncheckSelect  = 0;
	c.uUncheckDisable = 0;
	c.uCheckNormal    = 0;
	c.uCheckMouseIn   = 0;
	c.uCheckSelect    = 0;
	c.uCheckDisable   = 0;
}
UIBTN_IMAGE::UIBTN_IMAGE(UINT normal, UINT mouseIn, UINT select, UINT disable, COLORREF mask)
{
	clrMask = mask;
	c.uUncheckNormal  = 0;
	c.uUncheckMouseIn = 0;
	c.uUncheckSelect  = 0;
	c.uUncheckDisable = 0;
	c.uCheckNormal    = 0;
	c.uCheckMouseIn   = 0;
	c.uCheckSelect    = 0;
	c.uCheckDisable   = 0;

	b.uNormal  = normal;
	b.uMouseIn = mouseIn;
	b.uSelect  = select;
	b.uDisable = disable;
}
UIBTN_IMAGE::UIBTN_IMAGE(UINT ucNormal, UINT ucMouseIn, UINT ucSel, UINT ucDisable, UINT ckNormal, UINT ckMouseIn, UINT ckSel, UINT ckDisable, COLORREF mask)
{
	clrMask = mask;
	c.uUncheckNormal  = ucNormal;
	c.uUncheckMouseIn = ucMouseIn;
	c.uUncheckSelect  = ucSel;
	c.uUncheckDisable = ucDisable;
	c.uCheckNormal    = ckNormal;
	c.uCheckMouseIn   = ckMouseIn;
	c.uCheckSelect    = ckSel;
	c.uCheckDisable   = ckDisable;
}

UIBTN_IMAGE& UIBTN_IMAGE::operator = (const UIBTN_IMAGE* pImg)
{
	clrMask = pImg->clrMask;
	c.uUncheckNormal  = pImg->c.uUncheckNormal;
	c.uUncheckMouseIn = pImg->c.uUncheckMouseIn;
	c.uUncheckSelect  = pImg->c.uUncheckSelect;
	c.uUncheckDisable = pImg->c.uUncheckDisable;
	c.uCheckNormal    = pImg->c.uCheckNormal;
	c.uCheckMouseIn   = pImg->c.uCheckMouseIn;
	c.uCheckSelect    = pImg->c.uCheckSelect;
	c.uCheckDisable   = pImg->c.uCheckDisable;

	return *this;
}

UIBTN_STRING::UIBTN_STRING()
{
	pFont = NULL;
	sCaption = _T("");
	c.clrUncheckNormal  = 0;
	c.clrUncheckMouseIn = 0;
	c.clrUncheckSelect  = 0;
	c.clrUncheckDisable = 0;
	c.clrCheckNormal    = 0;
	c.clrCheckMouseIn   = 0;
	c.clrCheckSelect    = 0;
	c.clrCheckDisable   = 0;
}
UIBTN_STRING::UIBTN_STRING(CString caption, COLORREF normal, COLORREF mouseIn, COLORREF select, COLORREF disable, CFont* pft)
{
	pFont = pft;
	sCaption = caption;
	c.clrUncheckNormal  = 0;
	c.clrUncheckMouseIn = 0;
	c.clrUncheckSelect  = 0;
	c.clrUncheckDisable = 0;
	c.clrCheckNormal    = 0;
	c.clrCheckMouseIn   = 0;
	c.clrCheckSelect    = 0;
	c.clrCheckDisable   = 0;

	b.clrNormal  = normal;
	b.clrMouseIn = mouseIn;
	b.clrSelect  = select;
	b.clrDisable = disable;
}
UIBTN_STRING::UIBTN_STRING(CString caption, COLORREF ucNormal, COLORREF ucMouseIn, COLORREF ucSel, COLORREF ucDisable, 
						   COLORREF ckNormal, COLORREF ckMouseIn, COLORREF ckSel, COLORREF ckDisable, CFont* pft)
{
	pFont = pft;
	sCaption = caption;
	c.clrUncheckNormal  = ucNormal;
	c.clrUncheckMouseIn = ucMouseIn;
	c.clrUncheckSelect  = ucSel;
	c.clrUncheckDisable = ucDisable;
	c.clrCheckNormal    = ckNormal;
	c.clrCheckMouseIn   = ckMouseIn;
	c.clrCheckSelect    = ckSel;
	c.clrCheckDisable   = ckDisable;
}

UIBTN_STRING& UIBTN_STRING::operator = (const UIBTN_STRING* pString)
{
	pFont = pString->pFont;
	sCaption = pString->sCaption;
	c.clrUncheckNormal  = pString->c.clrUncheckNormal;
	c.clrUncheckMouseIn = pString->c.clrUncheckMouseIn;
	c.clrUncheckSelect  = pString->c.clrUncheckSelect;
	c.clrUncheckDisable = pString->c.clrUncheckDisable;
	c.clrCheckNormal    = pString->c.clrCheckNormal;
	c.clrCheckMouseIn   = pString->c.clrCheckMouseIn;
	c.clrCheckSelect    = pString->c.clrCheckSelect;
	c.clrCheckDisable   = pString->c.clrCheckDisable;

	return *this;
}

UI_BTN::UI_BTN()
{
	pParent  = NULL;
	uId      = 0;
	rect     = CRect(0, 0, 0, 0);
	nType    = BTN_COMMON;
	dwStyle  = 0;
}

UI_BTN::UI_BTN(CWnd* parent, UINT id, CRect rcWin, UIBTN_IMAGE* pBmpMode, UIBTN_STRING* pStrMode, int btnType, DWORD style)
{
	pParent  = parent;
	uId      = id;
	rect     = rcWin;
	nType    = btnType;
	dwStyle  = style;

	if(NULL != pBmpMode) bmpMode = *pBmpMode;
	if(NULL != pStrMode) strMode = *pStrMode;
}
UI_BTN& UI_BTN::operator = (const UI_BTN* pBtn)
{
	pParent	= pBtn->pParent;
	uId		= pBtn->uId;
	rect	= pBtn->rect;
	bmpMode	= pBtn->bmpMode;
	strMode	= pBtn->strMode;	 
	nType	= pBtn->nType;
	dwStyle	= pBtn->dwStyle;

	return *this;
}


CUiButton::CUiButton()
{
	m_bEnabled = true;
	m_bChecked = false; 
	m_nState   = ST_MOVEOUT;
	m_hCursor  = NULL;
	m_nBtnType = BTN_COMMON;
	m_bConHits = false;
	m_nTimer1 = -1;
	m_nTimer2 = -1;
	m_clrBk = CLR_NONE;
}

CUiButton::~CUiButton()
{
	if(m_nTimer1 >= 0)
	{
		KillTimer(1);
		m_nTimer1 = -1;
	}

	if(m_nTimer2 >= 0)
	{
		KillTimer(2);
		m_nTimer2 = -1;
	}
}


BEGIN_MESSAGE_MAP(CUiButton, CUiBase)
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
END_MESSAGE_MAP()


CToolTipCtrl* CUiButton::GetToolTipCtrl()
{
	return &m_toolTip;
}

//-------------------------------------------------------------------------------
void CUiButton::CreateButton(UI_BTN btn)
{
	Create(btn.pParent, btn.uId, btn.rect, btn.dwStyle);
	SetButtonBitmap(btn.bmpMode, btn.strMode, btn.nType); 
}
//-------------------------------------------------------------------------------
void CUiButton::Enable(bool bEnable)
{
	if(m_bEnabled != bEnable)
	{
		m_bEnabled = bEnable;
		Invalidate(FALSE);
	}
}
//-------------------------------------------------------------------------------
bool CUiButton::IsEnable()
{
	return m_bEnabled;
}
//-------------------------------------------------------------------------------
bool CUiButton::IsCheck()
{
	return m_bChecked;
}
//-------------------------------------------------------------------------------
void CUiButton::SetCheck(bool bCheck)
{
	if(m_bEnabled && m_bChecked != bCheck)
	{
		m_bChecked = bCheck;
		Invalidate(FALSE);
	}
}
//-------------------------------------------------------------------------------
void CUiButton::EnableConsecutiveHits(bool bEnable)
{
	if(BTN_COMMON == m_nBtnType)
	{
		if(m_bEnabled && m_bConHits != bEnable)
		{
			m_bConHits = bEnable;
		}
	}
}
//-------------------------------------------------------------------------------
void CUiButton::SetButtonBitmap(UIBTN_IMAGE bmpMode, UIBTN_STRING strMode, int nBtnType)
{
	m_nBtnType  = nBtnType;
	m_BmpMode	= bmpMode;
	m_strMode	= strMode;

	UINT uId = 0;
	uId = (0 == uId) ? m_BmpMode.c.uCheckNormal    : uId;
	uId = (0 == uId) ? m_BmpMode.c.uCheckMouseIn   : uId;
	uId = (0 == uId) ? m_BmpMode.c.uCheckSelect    : uId;
	uId = (0 == uId) ? m_BmpMode.c.uCheckDisable   : uId;
	uId = (0 == uId) ? m_BmpMode.c.uUncheckNormal  : uId;
	uId = (0 == uId) ? m_BmpMode.c.uUncheckMouseIn : uId;
	uId = (0 == uId) ? m_BmpMode.c.uUncheckSelect  : uId;
	uId = (0 == uId) ? m_BmpMode.c.uUncheckDisable : uId;
	//ASSERT(0 != uId);
	if(0 != uId)
	{
		BITMAP  bmp;
		CBitmap bitmap;
		bitmap.LoadBitmap(uId);
		bitmap.GetBitmap(&bmp);
		SetWindowPos(NULL, 0, 0, bmp.bmWidth, bmp.bmHeight, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
		bitmap.DeleteObject();
		Invalidate(FALSE);
	}
}
//-------------------------------------------------------------------------------
void CUiButton::SetButtonImage(UIBTN_IMAGE bmpMode)
{
	m_BmpMode = bmpMode;

	UINT uId = 0;
	uId = (0 == uId) ? m_BmpMode.c.uCheckNormal    : uId;
	uId = (0 == uId) ? m_BmpMode.c.uCheckMouseIn   : uId;
	uId = (0 == uId) ? m_BmpMode.c.uCheckSelect    : uId;
	uId = (0 == uId) ? m_BmpMode.c.uCheckDisable   : uId;
	uId = (0 == uId) ? m_BmpMode.c.uUncheckNormal  : uId;
	uId = (0 == uId) ? m_BmpMode.c.uUncheckMouseIn : uId;
	uId = (0 == uId) ? m_BmpMode.c.uUncheckSelect  : uId;
	uId = (0 == uId) ? m_BmpMode.c.uUncheckDisable : uId;
	//ASSERT(0 != uId);
	if(0 != uId)
	{
		BITMAP  bmp;
		CBitmap bitmap;
		bitmap.LoadBitmap(uId);
		bitmap.GetBitmap(&bmp);
		SetWindowPos(NULL, 0, 0, bmp.bmWidth, bmp.bmHeight, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
		bitmap.DeleteObject();
		Invalidate(FALSE);
	}
}
//-------------------------------------------------------------------------------
void CUiButton::SetButtonTextStyle(UIBTN_STRING strMode)
{
	m_strMode	= strMode;
	Invalidate(FALSE);
}
//-------------------------------------------------------------------------------
void CUiButton::SetCapture(CString sText, bool bTip)
{
	m_strMode.sCaption = sText;
	if(bTip) SetToolTip(sText, 100);
	Invalidate(FALSE);
}
//-------------------------------------------------------------------------------
CString CUiButton::GetCapture()
{
	return m_strMode.sCaption;
}
//-------------------------------------------------------------------------------
void CUiButton::GetWindowText(CString& sText)
{
	sText = m_strMode.sCaption;
}
//-------------------------------------------------------------------------------
void CUiButton::SetCursor(UINT nCursorId)
{
	if(m_hCursor != NULL) 
	{ 
		::DestroyCursor(m_hCursor);
		m_hCursor = NULL;
	}
	
	if(nCursorId != -1)
	{
		m_hCursor = (HCURSOR)::LoadImage(AfxFindResourceHandle(MAKEINTRESOURCE(nCursorId), RT_GROUP_CURSOR), 
			                             MAKEINTRESOURCE(nCursorId), IMAGE_CURSOR, 0, 0, 0);
	}
}
//-------------------------------------------------------------------------------
void CUiButton::SetBkColor(COLORREF clrBk) 
{
	if(clrBk == m_BmpMode.clrMask) clrBk ++;
	m_clrBk = clrBk;
	Invalidate(FALSE);
}
//-------------------------------------------------------------------------------
void CUiButton::SetToolTip(CString sTip, int nMaxTipWidth)
{
	if(NULL != GetSafeHwnd() && sTip != _T("")) 
	{
		if(NULL == m_toolTip.GetSafeHwnd()) 
		{
			m_toolTip.Create(this, TTS_ALWAYSTIP);
			m_toolTip.Activate(TRUE);
			m_toolTip.AddTool(this, sTip);
			if(nMaxTipWidth > 0)
			{
				m_toolTip.SetMaxTipWidth(nMaxTipWidth);
			}
		}
		else
		{
			m_toolTip.UpdateTipText(sTip, this);	
			if(nMaxTipWidth > 0)
			{
				m_toolTip.SetMaxTipWidth(nMaxTipWidth);
			}
		}
	}
}
//-------------------------------------------------------------------------------
BOOL CUiButton::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message == WM_MOUSEMOVE)
	{
		if (m_toolTip.GetSafeHwnd()) { m_toolTip.RelayEvent(pMsg); }
	}

	return CUiBase::PreTranslateMessage(pMsg);
}
//-------------------------------------------------------------------------------
BOOL CUiButton::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if(m_hCursor != NULL && m_bEnabled)
	{
		::SetCursor(m_hCursor);
		return TRUE;
	}	

	return CUiBase::OnSetCursor(pWnd, nHitTest, message);
}
//-------------------------------------------------------------------------------
void CUiButton::OnTimer(UINT_PTR nIDEvent)
{
	if(1 == nIDEvent)
	{
		KillTimer(1);
		m_nTimer1 = -1;
		if(m_nTimer2 < 0)
		{
			m_nTimer2 = SetTimer(2, TIMER_SENDMSG, NULL);
		}
	}

	if(2 == nIDEvent)
	{
		CWnd* pParent = GetParent();
		while(NULL != pParent)
		{
			if(pParent->SendMessage(WM_UI_BUTTON_CLICKED, GetDlgCtrlID(), m_nBtnType)) break;
			pParent = pParent->GetParent();
		}
	}

	CUiBase::OnTimer(nIDEvent);
}
//-------------------------------------------------------------------------------
void CUiButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(ST_MOVEOUT == m_nState)
	{
		m_nState = ST_MOVEIN;

		//Active WM_MOUSELEAVE message
		TRACKMOUSEEVENT trackmouseevent;
		trackmouseevent.cbSize = sizeof(trackmouseevent);
		trackmouseevent.dwFlags     = TME_LEAVE;
		trackmouseevent.hwndTrack   = GetSafeHwnd();
		trackmouseevent.dwHoverTime = HOVER_DEFAULT;
		_TrackMouseEvent(&trackmouseevent);

		if(m_bEnabled) 
		{
			Invalidate(FALSE);
		}
	}

	CUiBase::OnMouseMove(nFlags, point);
}
//-------------------------------------------------------------------------------
LRESULT CUiButton::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	if(ST_MOVEOUT != m_nState)
	{
		m_nState = ST_MOVEOUT;
		if(m_bEnabled)
		{
			Invalidate(FALSE);
		}

		if(m_nTimer1 >= 0)
		{
			KillTimer(1);
			m_nTimer1 = -1;
		}

		if(m_nTimer2 >= 0)
		{
			KillTimer(2);
			m_nTimer2 = -1;
		}
	}

	return 0;
}
//---------------------------------------------------------------------------------
void CUiButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if(ST_MOUSEDOWN != m_nState)
	{
		m_nState = ST_MOUSEDOWN;

		if(m_bEnabled)
		{	
			Invalidate(FALSE);
			if(m_bConHits)
			{
				if(m_nTimer1 < 0)
				{
					m_nTimer1 = (int)SetTimer(1, TIMER_START, NULL);
				}
			}
		}
	}

	CUiBase::OnLButtonDown(nFlags, point);
}
//-------------------------------------------------------------------------------
void CUiButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if(ST_MOUSEDOWN == m_nState || ST_MOUSEUP == m_nState)
	{
		m_nState = ST_MOUSEUP;
		if(m_bEnabled)
		{
			switch(m_nBtnType)
			{
			case BTN_CHECK:  m_bChecked = !m_bChecked; break;
			case BTN_RADIO:  m_bChecked = true; break;
			}

			Invalidate(FALSE);

			CWnd* pParent = GetParent();
			while(NULL != pParent)
			{
				if(pParent->SendMessage(WM_UI_BUTTON_CLICKED, GetDlgCtrlID(), m_nBtnType)) break;
				pParent = pParent->GetParent();
			}
		}

		if(m_nTimer1 >= 0)
		{
			KillTimer(1);
			m_nTimer1 = -1;
		}

		if(m_nTimer2 >= 0)
		{
			KillTimer(2);
			m_nTimer2 = -1;
		}
	}

	CUiBase::OnLButtonUp(nFlags, point);
}
//-------------------------------------------------------------------------------
void CUiButton::Draw(CDC* pDC, CRect rcCli)
{
	DrawButton(pDC, rcCli);
}
//-------------------------------------------------------------------------------
void CUiButton::DrawButton(CDC* pDC, CRect rcCli)
{
	UINT uId = 0;
	CString sCaption = _T("");
	CFont* pFont = NULL;
	COLORREF clrText = CLR_NONE;

	if(!m_bEnabled)
	{
		switch(m_nBtnType)
		{
		case BTN_COMMON:{ 
							uId			= m_BmpMode.b.uDisable; 
							sCaption	= m_strMode.sCaption;
							pFont		= m_strMode.pFont;
							clrText		= m_strMode.b.clrDisable;
							break;
						}
		case BTN_CHECK:{  
							sCaption	= m_strMode.sCaption;
							pFont		= m_strMode.pFont;
							clrText		= m_bChecked ? m_strMode.c.clrCheckDisable : m_strMode.c.clrUncheckDisable; 
							uId			= m_bChecked ? m_BmpMode.c.uCheckDisable : m_BmpMode.c.uUncheckDisable; 
							break;
					   }
		case BTN_RADIO:{
							sCaption	= m_strMode.sCaption;
							pFont		= m_strMode.pFont;
							clrText		= m_bChecked ? m_strMode.r.clrCheckDisable : m_strMode.r.clrUncheckDisable; 
							uId			= m_bChecked ? m_BmpMode.r.uCheckDisable : m_BmpMode.r.uUncheckDisable; 
							break; 
					   }
		}
	}
	else
	{
		switch(m_nState)
		{
		case ST_MOVEOUT:  
			switch(m_nBtnType)
			{
			case BTN_COMMON:{
								sCaption	= m_strMode.sCaption;
								pFont		= m_strMode.pFont;
								clrText		= m_strMode.b.clrNormal;
								uId			= m_BmpMode.b.uNormal; 
								break;
							}
			case BTN_CHECK:{
								sCaption	= m_strMode.sCaption;
								pFont		= m_strMode.pFont;
								clrText		= m_bChecked ? m_strMode.c.clrCheckNormal : m_strMode.c.clrUncheckNormal;
								uId			= m_bChecked ? m_BmpMode.c.uCheckNormal : m_BmpMode.c.uUncheckNormal; 
								break;
						   }
			case BTN_RADIO:{
								sCaption	= m_strMode.sCaption;
								pFont		= m_strMode.pFont;
								clrText		= m_bChecked ? m_strMode.r.clrCheckNormal : m_strMode.r.clrUncheckNormal;
								uId			= m_bChecked ? m_BmpMode.r.uCheckNormal : m_BmpMode.r.uUncheckNormal; 
								break; 
						   }
			}
			break;
		case ST_MOVEIN:
		case ST_MOUSEUP:
			switch(m_nBtnType)
			{
			case BTN_COMMON:{
								sCaption	= m_strMode.sCaption;
								pFont		= m_strMode.pFont;
								clrText		= m_strMode.b.clrMouseIn;
								uId			= m_BmpMode.b.uMouseIn; 
								break;
							}
			case BTN_CHECK:{  
								sCaption	= m_strMode.sCaption;
								pFont		= m_strMode.pFont;
								clrText		= m_bChecked ? m_strMode.c.clrCheckMouseIn : m_strMode.c.clrUncheckMouseIn; 
								uId			= m_bChecked ? m_BmpMode.c.uCheckMouseIn : m_BmpMode.c.uUncheckMouseIn; 
								break;
						   }
			case BTN_RADIO:{
								sCaption	= m_strMode.sCaption;
								pFont		= m_strMode.pFont;
								clrText		= m_bChecked ? m_strMode.r.clrCheckMouseIn : m_strMode.r.clrUncheckMouseIn; 
								uId			= m_bChecked ? m_BmpMode.r.uCheckMouseIn : m_BmpMode.r.uUncheckMouseIn; 
								break; 
						   }
			}
			break;
		case ST_MOUSEDOWN: 
			switch(m_nBtnType)
			{
			case BTN_COMMON:{
								sCaption	= m_strMode.sCaption;
								pFont		= m_strMode.pFont;
								clrText		= m_strMode.b.clrSelect;
								uId			= m_BmpMode.b.uSelect; 
								break;
							}
			case BTN_CHECK:{  
								sCaption	= m_strMode.sCaption;
								pFont		= m_strMode.pFont;
								clrText		= m_bChecked ? m_strMode.c.clrCheckSelect : m_strMode.c.clrUncheckSelect; 
								uId			= m_bChecked ? m_BmpMode.c.uCheckSelect : m_BmpMode.c.uUncheckSelect; 
								break;
						   }
			case BTN_RADIO:{
								sCaption	= m_strMode.sCaption;
								pFont		= m_strMode.pFont;
								clrText		= m_bChecked ? m_strMode.r.clrCheckSelect : m_strMode.r.clrUncheckSelect; 
								uId			= m_bChecked ? m_BmpMode.r.uCheckSelect : m_BmpMode.r.uUncheckSelect; 
								break; 
						   }
			}
			break;
		}
	}

	if (m_clrBk != CLR_NONE)
	{
		pDC->FillSolidRect(rcCli, m_clrBk);
	}

	if(0 != uId)
	{
		DrawBitmap(pDC, rcCli, uId, m_BmpMode.clrMask);
	}

	if(_T("") != sCaption)
	{
		DrawText(pDC, rcCli, sCaption, DT_SINGLELINE | DT_VCENTER | DT_CENTER | DT_END_ELLIPSIS, clrText, pFont);
	}
}
//-------------------------------------------------------------------------------