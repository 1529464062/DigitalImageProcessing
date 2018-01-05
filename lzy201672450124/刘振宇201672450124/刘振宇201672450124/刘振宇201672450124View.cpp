
// 刘振宇201672450124View.cpp : C刘振宇201672450124View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "刘振宇201672450124.h"
#endif

#include "刘振宇201672450124Doc.h"
#include "刘振宇201672450124View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C刘振宇201672450124View

IMPLEMENT_DYNCREATE(C刘振宇201672450124View, CView)

BEGIN_MESSAGE_MAP(C刘振宇201672450124View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(create, &C刘振宇201672450124View::OnCreate)
END_MESSAGE_MAP()

// C刘振宇201672450124View 构造/析构

C刘振宇201672450124View::C刘振宇201672450124View()
{
	// TODO: 在此处添加构造代码

}

C刘振宇201672450124View::~C刘振宇201672450124View()
{
}

BOOL C刘振宇201672450124View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C刘振宇201672450124View 绘制

void C刘振宇201672450124View::OnDraw(CDC* /*pDC*/)
{
	C刘振宇201672450124Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C刘振宇201672450124View 打印

BOOL C刘振宇201672450124View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C刘振宇201672450124View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C刘振宇201672450124View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C刘振宇201672450124View 诊断

#ifdef _DEBUG
void C刘振宇201672450124View::AssertValid() const
{
	CView::AssertValid();
}

void C刘振宇201672450124View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C刘振宇201672450124Doc* C刘振宇201672450124View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C刘振宇201672450124Doc)));
	return (C刘振宇201672450124Doc*)m_pDocument;
}
#endif //_DEBUG


// C刘振宇201672450124View 消息处理程序

//内部方法
#define T 20
float BEN[4][4] = { -1,3,-3,1,3,-6,3,0,-3,3,0,0,1,0,0,0 };
float point[4][3] = { 100,100,1,200,300,1,400,300,1,300,100,1 };
void bezier(CDC * pDC, int n, int t, float p[4][3]);
void matx44(float a[4][4], float b[4][3], float c[4][3]);
void matx14(float a[4], float b[4][3], float c[3]);
/*
*绘制bezier曲线
**/
void bezier(CDC * pDC, int n, int t, float p[4][3])
{
	float cc[4][3];
	float pp[3];
	int i, xx, yy, a, b;
	float u[4];
	u[3] = 1.0;
	a = p[0][0];
	b = p[0][1];
	for (i = 2; i < T; i++)
	{
		u[2] = (1.0 / T)*i;
		u[1] = u[2] * u[2];
		u[0] = u[2] * u[2] * u[2];
		matx44(BEN, p, cc);
		matx14(u, cc, pp);
		xx = pp[0];
		yy = pp[1];
		pDC->MoveTo(a, b);
		pDC->LineTo(xx, yy);
		a = xx;
		b = yy;
	}
}
void matx44(float a[4][4], float b[4][3], float c[4][3])
{
	int i, j, m;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			c[i][j] = 0.0;
		}
	}
	for (m = 0; m < 4; m++)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 4; j++)
			{
				c[m][j] += a[m][j] * b[j][i];
			}
		}
	}
}
void matx14(float a[4], float b[4][3], float c[3])
{
	int i, j;
	c[0] = c[1] = c[2] = 0.0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			c[i] += a[j] * b[j][i];

		}
	}
}
// C刘振宇201672450124View 消息处理程序


void C刘振宇201672450124View::OnCreate()
{
	// TODO: 在此添加命令处理程序代码
	CDC * pDC = GetDC();
	pDC->TextOutW(30, 20, _T("开始绘制三次 Bezier 曲线"));
	float xx, yy;
	for (int i = 0; i < 4; i++)
	{
		xx = point[i][0];
		yy = point[i][1];
		pDC->MoveTo(xx - 3, yy - 3);
		pDC->LineTo(xx + 3, yy + 3);
		pDC->MoveTo(xx - 3, yy + 3);
		pDC->LineTo(xx + 3, yy - 3);
	}
	bezier(pDC, 4, T, point);
	ReleaseDC(pDC);
}
