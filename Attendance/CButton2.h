#pragma once
#include <afxwin.h>

#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;

class CButton2 :
    public CButton
{
public:
    const WCHAR* imgPath;
    const WCHAR* BackGround;
    CString Words;
    void setButton(WCHAR* imgpath, CString words = _T(" "), WCHAR* bk = nullptr);

    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
};

