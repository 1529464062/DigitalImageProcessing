
// ������201672450124.h : ������201672450124 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C������201672450124App:
// �йش����ʵ�֣������ ������201672450124.cpp
//

class C������201672450124App : public CWinAppEx
{
public:
	C������201672450124App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C������201672450124App theApp;
