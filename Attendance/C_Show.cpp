// C_Show.cpp: 实现文件
//

#include "pch.h"
#include "Attendance.h"
#include "C_Show.h"
#include "afxdialogex.h"
#include "C_Information.h"


// C_Show 对话框

IMPLEMENT_DYNAMIC(C_Show, CDialogEx)

C_Show::C_Show(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Show, pParent)
{

}

C_Show::~C_Show()
{
}

void C_Show::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_Abs, CtrAbsence);
	DDX_Control(pDX, IDC_BUTTON_Att, CtrAttendance);
	DDX_Control(pDX, IDC_BUTTON_Self, CtrSelf);
}


BEGIN_MESSAGE_MAP(C_Show, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_Self, &C_Show::OnBnClickedButtonSelf)
	ON_BN_CLICKED(IDC_BUTTON_Abs, &C_Show::OnBnClickedButtonAbs)
END_MESSAGE_MAP()


// C_Show 消息处理程序


void C_Show::OnBnClickedButtonSelf()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	C_Information inf;
	inf.DoModal();
}


void C_Show::OnBnClickedButtonAbs()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	C_
}
