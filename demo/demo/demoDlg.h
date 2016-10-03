// demoDlg.h : header file
//

#pragma once


// CdemoDlg dialog
class CDemoDlg : public CUiDlg
{
// Construction
public:
	CDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DEMO_DIALOG };

protected:
	typedef enum _STC_ID
	{
		STC_IMG_HEAD = 0,
		STC_QTY,
	};

	typedef enum _BTN_ID
	{
		BTN_NORMAL_CLK,
		BTN_CLOSE,
		BTN_QTY,
	};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnUiButtonClick(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

	CUiStatic m_stc[STC_QTY];
	CUiButton m_btn[BTN_QTY];
};
