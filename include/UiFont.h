#ifndef _UI_CFONT_H
#define _UI_CFONT_H


/*****************************************************************************************************************
 *
 * CUiFont: Ui Font Loader
 *
 *****************************************************************************************************************/

class CUiFont
{
public:
	CUiFont();
	~CUiFont();

	void Init(HWND hWnd, CString sFontfamily, UINT uFontId = 0);
	CFont* GetFont(int nFontSize);

protected:
	enum { FONT_SIZE_MIN = 6, FONT_SIZE_MAX = 30, FONT_COUNT = FONT_SIZE_MAX - FONT_SIZE_MIN + 1 };
	HANDLE InstallFont(UINT uFontId);
	void UninstallFont(HANDLE hFont);

private:
	CFont m_font[FONT_COUNT];
	HANDLE	m_hFont;
};

#endif 
