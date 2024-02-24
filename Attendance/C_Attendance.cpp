// C_Attendance.cpp: 实现文件
//

#include "pch.h"
#include "DGattendanceApplication1.h"
#include "C_Attendance.h"
#include "afxdialogex.h"


// C_Attendance 对话框

IMPLEMENT_DYNAMIC(C_Attendance, CDialogEx)

C_Attendance::C_Attendance(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ATTENDANCE, pParent)
{

}

C_Attendance::~C_Attendance()
{
}

void C_Attendance::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(C_Attendance, CDialogEx)
END_MESSAGE_MAP()


// C_Attendance 消息处理程序
