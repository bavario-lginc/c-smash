#define MAX_STRING_LEN 128 // Can be removed later
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#endif

int createWindow (char *argv[], char *buttons[]) {
	#ifdef _WIN32
	#define BUTTONSCONST MB_YESNOCANCEL // Can not be changed
	#define ICONCONST (!strcmp(argv[3], "1") ? MB_ICONINFORMATION : (!strcmp(argv[3], "2") ? MB_ICONWARNING : (!strcmp(argv[3], "3") ? MB_ICONQUESTION : MB_ICONERROR)))
	int msgboxID = MessageBox(
		NULL,
		(LPCSTR)argv[2],
		(LPCSTR)argv[1],
		ICONCONST | BUTTONSCONST | MB_DEFBUTTON1
	);
	return msgboxID;
	#elif __APPLE__
	#define ICONCONST (!strcmp(argv[3], "1") ? "with icon note" : (!strcmp(argv[3], "2") ? "with icon caution" : (!strcmp(argv[3], "3") ? "" : "with icon stop")))
	char unrolledButtons[MAX_STRING_LEN];
	sprintf(unrolledButtons, "\"%s\"", buttons[0]);
	for (int i = 1; i <= sizeof(buttons); i++) {
		strcat(unrolledButtons, ", \"");
		strcat(unrolledButtons, buttons[i]);
		strcat(unrolledButtons, "\"");
	}
	char command[999];
	sprintf(command, "osascript -e 'display dialog \"%s\" message \"%s\" buttons {%s} %s'", argv[1], argv[2], unrolledButtons, ICONCONST);
	system(command);
	#elif linux
	#define ICONCONST (!strcmp(argv[3], "1") ? "--info" : (!strcmp(argv[3], "2") ? "--warning" : (!strcmp(argv[3], "3") ? "--question" : "--error")))
	char unrolledButtons[MAX_STRING_LEN];
	int arrayLength = sizeof(buttons) / sizeof(buttons[0]);
	sprintf(unrolledButtons, "--ok-label '%s'", buttons[0]);
	for (int i = 1; i <= arrayLength; i++) {
		strcat(unrolledButtons, " --extra-button '");
		strcat(unrolledButtons, buttons[i]);
		strcat(unrolledButtons, "'");
	}
	char command[999];
	sprintf(command, "window=$(zenity --title '%s' --text '%s' %s %s)", argv[1], argv[2], unrolledButtons, ICONCONST);
	system(command);
	#endif
}

	
int createToast (char *argv[]) {
	#ifdef _WIN32
	#define ICONCONST_T (!strcmp(argv[3], "1") ? "Information" : (!strcmp(argv[3], "2") ? "Warning" : (!strcmp(argv[3], "3") ? "Question" : "Error")))
	// system("start powershell.exe Set-ExecutionPolicy RemoteSigned");
	char pscommand[999];
	sprintf(pscommand, "[reflection.assembly]::loadwithpartialname(\"System.Windows.Forms\")\n\
		[reflection.assembly]::loadwithpartialname(\"System.Drawing\")\n\
		$notify = new-object system.windows.forms.notifyicon\n\
		$notify.icon = [System.Drawing.SystemIcons]::%s\n\
		$notify.visible = $true\n\
		$notify.showballoontip(10,\"%s\",\"%s\",[system.windows.forms.tooltipicon]::None)\n",
		ICONCONST_T,
		argv[1],
		argv[2]);
	FILE *powershell = fopen("toastscript.ps1", "w");
	fputs(pscommand, powershell);
	fclose(powershell);
	system("start /B powershell.exe ./toastscript.ps1");
	Sleep(500);
	remove("toastscript.ps1");
	#elif __APPLE__
	char command[999];
	sprintf(command, "display notification \"%s\" with title \"%s\"", argv[2], argv[1]);
	printf("%s", command);
	#endif
}

/*int main () {
	char *test[] = {"", "Test", "ABC", "4", "4"};
	createToast(test);
	// createWindow(test);
}*/
