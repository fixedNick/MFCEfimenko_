// FruitDialog.cpp : implementation file
//

#include "pch.h"
#include "MFCEfimenko.h"
#include "FruitDialog.h"
#include "afxdialogex.h"


// FruitDialog dialog

IMPLEMENT_DYNAMIC(FruitDialog, CDialogEx)

FruitDialog::FruitDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(FRUIT_DIALOG, pParent)
{

}

FruitDialog::~FruitDialog()
{
}

void FruitDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FruitDialog, CDialogEx)
END_MESSAGE_MAP()


// FruitDialog message handlers
