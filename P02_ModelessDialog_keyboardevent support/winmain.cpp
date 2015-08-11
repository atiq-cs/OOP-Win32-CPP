//------------------------------------------------------------------------------
//
// File: winmain.cpp
// Application entry-point.
// Copyright (c) Microsoft Corporation. All rights reserved.
// 
// Author    : Atique
// Date      : May, 2014
// Desc      : Modeless Sample for OOP
//             This code has been fixed to work with keyboard, details are in 
//              commit log
//        C
//        d
//        e
//------------------------------------------------------------------------------

// Includes header files required for UI
#include "OOPCommon.h"
#include "MainDialog.h"


INT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPWSTR /*lpCmdLine*/, INT /*nCmdShow*/)
{
    // Create and show the dialog, we changed the application to support Modeless dialog
    MainDialog *pDlg = new (std::nothrow) MainDialog();
    if (pDlg == NULL)
    {
        MessageBox(NULL, TEXT("Out of memory."), NULL, MB_ICONSTOP);
    }
    else
    {
        // create and show window
        pDlg->ShowDialog(hInstance);
    }

    MSG msg = {};

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MODELESS_DLG_ACCL));

    /* while (TRUE)
    {
        if (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE))
        {
            if (Msg.message == WM_QUIT)
                break;
            else
            {
                if (Msg.message == WM_KEYDOWN || Msg.message == WM_LBUTTONDOWN)
                {
                    if (Msg.wParam == VK_END)
                        Msg.wParam = VK_TAB;
                    if (!IsDialogMessage(hwnd, &Msg))
                    {
                        TranslateMessage(&Msg);
                        DispatchMessage(&Msg);
                    }
                }
            }// els
        }
    }*/

    /*iRet = GetMessage(&msg, NULL, 0, 0);
    We need to pre translate keyboard events here, so can't use GetMessage

    solution is to use PeekMessage, ref: http://stackoverflow.com/questions/2441457/keyboard-input-the-win32-message-loop
    */
    __pragma(warning(disable:4127))

    while (TRUE)
    { 
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                PostQuitMessage(0);
                break;
            }

            if (msg.message != WM_INITDIALOG) {
                if (msg.message == WM_KEYUP) {
                    if (pDlg != NULL)
                    {
                        pDlg->ProcessMessage(pDlg->m_hDlg, msg.message, msg.wParam, msg.lParam);
                    }
                }
            }
            
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg) || !IsDialogMessage(pDlg->GetHwnd(), &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
    }

    // time to destroy the dialog box
    delete pDlg;

    return msg.wParam;
}
