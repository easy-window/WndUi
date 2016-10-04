#include "stdafx.h"
#include "UiFont.h"
#include "UiMessage.h"


CUiFont::CUiFont()
{
	m_hFont = NULL;
}
//-------------------------------------------------------------------------------
CUiFont::~CUiFont()
{
	UninstallFont(m_hFont);
}
//-------------------------------------------------------------------------------
void CUiFont::Init(HWND hWnd, CString sFontfamily, UINT uFontId, int nEscapement,
				   int nOrientation, int nWeight, BYTE bItalic, BYTE bUnderline,
				   BYTE cStrikeOut, BYTE nCharSet, BYTE nOutPrecision,
				   BYTE nClipPrecision, BYTE nQuality, BYTE nPitchAndFamily)
{
	HDC hdc = ::GetDC(hWnd);
	m_nDC = ::GetDeviceCaps(hdc, LOGPIXELSY);
	m_uFontId = uFontId;
	m_hFont = InstallFont(m_uFontId);

	for (int i = FONT_SIZE_MIN; i <= FONT_SIZE_MAX; i++)
	{
		int nHPixel = -MulDiv(i, m_nDC, 72);
		m_font[i - FONT_SIZE_MIN].CreateFont(nHPixel, 0, nEscapement, nOrientation, 
			nWeight, bItalic, bUnderline, cStrikeOut, nCharSet, nOutPrecision, nClipPrecision, 
			nQuality, nPitchAndFamily, sFontfamily);
	}
	::ReleaseDC(hWnd, hdc);
}
//-------------------------------------------------------------------------------
CFont* CUiFont::GetFont(int nFontSize)
{
	if(NULL == m_font[nFontSize - FONT_SIZE_MIN].GetSafeHandle()) return NULL;
	return &m_font[nFontSize - FONT_SIZE_MIN];
}
//-------------------------------------------------------------------------------
CFont* CUiFont::SetFont(int nFontSize, CString sFontfamily, int nEscapement,
				   int nOrientation, int nWeight, BYTE bItalic, BYTE bUnderline,
				   BYTE cStrikeOut, BYTE nCharSet, BYTE nOutPrecision,
				   BYTE nClipPrecision, BYTE nQuality, BYTE nPitchAndFamily)
{
	if(NULL == m_font[nFontSize - FONT_SIZE_MIN].GetSafeHandle()) return NULL;

	CFont* pFont = &m_font[nFontSize - FONT_SIZE_MIN];
	pFont->DeleteObject();

	int nHPixel = -MulDiv(nFontSize, m_nDC, 72);
	pFont->CreateFont(nHPixel, 0, nEscapement, nOrientation, 
		nWeight, bItalic, bUnderline, cStrikeOut, nCharSet, nOutPrecision, nClipPrecision, 
		nQuality, nPitchAndFamily, sFontfamily);

	return pFont;
}
//-------------------------------------------------------------------------------
HANDLE CUiFont::InstallFont(UINT uFontId)
{
	HINSTANCE hInstRes = NULL;
	HRSRC hRsrc = FindResource(hInstRes, MAKEINTRESOURCE(uFontId), _T("RT_FONT"));
	DWORD cbSize = SizeofResource(hInstRes, hRsrc);
	HGLOBAL hMem = LoadResource(hInstRes, hRsrc);
	LPVOID pvData = LockResource(hMem);
	DWORD nFontsInstalled = 0;
	return AddFontMemResourceEx(pvData, cbSize, NULL, &nFontsInstalled);
}
//-------------------------------------------------------------------------------
void CUiFont::UninstallFont(HANDLE hFont)
{
	if(NULL == hFont) return;
	RemoveFontMemResourceEx(hFont);
}
//-------------------------------------------------------------------------------
