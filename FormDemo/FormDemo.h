
// FormDemo.h: основной файл заголовка для приложения FormDemo
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CFormDemoApp:
// Сведения о реализации этого класса: FormDemo.cpp
//

class CFormDemoApp : public CWinApp
{
public:
	CFormDemoApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFormDemoApp theApp;
