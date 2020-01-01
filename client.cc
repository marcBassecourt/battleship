#include <iostream>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

int main()
{
	//Create a socket
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == -1)
	{
		cerr << "Can't create a socket" << endl;
		return -1;
	}
	//Create a hint structure for the server we're connecting with
	int port =54000;
	string ipAddress = "127.0.0.1";
	sockaddr_in hint;
	hint.sin_family=AF_INET;
	hint.sin_port=htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);
	
	//Connect to the server on the socket
	int connectRes=connect(sock, (sockaddr*)&hint, sizeof(hint));
	if(connectRes == -1)
	{
		cerr << "Can't connect to the server" << endl;
		return -3;
	}
	//While receiving a display message, echo message
	char buf[4096];
	string userInput;
	while(1)
	{
		//Enter lines of text
		cout << ">";
		getline(cin, userInput);
		//Send to server
		int sendRes = send(sock, userInput.c_str(), userInput.size()+1, 0);
		if(sendRes == -1)
		{
			cerr << "Message not send to the server" << endl;
			continue;
		}
		//Wait for response
		memset(buf, 0, 4096);
		int bytesRecv = recv(sock, buf, 4096, 0);
		//Display response
		cout << " SERVER reception: " << string(buf, bytesRecv) << endl;
	}
	//Close the socket
	close(sock);
	return 0;
}
