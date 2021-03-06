// AddDialog.cpp : implementation file
//

#include "pch.h"
#include "MFCEfimenko.h"
#include "AddDialog.h"
#include "afxdialogex.h"


// AddDialog dialog

IMPLEMENT_DYNAMIC(AddDialog, CDialogEx)

AddDialog::AddDialog(CMFCEfimenkoDoc* pDocIns, int index, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_name(_T(""))
	, m_amount(0)
	, m_price(0)
	, m_color(_T(""))
	, m_seeds(0)
	, m_trees(0)
	, m_ShowType(TRUE)
{
	this->pDoc = pDocIns;
	f_index = index;
}

AddDialog::~AddDialog()
{
}
void AddDialog::SetFruitFields(bool decision)
{
	if (decision)
	{
		//SHOWNORMAL
		e_control_name.ShowWindow(SW_SHOWNORMAL);
		e_control_amount.ShowWindow(SW_SHOWNORMAL);
		e_control_price.ShowWindow(SW_SHOWNORMAL);
		//GetDlgItem(IDC_STATIC)->ShowWindow(SW_SHOWNORMAL);

	}
	else
	{
		//SW_HIDE
		e_control_name.ShowWindow(SW_HIDE);
		e_control_amount.ShowWindow(SW_HIDE);
		e_control_price.ShowWindow(SW_HIDE);
		//GetDlgItem(IDC_STATIC)->ShowWindow(SW_HIDE);

	}
}


void AddDialog::SetAppleFields(bool decision)
{
	if (decision)
	{    //SW_SHOWNORMAL
		e_control_name.ShowWindow(SW_SHOWNORMAL);
		e_control_amount.ShowWindow(SW_SHOWNORMAL);
		e_control_price.ShowWindow(SW_SHOWNORMAL);
		e_control_color.ShowWindow(SW_SHOWNORMAL);
		e_control_seeds.ShowWindow(SW_SHOWNORMAL);
		e_control_trees.ShowWindow(SW_SHOWNORMAL);
		GetDlgItem(IDC_STATIC_COLOR)->ShowWindow(SW_SHOWNORMAL);
		GetDlgItem(IDC_STATIC_SEEDS)->ShowWindow(SW_SHOWNORMAL);
		GetDlgItem(IDC_STATIC_TREES)->ShowWindow(SW_SHOWNORMAL);
		//GetDlgItem(IDC_STATIC5)->EnableWindow();

	}
	else
	{
		//SW_HIDE
		GetDlgItem(IDC_STATIC_COLOR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_SEEDS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_TREES)->ShowWindow(SW_HIDE);
		e_control_name.ShowWindow(SW_HIDE);
		e_control_amount.ShowWindow(SW_HIDE);
		e_control_price.ShowWindow(SW_HIDE);
		e_control_color.ShowWindow(SW_HIDE);
		e_control_seeds.ShowWindow(SW_HIDE);
		e_control_trees.ShowWindow(SW_HIDE);
		//GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
	}
}

void AddDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT2_AMOUNT, m_amount);
	DDX_Text(pDX, IDC_EDIT2_PRICE, m_price);
	DDX_Text(pDX, IDC_EDIT2_COLOR, m_color);
	DDX_Text(pDX, IDC_EDIT2_SEEDS, m_seeds);
	DDX_Text(pDX, IDC_EDIT2_TREES, m_trees);
	DDX_Control(pDX, IDC_EDIT2_NAME, e_control_name);
	DDX_Control(pDX, IDC_EDIT2_AMOUNT, e_control_amount);
	DDX_Control(pDX, IDC_EDIT2_PRICE, e_control_price);
	DDX_Control(pDX, IDC_EDIT2_COLOR, e_control_color);
	DDX_Control(pDX, IDC_EDIT2_SEEDS, e_control_seeds);
	DDX_Control(pDX, IDC_EDIT2_TREES, e_control_trees);
	DDX_Radio(pDX, IDC_RADIO_FRUIT, m_ShowType);
	DDX_Control(pDX, IDC_TAB1, TabManager);
	DDX_Control(pDX, IDC_RADIO_APPLE, m_appleRadio);
}


BEGIN_MESSAGE_MAP(AddDialog, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_FRUIT, &AddDialog::OnBnClickedRadioFruit)
	ON_BN_CLICKED(IDC_RADIO_APPLE, &AddDialog::OnBnClickedRadioFruit)
	ON_BN_CLICKED(IDOK, &AddDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &AddDialog::OnBnClickedCheck1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &AddDialog::OnTabSelectChange)
	ON_BN_CLICKED(IDC_BUTTON1, &AddDialog::OnAddFromTabBtnClicked)
END_MESSAGE_MAP()


// AddDialog message handlers


BOOL AddDialog::OnInitDialog()
{

	CDialogEx::OnInitDialog();


	// ?????????????? ???????????,??????? ???? ????? ???????? ? ?????????? ????, ???? ?? ????? ???????? ???? ?? ????? ??????
	// GetDlgItem(IDC_RADIO_APPLE)->GetParent()->CheckRadioButton(IDC_RADIO_FRUIT, IDC_RADIO_APPLE, IDC_RADIO_APPLE);
	CButton* radioBtnApple = (CButton*)GetDlgItem(IDC_RADIO_APPLE);

	// ?????????? ?????? ???, ????? ?????? ?????? ?? Fruit

	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	pBtn->SetCheck(1);
	if (f_index == -1)
	{
		m_appleRadio.GetParent()->CheckRadioButton(IDC_RADIO_FRUIT, IDC_RADIO_APPLE, IDC_RADIO_APPLE);
		UpdateData(true);

		CTabCtrl* tabControl1 = (CTabCtrl*)GetDlgItem(IDC_TAB1);
		fruitTab.Create(FRUIT_DIALOG, tabControl1);

		CTabCtrl* tabControl2 = (CTabCtrl*)GetDlgItem(IDC_TAB1);
		appleTab.Create(APPLE_DIALOG, tabControl2);

		TCITEM appleWindow, fruitWindow;

		fruitWindow.mask = TCIF_TEXT | TCIF_PARAM;
		fruitWindow.lParam = (LPARAM)&fruitTab;
		fruitWindow.pszText = (LPSTR)_T("Fruit");
		tabControl1->InsertItem(0, &fruitWindow);

		appleWindow.mask = TCIF_TEXT | TCIF_PARAM;
		appleWindow.lParam = (LPARAM)&fruitTab;
		appleWindow.pszText = (LPSTR)_T("Apple");
		tabControl2->InsertItem(1, &appleWindow);

		CRect fruitRect, appleRect;
		tabControl1->GetItemRect(0, &fruitRect);
		fruitTab.SetWindowPos(NULL, fruitRect.left, fruitRect.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

		tabControl2->GetItemRect(0, &appleRect);
		appleTab.SetWindowPos(NULL, appleRect.left, appleRect.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

		fruitTab.ShowWindow(SW_SHOW);
		appleTab.ShowWindow(SW_HIDE);
	}
	else if (f_index >= 0)
	{
		auto isApple = this->pDoc->saladRecipe.IsApple(f_index);
		if (!isApple)
		{
			CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
			pBtn->SetCheck(0);

			m_appleRadio.GetParent()->CheckRadioButton(IDC_RADIO_FRUIT, IDC_RADIO_APPLE, IDC_RADIO_FRUIT);

			GetDlgItem(IDC_EDIT2_COLOR)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_EDIT2_SEEDS)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_EDIT2_TREES)->ShowWindow(SW_HIDE);

			GetDlgItem(IDC_STATIC_COLOR)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_STATIC_SEEDS)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_STATIC_TREES)->ShowWindow(SW_HIDE);
			UpdateData(true);
		}
		else
		{
			m_appleRadio.GetParent()->CheckRadioButton(IDC_RADIO_FRUIT, IDC_RADIO_APPLE, IDC_RADIO_APPLE);
			UpdateData(true);
		}
		TabManager.ShowWindow(SW_HIDE);
		CButton* btnAddFromTab = (CButton*)GetDlgItem(IDC_BUTTON1);
		btnAddFromTab->ShowWindow(SW_HIDE);
		pDoc->saladRecipe.LoadObj(this, f_index);
	}
	return true;
}


void AddDialog::OnBnClickedRadioFruit()
{
	UpdateData();
	switch (m_ShowType)
	{
	case 0:
		SetAppleFields(false);
		SetFruitFields(true);
		break;
	case 1:
		SetFruitFields(false);
		SetAppleFields(true);
		break;
	}
}


void AddDialog::OnBnClickedOk()//first for add// second for edit
{
	if (f_index < 0)
	{
		pDoc->saladRecipe.save_obj(this, m_ShowType, false);
	}
	else
	{
		pDoc->saladRecipe.save_obj(this, m_ShowType, false, f_index);// change exact index
	}
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

void AddDialog::OnAddFromTabBtnClicked()
{
	// ???????? ??????? ????? ????, ?? ?????? ADD FROM TAB [IDC_BUTTON1]
	if (f_index > 0) throw std::runtime_error("add from tab error. f_index < 0 means edit");
	int selected_type = TabManager.GetCurSel();
	bool isApple = false;
	if (selected_type == 0)
	{
		// fruit
		CString name, amount, price;
		CEdit* nameEditControl = (CEdit*)fruitTab.GetDlgItem(IDC_EDIT1);
		CEdit* amountEditControl = (CEdit*)fruitTab.GetDlgItem(IDC_EDIT2);
		CEdit* priceEditControl = (CEdit*)fruitTab.GetDlgItem(IDC_EDIT3);

		nameEditControl->GetWindowText(name);
		amountEditControl->GetWindowText(amount);
		priceEditControl->GetWindowText(price);

		this->m_name = name;
		this->m_amount = atoi(amount);
		this->m_price = atof(price);
	}
	else if (selected_type == 1)
	{
		// apple
		CString name, amount, price, color, seed, trees;
		CEdit* nameEditControl = (CEdit*)appleTab.GetDlgItem(IDC_EDIT1);
		CEdit* amountEditControl = (CEdit*)appleTab.GetDlgItem(IDC_EDIT2);
		CEdit* priceEditControl = (CEdit*)appleTab.GetDlgItem(IDC_EDIT3);
		CEdit* colorEditControl = (CEdit*)appleTab.GetDlgItem(IDC_EDIT4);
		CEdit* seedEditControl = (CEdit*)appleTab.GetDlgItem(IDC_EDIT5);
		CEdit* treesEditControl = (CEdit*)appleTab.GetDlgItem(IDC_EDIT7);

		nameEditControl->GetWindowText(name);
		amountEditControl->GetWindowText(amount);
		priceEditControl->GetWindowText(price);
		colorEditControl->GetWindowText(color);
		seedEditControl->GetWindowText(seed);
		treesEditControl->GetWindowText(trees);

		this->m_name = name;
		this->m_amount = atoi(amount);
		this->m_price = atof(price);
		this->m_color = color;
		this->m_seeds = atoi(seed);
		this->m_trees = atoi(trees);
		isApple = true;
	}
	else throw std::runtime_error("selected tab/type error");

	pDoc->saladRecipe.save_obj(this, isApple, true);
	CDialogEx::OnOK();
}

void AddDialog::OnBnClickedCheck1()
{
	UpdateData();

	if (IsDlgButtonChecked(IDC_CHECK1))
	{
		SetAppleFields(true);
	}
	else
	{
		SetAppleFields(false);
		SetFruitFields(true);
	}
}

void AddDialog::OnTabSelectChange(NMHDR* pNMHDR, LRESULT* pResult)
{
	int current_select = TabManager.GetCurSel();
	if (current_select == 0)
	{
		// fruit
		fruitTab.ShowWindow(SW_SHOW);
		appleTab.ShowWindow(SW_HIDE);
	}
	else
	{
		// apple
		appleTab.ShowWindow(SW_SHOW);
		fruitTab.ShowWindow(SW_HIDE);
	}

	*pResult = 0;
}