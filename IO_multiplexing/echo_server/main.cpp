#include "../unp.h"
#include "sock_recorder.h"
#include "echo_server.h"
#include <iostream>
#include <string>
#include <sstream>
#include <inttypes.h>
using namespace echo_server;
int main(void)
{
	int port;
	int fd;
	std::cout<<"please enter the server port:"<<std::endl;
	std::cin>>port;
	server.Init(port);
	
	while(1)
	{
		server.recorder.rset = server.allset;
		server.WaitNewClient(&(server.recorder.rset));
		fd = server.GetConnectFd();
		server.AddNewClient(fd);
		FD_SET(fd,server.allset);
		server.ReadAndWrite();
		return 0;
	}
}
