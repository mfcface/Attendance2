// WinLOGIN.cpp: 实现文件
//

#include "pch.h"
#include "DGattendanceApplication1.h"
#include "WinLOGIN.h"
#include "afxdialogex.h"
#include "C_Absences.h"
#include "C_Attendance.h"
#include "C_information.h"


// WinLOGIN 对话框

IMPLEMENT_DYNAMIC(WinLOGIN, CDialogEx)

WinLOGIN::WinLOGIN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DGATTENDANCEAPPLICATION1_LOGIN, pParent)
{

}

WinLOGIN::~WinLOGIN()
{
}

void WinLOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WinLOGIN, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ABS, &WinLOGIN::OnBnClickedButtonAbs)
	ON_BN_CLICKED(IDC_BUTTON_ATT, &WinLOGIN::OnBnClickedButtonAtt)
	ON_BN_CLICKED(IDC_BUTTON_inf, &WinLOGIN::OnBnClickedButtoninf)
END_MESSAGE_MAP()


// WinLOGIN 消息处理程序


void WinLOGIN::OnBnClickedButtonAbs()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	C_Absences abs;
	abs.DoModal();
}



void WinLOGIN::OnBnClickedButtonAtt()
{
	CDialogEx::OnOK();
	C_Attendance att;
	att.DoModal();
}


void WinLOGIN::OnBnClickedButtoninf()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	C_information inf;
	inf.DoModal();
}
