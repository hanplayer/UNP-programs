/*
 *author:hfz
 *create date:2017/7/18
 *version:1.0
 */
#include "echo_server.h"
namespace echo_server
{
void Server::Init(uint16_t port)
{
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);
	bind(listenfd,(SA*)&servaddr,sizeof(servaddr));
	listen(listenfd,10);
	
	recorder.Init();
	recorder.SetMaxFd(listenfd);
	FD_ZERO(&allset);
	FD_SET(listenfd,&allset);
}
int Server::WaitNewClient(fd_set *p_set)
{
	return select(recorder.GetMaxFd()+1,p_set,NULL,NULL,NULL);	
}
//return file descriptor
int Server::GetConnectFd()
{
	struct sockaddr_in cliaddr;
	int length = sizeof(cliaddr);
	return accept(listenfd,(SA*)&cliaddr,&clilen);
}
int Server::AddNewClient(int fd)
{
	int index;	
	if(recorder.GetMaxFd()<fd)
	{
		recorder.SetMaxFd(fd);
	}
	index = recorder.AddStatus(fd);
	if( -1!=index && index > recorder.GetMaxIndex() )
	{
		recorder.SetMaxIndex(index);
	}
	return 0;
}

};
