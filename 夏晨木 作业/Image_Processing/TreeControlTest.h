#pragma once
#include "afxcmn.h"


// TreeControlTest �Ի���

class TreeControlTest : public CDialogEx
{
	DECLARE_DYNAMIC(TreeControlTest)

public:
	TreeControlTest(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TreeControlTest();

// �Ի�������
	enum { IDD = IDD_TreeControl };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CMFCShellTreeCtrl m_wbdShellTree;
	CMFCShellListCtrl m_wndShellList;
	virtual BOOL OnInitDialog();
	
};
