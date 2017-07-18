/*
 *author:hfz
 *create date:2017/7/18
 *version:1.0
 */

#include "sock_recorder.h"
namespace echo_server
{
void SockRecorder::SetMaxFd(int max)
{
	MaxFd = max;
}
int SockRecorder::GetMaxFd()
{
	return MaxFd;
}
int SockRecorder::AddStatus(int sockfd)
{
	for(int i = 0; i < FD_SETSIZE;i++)
	{
		if(client[i] < 0)
		{
			client[i] = sockfd;
			return i;
		}
	}
	return -1;
}
};
