#pragma once

#include "MyView.h"
// ViewTest �Ի���

class ViewTest : public CDialogEx
{
	DECLARE_DYNAMIC(ViewTest)

public:
	ViewTest(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ViewTest();

// �Ի�������
	enum { IDD = IDD_ViewTest };
	CMyView * m_pMyView;//CMyViewָ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void PreInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
