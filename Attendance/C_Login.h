#pragma once


// C_Login 对话框

class C_Login : public CDialogEx
{
	DECLARE_DYNAMIC(C_Login)

public:
	C_Login(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~C_Login();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Login };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnBnClickedButtonRegist();
};
