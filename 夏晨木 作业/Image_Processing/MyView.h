#pragma once


// CMyView ��ͼ

class CMyView : public CView
{
	DECLARE_DYNCREATE(CMyView)

protected:
	CMyView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyView();

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


