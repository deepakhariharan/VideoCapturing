
// VideoStreaming ApplicationView.h : interface of the CVideoStreamingApplicationView class
//

#pragma once


class CVideoStreamingApplicationView : public CView
{
protected: // create from serialization only
	CVideoStreamingApplicationView() noexcept;
	DECLARE_DYNCREATE(CVideoStreamingApplicationView)

// Attributes
public:
	CVideoStreamingApplicationDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CVideoStreamingApplicationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileNew();
};

#ifndef _DEBUG  // debug version in VideoStreaming ApplicationView.cpp
inline CVideoStreamingApplicationDoc* CVideoStreamingApplicationView::GetDocument() const
   { return reinterpret_cast<CVideoStreamingApplicationDoc*>(m_pDocument); }
#endif

