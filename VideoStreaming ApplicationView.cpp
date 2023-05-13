
// VideoStreaming ApplicationView.cpp : implementation of the CVideoStreamingApplicationView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "VideoStreaming Application.h"
#endif

#include "VideoStreaming ApplicationDoc.h"
#include "VideoStreaming ApplicationView.h"
#include "CVideoStreamDialog.h"

#include <opencv2\opencv.hpp>
#include <opencv2\imgcodecs.hpp>

using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVideoStreamingApplicationView

IMPLEMENT_DYNCREATE(CVideoStreamingApplicationView, CView)

BEGIN_MESSAGE_MAP(CVideoStreamingApplicationView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CVideoStreamingApplicationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_NEW, &CVideoStreamingApplicationView::OnFileNew)
END_MESSAGE_MAP()

// CVideoStreamingApplicationView construction/destruction

CVideoStreamingApplicationView::CVideoStreamingApplicationView() noexcept
{
	// TODO: add construction code here

}

CVideoStreamingApplicationView::~CVideoStreamingApplicationView()
{
}

BOOL CVideoStreamingApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CVideoStreamingApplicationView drawing

void CVideoStreamingApplicationView::OnDraw(CDC* pDC)
{
	CVideoStreamingApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	

	// TODO: add draw code for native data here
}


// CVideoStreamingApplicationView printing


void CVideoStreamingApplicationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CVideoStreamingApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVideoStreamingApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVideoStreamingApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CVideoStreamingApplicationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CVideoStreamingApplicationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CVideoStreamingApplicationView diagnostics

#ifdef _DEBUG
void CVideoStreamingApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CVideoStreamingApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVideoStreamingApplicationDoc* CVideoStreamingApplicationView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVideoStreamingApplicationDoc)));
	return (CVideoStreamingApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CVideoStreamingApplicationView message handlers


void CVideoStreamingApplicationView::OnFileNew()
{
	// TODO: Add your command handler code here
	CVideoStreamDialog CVdoStrmDlg;
	CVdoStrmDlg.DoModal();
	
	/*Mat img;
	VideoCapture cam(0);
	namedWindow("camera");
	while (1) {
		cam >> img;
		imshow("camera", img);
		if (waitKey(1) == 27)
			break;
	}
	cam.release(); */





}
