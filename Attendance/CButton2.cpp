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

	// TODO:  添加您的代码以绘制指定项
	CDC* pdc = CDC::FromHandle(lpDrawItemStruct->hDC);
	CRect rect = lpDrawItemStruct->rcItem;


	Graphics graphics(pdc->GetSafeHdc());


	// 绘制按钮背景
	if (BackGround == nullptr)
	{
		SolidBrush backgroundBrush(Color(0, 0, 0, 0));  // 透明颜色
		graphics.FillRectangle(&backgroundBrush, rect.left, rect.top, rect.Width(), rect.Height());

	}
	else
	{
		Image backgroundImage(BackGround);  // 背景图片路径

		float imageWidth = static_cast<float>(backgroundImage.GetWidth());
		float imageHeight = static_cast<float>(backgroundImage.GetHeight());

		// 缩放背景图片以适应按钮区域
		RectF destRect((REAL)rect.left, (REAL)rect.top, (REAL)rect.Width(), (REAL)rect.Height());
		graphics.DrawImage(&backgroundImage, destRect, 0, 0, imageWidth, imageHeight, UnitPixel);
	}
	
	// 加载图像
	Image img(imgPath);

	int imageWidth = img.GetWidth();
	int imageHeight = img.GetHeight();
	int x = rect.left;
	int y = rect.top;
	graphics.DrawImage(&img, x, y, imageWidth, imageHeight);
	
	pdc->Detach();
}
