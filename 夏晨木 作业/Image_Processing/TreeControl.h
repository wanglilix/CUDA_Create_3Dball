#pragma once
#include "afxcmn.h"


// TreeControl �Ի���

class TreeControl : public CDialogEx
{
	DECLARE_DYNAMIC(TreeControl)

public:
	TreeControl(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TreeControl();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//CTreeCtrl CTreeCtrl;
	virtual BOOL OnInitDialog();
	CTreeCtrl m_webTree;
	CImageList m_imageList;
	afx_msg void OnTvnSelchangedWebTree(NMHDR *pNMHDR, LRESULT *pResult);
};
