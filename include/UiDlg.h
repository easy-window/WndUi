#ifndef _UI_CDIALOG_H
#define _UI_CDIALOG_H


/*****************************************************************************************************************
 *
 * CUiDlg: inherit from CDialog
 *
 *****************************************************************************************************************/

class CUiDlg : public CDialog
{
	DECLARE_DYNAMIC(CUiDlg)

public:
	CUiDlg();
	CUiDlg(UINT nIDTemplate, CWnd* pParentWnd=NULL);
	CUiDlg(LPCTSTR lpszTemplateName, CWnd* pParentWnd=NULL);
	virtual ~CUiDlg();

public:
	// res's id & transparency
	void    SetBkBitmap(UINT uId, UINT uAlpha=0xff, COLORREF clrMask=CLR_NONE);    // Set attributes of this dialog. 
	void    SetWinRgn(HRGN hWinGgn/*if null, set window region to null. this parameter will be ignored for have-no-parent window*/); 
	CDC*    GetBkDC();                                                             // Get memory dc of background.

private:
	void    Init();

private:
	UINT       m_uBk;
	UINT       m_uAlpha;
	COLORREF   m_clrMask;
	CDC        m_BkDC;
	bool       m_bStoredBkDc;
	bool       m_bPopupWin;
	bool	   m_bPopup;
	HRGN       m_hWinRgn;

protected:
	afx_msg void    OnPaint();
	afx_msg BOOL    OnEraseBkgnd(CDC* pDC);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	DECLARE_MESSAGE_MAP()

	virtual BOOL    OnCommand(WPARAM wParam, LPARAM lParam);
};

#endif 
