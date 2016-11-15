// ViewTest.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Image_Processing.h"
#include "ViewTest.h"
#include "afxdialogex.h"


// ViewTest �Ի���

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


// ViewTest ��Ϣ�������


int ViewTest::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CRect   rectWndClient;
	GetClientRect(&rectWndClient);//�ͻ���λ��

// 	CFrameWnd *pFrame = new CFrameWnd();
// 	pFrame->Create(NULL,NULL,WS_VISIBLE|WS_CHILD,rectWndClient,this);//�ȴ������
// 	
	////��̬���View
	CRuntimeClass*   pViewClass   =   RUNTIME_CLASS(CMyView);       //����CView����������Ĺ��캯���Ǳ�����Ա�����Բ���RuntimeClass��ʽ���������
	m_pMyView = (CMyView *)pViewClass-> CreateObject();             //����View�����  
	m_pMyView->Create(NULL,NULL,WS_BORDER|WS_CHILD,rectWndClient,this,  //Create��������������WS_CHILD��������ͼ��һ���Ӵ���           
		123);                                                //ָ����ߴ�Ϊrectsolid��������Ϊ(this)DLG��IDΪ����������
	m_pMyView->OnInitialUpdate();
	return 0;
}


void ViewTest::PreInitDialog()
{
	// TODO: �ڴ����ר�ô����/����û���
	m_pMyView->ShowWindow(SW_SHOW); 

	CDialogEx::PreInitDialog();
}


void ViewTest::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
}
