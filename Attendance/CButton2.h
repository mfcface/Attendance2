#pragma once
#include <afxwin.h>
#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;

class CButton2 :
    public CButton
{

    struct xySize
    {
        int X;
        int Y;
        int Width;
        int Height;
        xySize() :X(0), Y(), Width(0), Height(0) {}
        void set(int x, int y, int width, int height)
        {
            X=x;
            Y=y; 
            Width=width; 
            Height=height;
        }
    };
public:
    ULONG_PTR gdiplusToken;
    GdiplusStartupInput gdiplusStartupInput;
public:
    CButton2();
    ~CButton2();
    const WCHAR* imgPath;
    const WCHAR* BackGround;
    CString Words;
    void setButton(WCHAR* imgpath, CString words, WCHAR* bk,int x,int y, int width,int height);
    
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
private:
    xySize xy; // 按钮的位置和大小
};

