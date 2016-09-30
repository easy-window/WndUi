#ifndef  _UI_COMMON_H_
#define  _UI_COMMON_H_


/*****************************************************************************************************************
 *
 * There are windows messgae define by myself. They are the windows messages 
 * that the Ui control sends when it performs the appropriate action.
 *
 *****************************************************************************************************************/

///////////////////////////////////////////////////////////////////
//sample.h file
//  afx_msg LRESULT OnYourMsg(WPARAM wParam, LPARAM lParam);
//
//sample.cpp file
//  ON_MESSAGE(WM_USERMSG, OnYourMsg)
//  LRESULT CSample::OnYourMsg(WPARAM wParam, LPARAM lParam) {}
///////////////////////////////////////////////////////////////////


//wParam=(UINT)CtrlID, lParam=(int)ButtonType, from CUiButton when left click
#define WM_UI_BUTTON_CLICKED          WM_USER + 6001

#endif