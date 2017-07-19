/*
 *author:hfz
 *create date:2017/7/17
 *version:1.0
 */

/*
 *this source file is echo server.
 *this version use "select()"
 *select() needs to include <sys/select.h> <sys/time.h>
 */
#ifndef __ECHO_SERVER_H__
#define __ECHO_SERVER_H__
#include "./unp.h"
#include "sock_recorder.h"
#include <inttypes.h>
namespace echo_server
{
class Server
{
public:
	Server(){};
	~Server(){};
	void Init(uint16_t port);
	int WaitNewClient(fd_set *p_set);
	int GetConnectFd();
	int AddNewClient(int index);
	int ReadAndWrite(void);
private:
	SockRecorder recorder;
	struct sockaddr_in servaddr;
	fd_set allset;	
	int listenfd;
};
};
#endif
