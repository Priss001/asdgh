/* –азработать консольное приложение, в котором базовый процесс порождает дочерний.
ƒл€ каждого процесса предусмотрена сво€ область вывода,
в которой он выводит текущее системное врем€. */

#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;

int main() {

	HANDLE hProcess = NULL;
	HANDLE hThread = NULL;

	STARTUPINFO stpi;
	PROCESS_INFORMATION prci;

	ZeroMemory(&stpi, sizeof(stpi));
	ZeroMemory(&prci, sizeof(prci));

	BOOL bCreateProcess = NULL;

	bCreateProcess = CreateProcess(
		(LPCSTR)"D:\\LAB_1_WIN\\LAB_1_WIN\\Debug\\Child.exe",
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&stpi,
		&prci);

	if (!bCreateProcess)
	{
		cout << "Create process Failed & Error No - " << GetLastError() << endl;
	}
	cout << "Create parent process sucess" << endl;

	SYSTEMTIME st;
	GetLocalTime(&st);
	cout << "Time in the parent process: " << endl;
	printf("%d-%02d-%02d %02d:%02d:%02d.%03d",
		st.wYear,
		st.wMonth,
		st.wDay,
		st.wHour,
		st.wMinute,
		st.wSecond,
		st.wMilliseconds);
	cout << endl;
	WaitForSingleObject(prci.hProcess, INFINITE);

	CloseHandle(prci.hProcess);
	CloseHandle(prci.hThread);

	TerminateProcess(prci.hProcess, NO_ERROR);

	return 0;
}