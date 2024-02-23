#include "pch.h"
#include "CButton2.h"

CButton2::CButton2():imgPath(nullptr), BackGround(nullptr), xy()
{
    //初始化GDI+
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

CButton2::~CButton2()
{
    // 关闭 GDI+
    GdiplusShutdown(gdiplusToken);
}

void CButton2::setButton(WCHAR* imgpath, CString words, WCHAR* bk, int x, int y, int width, int height)
{
    imgPath = imgpath;
    Words = words;
    BackGround = bk;
    xy.set(x, y, width, height);

    // 移动按钮控件
    SetWindowPos(NULL, x, y, width, height, SWP_NOZORDER);

}

void CButton2::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{// 获取 CDC 对象
    CDC* pdc = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rect = lpDrawItemStruct->rcItem;

    // 创建内存设备上下文
    CDC memDC;
    memDC.CreateCompatibleDC(pdc);
    CBitmap memBitmap;
    memBitmap.CreateCompatibleBitmap(pdc, rect.Width(), rect.Height());
    CBitmap* pOldBitmap = memDC.SelectObject(&memBitmap);

    // 清空原有内容
    memDC.FillSolidRect(&rect, RGB(255, 255, 255));

    // 创建 Graphics 对象
    Graphics graphics(memDC.GetSafeHdc());

    // 判断是否有背景图片，没有则使用默认填充
    if (BackGround != nullptr) 
    {
        Image backgroundImage(BackGround); // 背景图片路径

        // 计算背景图片的裁剪区域和填充区域
        graphics.DrawImage(&backgroundImage, 0, 0, xy.X, xy.Y, xy.Width, xy.Height, UnitPixel);
    }
    else
    {
        // 使用默认填充色填充背景
        memDC.FillSolidRect(&rect, RGB(192, 192, 192));
    }
    //-------------------------------------------

    // 判断是否有按钮图片，没有则使用默认绘制方式
    if (imgPath != nullptr) 
    {
        // 加载图像并绘制在按钮上
        Image img(imgPath);
        int imageWidth = img.GetWidth();
        int imageHeight = img.GetHeight();
        int x = rect.left + (rect.Width() - imageWidth) / 2; // 水平居中显示图像
        int y = rect.top + (rect.Height() - imageHeight) / 2; // 垂直居中显示图像
        graphics.DrawImage(&img, x, y, imageWidth, imageHeight);
    }
    //-------------------------------------------

    //---- 绘制按钮文本

    // 创建并选择自定义字体
    CFont font;
    font.CreatePointFont(120, _T("Arial")); // 创建 120 点的 Arial 字体
    CFont* pOldFont = memDC.SelectObject(&font);

    // 设置背景透明
    memDC.SetBkMode(TRANSPARENT);

    CString text = Words.IsEmpty() ? _T("") : Words;
    memDC.SetBkMode(TRANSPARENT); // 设置背景透明
    memDC.DrawText(text, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    //-----------------

    // 将绘制好的图像复制到屏幕上
    pdc->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

    // 清理资源
    memDC.SelectObject(pOldBitmap);
    memBitmap.DeleteObject();
    memDC.DeleteDC();

    // 释放 CDC 对象
    pdc->Detach();

}
