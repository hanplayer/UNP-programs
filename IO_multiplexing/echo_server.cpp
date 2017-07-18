/*
 *author:hfz
 *create date:2017/7/18
 *version:1.0
 */
#include "echo_server.h"
#include <inttype.h>
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
	FD_ZERO(&allset);
	FD_SET(listenfd,&allset);
}
};
