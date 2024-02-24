#pragma once


// WinREGIST 对话框

class WinREGIST : public CDialogEx
{
	DECLARE_DYNAMIC(WinREGIST)

public:
	WinREGIST(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~WinREGIST();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DGATTENDANCEAPPLICATION1_REGIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
