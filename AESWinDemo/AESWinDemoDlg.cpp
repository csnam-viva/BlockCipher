﻿
// AESWinDemoDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "AESWinDemo.h"
#include "AESWinDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CAESWinDemoDlg 대화 상자



CAESWinDemoDlg::CAESWinDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AESWINDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAESWinDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAESWinDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_KeyExpand, &CAESWinDemoDlg::OnBnClickedKeyexpand)
	ON_BN_CLICKED(IDC_BTN_ENCRIPTION, &CAESWinDemoDlg::OnBnClickedBtnEncription)
	ON_BN_CLICKED(IDC_BTN_DESCRIPTION, &CAESWinDemoDlg::OnBnClickedBtnDescription)
END_MESSAGE_MAP()


// CAESWinDemoDlg 메시지 처리기

BOOL CAESWinDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CString strPlainText = _T("ABCDEFGHIJKLMNOP");
	SetDlgItemText(IDC_EDIT_PLAINTEXT, strPlainText);
	CString strKeyEnc = _T("01020304050607080910111213141516");
	SetDlgItemText(IDC_EDIT_KEY_ENC, strKeyEnc);


	

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CAESWinDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CAESWinDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CAESWinDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAESWinDemoDlg::OnBnClickedKeyexpand()
{
	Expandkey();

}

void CAESWinDemoDlg::Expandkey()
{
	std::vector<byte> cipherKyey = { 0x11,0x22 };
	std::vector<byte> roundKey(16, 0);

}
#include "AES.hpp"
void CAESWinDemoDlg::OnBnClickedBtnEncription()
{

	AES aes128(128); // 128  ECB mode
	CString strPlainText;
	CString strCipherKey;
	int count = GetDlgItemText(IDC_EDIT_PLAINTEXT, strPlainText);

	std::string str = CT2A(strPlainText); // "ABCDEFGHIJKLMNOP";
	std::string hexStr = aes128.convertStrToHexStr(str);
	std::string plainText = hexStr;


	count = GetDlgItemText(IDC_EDIT_KEY_ENC, strCipherKey);
	if (count < 1) {
		AfxMessageBox(_T("암호키가 입력 되지 않았습니다."));
		return;
	}
	std::string cipherKey = CT2A(strCipherKey); // "01020304050607080910111213141516";
	//std::string cipherKey = "01020304050607080910111213141516";

	std::string cipherText = aes128.encryption(plainText, cipherKey, true);


	CString strCipherText(cipherText.c_str());
	this->SetDlgItemText(IDC_EDIT_CIPHERTEXT, strCipherText);

	/*std::string origin = aes128.decryption(cipherText, cipherKey, true);

	std::string decstr = aes128.convertHexStrToStr(origin);

	CString strDecodeText(decstr.c_str());

	this->SetDlgItemText(IDC_EDIT_PLAINTEXT_DECODE, strDecodeText);*/
}


void CAESWinDemoDlg::OnBnClickedBtnDescription()
{
	CString strCipherText;
	CString strCipherKey;
	AES aes128(128); // 128  ECB mode
	//std::string cipherKey = "01020304050607080910111213141516";

	int count = GetDlgItemText(IDC_EDIT_CIPHER_TEXT_DECODE, strCipherText);
	if (count < 1) {
		AfxMessageBox(_T("암호문이 입력 되지 않았습니다."));
		return;
	}
	std::string cipherText = CT2A(strCipherText);

	count = GetDlgItemText(IDC_EDIT_KEY_DECODE, strCipherKey);
	if (count < 1) {
		AfxMessageBox(_T("암호키가 입력 되지 않았습니다."));
		return;
	}
	std::string cipherKey = CT2A(strCipherKey); // "01020304050607080910111213141516";


	std::string origin = aes128.decryption(cipherText, cipherKey, true);
	std::string decstr = aes128.convertHexStrToStr(origin);

	CString strDecodeText(decstr.c_str());
	this->SetDlgItemText(IDC_EDIT_PLAINTEXT_DECODE, strDecodeText);

}
