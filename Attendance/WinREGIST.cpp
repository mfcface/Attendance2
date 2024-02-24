// WinREGIST.cpp: 实现文件
//

#include "pch.h"
#include "DGattendanceApplication1.h"
#include "WinREGIST.h"
#include "afxdialogex.h"


// WinREGIST 对话框

IMPLEMENT_DYNAMIC(WinREGIST, CDialogEx)

WinREGIST::WinREGIST(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DGATTENDANCEAPPLICATION1_REGIST, pParent)
{

}

WinREGIST::~WinREGIST()
{
}

void WinREGIST::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WinREGIST, CDialogEx)
END_MESSAGE_MAP()


// WinREGIST 消息处理程序
