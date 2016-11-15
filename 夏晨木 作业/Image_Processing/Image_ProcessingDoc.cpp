
// Image_ProcessingDoc.cpp : CImage_ProcessingDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Image_Processing.h"
#endif

#include "Image_ProcessingDoc.h"
#include <propkey.h>
#include "TreeControl.h"
#include "TreeControlTest.h"
#include "ViewTest.h"
#include "afxmt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CImage_ProcessingDoc

IMPLEMENT_DYNCREATE(CImage_ProcessingDoc, CDocument)

BEGIN_MESSAGE_MAP(CImage_ProcessingDoc, CDocument)
	ON_COMMAND(ID_TreeControl, &CImage_ProcessingDoc::OnTreecontrol)
	ON_COMMAND(ID_DynamicView, &CImage_ProcessingDoc::OnDynamicview)
	ON_COMMAND_RANGE(ID_CommandRang,ID_CommandRang2,OnCommandrang)
	ON_COMMAND(ID_ThreadTest, &CImage_ProcessingDoc::OnThreadtest)
	ON_COMMAND(ID_ThreadTest2, &CImage_ProcessingDoc::OnThreadtest2)
	ON_COMMAND(ID_BeginThread, &CImage_ProcessingDoc::OnBeginthread)
END_MESSAGE_MAP()


// CImage_ProcessingDoc ����/����

CImage_ProcessingDoc::CImage_ProcessingDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CImage_ProcessingDoc::~CImage_ProcessingDoc()
{
}

BOOL CImage_ProcessingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CImage_ProcessingDoc ���л�

void CImage_ProcessingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CImage_ProcessingDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CImage_ProcessingDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CImage_ProcessingDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CImage_ProcessingDoc ���

#ifdef _DEBUG
void CImage_ProcessingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImage_ProcessingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImage_ProcessingDoc ����


void CImage_ProcessingDoc::OnTreecontrol()
{
	TreeControl test;
	test.DoModal();
	TreeControlTest test2;
	test2.DoModal();
	// TODO: �ڴ���������������
}
void CImage_ProcessingDoc::OnDynamicview()
{
	ViewTest dlg;
	dlg.DoModal();
	// TODO: �ڴ���������������
}
void CImage_ProcessingDoc::OnCommandrang(UINT m_nID)
{
	switch (m_nID)
	{
		int a;
	case ID_CommandRang:
		 a = 0;
		break;
	case ID_CommandRang2:
		 a=1;
		break;
	}
	// TODO: �ڴ���������������
}

unsigned int _stdcall ExcuteThreadFun( LPVOID lpParam )
{
	int *pNum = (int*)lpParam;
	MessageBox(NULL,_T("�߳̿�ʼִ�У�"),_T("thread func"),MB_OK);
	auto i=90;

	for(;i>2;--i)
	{
			Sleep(2);//����55u
		
	}
	MessageBox(NULL,_T("�߳�ִ����ϣ�"),_T("thread func"),MB_OK);
	return 0;
}

void CImage_ProcessingDoc::OnThreadtest()
{
	void *pNum = new int (8);//����Ĳ���
	pThread = (CWinThread *)_beginthreadex(0,0,ExcuteThreadFun,this,0,0); 
// 		::AfxBeginThread(ThreadFun,pNum,
// 		THREAD_PRIORITY_NORMAL,0,NULL);//THREAD_PRIORITY_NORMAL�����ȼ�һ��  CREATE_SUSPENDED:����
	SuspendThread(pThread);
}




CCriticalSection g_criSection;//�ٽ�������
char g_charArray[4];
CString szResult;


UINT FunOne (LPVOID pParam)
{
	g_criSection.Lock();
	for(int i = 0;i<4;++i)
		g_charArray[i]='S';
	g_criSection.Unlock();
	return 0;
}
UINT FunTwo (LPVOID pParam)
{
	g_criSection.Lock();
	for(int i = 0;i<4;++i)
		g_charArray[i]='B';
	g_criSection.Unlock();
	return 0;
}
UINT GetResult (LPVOID pParam)
{
	g_criSection.Lock();
	szResult = CString(g_charArray);
	g_criSection.Unlock();
	MessageBox(NULL,szResult,_T("Thread Lock"),MB_OK);
	return 0;
}

void CImage_ProcessingDoc::OnThreadtest2()
{
	AfxBeginThread(FunOne,NULL);
	AfxBeginThread(FunTwo,NULL);
	AfxBeginThread(GetResult,NULL);
}




void CImage_ProcessingDoc::OnBeginthread()
{
	ResumeThread(pThread);	
	// TODO: �ڴ���������������
}
