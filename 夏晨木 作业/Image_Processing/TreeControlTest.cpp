// TreeControlTest.cpp : 实现文件
//

#include "stdafx.h"
#include "Image_Processing.h"
#include "TreeControlTest.h"
#include "afxdialogex.h"


// TreeControlTest 对话框

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


// TreeControlTest 消息处理程序


BOOL TreeControlTest::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_wbdShellTree.Expand(m_wbdShellTree.GetRootItem(),TVE_EXPAND);
	m_wbdShellTree.SetRelatedList(&m_wndShellList);

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
