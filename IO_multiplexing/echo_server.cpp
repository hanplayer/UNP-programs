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
#include "./unp.h"
namespace echo_server
{
class SockRecoder
{
public:
	void AddStatus(int sockfd);//input parameter
	void RemoveStatus(int index);//this function needs to be provided client array index
private:
	int client[FD_SETSIZE];
	fd_set rset;
};
class Server
{
public:
	void Init(int port);
	int ChangeReadable(int connfd);
	int ChangeUnreadable(int index);
private:
	SockRecorder recorder;
};
};
