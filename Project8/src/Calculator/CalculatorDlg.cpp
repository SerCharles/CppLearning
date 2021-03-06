
// CalculatorDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX, IDC_EDIT1, num1);
	DDX_Text(pDX, IDC_EDIT2, num2);
	DDX_Text(pDX, IDC_EDIT3, ans);
	DDX_Text(pDX, IDC_EDIT4, additional);

	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONPLUS, &CCalculatorDlg::OnBnClickedButtonplus)
	ON_BN_CLICKED(IDC_BUTTONMINUS, &CCalculatorDlg::OnBnClickedButtonminus)
	ON_BN_CLICKED(IDC_BUTTONMULTI, &CCalculatorDlg::OnBnClickedButtonmulti)
	ON_BN_CLICKED(IDC_BUTTONDIVIDE, &CCalculatorDlg::OnBnClickedButtondivide)
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CCalculatorDlg::OnEnChangeEdit2)
	ON_EN_UPDATE(IDC_EDIT2, &CCalculatorDlg::OnEnUpdateEdit2)
	ON_EN_UPDATE(IDC_EDIT1, &CCalculatorDlg::OnEnUpdateEdit1)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CCalculatorDlg::OnBnClickedButtonplus()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	type = 1;
	real = long long(num1) + long long(num2);
	ans = num1 + num2;
	if (real != ans) AfxMessageBox(_T("数据范围溢出！"));
	CEdit *edit1 = (CEdit*)GetDlgItem(IDC_EDIT4);
	CEdit *edit2 = (CEdit*)GetDlgItem(IDC_STATIC);
	edit1->ShowWindow(false);
	edit2->ShowWindow(false);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonminus()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	type = 2;
	real = long long(num1) - long long(num2);
	ans = num1 - num2;
	if (real != ans) AfxMessageBox(_T("数据范围溢出！"));
	CEdit *edit1 = (CEdit*)GetDlgItem(IDC_EDIT4);
	CEdit *edit2 = (CEdit*)GetDlgItem(IDC_STATIC);
	edit1->ShowWindow(false);
	edit2->ShowWindow(false);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonmulti()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	type = 3;
	real = long long(num1) * long long(num2);
	ans = num1 * num2;
	if (real != ans) AfxMessageBox(_T("数据范围溢出！"));
	CEdit *edit1 = (CEdit*)GetDlgItem(IDC_EDIT4);
	CEdit *edit2 = (CEdit*)GetDlgItem(IDC_STATIC);
	edit1->ShowWindow(false);
	edit2->ShowWindow(false);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtondivide()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	type = 4;
	if (num2 == 0)
	{
		AfxMessageBox(_T("不能除以0!"));
	}
	else
	{
		real = long long(num1) / long long(num2);
		additional = num1 % num2;
		ans = num1 / num2;
		if (real != ans) AfxMessageBox(_T("数据范围溢出！"));
		if (additional != 0)
		{
			CEdit *edit1 = (CEdit*)GetDlgItem(IDC_EDIT4);
			CEdit *edit2 = (CEdit*)GetDlgItem(IDC_STATIC);
			edit1->ShowWindow(true);
			edit2->ShowWindow(true);
		}
		else
		{
			CEdit *edit1 = (CEdit*)GetDlgItem(IDC_EDIT4);
			CEdit *edit2 = (CEdit*)GetDlgItem(IDC_STATIC);
			edit1->ShowWindow(false);
			edit2->ShowWindow(false);
		}
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	if (type == 1) OnBnClickedButtonplus();
	if (type == 2)OnBnClickedButtonminus();
	if (type == 3) OnBnClickedButtonmulti();
	if (type == 4) OnBnClickedButtondivide();
	// TODO:  在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	if (type == 1) OnBnClickedButtonplus();
	if (type == 2)OnBnClickedButtonminus();
	if (type == 3) OnBnClickedButtonmulti();
	if (type == 4) OnBnClickedButtondivide();
	// TODO:  在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnEnUpdateEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数，以将 EM_SETEVENTMASK 消息发送到该控件，
	// 同时将 ENM_UPDATE 标志“或”运算到 lParam 掩码中。
	if (type == 1) OnBnClickedButtonplus();
	if (type == 2)OnBnClickedButtonminus();
	if (type == 3) OnBnClickedButtonmulti();
	if (type == 4) OnBnClickedButtondivide();
	// TODO:  在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnEnUpdateEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数，以将 EM_SETEVENTMASK 消息发送到该控件，
	// 同时将 ENM_UPDATE 标志“或”运算到 lParam 掩码中。
	if (type == 1) OnBnClickedButtonplus();
	if (type == 2)OnBnClickedButtonminus();
	if (type == 3) OnBnClickedButtonmulti();
	if (type == 4) OnBnClickedButtondivide();
	// TODO:  在此添加控件通知处理程序代码
}






