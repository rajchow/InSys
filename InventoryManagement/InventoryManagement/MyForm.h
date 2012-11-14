#pragma once
#include "TableInterface.h"
#include "Category.h"
#include "Product.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

namespace InventoryManagement {

	using namespace msclr::interop;
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
	
		/// \brief Function to return the entire contents of the specified file
	private:
		vector<string> returnFile(string fileName){
			// vector to store each row of the file
			vector<string> fileVect;

			ifstream inFile;

			// opens the connection to the textFile
			inFile.open(fileName);

			// string to contain current row
			string rowReceive;

			// ensures that categoryInFile is open
			if(inFile.is_open())
			{
				// while loop continues as long as there is another line in the text file
				while(inFile.good())
				{
					// retrieves the next line in categoryInFile and assigns it to the string rowReceive
					getline(inFile, rowReceive);

					// ensures that the row contains data
					if(!rowReceive.empty())
					{
						// adds the row to the vector
						fileVect.push_back(rowReceive);
					}
				}
			}

			// close connection to file
			inFile.close();

			return fileVect;
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
	private: System::Windows::Forms::TextBox^  txtCategorySearch;
	private: System::Windows::Forms::ComboBox^  cmbCategorySearchBy;
	private: System::Windows::Forms::Label^  lblCategorySearchBy;
	private: System::Windows::Forms::Button^  btnCategorySearch;
	private: System::Windows::Forms::Label^  lblCategorySearchInfo;
	private: System::Windows::Forms::TextBox^  txtCategorySearchResults;
	private: System::Windows::Forms::Button^  btnProductSearch;
	private: System::Windows::Forms::Label^  lblProductSearchInfo;
	private: System::Windows::Forms::TextBox^  txtProductSearch;
	private: System::Windows::Forms::ComboBox^  cmbProductSearch;
	private: System::Windows::Forms::Label^  lblProductSearchBy;
	private: System::Windows::Forms::TextBox^  txtProductSearchResults;


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
			this->txtCategorySearchResults = (gcnew System::Windows::Forms::TextBox());
			this->btnCategorySearch = (gcnew System::Windows::Forms::Button());
			this->lblCategorySearchInfo = (gcnew System::Windows::Forms::Label());
			this->txtCategorySearch = (gcnew System::Windows::Forms::TextBox());
			this->cmbCategorySearchBy = (gcnew System::Windows::Forms::ComboBox());
			this->lblCategorySearchBy = (gcnew System::Windows::Forms::Label());
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
			this->txtProductSearchResults = (gcnew System::Windows::Forms::TextBox());
			this->btnProductSearch = (gcnew System::Windows::Forms::Button());
			this->lblProductSearchInfo = (gcnew System::Windows::Forms::Label());
			this->txtProductSearch = (gcnew System::Windows::Forms::TextBox());
			this->cmbProductSearch = (gcnew System::Windows::Forms::ComboBox());
			this->lblProductSearchBy = (gcnew System::Windows::Forms::Label());
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
			this->tpCategory->Controls->Add(this->txtCategorySearchResults);
			this->tpCategory->Controls->Add(this->btnCategorySearch);
			this->tpCategory->Controls->Add(this->lblCategorySearchInfo);
			this->tpCategory->Controls->Add(this->txtCategorySearch);
			this->tpCategory->Controls->Add(this->cmbCategorySearchBy);
			this->tpCategory->Controls->Add(this->lblCategorySearchBy);
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
			// txtCategorySearchResults
			// 
			this->txtCategorySearchResults->Location = System::Drawing::Point(7, 219);
			this->txtCategorySearchResults->Multiline = true;
			this->txtCategorySearchResults->Name = L"txtCategorySearchResults";
			this->txtCategorySearchResults->ReadOnly = true;
			this->txtCategorySearchResults->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtCategorySearchResults->Size = System::Drawing::Size(490, 141);
			this->txtCategorySearchResults->TabIndex = 16;
			// 
			// btnCategorySearch
			// 
			this->btnCategorySearch->Location = System::Drawing::Point(6, 168);
			this->btnCategorySearch->Name = L"btnCategorySearch";
			this->btnCategorySearch->Size = System::Drawing::Size(75, 23);
			this->btnCategorySearch->TabIndex = 15;
			this->btnCategorySearch->Text = L"Search";
			this->btnCategorySearch->UseVisualStyleBackColor = true;
			this->btnCategorySearch->Click += gcnew System::EventHandler(this, &MyForm::btnCategorySearch_Click);
			// 
			// lblCategorySearchInfo
			// 
			this->lblCategorySearchInfo->AutoSize = true;
			this->lblCategorySearchInfo->Location = System::Drawing::Point(7, 113);
			this->lblCategorySearchInfo->Name = L"lblCategorySearchInfo";
			this->lblCategorySearchInfo->Size = System::Drawing::Size(142, 13);
			this->lblCategorySearchInfo->TabIndex = 14;
			this->lblCategorySearchInfo->Text = L"Enter Information for Search:";
			// 
			// txtCategorySearch
			// 
			this->txtCategorySearch->Location = System::Drawing::Point(7, 137);
			this->txtCategorySearch->Name = L"txtCategorySearch";
			this->txtCategorySearch->Size = System::Drawing::Size(490, 20);
			this->txtCategorySearch->TabIndex = 13;
			// 
			// cmbCategorySearchBy
			// 
			this->cmbCategorySearchBy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCategorySearchBy->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"ID", L"Name", L"Description"});
			this->cmbCategorySearchBy->Location = System::Drawing::Point(7, 75);
			this->cmbCategorySearchBy->Name = L"cmbCategorySearchBy";
			this->cmbCategorySearchBy->Size = System::Drawing::Size(114, 21);
			this->cmbCategorySearchBy->TabIndex = 12;
			this->cmbCategorySearchBy->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cmbCategorySearchBy_SelectedIndexChanged);
			// 
			// lblCategorySearchBy
			// 
			this->lblCategorySearchBy->AutoSize = true;
			this->lblCategorySearchBy->Location = System::Drawing::Point(7, 55);
			this->lblCategorySearchBy->Name = L"lblCategorySearchBy";
			this->lblCategorySearchBy->Size = System::Drawing::Size(59, 13);
			this->lblCategorySearchBy->TabIndex = 11;
			this->lblCategorySearchBy->Text = L"Search By:";
			// 
			// btnCategoryDelete
			// 
			this->btnCategoryDelete->Location = System::Drawing::Point(6, 108);
			this->btnCategoryDelete->Name = L"btnCategoryDelete";
			this->btnCategoryDelete->Size = System::Drawing::Size(75, 23);
			this->btnCategoryDelete->TabIndex = 10;
			this->btnCategoryDelete->Text = L"Delete";
			this->btnCategoryDelete->UseVisualStyleBackColor = true;
			this->btnCategoryDelete->Click += gcnew System::EventHandler(this, &MyForm::btnCategoryDelete_Click);
			// 
			// btnCategoryModify
			// 
			this->btnCategoryModify->Location = System::Drawing::Point(7, 246);
			this->btnCategoryModify->Name = L"btnCategoryModify";
			this->btnCategoryModify->Size = System::Drawing::Size(75, 23);
			this->btnCategoryModify->TabIndex = 9;
			this->btnCategoryModify->Text = L"Modify";
			this->btnCategoryModify->UseVisualStyleBackColor = true;
			this->btnCategoryModify->Click += gcnew System::EventHandler(this, &MyForm::btnCategoryModify_Click);
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
			this->btnCategoryAdd->Click += gcnew System::EventHandler(this, &MyForm::btnCategoryAdd_Click);
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
			this->cmbCategorySelect->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cmbCategorySelect_SelectedIndexChanged);
			// 
			// cmbCategoryFunction
			// 
			this->cmbCategoryFunction->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCategoryFunction->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Add", L"Modify", L"Delete", L"Search"});
			this->cmbCategoryFunction->Location = System::Drawing::Point(7, 27);
			this->cmbCategoryFunction->Name = L"cmbCategoryFunction";
			this->cmbCategoryFunction->Size = System::Drawing::Size(114, 21);
			this->cmbCategoryFunction->TabIndex = 0;
			this->cmbCategoryFunction->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cmbCategoryFunction_SelectedIndexChanged);
			// 
			// tpProduct
			// 
			this->tpProduct->Controls->Add(this->txtProductSearchResults);
			this->tpProduct->Controls->Add(this->btnProductSearch);
			this->tpProduct->Controls->Add(this->lblProductSearchInfo);
			this->tpProduct->Controls->Add(this->txtProductSearch);
			this->tpProduct->Controls->Add(this->cmbProductSearch);
			this->tpProduct->Controls->Add(this->lblProductSearchBy);
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
			// txtProductSearchResults
			// 
			this->txtProductSearchResults->Location = System::Drawing::Point(6, 224);
			this->txtProductSearchResults->Multiline = true;
			this->txtProductSearchResults->Name = L"txtProductSearchResults";
			this->txtProductSearchResults->ReadOnly = true;
			this->txtProductSearchResults->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtProductSearchResults->Size = System::Drawing::Size(490, 225);
			this->txtProductSearchResults->TabIndex = 30;
			// 
			// btnProductSearch
			// 
			this->btnProductSearch->Location = System::Drawing::Point(6, 186);
			this->btnProductSearch->Name = L"btnProductSearch";
			this->btnProductSearch->Size = System::Drawing::Size(75, 23);
			this->btnProductSearch->TabIndex = 29;
			this->btnProductSearch->Text = L"Search";
			this->btnProductSearch->UseVisualStyleBackColor = true;
			this->btnProductSearch->Click += gcnew System::EventHandler(this, &MyForm::btnProductSearch_Click);
			// 
			// lblProductSearchInfo
			// 
			this->lblProductSearchInfo->AutoSize = true;
			this->lblProductSearchInfo->Location = System::Drawing::Point(7, 117);
			this->lblProductSearchInfo->Name = L"lblProductSearchInfo";
			this->lblProductSearchInfo->Size = System::Drawing::Size(142, 13);
			this->lblProductSearchInfo->TabIndex = 28;
			this->lblProductSearchInfo->Text = L"Enter Information for Search:";
			// 
			// txtProductSearch
			// 
			this->txtProductSearch->Location = System::Drawing::Point(7, 141);
			this->txtProductSearch->Name = L"txtProductSearch";
			this->txtProductSearch->Size = System::Drawing::Size(490, 20);
			this->txtProductSearch->TabIndex = 27;
			// 
			// cmbProductSearch
			// 
			this->cmbProductSearch->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbProductSearch->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Product ID", L"Category ID", L"Name", 
				L"Description", L"Price"});
			this->cmbProductSearch->Location = System::Drawing::Point(7, 75);
			this->cmbProductSearch->Name = L"cmbProductSearch";
			this->cmbProductSearch->Size = System::Drawing::Size(114, 21);
			this->cmbProductSearch->TabIndex = 26;
			this->cmbProductSearch->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cmbProductSearch_SelectedIndexChanged);
			// 
			// lblProductSearchBy
			// 
			this->lblProductSearchBy->AutoSize = true;
			this->lblProductSearchBy->Location = System::Drawing::Point(7, 55);
			this->lblProductSearchBy->Name = L"lblProductSearchBy";
			this->lblProductSearchBy->Size = System::Drawing::Size(59, 13);
			this->lblProductSearchBy->TabIndex = 25;
			this->lblProductSearchBy->Text = L"Search By:";
			// 
			// btnProductDelete
			// 
			this->btnProductDelete->Location = System::Drawing::Point(7, 112);
			this->btnProductDelete->Name = L"btnProductDelete";
			this->btnProductDelete->Size = System::Drawing::Size(75, 23);
			this->btnProductDelete->TabIndex = 24;
			this->btnProductDelete->Text = L"Delete";
			this->btnProductDelete->UseVisualStyleBackColor = true;
			this->btnProductDelete->Click += gcnew System::EventHandler(this, &MyForm::btnProductDelete_Click);
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
			this->cmbProductCategorySelect->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cmbProductCategorySelect_SelectedIndexChanged);
			// 
			// btnProductModify
			// 
			this->btnProductModify->Location = System::Drawing::Point(7, 414);
			this->btnProductModify->Name = L"btnProductModify";
			this->btnProductModify->Size = System::Drawing::Size(75, 23);
			this->btnProductModify->TabIndex = 19;
			this->btnProductModify->Text = L"Modify";
			this->btnProductModify->UseVisualStyleBackColor = true;
			this->btnProductModify->Click += gcnew System::EventHandler(this, &MyForm::btnProductModify_Click);
			// 
			// btnProductAdd
			// 
			this->btnProductAdd->Location = System::Drawing::Point(6, 414);
			this->btnProductAdd->Name = L"btnProductAdd";
			this->btnProductAdd->Size = System::Drawing::Size(43, 23);
			this->btnProductAdd->TabIndex = 18;
			this->btnProductAdd->Text = L"Add";
			this->btnProductAdd->UseVisualStyleBackColor = true;
			this->btnProductAdd->Click += gcnew System::EventHandler(this, &MyForm::btnProductAdd_Click);
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
			this->cmbProductSelect->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cmbProductSelect_SelectedIndexChanged);
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
			this->cmbProductFunction->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Add", L"Modify", L"Delete", L"Search"});
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
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
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
	
			/// \brief On loading the form, components are set to visible=false
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
				 lblCategorySearchBy->Visible = false;
				 cmbCategorySearchBy->Visible = false;
				 lblCategorySearchInfo->Visible = false;
				 txtCategorySearch->Visible = false;
				 btnCategorySearch->Visible = false;
				 txtCategorySearchResults->Visible = false;

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
				 lblProductSearchBy->Visible = false;
				 cmbProductSearch->Visible = false;
				 lblProductSearchInfo->Visible = false;
				 txtProductSearch->Visible = false;
				 btnProductSearch->Visible = false;
				 txtProductSearchResults->Visible = false;

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
			 /// SelectedIndex == 3 : "Search"
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
					 // Label "Search By:" set to invisible
					 lblCategorySearchBy->Visible = false;
					 // Combobox for category "search by" set to invisible
					 cmbCategorySearchBy->Visible = false;
					 // Label "Enter Information for Search:" set to invisible
					 lblCategorySearchInfo->Visible = false;
					 // Text box for category search set to invisible
					 txtCategorySearch->Visible = false;
					 // Button for search set to invisible
					 btnCategorySearch->Visible = false;
					 // Category search results textbox set to invisible
					 txtCategorySearchResults->Visible = false;

					 // clears the textboxes
					 txtCategoryName->Text = "";
					 txtCategoryDescription->Text = "";

					 // enables textboxes
					 txtCategoryName->Enabled = true;
					 txtCategoryDescription->Enabled = true;

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
					 lblCategorySearchBy->Visible = false;
					 cmbCategorySearchBy->Visible = false;
					 lblCategorySearchInfo->Visible = false;
					 txtCategorySearch->Visible = false;
					 btnCategorySearch->Visible = false;
					 txtCategorySearchResults->Visible = false;

					 // disables textboxes and modify button
					 txtCategoryName->Enabled = false;
					 txtCategoryDescription->Enabled = false;
					 btnCategoryModify->Enabled = false;

					 // clears the textboxes
					 txtCategoryName->Text = "";
					 txtCategoryDescription->Text = "";

					 // clear combobox
					 cmbCategorySelect->Items->Clear();

					 // currentRow string
					 System::String ^ currentRow;

					 // vector to contain the category file contents
					 vector<string> categoriesFile;
					 // retrieve vector containing contents of category file
					 categoriesFile = returnFile("textFiles/category.txt");

					 // insert contents of category file into combobox
					 for(int i = 0; i < categoriesFile.size(); i++)
					 {
						 currentRow = gcnew String (categoriesFile[i].c_str());
						 cmbCategorySelect->Items->Add(currentRow);
					 }

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
					 lblCategorySearchBy->Visible = false;
					 cmbCategorySearchBy->Visible = false;
					 lblCategorySearchInfo->Visible = false;
					 txtCategorySearch->Visible = false;
					 btnCategorySearch->Visible = false;
					 txtCategorySearchResults->Visible = false;

					 btnCategoryDelete->Enabled = false;


					 // clear combobox
					 cmbCategorySelect->Items->Clear();

					 // currentRow string
					 System::String ^ currentRow;

					 // vector to contain the category file contents
					 vector<string> categoriesFile;
					 // retrieve vector containing contents of category file
					 categoriesFile = returnFile("textFiles/category.txt");

					 // insert contents of category file into combobox
					 for(int i = 0; i < categoriesFile.size(); i++)
					 {
						 currentRow = gcnew String (categoriesFile[i].c_str());
						 cmbCategorySelect->Items->Add(currentRow);
					 }
				 } else if(cmbCategoryFunction->SelectedIndex == 3)
				 {
					 lblCategoryName->Visible = false;
					 txtCategoryName->Visible = false;
					 lblCategoryDescription->Visible = false;
					 txtCategoryDescription->Visible = false;
					 btnCategoryAdd->Visible = false;
					 btnCategoryModify->Visible = false;
					 btnCategoryDelete->Visible = false;
					 lblCategorySelect->Visible = false;
					 cmbCategorySelect->Visible = false;
					 lblCategorySearchBy->Visible = true;
					 cmbCategorySearchBy->Visible = true;
					 lblCategorySearchInfo->Visible = true;
					 txtCategorySearch->Visible = true;
					 btnCategorySearch->Visible = true;
					 txtCategorySearchResults->Visible = true;
					 txtCategorySearchResults->Text = "";
					 txtCategorySearch->Text = "";

					 txtCategorySearch->Enabled = false;
					 btnCategorySearch->Enabled = false;
				 }

			 }

			 /// \brief Changes the visibility of certain components for the product tab based on the user selected function
			 ///
			 /// SelectedIndex == 0 : "Add"
			 /// SelectedIndex == 1 : "Modify"
			 /// SelectedIndex == 2 : "Delete"
			 /// SelectedIndex == 3 : "Search"
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
					 btnProductAdd->Enabled = false;
					 btnProductModify->Visible = false;
					 btnProductDelete->Visible = false;
					 lblProductSearchBy->Visible = false;
					 cmbProductSearch->Visible = false;
					 lblProductSearchInfo->Visible = false;
					 txtProductSearch->Visible = false;
					 btnProductSearch->Visible = false;
					 txtProductSearchResults->Visible = false;

					 txtProdID->Enabled = true;
					 txtProductName->Enabled = true;
					 cmbProductCategorySelect->Enabled = true;
					 txtProductDescription->Enabled = true;
					 txtProductPrice->Enabled = true;

					 txtProductDescription->Text = "";
					 txtProductName->Text = "";
					 txtProductPrice->Text = "";
					 txtProdID->Text = "";

					 // clear combobox
					 cmbProductCategorySelect->Items->Clear();

					 // currentRow string
					 System::String ^ currentRow;

					 // vector to contain the category file contents
					 vector<string> categoriesFile;
					 // retrieve vector containing contents of category file
					 categoriesFile = returnFile("textFiles/category.txt");

					 // insert contents of category file into combobox
					 for(int i = 0; i < categoriesFile.size(); i++)
					 {
						 currentRow = gcnew String (categoriesFile[i].c_str());
						 cmbProductCategorySelect->Items->Add(currentRow);
					 }
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
					 lblProductSearchBy->Visible = false;
					 cmbProductSearch->Visible = false;
					 lblProductSearchInfo->Visible = false;
					 txtProductSearch->Visible = false;
					 btnProductSearch->Visible = false;
					 txtProductSearchResults->Visible = false;

					 // disable and clear controls
					 txtProdID->Enabled = false;
					 txtProdID->Text = "";
					 txtProductName->Enabled = false;
					 txtProductName->Text = "";
					 cmbProductCategorySelect->Enabled = false;
					 // clear combobox
					 cmbProductCategorySelect->Items->Clear();

					 // currentRow string
					 System::String ^ currentRow;

					 // vector to contain the category file contents
					 vector<string> categoriesFile;
					 // retrieve vector containing contents of category file
					 categoriesFile = returnFile("textFiles/category.txt");

					 // insert contents of category file into combobox
					 for(int i = 0; i < categoriesFile.size(); i++)
					 {
						 currentRow = gcnew String (categoriesFile[i].c_str());
						 cmbProductCategorySelect->Items->Add(currentRow);
					 }
					 txtProductDescription->Enabled = false;
					 txtProductDescription->Text = "";
					 txtProductPrice->Enabled = false;
					 txtProductPrice->Text = "";
					 btnProductModify->Enabled = false;

					 // populate product selection drop down list
					 cmbProductSelect->Items->Clear();

					 // vector to contain the category file contents
					 vector<string> productFile;
					 // retrieve vector containing contents of category file
					 productFile = returnFile("textFiles/product.txt");

					 // insert contents of category file into combobox
					 for(int i = 0; i < productFile.size(); i++)
					 {
						 currentRow = gcnew String (productFile[i].c_str());
						 cmbProductSelect->Items->Add(currentRow);
					 }
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
					 lblProductSearchBy->Visible = false;
					 cmbProductSearch->Visible = false;
					 lblProductSearchInfo->Visible = false;
					 txtProductSearch->Visible = false;
					 btnProductSearch->Visible = false;
					 txtProductSearchResults->Visible = false;

					 // disable delete button
					 btnProductDelete->Enabled = false;

					 // clear combobox
					 cmbProductSelect->Items->Clear();

					 // currentRow string
					 System::String ^ currentRow;

					 // vector to contain the category file contents
					 vector<string> productFile;
					 // retrieve vector containing contents of category file
					 productFile = returnFile("textFiles/product.txt");

					 // insert contents of category file into combobox
					 for(int i = 0; i < productFile.size(); i++)
					 {
						 currentRow = gcnew String (productFile[i].c_str());
						 cmbProductSelect->Items->Add(currentRow);
					 }
				 } else if(cmbProductFunction->SelectedIndex == 3)
				 {
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
					 lblProductSearchBy->Visible = true;
					 cmbProductSearch->Visible = true;
					 lblProductSearchInfo->Visible = true;
					 txtProductSearch->Visible = true;
					 btnProductSearch->Visible = true;
					 txtProductSearchResults->Visible = true;
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

			 /// \brief Exit button in the "File" menu closes the application
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }

			 /// \brief Selection in the category selector changed
			 ///
			 /// When a selection is made the necessary components are made available to the user
	private: System::Void cmbCategorySelect_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 // enable textboxes and modify button
				 txtCategoryName->Enabled = true;
				 txtCategoryDescription->Enabled = true;
				 btnCategoryModify->Enabled = true;
				 btnCategoryDelete->Enabled = true;

				 // string containing contents of the selection in the combobox
				 System::String^ category = cmbCategorySelect->SelectedItem->ToString();

				 // position of delimiter one
				 int delimiter1 = category->IndexOf("|");
				 //position of delimiter two
				 int delimiter2 = category->IndexOf("|", delimiter1 + 1);

				 // string containing name from the combobox
				 System::String ^ name = category->Substring(delimiter2 + 1);

				 // placing name string into textbox
				 txtCategoryName->Text = name;

				 // string containing description from the combobox
				 System::String ^ description = category->Substring(delimiter1 + 1, delimiter2 - delimiter1 - 1);

				 // placing description string into textbox
				 txtCategoryDescription->Text = description;

			 }

			 /// \brief Modify button on the category tab is pressed - performs modify function
	private: System::Void btnCategoryModify_Click(System::Object^  sender, System::EventArgs^  e) {
				 // create instance of Category()
				 Table cat = new Category();

				 // string for contents of selction in drop box
				 System::String^ category = cmbCategorySelect->SelectedItem->ToString();
				 // position of first delimiter
				 int delimiter1 = category->IndexOf("|");

				 // string for category ID
				 System::String ^ categoryID = category->Substring(0,delimiter1);

				 // convert System::String to std::string
				 string categoryIDstring(marshal_as<std::string>(categoryID));
				 string categoryNameString(marshal_as<std::string>(txtCategoryName->Text->ToString()));
				 string categoryDescriptionString(marshal_as<std::string>(txtCategoryDescription->Text->ToString()));

				 // perform category::modify function
				 cat->modifyRow(categoryIDstring,"name",categoryNameString);
				 // perform category::modify function
				 cat->modifyRow(categoryIDstring,"description",categoryDescriptionString);

				 // clear text boxes
				 txtCategoryDescription->Text = "";
				 txtCategoryName->Text = "";

				 // clear combobox
				 cmbCategorySelect->Items->Clear();

				 // currentRow string
				 System::String ^ currentRow;

				 // vector to contain the category file contents
				 vector<string> categoriesFile;
				 // retrieve vector containing contents of category file
				 categoriesFile = returnFile("textFiles/category.txt");

				 // insert contents of category file into combobox
				 for(int i = 0; i < categoriesFile.size(); i++)
				 {
					 currentRow = gcnew String (categoriesFile[i].c_str());
					 cmbCategorySelect->Items->Add(currentRow);
				 }

				 // disable textboxes and modify button
				 txtCategoryName->Enabled = false;
				 txtCategoryDescription->Enabled = false;
				 btnCategoryModify->Enabled = false;

				 // delete instance of category
				 delete cat;
			 }

			 /// \brief Add button on the category tab is pressed - performs add function
	private: System::Void btnCategoryAdd_Click(System::Object^  sender, System::EventArgs^  e) {
				 // create instance of Category()
				 Table cat = new Category();

				 // retrieves category name from the textbox, converts it from System::String^ to std::string and stores it in categoryNameString
				 string categoryNameString(marshal_as<std::string>(txtCategoryName->Text->ToString()));

				 // retrieves category description from the textbox, converts it from System::String^ to std::string and stores it in categoryDescriptionString
				 string categoryDescriptionString(marshal_as<std::string>(txtCategoryDescription->Text->ToString()));

				 // vector to store the name and description for Category::Add
				 vector<string> catVect;

				 // adds description to catVect
				 catVect.push_back(categoryDescriptionString);

				 // adds name to catVect
				 catVect.push_back(categoryNameString);

				 // calls the Category::Add function with the vector parameter
				 cat->add(catVect);

				 // delete instance of category
				 delete cat;

				 // clear text boxes
				 txtCategoryDescription->Text = "";
				 txtCategoryName->Text = "";
			 }

			 /// \brief Delete button on the category tab is pressed - performs delete function after confirming
			 /// that user wishes to delete
	private: System::Void btnCategoryDelete_Click(System::Object^  sender, System::EventArgs^  e) {

				 if(MessageBox::Show("Are you sure you wish to delete the selected category?", "InSys", MessageBoxButtons::YesNo,MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				 {
					 // create instance of Category()
					 Table cat = new Category();

					 // string for contents of selction in drop box
					 System::String^ category = cmbCategorySelect->SelectedItem->ToString();
					 // position of first delimiter
					 int delimiter1 = category->IndexOf("|");

					 // string for category ID
					 System::String ^ categoryID = category->Substring(0,delimiter1);

					 // convert System::String to std::string
					 string categoryIDstring(marshal_as<std::string>(categoryID));

					 // call Category Delete function
					 cat->deleteRow(categoryIDstring);

					 // delete instance of category
					 delete cat;

					 // clear combobox
					 cmbCategorySelect->Items->Clear();

					 // currentRow string
					 System::String ^ currentRow;

					 // vector to contain the category file contents
					 vector<string> categoriesFile;
					 // retrieve vector containing contents of category file
					 categoriesFile = returnFile("textFiles/category.txt");

					 // insert contents of category file into combobox
					 for(int i = 0; i < categoriesFile.size(); i++)
					 {
						 currentRow = gcnew String (categoriesFile[i].c_str());
						 cmbCategorySelect->Items->Add(currentRow);
					 }
				 }
			 }

			 /// \brief Selection in the category search by selector changed
			 ///
			 /// When a selection is made the necessary components are made available to the user
	private: System::Void cmbCategorySearchBy_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 // enable textbox and button
				 txtCategorySearch->Enabled = true;
				 btnCategorySearch->Enabled = true;
				 txtCategorySearchResults->Text = "";
				 txtCategorySearch->Text = "";
			 }

			 /// \brief Search button on the category tab is pressed - performs search function
	private: System::Void btnCategorySearch_Click(System::Object^  sender, System::EventArgs^  e) {
				 try{
					 Table cat = new Category();
					 string resultOfSearch;
					 if(cmbCategorySearchBy->SelectedIndex == 0)
					 {
						 resultOfSearch = cat->search("category_id",marshal_as<std::string>(txtCategorySearch->Text->ToString()));
					 } else if(cmbCategorySearchBy->SelectedIndex == 1)
					 {
						 resultOfSearch = cat->search("name",marshal_as<std::string>(txtCategorySearch->Text->ToString()));
					 } else if(cmbCategorySearchBy->SelectedIndex == 2)
					 {
						 resultOfSearch = cat->search("description",marshal_as<std::string>(txtCategorySearch->Text->ToString()));
					 }
					 delete cat;

					 System::String^ results = gcnew String (resultOfSearch.c_str());

					 txtCategorySearchResults->Text = results;

				 } catch (DoesNotExistException e)
				 {
					 MessageBox::Show("Search parameters did not return any results", "InSys", MessageBoxButtons::OK,MessageBoxIcon::Information);
					 txtCategorySearchResults->Text = "";
					 txtCategorySearch->Text = "";
				 } catch(Exception^ e) {
					 MessageBox::Show("An unknown error has occured: " + e->Message, "InSys", MessageBoxButtons::OK,MessageBoxIcon::Error);
				 }
			 }

			 /// \brief Add button on the product tab is pressed - performs add function
	private: System::Void btnProductAdd_Click(System::Object^  sender, System::EventArgs^  e) {
				 try{
					 if(txtProdID->Text->Length == 0)
					 {
						 MessageBox::Show("Please Enter a Product ID", "InSys", MessageBoxButtons::OK,MessageBoxIcon::Error);
					 } else {
						 Table prod = new Product();

						 // retrieves product id from the textbox, converts it from System::String^ to std::string and stores it in productIDString
						 string productIDString(marshal_as<std::string>(txtProdID->Text->ToString()));
						 // retrieves product name from the textbox, converts it from System::String^ to std::string and stores it in productNameString
						 string productNameString(marshal_as<std::string>(txtProductName->Text->ToString()));
						 // retrieves product description from the textbox, converts it from System::String^ to std::string and stores it in productDescriptionString
						 string productDescriptionString(marshal_as<std::string>(txtProductDescription->Text->ToString()));
						 // retrieves product price from the textbox, converts it from System::String^ to std::string and stores it in productPriceString
						 string productPriceString(marshal_as<std::string>(txtProductPrice->Text->ToString()));

						 // string for contents of selction in drop box
						 System::String^ category = cmbProductCategorySelect->SelectedItem->ToString();
						 // position of first delimiter
						 int delimiter1 = category->IndexOf("|");

						 // string for category ID
						 System::String ^ categoryID = category->Substring(0,delimiter1);

						 // convert System::String to std::string
						 string categoryIDstring(marshal_as<std::string>(categoryID));

						 // vector to use for the add function parameter
						 vector<string> prodVect;

						 // add the product information to the vector
						 prodVect.push_back(productIDString);
						 prodVect.push_back(categoryIDstring);
						 prodVect.push_back(productDescriptionString);
						 prodVect.push_back(productNameString);
						 prodVect.push_back(productPriceString);

						 prod->add(prodVect);

						 delete prod;

						 // clear combobox
						 cmbProductCategorySelect->Items->Clear();

						 // currentRow string
						 System::String ^ currentRow;

						 // vector to contain the category file contents
						 vector<string> categoriesFile;
						 // retrieve vector containing contents of category file
						 categoriesFile = returnFile("textFiles/category.txt");

						 // insert contents of category file into combobox
						 for(int i = 0; i < categoriesFile.size(); i++)
						 {
							 currentRow = gcnew String (categoriesFile[i].c_str());
							 cmbProductCategorySelect->Items->Add(currentRow);
						 }

						 txtProdID->Text = "";
						 txtProductName->Text = "";
						 txtProductDescription->Text = "";
						 txtProductPrice->Text = "";
						 btnProductAdd->Enabled = false;
					 }
				 } catch(AlreadyExistsException e)
				 {
					 MessageBox::Show("Product ID already exists\r\nPlease enter a new Product ID", "InSys", MessageBoxButtons::OK,MessageBoxIcon::Exclamation);
				 } catch(Exception^ e)
				 {
					 MessageBox::Show("An unknown error has occured: " + e->Message, "InSys", MessageBoxButtons::OK,MessageBoxIcon::Error);
				 }
			 }

			 /// \brief Selection in the product category selector changed
			 ///
			 /// When a selection is made the necessary components are made available to the user
	private: System::Void cmbProductCategorySelect_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 btnProductAdd->Enabled = true;
			 }
			 
			 /// \brief Search button on the product tab is pressed - performs search function
	private: System::Void btnProductSearch_Click(System::Object^  sender, System::EventArgs^  e) {
				 try{
					 Table prod = new Product();
					 string resultOfSearch;
					 if(cmbProductSearch->SelectedIndex == 0)
					 {
						 resultOfSearch = prod->search("product_id",marshal_as<std::string>(txtProductSearch->Text->ToString()));
					 } else if(cmbProductSearch->SelectedIndex == 1)
					 {
						 resultOfSearch = prod->search("category_id",marshal_as<std::string>(txtProductSearch->Text->ToString()));
					 } else if(cmbProductSearch->SelectedIndex == 2)
					 {
						 resultOfSearch = prod->search("name",marshal_as<std::string>(txtProductSearch->Text->ToString()));
					 } else if(cmbProductSearch->SelectedIndex == 3)
					 {
						 resultOfSearch = prod->search("description",marshal_as<std::string>(txtProductSearch->Text->ToString()));
					 } else if(cmbProductSearch->SelectedIndex == 4)
					 {
						 resultOfSearch = prod->search("price",marshal_as<std::string>(txtProductSearch->Text->ToString()));
					 }
					 delete prod;

					 System::String^ results = gcnew String (resultOfSearch.c_str());

					 txtProductSearchResults->Text = results;

				 } catch (DoesNotExistException e)
				 {
					 MessageBox::Show("Search parameters did not return any results", "InSys", MessageBoxButtons::OK,MessageBoxIcon::Information);
					 txtProductSearchResults->Text = "";
					 txtProductSearch->Text = "";
				 } catch(Exception^ e) {
					 MessageBox::Show("An unknown error has occured: " + e->Message, "InSys", MessageBoxButtons::OK,MessageBoxIcon::Error);
				 }
			 }

			 /// \brief Selection in the product search by selector changed
			 ///
			 /// When a selection is made the necessary components are made available to the user
	private: System::Void cmbProductSearch_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 txtProductSearchResults->Text = "";
				 txtProductSearch->Text = "";
			 }

			 /// \brief Selection in the product selector changed
			 ///
			 /// When a selection is made the necessary components are made available to the user
			 /// and the data for the selected product is filled into the appropriate components
	private: System::Void cmbProductSelect_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 // Enable components for modify function
				 txtProductName->Enabled = true;
				 txtProductDescription->Enabled = true;
				 txtProductPrice->Enabled = true;
				 btnProductModify->Enabled = true;
				 cmbProductCategorySelect->Enabled = true;

				 // Enable button for delete
				 btnProductDelete->Enabled = true;

				 // string containing contents of the selection in the combobox
				 System::String^ product = cmbProductSelect->SelectedItem->ToString();

				 // position of delimiter one
				 int delimiter1 = product->IndexOf("|");
				 //position of delimiter two
				 int delimiter2 = product->IndexOf("|", delimiter1 + 1);
				 //position of delimiter three
				 int delimiter3 = product->IndexOf("|", delimiter2 + 1);
				 //position of delimiter four
				 int delimiter4 = product->IndexOf("|", delimiter3 + 1);

				 // string containing name from the combobox
				 System::String ^ prodID = product->Substring(0,delimiter1);

				 // placing prodID string into textbox
				 txtProdID->Text = prodID;

				 // string containing categoryID from the combobox
				 System::String ^ categoryID = product->Substring(delimiter1 + 1, delimiter2 - delimiter1 - 1);

				 try{
					 Table cat = new Category();
					 string categoryResult = cat->search("category_id",marshal_as<std::string>(categoryID));
					 System::String^ categoryResultString = gcnew String(categoryResult.c_str());
					 cmbProductCategorySelect->SelectedItem = categoryResultString;
				 } catch(DoesNotExistException e){
					 MessageBox::Show("Category does not exist, /r/nPlease select a new category", "InSys", MessageBoxButtons::OK,MessageBoxIcon::Information);
				 } catch (...) {
					 MessageBox::Show("An unknown error has occured", "InSys", MessageBoxButtons::OK,MessageBoxIcon::Error);
				 }

				 // string containing product description from the combobox
				 System::String ^ description = product->Substring(delimiter2 + 1, delimiter3 - delimiter2 - 1);

				 // placing description string into textbox
				 txtProductDescription->Text = description;

				 // string containing product name from the combobox
				 System::String ^ name = product->Substring(delimiter3 + 1, delimiter4 - delimiter3 - 1);

				 // placing description string into textbox
				 txtProductName->Text = name;

				 // string containing product price from the combobox
				 System::String ^ price = product->Substring(delimiter4 + 1);

				 // placing description string into textbox
				 txtProductPrice->Text = price;
			 }

			 /// \brief Modify button on the product tab is pressed - performs modify function
	private: System::Void btnProductModify_Click(System::Object^  sender, System::EventArgs^  e) {
				 // string for contents of selction in drop box
				 System::String^ category = cmbProductCategorySelect->SelectedItem->ToString();
				 // position of first delimiter
				 int delimiter1 = category->IndexOf("|");

				 // string for category ID
				 System::String ^ categoryID = category->Substring(0,delimiter1);

				 // convert System::String to std::string
				 string categoryIDstring(marshal_as<std::string>(categoryID));

				 Table prod = new Product();

				 // perform product modify function for product category id
				 prod->modifyRow(marshal_as<std::string>(txtProdID->Text->ToString()),"categoryID", categoryIDstring);

				 // perform product modify function for product name
				 prod->modifyRow(marshal_as<std::string>(txtProdID->Text->ToString()),"name",
					 marshal_as<std::string>(txtProductName->Text->ToString()));

				 // perform product modify function for product description
				 prod->modifyRow(marshal_as<std::string>(txtProdID->Text->ToString()),"description",
					 marshal_as<std::string>(txtProductDescription->Text->ToString()));

				 // perform product modify function for product price
				 prod->modifyRow(marshal_as<std::string>(txtProdID->Text->ToString()),"price",
					 marshal_as<std::string>(txtProductPrice->Text->ToString()));

				 delete prod;

				 // disable and clear components for modify function
				 txtProdID->Text = "";
				 txtProductName->Enabled = false;
				 txtProductName->Text = "";
				 txtProductDescription->Enabled = false;
				 txtProductDescription->Text = "";
				 txtProductPrice->Enabled = false;
				 txtProductPrice->Text = "";
				 btnProductModify->Enabled = false;
				 cmbProductCategorySelect->Enabled = false;
				 // clear combobox
				 cmbProductCategorySelect->Items->Clear();

				 // currentRow string
				 System::String ^ currentRow;

				 // vector to contain the category file contents
				 vector<string> categoriesFile;
				 // retrieve vector containing contents of category file
				 categoriesFile = returnFile("textFiles/category.txt");

				 // insert contents of category file into combobox
				 for(int i = 0; i < categoriesFile.size(); i++)
				 {
					 currentRow = gcnew String (categoriesFile[i].c_str());
					 cmbProductCategorySelect->Items->Add(currentRow);
				 }

				 // populate product selection drop down list
				 cmbProductSelect->Items->Clear();

				 // vector to contain the category file contents
				 vector<string> productFile;
				 // retrieve vector containing contents of category file
				 productFile = returnFile("textFiles/product.txt");

				 // insert contents of category file into combobox
				 for(int i = 0; i < productFile.size(); i++)
				 {
					 currentRow = gcnew String (productFile[i].c_str());
					 cmbProductSelect->Items->Add(currentRow);
				 }
			 }

			 /// \brief Delete button on the product tab is pressed - performs delete function
	private: System::Void btnProductDelete_Click(System::Object^  sender, System::EventArgs^  e) {

				 if(MessageBox::Show("Are you sure you wish to delete the selected product?", "InSys", MessageBoxButtons::YesNo,MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				 {
					 // create instance of Category()
					 Table prod = new Product();

					 // string for contents of selction in drop box
					 System::String^ product = cmbProductSelect->SelectedItem->ToString();
					 // position of first delimiter
					 int delimiter1 = product->IndexOf("|");

					 // string for category ID
					 System::String ^ prodID = product->Substring(0,delimiter1);

					 // convert System::String to std::string
					 string productIDString(marshal_as<std::string>(prodID));

					 // call Category Delete function
					 prod->deleteRow(productIDString);

					 // delete instance of category
					 delete prod;


					 // disable button for delete
					 btnProductDelete->Enabled = false;

					 // clear combobox
					 cmbProductSelect->Items->Clear();

					 // currentRow string
					 System::String ^ currentRow;

					 // vector to contain the category file contents
					 vector<string> productFile;
					 // retrieve vector containing contents of category file
					 productFile = returnFile("textFiles/product.txt");

					 // insert contents of category file into combobox
					 for(int i = 0; i < productFile.size(); i++)
					 {
						 currentRow = gcnew String (productFile[i].c_str());
						 cmbProductSelect->Items->Add(currentRow);
					 }
				 }
			 }

	};
}
