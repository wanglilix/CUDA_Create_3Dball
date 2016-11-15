// TreeControl.cpp : 实现文件
//

#include "stdafx.h"
#include "Image_Processing.h"
#include "TreeControl.h"
#include "afxdialogex.h"


// TreeControl 对话框

IMPLEMENT_DYNAMIC(TreeControl, CDialogEx)

TreeControl::TreeControl(CWnd* pParent /*=NULL*/)
	: CDialogEx(TreeControl::IDD, pParent)
{

}

TreeControl::~TreeControl()
{
}

void TreeControl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_TREE1, CTreeCtrl);
	DDX_Control(pDX, IDC_WEB_TREE, m_webTree);
}


BEGIN_MESSAGE_MAP(TreeControl, CDialogEx)
	ON_NOTIFY(TVN_SELCHANGED, IDC_WEB_TREE, &TreeControl::OnTvnSelchangedWebTree)
END_MESSAGE_MAP()


// TreeControl 消息处理程序


BOOL TreeControl::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	HICON hIcon[3];
	HTREEITEM hRoot;
	HTREEITEM hCataItem;
	HTREEITEM hArtItem;
	hIcon[0] = theApp.LoadIconA(IDI_WEB_ICON);
	hIcon[1] = theApp.LoadIconA(IDI_CATALOG_ICON);
	hIcon[2] = theApp.LoadIconA(IDI_ARTICLE_ICON);

	m_imageList.Create(32,32,ILC_COLOR32,3,3);

	for(int i=0;i<3;i++)
	{
		m_imageList.Add(hIcon[i]);
	}
		m_webTree.SetImageList(&m_imageList,TVSIL_NORMAL);//设置图标

		hRoot = m_webTree.InsertItem(_T("鸡啄米"),0,0);  //添加根节点
		hCataItem = m_webTree.InsertItem(_T("IT互联网"),1,1,hRoot,TVI_LAST);//添加新节点
		m_webTree.SetItemData(hCataItem,1);
		hArtItem = m_webTree.InsertItem(_T("百度文字"),2,2,hCataItem,TVI_LAST);//添加新节点
		m_webTree.SetItemData(hArtItem,2);
		hArtItem = m_webTree.InsertItem(_T("谷歌文字"),2,2,hCataItem,TVI_LAST);  //添加新节点
		m_webTree.SetItemData(hArtItem,3);//附加信息 ：编号




	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void TreeControl::OnTvnSelchangedWebTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	CString strText;

	//HTREEITEM hItem = m_webTree.GetSelectedItem();//获取当前选择节点的句柄
	strText = m_webTree.GetItemText(m_webTree.GetSelectedItem());//获取选择的节点的标签文本字符串
	SetDlgItemText(IDC_ITEM_SEL_EDIT,strText);


	*pResult = 0;
}
