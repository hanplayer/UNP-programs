/*
 *author:hfz
 *create date:2017/7/18
 *version:1.0
 */
#ifndef __SOCK_RECORDER_H__
#define __SOCK_RECORDER_H__
#include "./unp.h"
namespace echo_server
{
class SockRecoder
{
public:
	SockRecoder(){};
	~SockRecoder(){};
        void AddStatus(int sockfd);//input parameter
        void RemoveStatus(int index);//this function needs to be provided client array index
	void Init(void);
	void SetMaxFd(int max);
	int GetMaxFd(void);
	int GetMaxIndex(void);
	void SetMaxIndex(int);

        int client[FD_SETSIZE];
        fd_set rset;
private:
	int MaxIndex;//client element is available if index less then the number
	int MaxFd;
};
};
#endif
