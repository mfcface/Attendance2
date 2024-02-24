#pragma once


// C_Regist 对话框

class C_Regist : public CDialogEx
{
	DECLARE_DYNAMIC(C_Regist)

public:
	C_Regist(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~C_Regist();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Regist };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
