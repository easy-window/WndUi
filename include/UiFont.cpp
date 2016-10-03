#include "stdafx.h"
#include "UiFont.h"
#include "UiMessage.h"


CUiFont::CUiFont()
{
	
}
//-------------------------------------------------------------------------------
CUiFont::~CUiFont()
{
}
//-------------------------------------------------------------------------------
void CUiFont::Init(HWND hWnd, CString sFontfamily, UINT uFontId)
{
	HDC hdc = ::GetDC(hWnd);
	int nDC = ::GetDeviceCaps(hdc, LOGPIXELSY);
	m_hFont = InstallFont(uFontId);

	for (int i = FONT_SIZE_MIN; i <= FONT_SIZE_MAX; i++)
	{
		int nHPixel = (i * nDC) / 72;
		m_font[i - FONT_SIZE_MIN].CreateFont(nHPixel, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
			DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, sFontfamily);
	}
	::ReleaseDC(hWnd, hdc);
}
//-------------------------------------------------------------------------------
CFont* CUiFont::GetFont(int nFontSize)
{
	return &m_font[nFontSize - FONT_SIZE_MIN];
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
