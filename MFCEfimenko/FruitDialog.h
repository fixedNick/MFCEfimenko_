#pragma once


// FruitDialog dialog

class FruitDialog : public CDialogEx
{
	DECLARE_DYNAMIC(FruitDialog)

public:
	FruitDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~FruitDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OLE_PROPPAGE_LARGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
