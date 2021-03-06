
// PictureShowView.cpp: CPictureShowView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "PictureShow.h"
#endif

#include "PictureShowDoc.h"
#include "PictureShowView.h"
#include"cp_sword.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define pi 3.1415926


// CPictureShowView

IMPLEMENT_DYNCREATE(CPictureShowView, CView)

BEGIN_MESSAGE_MAP(CPictureShowView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPictureShowView 构造/析构

CPictureShowView::CPictureShowView()
{
	// TODO: 在此处添加构造代码

}

CPictureShowView::~CPictureShowView()
{
}

BOOL CPictureShowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPictureShowView 绘图

void CPictureShowView::OnDraw(CDC* pDC)
{
	CPictureShowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	cp_shield* shield = NULL;
	shield = new cp_shield();
	if (shield == NULL) return;
	else
	{
		shield->set(230, 30, 300, 100, 39, 100, 180);
		shield->draw(pDC);
	}
	delete(shield);
	cp_sword* sword = NULL;
	
	sword=new cp_sword();
	if (sword == NULL) return;
	else
	{
		sword->set(200, 200, pi/4, 20);
		sword->draw(pDC);
	}
	delete(sword);
	
	sword = new cp_sword();
	if (sword == NULL) return;
	else
	{
		sword->set(340, 188, pi*3/4, 20);
		sword->draw(pDC);
	}
	delete(sword);
	
	
	// TODO: 在此处为本机数据添加绘制代码
	
}


// CPictureShowView 打印

BOOL CPictureShowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPictureShowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPictureShowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CPictureShowView 诊断

#ifdef _DEBUG
void CPictureShowView::AssertValid() const
{
	CView::AssertValid();
}

void CPictureShowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPictureShowDoc* CPictureShowView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPictureShowDoc)));
	return (CPictureShowDoc*)m_pDocument;
}
#endif //_DEBUG


// CPictureShowView 消息处理程序
