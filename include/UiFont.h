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

	void Init(HWND hWnd, CString sFontfamily, UINT uFontId = 0, int nEscapement = 0,
		int nOrientation = 0, int nWeight = FW_NORMAL, BYTE bItalic = FALSE, BYTE bUnderline = FALSE,
		BYTE cStrikeOut = 0, BYTE nCharSet = ANSI_CHARSET, BYTE nOutPrecision = OUT_DEFAULT_PRECIS,
		BYTE nClipPrecision = CLIP_DEFAULT_PRECIS, BYTE nQuality = DEFAULT_QUALITY, BYTE nPitchAndFamily = DEFAULT_PITCH | FF_SWISS);
	CFont* GetFont(int nFontSize);
	CFont* SetFont(int nFontSize, CString sFontfamily, int nEscapement = 0,
		int nOrientation = 0, int nWeight = FW_NORMAL, BYTE bItalic = FALSE, BYTE bUnderline = FALSE,
		BYTE cStrikeOut = 0, BYTE nCharSet = ANSI_CHARSET, BYTE nOutPrecision = OUT_DEFAULT_PRECIS,
		BYTE nClipPrecision = CLIP_DEFAULT_PRECIS, BYTE nQuality = DEFAULT_QUALITY, BYTE nPitchAndFamily = DEFAULT_PITCH | FF_SWISS);

protected:
	enum { FONT_SIZE_MIN = 6, FONT_SIZE_MAX = 36, FONT_COUNT = FONT_SIZE_MAX - FONT_SIZE_MIN + 1 };
	HANDLE InstallFont(UINT uFontId);
	void UninstallFont(HANDLE hFont);

private:
	CFont	m_font[FONT_COUNT];
	UINT	m_uFontId;
	HANDLE	m_hFont;
	int		m_nDC;
};

#endif 
