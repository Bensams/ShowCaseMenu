#include "MyForm.h"

using namespace ShowCaseMenu;
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	MyForm form;
	Application::Run(% form);
}