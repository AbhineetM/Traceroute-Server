//
//  ServerSoc.h
//  traceroute
//
//  Created by Abhineet on 07/09/12.
//  Copyright (c) 2012 Abhineet. All rights reserved.
//

#ifndef __traceroute__ServerSoc__
#define __traceroute__ServerSoc__

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//#include "Globals.h"


using namespace std;

#define YES 1
#define NO 0
#define MAX_CONNS 100


using namespace std;
typedef enum
{
    TCP=1,
    UDP,
}PROTOCOL_FAMILY;



class Socket{
    
public:

    //ivars
    int sock_fd;
    struct sockaddr_in bindAddress;

    
    int portNumber;
    //maximum users that can connect at a time to the server
    int maximum_users;
    //this implies how many request by one user in one second
    int reqPerMinPerUser;
    int strictDestination;
    
    PROTOCOL_FAMILY protocol;
    
    pthread_t pids[MAX_CONNS];
    int totalThreads;
    int remainingConnections;

    
    
    //methods
    int bindSocket();
    static Socket* shared();
//    int createSocket(int portNo, int maxUsers, int rate, int strict_dest);
    int createSocket();
    void startServerProcess();
    void stopServerProcess();

    
     

    
    
};



#endif /* defined(__traceroute__ServerSoc__) */
