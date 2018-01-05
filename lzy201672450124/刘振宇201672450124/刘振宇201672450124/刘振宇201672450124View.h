
// 刘振宇201672450124View.h : C刘振宇201672450124View 类的接口
//

#pragma once


class C刘振宇201672450124View : public CView
{
protected: // 仅从序列化创建
	C刘振宇201672450124View();
	DECLARE_DYNCREATE(C刘振宇201672450124View)

// 特性
public:
	C刘振宇201672450124Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C刘振宇201672450124View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCreate();
};

#ifndef _DEBUG  // 刘振宇201672450124View.cpp 中的调试版本
inline C刘振宇201672450124Doc* C刘振宇201672450124View::GetDocument() const
   { return reinterpret_cast<C刘振宇201672450124Doc*>(m_pDocument); }
#endif

