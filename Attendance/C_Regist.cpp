// C_Regist.cpp: 实现文件
//

#include "pch.h"
#include "Attendance.h"
#include "C_Regist.h"
#include "afxdialogex.h"


// C_Regist 对话框

IMPLEMENT_DYNAMIC(C_Regist, CDialogEx)

C_Regist::C_Regist(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Regist, pParent)
{

}

C_Regist::~C_Regist()
{
}

void C_Regist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(C_Regist, CDialogEx)
END_MESSAGE_MAP()


// C_Regist 消息处理程序
