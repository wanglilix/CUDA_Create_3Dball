// TreeControlTest.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Image_Processing.h"
#include "TreeControlTest.h"
#include "afxdialogex.h"


// TreeControlTest �Ի���

IMPLEMENT_DYNAMIC(TreeControlTest, CDialogEx)

TreeControlTest::TreeControlTest(CWnd* pParent /*=NULL*/)
	: CDialogEx(TreeControlTest::IDD, pParent)
{

}

TreeControlTest::~TreeControlTest()
{
}

void TreeControlTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_wbdShellTree);
	DDX_Control(pDX, IDC_LIST1, m_wndShellList);
}


BEGIN_MESSAGE_MAP(TreeControlTest, CDialogEx)
END_MESSAGE_MAP()


// TreeControlTest ��Ϣ�������


BOOL TreeControlTest::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_wbdShellTree.Expand(m_wbdShellTree.GetRootItem(),TVE_EXPAND);
	m_wbdShellTree.SetRelatedList(&m_wndShellList);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
