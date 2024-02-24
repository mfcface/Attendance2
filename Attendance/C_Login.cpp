// C_Login.cpp: 实现文件
//

#include "pch.h"
#include "Attendance.h"
#include "C_Login.h"
#include "afxdialogex.h"
#include "C_Show.h"
#include "C_Regist.h"


// C_Login 对话框

IMPLEMENT_DYNAMIC(C_Login, CDialogEx)

C_Login::C_Login(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Login, pParent)
{

}

C_Login::~C_Login()
{
}

void C_Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(C_Login, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_Login, &C_Login::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_Regist, &C_Login::OnBnClickedButtonRegist)
END_MESSAGE_MAP()


// C_Login 消息处理程序


void C_Login::OnBnClickedButtonLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	C_Show show;
	show.DoModal();
}


void C_Login::OnBnClickedButtonRegist()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	C_Regist regist;
	regist.DoModal();
}
