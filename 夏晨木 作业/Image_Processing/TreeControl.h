#pragma once
#include "afxcmn.h"


// TreeControl 对话框

class TreeControl : public CDialogEx
{
	DECLARE_DYNAMIC(TreeControl)

public:
	TreeControl(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TreeControl();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//CTreeCtrl CTreeCtrl;
	virtual BOOL OnInitDialog();
	CTreeCtrl m_webTree;
	CImageList m_imageList;
	afx_msg void OnTvnSelchangedWebTree(NMHDR *pNMHDR, LRESULT *pResult);
};
