
// ������201672450124View.h : C������201672450124View ��Ľӿ�
//

#pragma once


class C������201672450124View : public CView
{
protected: // �������л�����
	C������201672450124View();
	DECLARE_DYNCREATE(C������201672450124View)

// ����
public:
	C������201672450124Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C������201672450124View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCreate();
};

#ifndef _DEBUG  // ������201672450124View.cpp �еĵ��԰汾
inline C������201672450124Doc* C������201672450124View::GetDocument() const
   { return reinterpret_cast<C������201672450124Doc*>(m_pDocument); }
#endif

