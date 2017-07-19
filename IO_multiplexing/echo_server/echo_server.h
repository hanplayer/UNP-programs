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
    int AddNewClient(int fd);
    int ReadAndWrite(void);

    SockRecorder recorder;
    fd_set allset;  
private:
    struct sockaddr_in servaddr;
    int listenfd;
};
};
#endif
