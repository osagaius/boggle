#include <tchar.h>
#include "BoggleForm.h"



[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew BoggleForm());

	String^ delimStr = " ,.:\t";
	Console::WriteLine("delimiter : '{0}'", delimStr);
	array<Char>^ delimiter = delimStr->ToCharArray();
	array<String^>^ words;
	String^ line = "one\ttwo three:four,five six seven";

	Console::WriteLine("text : '{0}'", line);
	words = line->Split(delimiter);
	Console::WriteLine("Number of Words : {0}", words->Length);
	for (int word = 0; word<words->Length; word++)
		Console::WriteLine("{0}", words[word]);

	return 0;
}