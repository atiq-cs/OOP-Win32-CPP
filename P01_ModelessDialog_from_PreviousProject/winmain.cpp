//------------------------------------------------------------------------------
//
// File: winmain.cpp
// Application entry-point.
// Copyright (c) Microsoft Corporation. All rights reserved.
// 
// Author    : Atique
// Date        : May, 2014
// Title    : Modeless Dialog Sample
// Desc        : Windows SDK C++, minimalist version
//        a
//        b
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

    INT iRet;
    MSG msg;

    // HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MODELESS_DLG_ACCL));



    iRet = GetMessage(&msg, NULL, 0, 0);
    while (iRet != 0)
    { 
        if (iRet == -1)
        {
            HRESULT hr = HRESULT_FROM_WIN32(GetLastError());
            UNREFERENCED_PARAMETER(hr);
            MessageBox(NULL, TEXT("Error processing the application window message loop"), TEXT("Caption"), MB_ICONERROR);
        }
        else
        {
            // if (!IsWindow(pDlg->GetHwnd()) || !IsDialogMessage(pDlg->GetHwnd(), &msg)) 
            if (!TranslateAccelerator(msg.hwnd, NULL, &msg) || !IsDialogMessage(pDlg->GetHwnd(), &msg))
            { 
                TranslateMessage(&msg); 
                DispatchMessage(&msg); 
            }
        }

        iRet = GetMessage(&msg, NULL, 0, 0);
    }

    // time to destroy the dialog box
    delete pDlg;

    return msg.wParam;
}
