// CVideoStreamDialog.cpp : implementation file
//

#include "pch.h"
#include "VideoStreaming Application.h"
#include "afxdialogex.h"
#include "CVideoStreamDialog.h"

#include <opencv2\opencv.hpp>
#include <opencv2\imgcodecs.hpp>

using namespace cv;


// CVideoStreamDialog dialog

IMPLEMENT_DYNAMIC(CVideoStreamDialog, CDialog)

CVideoStreamDialog::CVideoStreamDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CVideoStreamDialog, pParent)
{

}

CVideoStreamDialog::~CVideoStreamDialog()
{
}

void CVideoStreamDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CVideoStreamDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CVideoStreamDialog::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CVideoStreamDialog::OnBnClickedButton2)
    ON_BN_CLICKED(IDOK, &CVideoStreamDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CVideoStreamDialog message handlers


void CVideoStreamDialog::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

    Mat img;
    VideoCapture cam(0);
    namedWindow("camera");
    while (1) {
        cam >> img;
        imshow("camera", img);
        if (waitKey(1) == 27)
            break;
    }

    cam.release();
}


void CVideoStreamDialog::OnBnClickedButton2()

{
    
    

    // TODO: Add your control notification handler code here
}


void CVideoStreamDialog::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialog::OnOK();
}
