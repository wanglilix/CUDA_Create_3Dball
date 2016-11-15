// MyView.cpp : 实现文件
//

#include "stdafx.h"
#include "Image_Processing.h"
#include "MyView.h"


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

CMyView::CMyView()
{

}

CMyView::~CMyView()
{
}

BEGIN_MESSAGE_MAP(CMyView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CMyView 绘图

void CMyView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	CRect rt(0,50,1200,200);
	pDC->DrawText("动态创建并添加的View类，注意在基于对话框的程序时与基于单文档程序的区别.\n\n 在基于对话框的程序中可以直接将视图添加到对话框中 \n\n在单文档程序时：需要先手动将框架添加到弹出对话框中，再将视图添加到框架中",&rt,DT_CENTER);
	// TODO: 在此添加绘制代码
}


// CMyView 诊断

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyView 消息处理程序


void CMyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
}
