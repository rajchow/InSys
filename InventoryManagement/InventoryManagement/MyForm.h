#pragma once
#include "TableInterface.h"
#include "Category.h"

namespace InventoryManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tbInventorySystem;
	protected: 
	private: System::Windows::Forms::TabPage^  tpCategory;
	private: System::Windows::Forms::Button^  btnCategoryAdd;

	private: System::Windows::Forms::Label^  lblCategoryDescription;
	private: System::Windows::Forms::TextBox^  txtCategoryDescription;


	private: System::Windows::Forms::Label^  lblCategoryName;
	private: System::Windows::Forms::TextBox^  txtCategoryName;
	private: System::Windows::Forms::ComboBox^  cmbCategorySelect;



	private: System::Windows::Forms::ComboBox^  cmbCategoryFunction;
	private: System::Windows::Forms::TabPage^  tpProduct;
	private: System::Windows::Forms::TabPage^  tpSales;
	private: System::Windows::Forms::TabPage^  tpInvoices;
	private: System::Windows::Forms::MenuStrip^  msMenu;

	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  programHelpToolStripMenuItem;
	private: System::Windows::Forms::Label^  lblCategoryFunction;
	private: System::Windows::Forms::Label^  lblCategorySelect;
	private: System::Windows::Forms::Label^  lblProductFunction;
	private: System::Windows::Forms::ComboBox^  cmbProductFunction;
	private: System::Windows::Forms::Label^  lblProductSelect;
	private: System::Windows::Forms::ComboBox^  cmbProductSelect;
	private: System::Windows::Forms::Label^  lblProductPrice;

	private: System::Windows::Forms::Label^  lblProductDescription;
	private: System::Windows::Forms::TextBox^  txtProductDescription;

	private: System::Windows::Forms::Label^  lblProductName;
	private: System::Windows::Forms::TextBox^  txtProductName;

	private: System::Windows::Forms::Button^  btnCategoryModify;
	private: System::Windows::Forms::Button^  btnProductModify;
	private: System::Windows::Forms::Button^  btnProductAdd;
	private: System::Windows::Forms::TextBox^  txtProductPrice;
	private: System::Windows::Forms::Button^  btnCategoryDelete;
	private: System::Windows::Forms::Label^  lblProductCategory;
	private: System::Windows::Forms::ComboBox^  cmbProductCategorySelect;
	private: System::Windows::Forms::TextBox^  txtProdID;
	private: System::Windows::Forms::Label^  lblProductID;
	private: System::Windows::Forms::Button^  btnProductDelete;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cmbSalesFunction;
	private: System::Windows::Forms::Label^  lblSalesReceiptSelect;
	private: System::Windows::Forms::ComboBox^  cmbSalesReceiptSelect;
	private: System::Windows::Forms::Button^  btnSalesRemoveProduct;
	private: System::Windows::Forms::ListBox^  lstSalesProducts;
	private: System::Windows::Forms::Button^  btnSalesAddProduct;
	private: System::Windows::Forms::TextBox^  txtSalesProductQuantity;
	private: System::Windows::Forms::Label^  lblSaleProductQuantity;
	private: System::Windows::Forms::Label^  lblSalesProductSelect;
	private: System::Windows::Forms::ComboBox^  cmbSalesProductSelect;


	private: System::Windows::Forms::TextBox^  txtSalesProductDiscount;
	private: System::Windows::Forms::Label^  lblSalesProductDiscount;
	private: System::Windows::Forms::Button^  btnSalesCreateReceipt;
	private: System::Windows::Forms::Button^  btnSalesModify;
	private: System::Windows::Forms::DateTimePicker^  dtSalesReceiptDate;
	private: System::Windows::Forms::DateTimePicker^  dtInvoiceDate;
	private: System::Windows::Forms::Button^  btnInvoiceModify;
	private: System::Windows::Forms::Button^  btnInvoiceCreateInvoice;
	private: System::Windows::Forms::Label^  lblInvoiceSelect;
	private: System::Windows::Forms::ComboBox^  cmbInvoiceSelect;
	private: System::Windows::Forms::Button^  btnInvoiceRemoveProduct;
	private: System::Windows::Forms::ListBox^  lstInvoiceProductList;
	private: System::Windows::Forms::Button^  btnInvoiceAddProduct;
	private: System::Windows::Forms::TextBox^  txtInvoiceProductQuantity;
	private: System::Windows::Forms::Label^  lblInvoiceProductQuantity;
	private: System::Windows::Forms::Label^  lblInvoiceProductSelect;
	private: System::Windows::Forms::ComboBox^  cmbInvoiceProductSelect;
	private: System::Windows::Forms::Label^  lblInvoiceFunction;
	private: System::Windows::Forms::ComboBox^  cmbInvoiceFunction;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tbInventorySystem = (gcnew System::Windows::Forms::TabControl());
			this->tpCategory = (gcnew System::Windows::Forms::TabPage());
			this->btnCategoryDelete = (gcnew System::Windows::Forms::Button());
			this->btnCategoryModify = (gcnew System::Windows::Forms::Button());
			this->lblCategorySelect = (gcnew System::Windows::Forms::Label());
			this->lblCategoryFunction = (gcnew System::Windows::Forms::Label());
			this->btnCategoryAdd = (gcnew System::Windows::Forms::Button());
			this->lblCategoryDescription = (gcnew System::Windows::Forms::Label());
			this->txtCategoryDescription = (gcnew System::Windows::Forms::TextBox());
			this->lblCategoryName = (gcnew System::Windows::Forms::Label());
			this->txtCategoryName = (gcnew System::Windows::Forms::TextBox());
			this->cmbCategorySelect = (gcnew System::Windows::Forms::ComboBox());
			this->cmbCategoryFunction = (gcnew System::Windows::Forms::ComboBox());
			this->tpProduct = (gcnew System::Windows::Forms::TabPage());
			this->btnProductDelete = (gcnew System::Windows::Forms::Button());
			this->txtProdID = (gcnew System::Windows::Forms::TextBox());
			this->lblProductID = (gcnew System::Windows::Forms::Label());
			this->lblProductCategory = (gcnew System::Windows::Forms::Label());
			this->cmbProductCategorySelect = (gcnew System::Windows::Forms::ComboBox());
			this->btnProductModify = (gcnew System::Windows::Forms::Button());
			this->btnProductAdd = (gcnew System::Windows::Forms::Button());
			this->txtProductPrice = (gcnew System::Windows::Forms::TextBox());
			this->lblProductPrice = (gcnew System::Windows::Forms::Label());
			this->lblProductDescription = (gcnew System::Windows::Forms::Label());
			this->txtProductDescription = (gcnew System::Windows::Forms::TextBox());
			this->lblProductName = (gcnew System::Windows::Forms::Label());
			this->txtProductName = (gcnew System::Windows::Forms::TextBox());
			this->lblProductSelect = (gcnew System::Windows::Forms::Label());
			this->cmbProductSelect = (gcnew System::Windows::Forms::ComboBox());
			this->lblProductFunction = (gcnew System::Windows::Forms::Label());
			this->cmbProductFunction = (gcnew System::Windows::Forms::ComboBox());
			this->tpSales = (gcnew System::Windows::Forms::TabPage());
			this->dtSalesReceiptDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnSalesModify = (gcnew System::Windows::Forms::Button());
			this->btnSalesCreateReceipt = (gcnew System::Windows::Forms::Button());
			this->txtSalesProductDiscount = (gcnew System::Windows::Forms::TextBox());
			this->lblSalesProductDiscount = (gcnew System::Windows::Forms::Label());
			this->lblSalesReceiptSelect = (gcnew System::Windows::Forms::Label());
			this->cmbSalesReceiptSelect = (gcnew System::Windows::Forms::ComboBox());
			this->btnSalesRemoveProduct = (gcnew System::Windows::Forms::Button());
			this->lstSalesProducts = (gcnew System::Windows::Forms::ListBox());
			this->btnSalesAddProduct = (gcnew System::Windows::Forms::Button());
			this->txtSalesProductQuantity = (gcnew System::Windows::Forms::TextBox());
			this->lblSaleProductQuantity = (gcnew System::Windows::Forms::Label());
			this->lblSalesProductSelect = (gcnew System::Windows::Forms::Label());
			this->cmbSalesProductSelect = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbSalesFunction = (gcnew System::Windows::Forms::ComboBox());
			this->tpInvoices = (gcnew System::Windows::Forms::TabPage());
			this->dtInvoiceDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnInvoiceModify = (gcnew System::Windows::Forms::Button());
			this->btnInvoiceCreateInvoice = (gcnew System::Windows::Forms::Button());
			this->lblInvoiceSelect = (gcnew System::Windows::Forms::Label());
			this->cmbInvoiceSelect = (gcnew System::Windows::Forms::ComboBox());
			this->btnInvoiceRemoveProduct = (gcnew System::Windows::Forms::Button());
			this->lstInvoiceProductList = (gcnew System::Windows::Forms::ListBox());
			this->btnInvoiceAddProduct = (gcnew System::Windows::Forms::Button());
			this->txtInvoiceProductQuantity = (gcnew System::Windows::Forms::TextBox());
			this->lblInvoiceProductQuantity = (gcnew System::Windows::Forms::Label());
			this->lblInvoiceProductSelect = (gcnew System::Windows::Forms::Label());
			this->cmbInvoiceProductSelect = (gcnew System::Windows::Forms::ComboBox());
			this->lblInvoiceFunction = (gcnew System::Windows::Forms::Label());
			this->cmbInvoiceFunction = (gcnew System::Windows::Forms::ComboBox());
			this->msMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->programHelpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tbInventorySystem->SuspendLayout();
			this->tpCategory->SuspendLayout();
			this->tpProduct->SuspendLayout();
			this->tpSales->SuspendLayout();
			this->tpInvoices->SuspendLayout();
			this->msMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// tbInventorySystem
			// 
			this->tbInventorySystem->Controls->Add(this->tpCategory);
			this->tbInventorySystem->Controls->Add(this->tpProduct);
			this->tbInventorySystem->Controls->Add(this->tpSales);
			this->tbInventorySystem->Controls->Add(this->tpInvoices);
			this->tbInventorySystem->Location = System::Drawing::Point(12, 28);
			this->tbInventorySystem->Name = L"tbInventorySystem";
			this->tbInventorySystem->SelectedIndex = 0;
			this->tbInventorySystem->Size = System::Drawing::Size(511, 497);
			this->tbInventorySystem->TabIndex = 0;
			// 
			// tpCategory
			// 
			this->tpCategory->Controls->Add(this->btnCategoryDelete);
			this->tpCategory->Controls->Add(this->btnCategoryModify);
			this->tpCategory->Controls->Add(this->lblCategorySelect);
			this->tpCategory->Controls->Add(this->lblCategoryFunction);
			this->tpCategory->Controls->Add(this->btnCategoryAdd);
			this->tpCategory->Controls->Add(this->lblCategoryDescription);
			this->tpCategory->Controls->Add(this->txtCategoryDescription);
			this->tpCategory->Controls->Add(this->lblCategoryName);
			this->tpCategory->Controls->Add(this->txtCategoryName);
			this->tpCategory->Controls->Add(this->cmbCategorySelect);
			this->tpCategory->Controls->Add(this->cmbCategoryFunction);
			this->tpCategory->Location = System::Drawing::Point(4, 22);
			this->tpCategory->Name = L"tpCategory";
			this->tpCategory->Padding = System::Windows::Forms::Padding(3);
			this->tpCategory->Size = System::Drawing::Size(503, 471);
			this->tpCategory->TabIndex = 0;
			this->tpCategory->Text = L"Category";
			this->tpCategory->UseVisualStyleBackColor = true;
			// 
			// btnCategoryDelete
			// 
			this->btnCategoryDelete->Location = System::Drawing::Point(6, 108);
			this->btnCategoryDelete->Name = L"btnCategoryDelete";
			this->btnCategoryDelete->Size = System::Drawing::Size(75, 23);
			this->btnCategoryDelete->TabIndex = 10;
			this->btnCategoryDelete->Text = L"Delete";
			this->btnCategoryDelete->UseVisualStyleBackColor = true;
			// 
			// btnCategoryModify
			// 
			this->btnCategoryModify->Location = System::Drawing::Point(7, 246);
			this->btnCategoryModify->Name = L"btnCategoryModify";
			this->btnCategoryModify->Size = System::Drawing::Size(75, 23);
			this->btnCategoryModify->TabIndex = 9;
			this->btnCategoryModify->Text = L"Modify";
			this->btnCategoryModify->UseVisualStyleBackColor = true;
			// 
			// lblCategorySelect
			// 
			this->lblCategorySelect->AutoSize = true;
			this->lblCategorySelect->Location = System::Drawing::Point(7, 55);
			this->lblCategorySelect->Name = L"lblCategorySelect";
			this->lblCategorySelect->Size = System::Drawing::Size(52, 13);
			this->lblCategorySelect->TabIndex = 8;
			this->lblCategorySelect->Text = L"Category:";
			// 
			// lblCategoryFunction
			// 
			this->lblCategoryFunction->AutoSize = true;
			this->lblCategoryFunction->Location = System::Drawing::Point(7, 7);
			this->lblCategoryFunction->Name = L"lblCategoryFunction";
			this->lblCategoryFunction->Size = System::Drawing::Size(51, 13);
			this->lblCategoryFunction->TabIndex = 7;
			this->lblCategoryFunction->Text = L"Function:";
			// 
			// btnCategoryAdd
			// 
			this->btnCategoryAdd->Location = System::Drawing::Point(7, 246);
			this->btnCategoryAdd->Name = L"btnCategoryAdd";
			this->btnCategoryAdd->Size = System::Drawing::Size(43, 23);
			this->btnCategoryAdd->TabIndex = 6;
			this->btnCategoryAdd->Text = L"Add";
			this->btnCategoryAdd->UseVisualStyleBackColor = true;
			// 
			// lblCategoryDescription
			// 
			this->lblCategoryDescription->AutoSize = true;
			this->lblCategoryDescription->Location = System::Drawing::Point(7, 173);
			this->lblCategoryDescription->Name = L"lblCategoryDescription";
			this->lblCategoryDescription->Size = System::Drawing::Size(63, 13);
			this->lblCategoryDescription->TabIndex = 5;
			this->lblCategoryDescription->Text = L"Description:";
			// 
			// txtCategoryDescription
			// 
			this->txtCategoryDescription->Location = System::Drawing::Point(7, 192);
			this->txtCategoryDescription->MaxLength = 100;
			this->txtCategoryDescription->Multiline = true;
			this->txtCategoryDescription->Name = L"txtCategoryDescription";
			this->txtCategoryDescription->Size = System::Drawing::Size(490, 48);
			this->txtCategoryDescription->TabIndex = 4;
			// 
			// lblCategoryName
			// 
			this->lblCategoryName->AutoSize = true;
			this->lblCategoryName->Location = System::Drawing::Point(7, 118);
			this->lblCategoryName->Name = L"lblCategoryName";
			this->lblCategoryName->Size = System::Drawing::Size(38, 13);
			this->lblCategoryName->TabIndex = 3;
			this->lblCategoryName->Text = L"Name:";
			// 
			// txtCategoryName
			// 
			this->txtCategoryName->Location = System::Drawing::Point(7, 137);
			this->txtCategoryName->Name = L"txtCategoryName";
			this->txtCategoryName->Size = System::Drawing::Size(490, 20);
			this->txtCategoryName->TabIndex = 2;
			// 
			// cmbCategorySelect
			// 
			this->cmbCategorySelect->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCategorySelect->FormattingEnabled = true;
			this->cmbCategorySelect->Location = System::Drawing::Point(6, 75);
			this->cmbCategorySelect->Name = L"cmbCategorySelect";
			this->cmbCategorySelect->Size = System::Drawing::Size(491, 21);
			this->cmbCategorySelect->TabIndex = 1;
			// 
			// cmbCategoryFunction
			// 
			this->cmbCategoryFunction->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCategoryFunction->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Add", L"Modify", L"Delete"});
			this->cmbCategoryFunction->Location = System::Drawing::Point(7, 27);
			this->cmbCategoryFunction->Name = L"cmbCategoryFunction";
			this->cmbCategoryFunction->Size = System::Drawing::Size(114, 21);
			this->cmbCategoryFunction->TabIndex = 0;
			this->cmbCategoryFunction->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cmbCategoryFunction_SelectedIndexChanged);
			// 
			// tpProduct
			// 
			this->tpProduct->Controls->Add(this->btnProductDelete);
			this->tpProduct->Controls->Add(this->txtProdID);
			this->tpProduct->Controls->Add(this->lblProductID);
			this->tpProduct->Controls->Add(this->lblProductCategory);
			this->tpProduct->Controls->Add(this->cmbProductCategorySelect);
			this->tpProduct->Controls->Add(this->btnProductModify);
			this->tpProduct->Controls->Add(this->btnProductAdd);
			this->tpProduct->Controls->Add(this->txtProductPrice);
			this->tpProduct->Controls->Add(this->lblProductPrice);
			this->tpProduct->Controls->Add(this->lblProductDescription);
			this->tpProduct->Controls->Add(this->txtProductDescription);
			this->tpProduct->Controls->Add(this->lblProductName);
			this->tpProduct->Controls->Add(this->txtProductName);
			this->tpProduct->Controls->Add(this->lblProductSelect);
			this->tpProduct->Controls->Add(this->cmbProductSelect);
			this->tpProduct->Controls->Add(this->lblProductFunction);
			this->tpProduct->Controls->Add(this->cmbProductFunction);
			this->tpProduct->Location = System::Drawing::Point(4, 22);
			this->tpProduct->Name = L"tpProduct";
			this->tpProduct->Padding = System::Windows::Forms::Padding(3);
			this->tpProduct->Size = System::Drawing::Size(503, 471);
			this->tpProduct->TabIndex = 1;
			this->tpProduct->Text = L"Product";
			this->tpProduct->UseVisualStyleBackColor = true;
			// 
			// btnProductDelete
			// 
			this->btnProductDelete->Location = System::Drawing::Point(7, 112);
			this->btnProductDelete->Name = L"btnProductDelete";
			this->btnProductDelete->Size = System::Drawing::Size(75, 23);
			this->btnProductDelete->TabIndex = 24;
			this->btnProductDelete->Text = L"Delete";
			this->btnProductDelete->UseVisualStyleBackColor = true;
			// 
			// txtProdID
			// 
			this->txtProdID->Location = System::Drawing::Point(6, 126);
			this->txtProdID->Name = L"txtProdID";
			this->txtProdID->Size = System::Drawing::Size(100, 20);
			this->txtProdID->TabIndex = 23;
			// 
			// lblProductID
			// 
			this->lblProductID->AutoSize = true;
			this->lblProductID->Location = System::Drawing::Point(7, 106);
			this->lblProductID->Name = L"lblProductID";
			this->lblProductID->Size = System::Drawing::Size(61, 13);
			this->lblProductID->TabIndex = 22;
			this->lblProductID->Text = L"Product ID:";
			// 
			// lblProductCategory
			// 
			this->lblProductCategory->AutoSize = true;
			this->lblProductCategory->Location = System::Drawing::Point(7, 157);
			this->lblProductCategory->Name = L"lblProductCategory";
			this->lblProductCategory->Size = System::Drawing::Size(52, 13);
			this->lblProductCategory->TabIndex = 21;
			this->lblProductCategory->Text = L"Category:";
			// 
			// cmbProductCategorySelect
			// 
			this->cmbProductCategorySelect->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbProductCategorySelect->FormattingEnabled = true;
			this->cmbProductCategorySelect->Location = System::Drawing::Point(6, 177);
			this->cmbProductCategorySelect->Name = L"cmbProductCategorySelect";
			this->cmbProductCategorySelect->Size = System::Drawing::Size(491, 21);
			this->cmbProductCategorySelect->TabIndex = 20;
			// 
			// btnProductModify
			// 
			this->btnProductModify->Location = System::Drawing::Point(7, 414);
			this->btnProductModify->Name = L"btnProductModify";
			this->btnProductModify->Size = System::Drawing::Size(75, 23);
			this->btnProductModify->TabIndex = 19;
			this->btnProductModify->Text = L"Modify";
			this->btnProductModify->UseVisualStyleBackColor = true;
			// 
			// btnProductAdd
			// 
			this->btnProductAdd->Location = System::Drawing::Point(6, 414);
			this->btnProductAdd->Name = L"btnProductAdd";
			this->btnProductAdd->Size = System::Drawing::Size(43, 23);
			this->btnProductAdd->TabIndex = 18;
			this->btnProductAdd->Text = L"Add";
			this->btnProductAdd->UseVisualStyleBackColor = true;
			// 
			// txtProductPrice
			// 
			this->txtProductPrice->Location = System::Drawing::Point(7, 372);
			this->txtProductPrice->MaxLength = 8;
			this->txtProductPrice->Name = L"txtProductPrice";
			this->txtProductPrice->Size = System::Drawing::Size(100, 20);
			this->txtProductPrice->TabIndex = 17;
			// 
			// lblProductPrice
			// 
			this->lblProductPrice->AutoSize = true;
			this->lblProductPrice->Location = System::Drawing::Point(7, 355);
			this->lblProductPrice->Name = L"lblProductPrice";
			this->lblProductPrice->Size = System::Drawing::Size(34, 13);
			this->lblProductPrice->TabIndex = 16;
			this->lblProductPrice->Text = L"Price:";
			// 
			// lblProductDescription
			// 
			this->lblProductDescription->AutoSize = true;
			this->lblProductDescription->Location = System::Drawing::Point(6, 267);
			this->lblProductDescription->Name = L"lblProductDescription";
			this->lblProductDescription->Size = System::Drawing::Size(63, 13);
			this->lblProductDescription->TabIndex = 15;
			this->lblProductDescription->Text = L"Description:";
			// 
			// txtProductDescription
			// 
			this->txtProductDescription->Location = System::Drawing::Point(6, 286);
			this->txtProductDescription->MaxLength = 100;
			this->txtProductDescription->Multiline = true;
			this->txtProductDescription->Name = L"txtProductDescription";
			this->txtProductDescription->Size = System::Drawing::Size(490, 48);
			this->txtProductDescription->TabIndex = 14;
			// 
			// lblProductName
			// 
			this->lblProductName->AutoSize = true;
			this->lblProductName->Location = System::Drawing::Point(6, 212);
			this->lblProductName->Name = L"lblProductName";
			this->lblProductName->Size = System::Drawing::Size(38, 13);
			this->lblProductName->TabIndex = 13;
			this->lblProductName->Text = L"Name:";
			// 
			// txtProductName
			// 
			this->txtProductName->Location = System::Drawing::Point(6, 231);
			this->txtProductName->Name = L"txtProductName";
			this->txtProductName->Size = System::Drawing::Size(490, 20);
			this->txtProductName->TabIndex = 12;
			// 
			// lblProductSelect
			// 
			this->lblProductSelect->AutoSize = true;
			this->lblProductSelect->Location = System::Drawing::Point(7, 55);
			this->lblProductSelect->Name = L"lblProductSelect";
			this->lblProductSelect->Size = System::Drawing::Size(47, 13);
			this->lblProductSelect->TabIndex = 11;
			this->lblProductSelect->Text = L"Product:";
			// 
			// cmbProductSelect
			// 
			this->cmbProductSelect->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbProductSelect->FormattingEnabled = true;
			this->cmbProductSelect->Location = System::Drawing::Point(6, 75);
			this->cmbProductSelect->Name = L"cmbProductSelect";
			this->cmbProductSelect->Size = System::Drawing::Size(491, 21);
			this->cmbProductSelect->TabIndex = 10;
			// 
			// lblProductFunction
			// 
			this->lblProductFunction->AutoSize = true;
			this->lblProductFunction->Location = System::Drawing::Point(7, 7);
			this->lblProductFunction->Name = L"lblProductFunction";
			this->lblProductFunction->Size = System::Drawing::Size(51, 13);
			this->lblProductFunction->TabIndex = 9;
			this->lblProductFunction->Text = L"Function:";
			// 
			// cmbProductFunction
			// 
			this->cmbProductFunction->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbProductFunction->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Add", L"Modify", L"Delete"});
			this->cmbProductFunction->Location = System::Drawing::Point(7, 27);
			this->cmbProductFunction->Name = L"cmbProductFunction";
			this->cmbProductFunction->Size = System::Drawing::Size(114, 21);
			this->cmbProductFunction->TabIndex = 8;
			this->cmbProductFunction->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cmbProductFunction_SelectedIndexChanged);
			// 
			// tpSales
			// 
			this->tpSales->Controls->Add(this->dtSalesReceiptDate);
			this->tpSales->Controls->Add(this->btnSalesModify);
			this->tpSales->Controls->Add(this->btnSalesCreateReceipt);
			this->tpSales->Controls->Add(this->txtSalesProductDiscount);
			this->tpSales->Controls->Add(this->lblSalesProductDiscount);
			this->tpSales->Controls->Add(this->lblSalesReceiptSelect);
			this->tpSales->Controls->Add(this->cmbSalesReceiptSelect);
			this->tpSales->Controls->Add(this->btnSalesRemoveProduct);
			this->tpSales->Controls->Add(this->lstSalesProducts);
			this->tpSales->Controls->Add(this->btnSalesAddProduct);
			this->tpSales->Controls->Add(this->txtSalesProductQuantity);
			this->tpSales->Controls->Add(this->lblSaleProductQuantity);
			this->tpSales->Controls->Add(this->lblSalesProductSelect);
			this->tpSales->Controls->Add(this->cmbSalesProductSelect);
			this->tpSales->Controls->Add(this->label1);
			this->tpSales->Controls->Add(this->cmbSalesFunction);
			this->tpSales->Location = System::Drawing::Point(4, 22);
			this->tpSales->Name = L"tpSales";
			this->tpSales->Padding = System::Windows::Forms::Padding(3);
			this->tpSales->Size = System::Drawing::Size(503, 471);
			this->tpSales->TabIndex = 2;
			this->tpSales->Text = L"Sales";
			this->tpSales->UseVisualStyleBackColor = true;
			// 
			// dtSalesReceiptDate
			// 
			this->dtSalesReceiptDate->Location = System::Drawing::Point(7, 306);
			this->dtSalesReceiptDate->MaxDate = System::DateTime(2999, 12, 31, 0, 0, 0, 0);
			this->dtSalesReceiptDate->MinDate = System::DateTime(1901, 1, 1, 0, 0, 0, 0);
			this->dtSalesReceiptDate->Name = L"dtSalesReceiptDate";
			this->dtSalesReceiptDate->Size = System::Drawing::Size(200, 20);
			this->dtSalesReceiptDate->TabIndex = 35;
			// 
			// btnSalesModify
			// 
			this->btnSalesModify->Location = System::Drawing::Point(6, 346);
			this->btnSalesModify->Name = L"btnSalesModify";
			this->btnSalesModify->Size = System::Drawing::Size(75, 23);
			this->btnSalesModify->TabIndex = 34;
			this->btnSalesModify->Text = L"Modify";
			this->btnSalesModify->UseVisualStyleBackColor = true;
			// 
			// btnSalesCreateReceipt
			// 
			this->btnSalesCreateReceipt->Location = System::Drawing::Point(6, 346);
			this->btnSalesCreateReceipt->Name = L"btnSalesCreateReceipt";
			this->btnSalesCreateReceipt->Size = System::Drawing::Size(99, 23);
			this->btnSalesCreateReceipt->TabIndex = 33;
			this->btnSalesCreateReceipt->Text = L"Create Receipt";
			this->btnSalesCreateReceipt->UseVisualStyleBackColor = true;
			// 
			// txtSalesProductDiscount
			// 
			this->txtSalesProductDiscount->Location = System::Drawing::Point(6, 231);
			this->txtSalesProductDiscount->Name = L"txtSalesProductDiscount";
			this->txtSalesProductDiscount->Size = System::Drawing::Size(100, 20);
			this->txtSalesProductDiscount->TabIndex = 32;
			// 
			// lblSalesProductDiscount
			// 
			this->lblSalesProductDiscount->AutoSize = true;
			this->lblSalesProductDiscount->Location = System::Drawing::Point(7, 211);
			this->lblSalesProductDiscount->Name = L"lblSalesProductDiscount";
			this->lblSalesProductDiscount->Size = System::Drawing::Size(92, 13);
			this->lblSalesProductDiscount->TabIndex = 31;
			this->lblSalesProductDiscount->Text = L"Product Discount:";
			// 
			// lblSalesReceiptSelect
			// 
			this->lblSalesReceiptSelect->AutoSize = true;
			this->lblSalesReceiptSelect->Location = System::Drawing::Point(7, 57);
			this->lblSalesReceiptSelect->Name = L"lblSalesReceiptSelect";
			this->lblSalesReceiptSelect->Size = System::Drawing::Size(47, 13);
			this->lblSalesReceiptSelect->TabIndex = 30;
			this->lblSalesReceiptSelect->Text = L"Receipt:";
			// 
			// cmbSalesReceiptSelect
			// 
			this->cmbSalesReceiptSelect->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbSalesReceiptSelect->FormattingEnabled = true;
			this->cmbSalesReceiptSelect->Location = System::Drawing::Point(6, 77);
			this->cmbSalesReceiptSelect->Name = L"cmbSalesReceiptSelect";
			this->cmbSalesReceiptSelect->Size = System::Drawing::Size(491, 21);
			this->cmbSalesReceiptSelect->TabIndex = 29;
			// 
			// btnSalesRemoveProduct
			// 
			this->btnSalesRemoveProduct->Location = System::Drawing::Point(398, 261);
			this->btnSalesRemoveProduct->Name = L"btnSalesRemoveProduct";
			this->btnSalesRemoveProduct->Size = System::Drawing::Size(98, 23);
			this->btnSalesRemoveProduct->TabIndex = 28;
			this->btnSalesRemoveProduct->Text = L"Remove Product";
			this->btnSalesRemoveProduct->UseVisualStyleBackColor = true;
			// 
			// lstSalesProducts
			// 
			this->lstSalesProducts->FormattingEnabled = true;
			this->lstSalesProducts->Location = System::Drawing::Point(153, 159);
			this->lstSalesProducts->Name = L"lstSalesProducts";
			this->lstSalesProducts->Size = System::Drawing::Size(344, 95);
			this->lstSalesProducts->TabIndex = 27;
			// 
			// btnSalesAddProduct
			// 
			this->btnSalesAddProduct->Location = System::Drawing::Point(7, 261);
			this->btnSalesAddProduct->Name = L"btnSalesAddProduct";
			this->btnSalesAddProduct->Size = System::Drawing::Size(75, 23);
			this->btnSalesAddProduct->TabIndex = 26;
			this->btnSalesAddProduct->Text = L"Add To List";
			this->btnSalesAddProduct->UseVisualStyleBackColor = true;
			// 
			// txtSalesProductQuantity
			// 
			this->txtSalesProductQuantity->Location = System::Drawing::Point(6, 179);
			this->txtSalesProductQuantity->Name = L"txtSalesProductQuantity";
			this->txtSalesProductQuantity->Size = System::Drawing::Size(100, 20);
			this->txtSalesProductQuantity->TabIndex = 25;
			// 
			// lblSaleProductQuantity
			// 
			this->lblSaleProductQuantity->AutoSize = true;
			this->lblSaleProductQuantity->Location = System::Drawing::Point(7, 159);
			this->lblSaleProductQuantity->Name = L"lblSaleProductQuantity";
			this->lblSaleProductQuantity->Size = System::Drawing::Size(89, 13);
			this->lblSaleProductQuantity->TabIndex = 24;
			this->lblSaleProductQuantity->Text = L"Product Quantity:";
			// 
			// lblSalesProductSelect
			// 
			this->lblSalesProductSelect->AutoSize = true;
			this->lblSalesProductSelect->Location = System::Drawing::Point(7, 104);
			this->lblSalesProductSelect->Name = L"lblSalesProductSelect";
			this->lblSalesProductSelect->Size = System::Drawing::Size(47, 13);
			this->lblSalesProductSelect->TabIndex = 13;
			this->lblSalesProductSelect->Text = L"Product:";
			// 
			// cmbSalesProductSelect
			// 
			this->cmbSalesProductSelect->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbSalesProductSelect->FormattingEnabled = true;
			this->cmbSalesProductSelect->Location = System::Drawing::Point(6, 124);
			this->cmbSalesProductSelect->Name = L"cmbSalesProductSelect";
			this->cmbSalesProductSelect->Size = System::Drawing::Size(491, 21);
			this->cmbSalesProductSelect->TabIndex = 12;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Function:";
			// 
			// cmbSalesFunction
			// 
			this->cmbSalesFunction->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbSalesFunction->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Add", L"Modify"});
			this->cmbSalesFunction->Location = System::Drawing::Point(7, 27);
			this->cmbSalesFunction->Name = L"cmbSalesFunction";
			this->cmbSalesFunction->Size = System::Drawing::Size(114, 21);
			this->cmbSalesFunction->TabIndex = 10;
			this->cmbSalesFunction->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cmbSalesFunction_SelectedIndexChanged);
			// 
			// tpInvoices
			// 
			this->tpInvoices->Controls->Add(this->dtInvoiceDate);
			this->tpInvoices->Controls->Add(this->btnInvoiceModify);
			this->tpInvoices->Controls->Add(this->btnInvoiceCreateInvoice);
			this->tpInvoices->Controls->Add(this->lblInvoiceSelect);
			this->tpInvoices->Controls->Add(this->cmbInvoiceSelect);
			this->tpInvoices->Controls->Add(this->btnInvoiceRemoveProduct);
			this->tpInvoices->Controls->Add(this->lstInvoiceProductList);
			this->tpInvoices->Controls->Add(this->btnInvoiceAddProduct);
			this->tpInvoices->Controls->Add(this->txtInvoiceProductQuantity);
			this->tpInvoices->Controls->Add(this->lblInvoiceProductQuantity);
			this->tpInvoices->Controls->Add(this->lblInvoiceProductSelect);
			this->tpInvoices->Controls->Add(this->cmbInvoiceProductSelect);
			this->tpInvoices->Controls->Add(this->lblInvoiceFunction);
			this->tpInvoices->Controls->Add(this->cmbInvoiceFunction);
			this->tpInvoices->Location = System::Drawing::Point(4, 22);
			this->tpInvoices->Name = L"tpInvoices";
			this->tpInvoices->Padding = System::Windows::Forms::Padding(3);
			this->tpInvoices->Size = System::Drawing::Size(503, 471);
			this->tpInvoices->TabIndex = 3;
			this->tpInvoices->Text = L"Invoices";
			this->tpInvoices->UseVisualStyleBackColor = true;
			// 
			// dtInvoiceDate
			// 
			this->dtInvoiceDate->Location = System::Drawing::Point(7, 264);
			this->dtInvoiceDate->MaxDate = System::DateTime(2999, 12, 31, 0, 0, 0, 0);
			this->dtInvoiceDate->MinDate = System::DateTime(1901, 1, 1, 0, 0, 0, 0);
			this->dtInvoiceDate->Name = L"dtInvoiceDate";
			this->dtInvoiceDate->Size = System::Drawing::Size(200, 20);
			this->dtInvoiceDate->TabIndex = 51;
			// 
			// btnInvoiceModify
			// 
			this->btnInvoiceModify->Location = System::Drawing::Point(6, 304);
			this->btnInvoiceModify->Name = L"btnInvoiceModify";
			this->btnInvoiceModify->Size = System::Drawing::Size(75, 23);
			this->btnInvoiceModify->TabIndex = 50;
			this->btnInvoiceModify->Text = L"Modify";
			this->btnInvoiceModify->UseVisualStyleBackColor = true;
			// 
			// btnInvoiceCreateInvoice
			// 
			this->btnInvoiceCreateInvoice->Location = System::Drawing::Point(6, 304);
			this->btnInvoiceCreateInvoice->Name = L"btnInvoiceCreateInvoice";
			this->btnInvoiceCreateInvoice->Size = System::Drawing::Size(99, 23);
			this->btnInvoiceCreateInvoice->TabIndex = 49;
			this->btnInvoiceCreateInvoice->Text = L"Create Invoice";
			this->btnInvoiceCreateInvoice->UseVisualStyleBackColor = true;
			// 
			// lblInvoiceSelect
			// 
			this->lblInvoiceSelect->AutoSize = true;
			this->lblInvoiceSelect->Location = System::Drawing::Point(7, 57);
			this->lblInvoiceSelect->Name = L"lblInvoiceSelect";
			this->lblInvoiceSelect->Size = System::Drawing::Size(45, 13);
			this->lblInvoiceSelect->TabIndex = 46;
			this->lblInvoiceSelect->Text = L"Invoice:";
			// 
			// cmbInvoiceSelect
			// 
			this->cmbInvoiceSelect->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbInvoiceSelect->FormattingEnabled = true;
			this->cmbInvoiceSelect->Location = System::Drawing::Point(6, 77);
			this->cmbInvoiceSelect->Name = L"cmbInvoiceSelect";
			this->cmbInvoiceSelect->Size = System::Drawing::Size(491, 21);
			this->cmbInvoiceSelect->TabIndex = 45;
			// 
			// btnInvoiceRemoveProduct
			// 
			this->btnInvoiceRemoveProduct->Location = System::Drawing::Point(398, 261);
			this->btnInvoiceRemoveProduct->Name = L"btnInvoiceRemoveProduct";
			this->btnInvoiceRemoveProduct->Size = System::Drawing::Size(98, 23);
			this->btnInvoiceRemoveProduct->TabIndex = 44;
			this->btnInvoiceRemoveProduct->Text = L"Remove Product";
			this->btnInvoiceRemoveProduct->UseVisualStyleBackColor = true;
			// 
			// lstInvoiceProductList
			// 
			this->lstInvoiceProductList->FormattingEnabled = true;
			this->lstInvoiceProductList->Location = System::Drawing::Point(153, 159);
			this->lstInvoiceProductList->Name = L"lstInvoiceProductList";
			this->lstInvoiceProductList->Size = System::Drawing::Size(344, 95);
			this->lstInvoiceProductList->TabIndex = 43;
			// 
			// btnInvoiceAddProduct
			// 
			this->btnInvoiceAddProduct->Location = System::Drawing::Point(6, 205);
			this->btnInvoiceAddProduct->Name = L"btnInvoiceAddProduct";
			this->btnInvoiceAddProduct->Size = System::Drawing::Size(75, 23);
			this->btnInvoiceAddProduct->TabIndex = 42;
			this->btnInvoiceAddProduct->Text = L"Add To List";
			this->btnInvoiceAddProduct->UseVisualStyleBackColor = true;
			// 
			// txtInvoiceProductQuantity
			// 
			this->txtInvoiceProductQuantity->Location = System::Drawing::Point(6, 179);
			this->txtInvoiceProductQuantity->Name = L"txtInvoiceProductQuantity";
			this->txtInvoiceProductQuantity->Size = System::Drawing::Size(100, 20);
			this->txtInvoiceProductQuantity->TabIndex = 41;
			// 
			// lblInvoiceProductQuantity
			// 
			this->lblInvoiceProductQuantity->AutoSize = true;
			this->lblInvoiceProductQuantity->Location = System::Drawing::Point(7, 159);
			this->lblInvoiceProductQuantity->Name = L"lblInvoiceProductQuantity";
			this->lblInvoiceProductQuantity->Size = System::Drawing::Size(89, 13);
			this->lblInvoiceProductQuantity->TabIndex = 40;
			this->lblInvoiceProductQuantity->Text = L"Product Quantity:";
			// 
			// lblInvoiceProductSelect
			// 
			this->lblInvoiceProductSelect->AutoSize = true;
			this->lblInvoiceProductSelect->Location = System::Drawing::Point(7, 104);
			this->lblInvoiceProductSelect->Name = L"lblInvoiceProductSelect";
			this->lblInvoiceProductSelect->Size = System::Drawing::Size(47, 13);
			this->lblInvoiceProductSelect->TabIndex = 39;
			this->lblInvoiceProductSelect->Text = L"Product:";
			// 
			// cmbInvoiceProductSelect
			// 
			this->cmbInvoiceProductSelect->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbInvoiceProductSelect->FormattingEnabled = true;
			this->cmbInvoiceProductSelect->Location = System::Drawing::Point(6, 124);
			this->cmbInvoiceProductSelect->Name = L"cmbInvoiceProductSelect";
			this->cmbInvoiceProductSelect->Size = System::Drawing::Size(491, 21);
			this->cmbInvoiceProductSelect->TabIndex = 38;
			// 
			// lblInvoiceFunction
			// 
			this->lblInvoiceFunction->AutoSize = true;
			this->lblInvoiceFunction->Location = System::Drawing::Point(7, 7);
			this->lblInvoiceFunction->Name = L"lblInvoiceFunction";
			this->lblInvoiceFunction->Size = System::Drawing::Size(51, 13);
			this->lblInvoiceFunction->TabIndex = 37;
			this->lblInvoiceFunction->Text = L"Function:";
			// 
			// cmbInvoiceFunction
			// 
			this->cmbInvoiceFunction->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbInvoiceFunction->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Add", L"Modify"});
			this->cmbInvoiceFunction->Location = System::Drawing::Point(7, 27);
			this->cmbInvoiceFunction->Name = L"cmbInvoiceFunction";
			this->cmbInvoiceFunction->Size = System::Drawing::Size(114, 21);
			this->cmbInvoiceFunction->TabIndex = 36;
			this->cmbInvoiceFunction->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cmbInvoiceFunction_SelectedIndexChanged);
			// 
			// msMenu
			// 
			this->msMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->helpToolStripMenuItem});
			this->msMenu->Location = System::Drawing::Point(0, 0);
			this->msMenu->Name = L"msMenu";
			this->msMenu->Size = System::Drawing::Size(535, 24);
			this->msMenu->TabIndex = 1;
			this->msMenu->Text = L"MainMenuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->aboutToolStripMenuItem, 
				this->programHelpToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// programHelpToolStripMenuItem
			// 
			this->programHelpToolStripMenuItem->Name = L"programHelpToolStripMenuItem";
			this->programHelpToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->programHelpToolStripMenuItem->Text = L"Program Help";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 537);
			this->Controls->Add(this->tbInventorySystem);
			this->Controls->Add(this->msMenu);
			this->MainMenuStrip = this->msMenu;
			this->MinimumSize = System::Drawing::Size(370, 415);
			this->Name = L"MyForm";
			this->Text = L"Inventory Management System";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tbInventorySystem->ResumeLayout(false);
			this->tpCategory->ResumeLayout(false);
			this->tpCategory->PerformLayout();
			this->tpProduct->ResumeLayout(false);
			this->tpProduct->PerformLayout();
			this->tpSales->ResumeLayout(false);
			this->tpSales->PerformLayout();
			this->tpInvoices->ResumeLayout(false);
			this->tpInvoices->PerformLayout();
			this->msMenu->ResumeLayout(false);
			this->msMenu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 // Category: all components (except Function label and combobox selector) set to invisible
				 lblCategoryName->Visible = false;
				 txtCategoryName->Visible = false;
				 lblCategoryDescription->Visible = false;
				 txtCategoryDescription->Visible = false;
				 btnCategoryAdd->Visible = false;
				 btnCategoryModify->Visible = false;
				 btnCategoryDelete->Visible = false;
				 lblCategorySelect->Visible = false;
				 cmbCategorySelect->Visible = false;

				 // Product: all components (except Function label and combobox selector) set to invisible
				 lblProductSelect->Visible = false;
				 cmbProductSelect->Visible = false;
				 lblProductID->Visible = false;
				 txtProdID->Visible = false;
				 lblProductCategory->Visible = false;
				 cmbProductCategorySelect->Visible = false;
				 lblProductName->Visible = false;
				 txtProductName->Visible = false;
				 lblProductDescription->Visible = false;
				 txtProductDescription->Visible = false;
				 lblProductPrice->Visible = false;
				 txtProductPrice->Visible = false;
				 btnProductAdd->Visible = false;
				 btnProductModify->Visible = false;
				 btnProductDelete->Visible = false;

				 // Sales: all components (except Function label and combobox selector) set to invisible
				 lblSalesReceiptSelect->Visible = false;
				 cmbSalesReceiptSelect->Visible = false;
				 lblSalesProductSelect->Visible = false;
				 cmbSalesProductSelect->Visible = false;
				 lblSaleProductQuantity->Visible = false;
				 txtSalesProductQuantity->Visible = false;
				 lblSalesProductDiscount->Visible = false;
				 txtSalesProductDiscount->Visible = false;
				 btnSalesAddProduct->Visible = false;
				 lstSalesProducts->Visible = false;
				 btnSalesRemoveProduct->Visible = false;
				 dtSalesReceiptDate->Visible = false;
				 btnSalesCreateReceipt->Visible = false;
				 btnSalesModify->Visible = false;

				 // Invoice: all components (except Function label and combobox selector) set to invisible
				 lblInvoiceSelect->Visible = false;
				 cmbInvoiceSelect->Visible = false;
				 lblInvoiceProductSelect->Visible = false;
				 cmbInvoiceProductSelect->Visible = false;
				 lblInvoiceProductQuantity->Visible = false;
				 txtInvoiceProductQuantity->Visible = false;
				 btnInvoiceAddProduct->Visible = false;
				 lstInvoiceProductList->Visible = false;
				 btnInvoiceRemoveProduct->Visible = false;
				 dtInvoiceDate->Visible = false;
				 btnInvoiceCreateInvoice->Visible = false;
				 btnInvoiceModify->Visible = false;
			 }

			 /// \brief Changes the visibility of certain components for the category tab based on the user selected function
			 ///
			 /// SelectedIndex == 0 : "Add"
			 /// SelectedIndex == 1 : "Modify"
			 /// SelectedIndex == 2 : "Delete"
	private: System::Void cmbCategoryFunction_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

				 if(cmbCategoryFunction->SelectedIndex == 0)
				 {
					 // Label "Name:" set to visible
					 lblCategoryName->Visible = true;
					 // Textbox for name set to visible
					 txtCategoryName->Visible = true;
					 // Label "Description:" set to visible
					 lblCategoryDescription->Visible = true;
					 // Textbox for description set to visible
					 txtCategoryDescription->Visible = true;
					 // "Add" button set to visible
					 btnCategoryAdd->Visible = true;
					 // "Modify" button set to invisible
					 btnCategoryModify->Visible = false;
					 // "Delete" button set to invisible
					 btnCategoryDelete->Visible = false;
					 // Label "Category:" set to visible
					 lblCategorySelect->Visible = false;
					 // Combobox for Category selection set to invisible
					 cmbCategorySelect->Visible = false;
				 } else if(cmbCategoryFunction->SelectedIndex == 1)
				 {
					 lblCategoryName->Visible = true;
					 txtCategoryName->Visible = true;
					 lblCategoryDescription->Visible = true;
					 txtCategoryDescription->Visible = true;
					 btnCategoryAdd->Visible = false;
					 btnCategoryModify->Visible = true;
					 btnCategoryDelete->Visible = false;
					 lblCategorySelect->Visible = true;
					 cmbCategorySelect->Visible = true;
				 } else if(cmbCategoryFunction->SelectedIndex == 2)
				 {
					 lblCategoryName->Visible = false;
					 txtCategoryName->Visible = false;
					 lblCategoryDescription->Visible = false;
					 txtCategoryDescription->Visible = false;
					 btnCategoryAdd->Visible = false;
					 btnCategoryModify->Visible = false;
					 btnCategoryDelete->Visible = true;
					 lblCategorySelect->Visible = true;
					 cmbCategorySelect->Visible = true;
				 }

			 }

			 /// \brief Changes the visibility of certain components for the product tab based on the user selected function
			 ///
			 /// SelectedIndex == 0 : "Add"
			 /// SelectedIndex == 1 : "Modify"
			 /// SelectedIndex == 2 : "Delete"
	private: System::Void cmbProductFunction_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(cmbProductFunction->SelectedIndex == 0)
				 {
					 lblProductSelect->Visible = false;
					 cmbProductSelect->Visible = false;
					 lblProductID->Visible = true;
					 txtProdID->Visible = true;
					 lblProductCategory->Visible = true;
					 cmbProductCategorySelect->Visible = true;
					 lblProductName->Visible = true;
					 txtProductName->Visible = true;
					 lblProductDescription->Visible = true;
					 txtProductDescription->Visible = true;
					 lblProductPrice->Visible = true;
					 txtProductPrice->Visible = true;
					 btnProductAdd->Visible = true;
					 btnProductModify->Visible = false;
					 btnProductDelete->Visible = false;
				 } else if(cmbProductFunction->SelectedIndex == 1)
				 {
					 lblProductSelect->Visible = true;
					 cmbProductSelect->Visible = true;
					 lblProductID->Visible = true;
					 txtProdID->Visible = true;
					 lblProductCategory->Visible = true;
					 cmbProductCategorySelect->Visible = true;
					 lblProductName->Visible = true;
					 txtProductName->Visible = true;
					 lblProductDescription->Visible = true;
					 txtProductDescription->Visible = true;
					 lblProductPrice->Visible = true;
					 txtProductPrice->Visible = true;
					 btnProductAdd->Visible = false;
					 btnProductModify->Visible = true;
					 btnProductDelete->Visible = false;
				 } else if(cmbProductFunction->SelectedIndex == 2)
				 {
					 lblProductSelect->Visible = true;
					 cmbProductSelect->Visible = true;
					 lblProductID->Visible = false;
					 txtProdID->Visible = false;
					 lblProductCategory->Visible = false;
					 cmbProductCategorySelect->Visible = false;
					 lblProductName->Visible = false;
					 txtProductName->Visible = false;
					 lblProductDescription->Visible = false;
					 txtProductDescription->Visible = false;
					 lblProductPrice->Visible = false;
					 txtProductPrice->Visible = false;
					 btnProductAdd->Visible = false;
					 btnProductModify->Visible = false;
					 btnProductDelete->Visible = true;
				 }
			 }

			 /// \brief Changes the visibility of certain components for the sales tab based on the user selected function
			 ///
			 /// SelectedIndex == 0 : "Add"
			 /// SelectedIndex == 1 : "Modify"
	private: System::Void cmbSalesFunction_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(cmbSalesFunction->SelectedIndex == 0)
				 {
					 lblSalesReceiptSelect->Visible = false;
					 cmbSalesReceiptSelect->Visible = false;
					 lblSalesProductSelect->Visible = true;
					 cmbSalesProductSelect->Visible = true;
					 lblSaleProductQuantity->Visible = true;
					 txtSalesProductQuantity->Visible = true;
					 lblSalesProductDiscount->Visible = true;
					 txtSalesProductDiscount->Visible = true;
					 btnSalesAddProduct->Visible = true;
					 lstSalesProducts->Visible = true;
					 btnSalesRemoveProduct->Visible = true;
					 dtSalesReceiptDate->Visible = true;
					 btnSalesCreateReceipt->Visible = true;
					 btnSalesModify->Visible = false;
				 } else if(cmbSalesFunction->SelectedIndex == 1)
				 {
					 lblSalesReceiptSelect->Visible = true;
					 cmbSalesReceiptSelect->Visible = true;
					 lblSalesProductSelect->Visible = true;
					 cmbSalesProductSelect->Visible = true;
					 lblSaleProductQuantity->Visible = true;
					 txtSalesProductQuantity->Visible = true;
					 lblSalesProductDiscount->Visible = true;
					 txtSalesProductDiscount->Visible = true;
					 btnSalesAddProduct->Visible = true;
					 lstSalesProducts->Visible = true;
					 btnSalesRemoveProduct->Visible = true;
					 dtSalesReceiptDate->Visible = true;
					 btnSalesCreateReceipt->Visible = false;
					 btnSalesModify->Visible = true;
				 }
			 }

			 /// \brief Changes the visibility of certain components for the invoice tab based on the user selected function
			 ///
			 /// SelectedIndex == 0 : "Add"
			 /// SelectedIndex == 1 : "Modify"
	private: System::Void cmbInvoiceFunction_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

				 if(cmbInvoiceFunction->SelectedIndex == 0)
				 {
					 lblInvoiceSelect->Visible = false;
					 cmbInvoiceSelect->Visible = false;
					 lblInvoiceProductSelect->Visible = true;
					 cmbInvoiceProductSelect->Visible = true;
					 lblInvoiceProductQuantity->Visible = true;
					 txtInvoiceProductQuantity->Visible = true;
					 btnInvoiceAddProduct->Visible = true;
					 lstInvoiceProductList->Visible = true;
					 btnInvoiceRemoveProduct->Visible = true;
					 dtInvoiceDate->Visible = true;
					 btnInvoiceCreateInvoice->Visible = true;
					 btnInvoiceModify->Visible = false;
				 } else if(cmbInvoiceFunction->SelectedIndex == 1)
				 {
					 lblInvoiceSelect->Visible = true;
					 cmbInvoiceSelect->Visible = true;
					 lblInvoiceProductSelect->Visible = true;
					 cmbInvoiceProductSelect->Visible = true;
					 lblInvoiceProductQuantity->Visible = true;
					 txtInvoiceProductQuantity->Visible = true;
					 btnInvoiceAddProduct->Visible = true;
					 lstInvoiceProductList->Visible = true;
					 btnInvoiceRemoveProduct->Visible = true;
					 dtInvoiceDate->Visible = true;
					 btnInvoiceCreateInvoice->Visible = false;
					 btnInvoiceModify->Visible = true;
				 }
			 }
	};
}
