#pragma once
#include "afxdialogex.h"


// CVideoStreamDialog dialog

class CVideoStreamDialog : public CDialog
{
	DECLARE_DYNAMIC(CVideoStreamDialog)

public:
	CVideoStreamDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CVideoStreamDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CVideoStreamDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
};
