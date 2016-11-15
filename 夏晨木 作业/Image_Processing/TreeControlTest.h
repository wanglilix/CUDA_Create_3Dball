#pragma once
#include "afxcmn.h"


// TreeControlTest 对话框

class TreeControlTest : public CDialogEx
{
	DECLARE_DYNAMIC(TreeControlTest)

public:
	TreeControlTest(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TreeControlTest();

// 对话框数据
	enum { IDD = IDD_TreeControl };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMFCShellTreeCtrl m_wbdShellTree;
	CMFCShellListCtrl m_wndShellList;
	virtual BOOL OnInitDialog();
	
};
