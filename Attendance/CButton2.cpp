#include "pch.h"
#include "CButton2.h"

CButton2::CButton2():imgPath(nullptr), BackGround(nullptr), xy()
{
    //��ʼ��GDI+
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

CButton2::~CButton2()
{
    // �ر� GDI+
    GdiplusShutdown(gdiplusToken);
}

void CButton2::setButton(WCHAR* imgpath, CString words, WCHAR* bk, int x, int y, int width, int height)
{
    imgPath = imgpath;
    Words = words;
    BackGround = bk;
    xy.set(x, y, width, height);

    // �ƶ���ť�ؼ�
    SetWindowPos(NULL, x, y, width, height, SWP_NOZORDER);

}

void CButton2::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{// ��ȡ CDC ����
    CDC* pdc = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rect = lpDrawItemStruct->rcItem;

    // �����ڴ��豸������
    CDC memDC;
    memDC.CreateCompatibleDC(pdc);
    CBitmap memBitmap;
    memBitmap.CreateCompatibleBitmap(pdc, rect.Width(), rect.Height());
    CBitmap* pOldBitmap = memDC.SelectObject(&memBitmap);

    // ���ԭ������
    memDC.FillSolidRect(&rect, RGB(255, 255, 255));

    // ���� Graphics ����
    Graphics graphics(memDC.GetSafeHdc());

    // �ж��Ƿ��б���ͼƬ��û����ʹ��Ĭ�����
    if (BackGround != nullptr) 
    {
        Image backgroundImage(BackGround); // ����ͼƬ·��

        // ���㱳��ͼƬ�Ĳü�������������
        graphics.DrawImage(&backgroundImage, 0, 0, xy.X, xy.Y, xy.Width, xy.Height, UnitPixel);
    }
    else
    {
        // ʹ��Ĭ�����ɫ��䱳��
        memDC.FillSolidRect(&rect, RGB(192, 192, 192));
    }
    //-------------------------------------------

    // �ж��Ƿ��а�ťͼƬ��û����ʹ��Ĭ�ϻ��Ʒ�ʽ
    if (imgPath != nullptr) 
    {
        // ����ͼ�񲢻����ڰ�ť��
        Image img(imgPath);
        int imageWidth = img.GetWidth();
        int imageHeight = img.GetHeight();
        int x = rect.left + (rect.Width() - imageWidth) / 2; // ˮƽ������ʾͼ��
        int y = rect.top + (rect.Height() - imageHeight) / 2; // ��ֱ������ʾͼ��
        graphics.DrawImage(&img, x, y, imageWidth, imageHeight);
    }
    //-------------------------------------------

    //---- ���ư�ť�ı�

    // ������ѡ���Զ�������
    CFont font;
    font.CreatePointFont(120, _T("Arial")); // ���� 120 ��� Arial ����
    CFont* pOldFont = memDC.SelectObject(&font);

    // ���ñ���͸��
    memDC.SetBkMode(TRANSPARENT);

    CString text = Words.IsEmpty() ? _T("") : Words;
    memDC.SetBkMode(TRANSPARENT); // ���ñ���͸��
    memDC.DrawText(text, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    //-----------------

    // �����ƺõ�ͼ���Ƶ���Ļ��
    pdc->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

    // ������Դ
    memDC.SelectObject(pOldBitmap);
    memBitmap.DeleteObject();
    memDC.DeleteDC();

    // �ͷ� CDC ����
    pdc->Detach();

}
