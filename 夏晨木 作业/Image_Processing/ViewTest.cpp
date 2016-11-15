// ViewTest.cpp : 实现文件
//

#include "stdafx.h"
#include "Image_Processing.h"
#include "ViewTest.h"
#include "afxdialogex.h"


// ViewTest 对话框

IMPLEMENT_DYNAMIC(ViewTest, CDialogEx)

ViewTest::ViewTest(CWnd* pParent /*=NULL*/)
	: CDialogEx(ViewTest::IDD, pParent)
{

}

ViewTest::~ViewTest()
{
}

void ViewTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ViewTest, CDialogEx)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// ViewTest 消息处理程序


int ViewTest::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CRect   rectWndClient;
	GetClientRect(&rectWndClient);//客户区位置

// 	CFrameWnd *pFrame = new CFrameWnd();
// 	pFrame->Create(NULL,NULL,WS_VISIBLE|WS_CHILD,rectWndClient,this);//先创建框架
// 	
	////动态添加View
	CRuntimeClass*   pViewClass   =   RUNTIME_CLASS(CMyView);       //由于CView及其派生类的构造函数是保护成员，所以采用RuntimeClass方式来构造对象
	m_pMyView = (CMyView *)pViewClass-> CreateObject();             //产生View类对象  
	m_pMyView->Create(NULL,NULL,WS_BORDER|WS_CHILD,rectWndClient,this,  //Create函数参数必须有WS_CHILD，表明视图是一个子窗口           
		123);                                                //指定其尺寸为rectsolid，父窗口为(this)DLG，ID为任意整数；
	m_pMyView->OnInitialUpdate();
	return 0;
}


void ViewTest::PreInitDialog()
{
	// TODO: 在此添加专用代码和/或调用基类
	m_pMyView->ShowWindow(SW_SHOW); 

	CDialogEx::PreInitDialog();
}


void ViewTest::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
}
