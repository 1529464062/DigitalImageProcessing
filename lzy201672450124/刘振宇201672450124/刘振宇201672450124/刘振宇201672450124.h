
// 刘振宇201672450124.h : 刘振宇201672450124 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C刘振宇201672450124App:
// 有关此类的实现，请参阅 刘振宇201672450124.cpp
//

class C刘振宇201672450124App : public CWinAppEx
{
public:
	C刘振宇201672450124App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C刘振宇201672450124App theApp;
