#pragma once

using namespace System;

public ref class Launcher {
private:
	String^ filePath;
	String^ category;
	String^ description;

public:

	Launcher(String^ fp, String^ ctgry, String^ desc) {
		filePath = fp;
		category = ctgry;
		description = desc;
	}

	// Method to launch the program
	void Launch()
	{
		System::Diagnostics::Process::Start(filePath);
	}

	String^ getFilePath() {
		return filePath;
	}

	property String^ Category
	{
		String^ get() { return category; }
	}
	// Property to get the description
	property String^ Description
	{
		String^ get() { return description; }
	}

};