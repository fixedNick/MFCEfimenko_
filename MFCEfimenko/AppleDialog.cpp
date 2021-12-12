// AppleDialog.cpp : implementation file
//

#include "pch.h"
#include "MFCEfimenko.h"
#include "AppleDialog.h"
#include "afxdialogex.h"


// AppleDialog dialog

IMPLEMENT_DYNAMIC(AppleDialog, CDialogEx)

AppleDialog::AppleDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(APPLE_DIALOG, pParent)
{

}

AppleDialog::~AppleDialog()
{
}

void AppleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AppleDialog, CDialogEx)
END_MESSAGE_MAP()


// AppleDialog message handlers
