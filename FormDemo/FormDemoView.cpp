
// FormDemoView.cpp: реализация класса CFormDemoView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "FormDemo.h"
#endif

#include "FormDemoDoc.h"
#include "FormDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFormDemoView

IMPLEMENT_DYNCREATE(CFormDemoView, CFormView)

BEGIN_MESSAGE_MAP(CFormDemoView, CFormView)
	ON_COMMAND(ID_OPTIONS_LIGHT, &CFormDemoView::OnOptionsLight)
	ON_UPDATE_COMMAND_UI(ID_OPTIONS_LIGHT, &CFormDemoView::OnUpdateOptionsLight)
	ON_COMMAND(ID_OPTIONS_DARK, &CFormDemoView::OnOptionsDark)
	ON_UPDATE_COMMAND_UI(ID_OPTIONS_DARK, &CFormDemoView::OnUpdateOptionsDark)
	ON_BN_CLICKED(IDC_RED, &CFormDemoView::OnClickedRed)
	ON_BN_CLICKED(IDC_GREEN, &CFormDemoView::OnClickedGreen)
	ON_BN_CLICKED(IDC_BLUE, &CFormDemoView::OnClickedBlue)
END_MESSAGE_MAP()

// Создание или уничтожение CFormDemoView

CFormDemoView::CFormDemoView() noexcept
	: CFormView(IDD_FORMDEMO_FORM)
	, m_Blue(FALSE)
	, m_Green(FALSE)
	, m_Red(FALSE)

{
	// TODO: добавьте код создания
	m_Intensity = INT_LIGHT;
}

CFormDemoView::~CFormDemoView()
{
}

void CFormDemoView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_BLUE, m_Blue);
	DDX_Check(pDX, IDC_GREEN, m_Green);
	DDX_Check(pDX, IDC_RED, m_Red);

}

BOOL CFormDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CFormDemoView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	GetDlgItem(IDC_SAMPLE)->GetWindowRect(&m_RectSample);
	ScreenToClient(&m_RectSample);
	int Border = (m_RectSample.right - m_RectSample.left) / 8;
	m_RectSample.InflateRect(-Border, -Border);

}


// Диагностика CFormDemoView

#ifdef _DEBUG
void CFormDemoView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFormDemoView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFormDemoDoc* CFormDemoView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFormDemoDoc)));
	return (CFormDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CFormDemoView


void CFormDemoView::OnOptionsLight()
{
	// TODO: добавьте свой код обработчика команд
	m_Intensity = INT_LIGHT;
	CClientDC ClientDC(this);
	OnPrepareDC(&ClientDC);
	CRect Rect = m_RectSample;
	ClientDC.LPtoDP(&Rect);
	InvalidateRect(&Rect);
	UpdateWindow();

}


void CFormDemoView::OnUpdateOptionsLight(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
	pCmdUI->SetRadio(m_Intensity == INT_LIGHT);
}


void CFormDemoView::OnOptionsDark()
{
	// TODO: добавьте свой код обработчика команд
	m_Intensity = INT_DARK;
	CClientDC ClientDC(this);
	OnPrepareDC(&ClientDC);
	CRect Rect = m_RectSample;
	ClientDC.LPtoDP(&Rect);
	InvalidateRect(&Rect);
	UpdateWindow();
}


void CFormDemoView::OnUpdateOptionsDark(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
	pCmdUI->SetRadio(m_Intensity == INT_DARK);
}


void CFormDemoView::OnClickedRed()
{
	// TODO: добавьте свой код обработчика уведомлений
	m_Red = IsDlgButtonChecked(IDC_RED);
	CClientDC ClientDC(this);
	OnPrepareDC(&ClientDC);
	CRect Rect = m_RectSample;
	ClientDC.LPtoDP(&Rect);
	InvalidateRect(&Rect);
	UpdateWindow();

}


void CFormDemoView::OnClickedGreen()
{
	// TODO: добавьте свой код обработчика уведомлений
	m_Green = IsDlgButtonChecked(IDC_GREEN);
	CClientDC ClientDC(this);
	OnPrepareDC(&ClientDC);
	CRect Rect = m_RectSample;
	ClientDC.LPtoDP(&Rect);
	InvalidateRect(&Rect);
	UpdateWindow();

}


void CFormDemoView::OnClickedBlue()
{
	// TODO: добавьте свой код обработчика уведомлений
	m_Blue = IsDlgButtonChecked(IDC_BLUE);
	CClientDC ClientDC(this);
	OnPrepareDC(&ClientDC);
	CRect Rect = m_RectSample;
	ClientDC.LPtoDP(&Rect);
	InvalidateRect(&Rect);
	UpdateWindow();

}


void CFormDemoView::OnDraw(CDC* pDC)
{
	// TODO: добавьте специализированный код или вызов базового класса
	COLORREF Color = RGB
	(m_Red ? (m_Intensity == INT_DARK ? 128 : 255) : 0,
		m_Green ? (m_Intensity == INT_DARK ? 128 : 255) : 0,
		m_Blue ? (m_Intensity == INT_DARK ? 128 : 255) : 0);
	CBrush Brush(Color);
	pDC->FillRect(&m_RectSample, &Brush);

}
