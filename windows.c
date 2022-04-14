#define MAX_STRING_LEN 128 // Can be removed later
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#endif

int createWindow (char *argv[]) {
	#ifdef _WIN32
	#define BUTTONSCONST (!strcmp(argv[3], "1") ? MB_ABORTRETRYIGNORE : (!strcmp(argv[3], "2") ? MB_CANCELTRYCONTINUE : (!strcmp(argv[3], "3") ? MB_HELP : (!strcmp(argv[3], "4") ? MB_OK : (!strcmp(argv[3], "5") ? MB_OKCANCEL : (!strcmp(argv[3], "6") ? MB_RETRYCANCEL : (!strcmp(argv[3], "7") ? MB_YESNO : MB_YESNOCANCEL)))))))
	#define ICONCONST (!strcmp(argv[4], "1") ? MB_ICONINFORMATION : (!strcmp(argv[4], "2") ? MB_ICONWARNING : (!strcmp(argv[4], "3") ? MB_ICONQUESTION : MB_ICONERROR)))
	printf("%i", argv[4] == "1");
	int msgboxID = MessageBox(
		NULL,
		(LPCSTR)argv[2],
		(LPCSTR)argv[1],
		ICONCONST | BUTTONSCONST | MB_DEFBUTTON1
	);
	return msgboxID;
	#elif __APPLE__
	#define BUTTONSCONST (!strcmp(argv[3], "1") ? "\"Cancel\", \"Try Again\", \"Continue\"" : (!strcmp(argv[3], "2") ? "\"Cancel\", \"Try Again\", \"Continue\"" : (!strcmp(argv[3], "3") ? "\"Help\"" : (!strcmp(argv[3], "4") ? "\"Ok\"" : (!strcmp(argv[3], "5") ? "\"Ok\", \"Cancel\"" : (!strcmp(argv[3], "6") ? "\"Try Again\", \"Cancel\"" : (!strcmp(argv[3], "7") ? "\"Yes\", \"No\"" : "\"Yes\", \"No\", \"Cancel\"")))))))
	#define ICONCONST (!strcmp(argv[4], "1") ? "with icon note" : (!strcmp(argv[4], "2") ? "with icon caution" : (!strcmp(argv[4], "3") ? "" : "with icon stop")))
	char command[999]; 
	sprintf(command, "osascript -e 'display dialog \"%s\" message \"%s\" buttons {%s} %s'", argv[1], argv[2], BUTTONSCONST, ICONCONST);
	system(command);
	#elif linux
	#define BUTTONSCONST (!strcmp(argv[3], "1") ? "--ok-label 'Cancel' --extra-button 'Try Again' --extra-button 'Continue'" : (!strcmp(argv[3], "2") ? "--ok-label 'Cancel' --extra-button 'Try Again' --extra-button 'Continue'" : (!strcmp(argv[3], "3") ? "--ok-label 'Help'" : (!strcmp(argv[3], "4") ? "" : (!strcmp(argv[3], "5") ? "--extra-button 'Cancel'" : (!strcmp(argv[3], "6") ? "--ok-label 'Try Again' --extra-button 'Cancel'" : (!strcmp(argv[3], "7") ? "--ok-label 'Yes' --extra-button 'No'" : "--ok-label 'Yes' --extra-button 'No' --extra-button 'Cancel'")))))))
	#define ICONCONST (!strcmp(argv[4], "1") ? "--info" : (!strcmp(argv[4], "2") ? "--warning" : (!strcmp(argv[4], "3") ? "--question" : "--error")))
	char command[MAX_STRING_LEN];
	sprintf(command, "window=$(zenity --title '%s' --text '%s' %s %s)", argv[1], argv[2], BUTTONSCONST, ICONCONST);
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