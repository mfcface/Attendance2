#include "pch.h"
#include "CButton2.h"

void CButton2::setButton(WCHAR* imgpath, CString words, WCHAR* bk)
{
	imgPath = imgpath;
	Words = words;
	BackGround = bk;
}

void CButton2::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{

	// TODO:  ������Ĵ����Ի���ָ����
	CDC* pdc = CDC::FromHandle(lpDrawItemStruct->hDC);
	CRect rect = lpDrawItemStruct->rcItem;


	Graphics graphics(pdc->GetSafeHdc());


	// ���ư�ť����
	if (BackGround == nullptr)
	{
		SolidBrush backgroundBrush(Color(0, 0, 0, 0));  // ͸����ɫ
		graphics.FillRectangle(&backgroundBrush, rect.left, rect.top, rect.Width(), rect.Height());

	}
	else
	{
		Image backgroundImage(BackGround);  // ����ͼƬ·��

		float imageWidth = static_cast<float>(backgroundImage.GetWidth());
		float imageHeight = static_cast<float>(backgroundImage.GetHeight());

		// ���ű���ͼƬ����Ӧ��ť����
		RectF destRect((REAL)rect.left, (REAL)rect.top, (REAL)rect.Width(), (REAL)rect.Height());
		graphics.DrawImage(&backgroundImage, destRect, 0, 0, imageWidth, imageHeight, UnitPixel);
	}
	
	// ����ͼ��
	Image img(imgPath);

	int imageWidth = img.GetWidth();
	int imageHeight = img.GetHeight();
	int x = rect.left;
	int y = rect.top;
	graphics.DrawImage(&img, x, y, imageWidth, imageHeight);
	
	pdc->Detach();
}
