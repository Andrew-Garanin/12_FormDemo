
// FormDemoView.h: интерфейс класса CFormDemoView
//

#pragma once


class CFormDemoView : public CFormView
{
public:
	CBrush m_DialogBrush;
	int m_Intensity;
	CRect m_RectSample;

	enum { INT_DARK, INT_LIGHT };

public:
	BOOL m_Blue;
	BOOL m_Green;
	BOOL m_Red;
protected: // создать только из сериализации
	CFormDemoView() noexcept;
	DECLARE_DYNCREATE(CFormDemoView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_FORMDEMO_FORM };
#endif

// Атрибуты
public:
	CFormDemoDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CFormDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOptionsLight();
	afx_msg void OnUpdateOptionsLight(CCmdUI* pCmdUI);
	afx_msg void OnOptionsDark();
	afx_msg void OnUpdateOptionsDark(CCmdUI* pCmdUI);
	afx_msg void OnClickedRed();
	afx_msg void OnClickedGreen();
	afx_msg void OnClickedBlue();
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // версия отладки в FormDemoView.cpp
inline CFormDemoDoc* CFormDemoView::GetDocument() const
   { return reinterpret_cast<CFormDemoDoc*>(m_pDocument); }
#endif

