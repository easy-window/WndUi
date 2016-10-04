// demoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "demoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define CLR_TRPT RGB(255, 0, 255)
#define CLR_WHITE RGB(255, 255, 255)
#define CLR_BLACK RGB(0, 0, 0)

// CdemoDlg dialog

CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CUiDlg(CDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CUiDlg::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDemoDlg, CUiDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_UI_BUTTON_CLICKED, OnUiButtonClick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDemoDlg::OnInitDialog()
{
	CUiDlg::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		

	SetBkBitmap(IDB_DLG_MAIN, 0xf0, CLR_TRPT);

	m_fonter.Init(m_hWnd, _T("Abril Fatface"), IDR_RT_FONT);

	m_stc[STC_IMG_HEAD].CreateStatic(UI_STATIC(this, STC_IMG_HEAD, CRect(10, 40, 0, 0), _T(""), IDB_STC_HEAD));
	m_stc[STC_TXT_TITLE].CreateStatic(UI_STATIC(this, STC_TXT_TITLE, CRect(300, 140, 600, 200), _T("This is a Demo.")));
	m_stc[STC_TXT_TITLE].SetFont(m_fonter.GetFont(25), CLR_BLACK);
	m_stc[STC_TXT_TITLE].ModifyCtrlStyle(ST_LEFT, ST_CENTER | ST_VCENTER);

	m_btn[BTN_NORMAL_CLK].CreateButton(UI_BTN(this, BTN_NORMAL_CLK, CRect(400, 300, 0, 0), 
		&UIBTN_IMAGE(IDB_BTN_NORMAL, IDB_BTN_HOVER, IDB_BTN_ACTIVE, IDB_BTN_DISABLE, 0, 0, 0, 0, CLR_TRPT), 
		&UIBTN_STRING(_T("Click"), CLR_WHITE, CLR_BLACK, CLR_WHITE, CLR_WHITE, 0, 0, 0, 0, m_fonter.GetFont(20))));
	m_btn[BTN_CLOSE].CreateButton(UI_BTN(this, BTN_CLOSE, CRect(590, 10, 0, 0), 
		&UIBTN_IMAGE(IDB_BTN_NGREEN, IDB_BTN_HGREEN, IDB_BTN_HGREEN, 0, 0, 0, 0, 0, CLR_TRPT)));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CUiDlg::OnPaint();
	}
}

HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CDemoDlg::OnUiButtonClick(WPARAM wParam, LPARAM lParam) 
{
	UINT dwID = wParam;
	switch(dwID)
	{
	case BTN_NORMAL_CLK: 
		MessageBox(_T("You click the button."), _T("Click"), MB_OK | MB_ICONINFORMATION);
		return 1; // Stop to send message when return 1.
	case BTN_CLOSE: 
		SendMessage(WM_CLOSE, 0, 0);
		return 1;
	}
	return 0;
}