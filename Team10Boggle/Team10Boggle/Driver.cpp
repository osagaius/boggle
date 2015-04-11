#include <tchar.h>
#include "BoggleForm.h"

using namespace view;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew BoggleForm());

	return 0;
}