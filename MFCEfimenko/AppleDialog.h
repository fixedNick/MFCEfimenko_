#pragma once


// AppleDialog dialog

class AppleDialog : public CDialogEx
{
	DECLARE_DYNAMIC(AppleDialog)

public:
	AppleDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AppleDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OLE_PROPPAGE_LARGE1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
