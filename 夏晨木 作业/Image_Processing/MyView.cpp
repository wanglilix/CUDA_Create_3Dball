// MyView.cpp : ʵ���ļ�
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


// CMyView ��ͼ

void CMyView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	CRect rt(0,50,1200,200);
	pDC->DrawText("��̬��������ӵ�View�࣬ע���ڻ��ڶԻ���ĳ���ʱ����ڵ��ĵ����������.\n\n �ڻ��ڶԻ���ĳ����п���ֱ�ӽ���ͼ��ӵ��Ի����� \n\n�ڵ��ĵ�����ʱ����Ҫ���ֶ��������ӵ������Ի����У��ٽ���ͼ��ӵ������",&rt,DT_CENTER);
	// TODO: �ڴ���ӻ��ƴ���
}


// CMyView ���

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


// CMyView ��Ϣ�������


void CMyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);
}
