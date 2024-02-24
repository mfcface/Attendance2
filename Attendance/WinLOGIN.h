#pragma once


// WinLOGIN 对话框

class WinLOGIN : public CDialogEx
{
	DECLARE_DYNAMIC(WinLOGIN)

public:
	WinLOGIN(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~WinLOGIN();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DGATTENDANCEAPPLICATION1_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAbs();
	afx_msg void OnBnClickedButton();
	afx_msg void OnBnClickedButtonAtt();
	afx_msg void OnBnClickedButtoninf();
};
