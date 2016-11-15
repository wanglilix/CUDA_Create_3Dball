// TreeControl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Image_Processing.h"
#include "TreeControl.h"
#include "afxdialogex.h"


// TreeControl �Ի���

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


// TreeControl ��Ϣ�������


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
		m_webTree.SetImageList(&m_imageList,TVSIL_NORMAL);//����ͼ��

		hRoot = m_webTree.InsertItem(_T("������"),0,0);  //��Ӹ��ڵ�
		hCataItem = m_webTree.InsertItem(_T("IT������"),1,1,hRoot,TVI_LAST);//����½ڵ�
		m_webTree.SetItemData(hCataItem,1);
		hArtItem = m_webTree.InsertItem(_T("�ٶ�����"),2,2,hCataItem,TVI_LAST);//����½ڵ�
		m_webTree.SetItemData(hArtItem,2);
		hArtItem = m_webTree.InsertItem(_T("�ȸ�����"),2,2,hCataItem,TVI_LAST);  //����½ڵ�
		m_webTree.SetItemData(hArtItem,3);//������Ϣ �����




	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void TreeControl::OnTvnSelchangedWebTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	CString strText;

	//HTREEITEM hItem = m_webTree.GetSelectedItem();//��ȡ��ǰѡ��ڵ�ľ��
	strText = m_webTree.GetItemText(m_webTree.GetSelectedItem());//��ȡѡ��Ľڵ�ı�ǩ�ı��ַ���
	SetDlgItemText(IDC_ITEM_SEL_EDIT,strText);


	*pResult = 0;
}
