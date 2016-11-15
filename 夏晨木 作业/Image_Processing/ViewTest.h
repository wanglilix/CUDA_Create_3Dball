#pragma once

#include "MyView.h"
// ViewTest 对话框

class ViewTest : public CDialogEx
{
	DECLARE_DYNAMIC(ViewTest)

public:
	ViewTest(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ViewTest();

// 对话框数据
	enum { IDD = IDD_ViewTest };
	CMyView * m_pMyView;//CMyView指针
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void PreInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
