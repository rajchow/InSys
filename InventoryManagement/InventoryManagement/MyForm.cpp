#include "MyForm.h"
#include <Windows.h>


using namespace std;
using namespace InventoryManagement;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nCmdShow)
{
	Application::Run(gcnew MyForm);
	return 0;
}