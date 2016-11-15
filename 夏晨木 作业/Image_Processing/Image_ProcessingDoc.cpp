
// Image_ProcessingDoc.cpp : CImage_ProcessingDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CImage_ProcessingDoc 构造/析构

CImage_ProcessingDoc::CImage_ProcessingDoc()
{
	// TODO: 在此添加一次性构造代码

}

CImage_ProcessingDoc::~CImage_ProcessingDoc()
{
}

BOOL CImage_ProcessingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CImage_ProcessingDoc 序列化

void CImage_ProcessingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CImage_ProcessingDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CImage_ProcessingDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CImage_ProcessingDoc 诊断

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


// CImage_ProcessingDoc 命令


void CImage_ProcessingDoc::OnTreecontrol()
{
	TreeControl test;
	test.DoModal();
	TreeControlTest test2;
	test2.DoModal();
	// TODO: 在此添加命令处理程序代码
}
void CImage_ProcessingDoc::OnDynamicview()
{
	ViewTest dlg;
	dlg.DoModal();
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令处理程序代码
}

unsigned int _stdcall ExcuteThreadFun( LPVOID lpParam )
{
	int *pNum = (int*)lpParam;
	MessageBox(NULL,_T("线程开始执行！"),_T("thread func"),MB_OK);
	auto i=90;

	for(;i>2;--i)
	{
			Sleep(2);//休眠55u
		
	}
	MessageBox(NULL,_T("线程执行完毕！"),_T("thread func"),MB_OK);
	return 0;
}

void CImage_ProcessingDoc::OnThreadtest()
{
	void *pNum = new int (8);//传入的参数
	pThread = (CWinThread *)_beginthreadex(0,0,ExcuteThreadFun,this,0,0); 
// 		::AfxBeginThread(ThreadFun,pNum,
// 		THREAD_PRIORITY_NORMAL,0,NULL);//THREAD_PRIORITY_NORMAL：优先级一般  CREATE_SUSPENDED:挂起
	SuspendThread(pThread);
}




CCriticalSection g_criSection;//临界区变量
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
	// TODO: 在此添加命令处理程序代码
}
