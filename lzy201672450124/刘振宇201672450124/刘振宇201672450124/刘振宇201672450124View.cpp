
// ������201672450124View.cpp : C������201672450124View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������201672450124.h"
#endif

#include "������201672450124Doc.h"
#include "������201672450124View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������201672450124View

IMPLEMENT_DYNCREATE(C������201672450124View, CView)

BEGIN_MESSAGE_MAP(C������201672450124View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(create, &C������201672450124View::OnCreate)
END_MESSAGE_MAP()

// C������201672450124View ����/����

C������201672450124View::C������201672450124View()
{
	// TODO: �ڴ˴���ӹ������

}

C������201672450124View::~C������201672450124View()
{
}

BOOL C������201672450124View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������201672450124View ����

void C������201672450124View::OnDraw(CDC* /*pDC*/)
{
	C������201672450124Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C������201672450124View ��ӡ

BOOL C������201672450124View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������201672450124View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������201672450124View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C������201672450124View ���

#ifdef _DEBUG
void C������201672450124View::AssertValid() const
{
	CView::AssertValid();
}

void C������201672450124View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������201672450124Doc* C������201672450124View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������201672450124Doc)));
	return (C������201672450124Doc*)m_pDocument;
}
#endif //_DEBUG


// C������201672450124View ��Ϣ�������

//�ڲ�����
#define T 20
float BEN[4][4] = { -1,3,-3,1,3,-6,3,0,-3,3,0,0,1,0,0,0 };
float point[4][3] = { 100,100,1,200,300,1,400,300,1,300,100,1 };
void bezier(CDC * pDC, int n, int t, float p[4][3]);
void matx44(float a[4][4], float b[4][3], float c[4][3]);
void matx14(float a[4], float b[4][3], float c[3]);
/*
*����bezier����
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
// C������201672450124View ��Ϣ�������


void C������201672450124View::OnCreate()
{
	// TODO: �ڴ���������������
	CDC * pDC = GetDC();
	pDC->TextOutW(30, 20, _T("��ʼ�������� Bezier ����"));
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
