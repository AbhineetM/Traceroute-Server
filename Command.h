//
//  Command.h
//  traceroute
//
//  Created by Abhineet on 10/09/12.
//  Copyright (c) 2012 Abhineet. All rights reserved.
//

#ifndef __traceroute__Command__
#define __traceroute__Command__


#include <iostream>
#include <string.h>
#include "Globals.h"
#include <arpa/inet.h>
using namespace std;

class Command {
 
 public:
    char    *orignal_command;
    char    *command;
    char    *args[10];
    int     total_args;
    CommandType cmdType;
     
    

    Command(char *userInput)
    {
        
         //Make copy of orignal command
         orignal_command = (char*)malloc(1024);
         command=(char*)malloc(1024);
        
        for (int i=0,j=0; i<strlen(userInput); i++)
        {
            if(!(iscntrl(userInput[i])))
                orignal_command[j++]=userInput[i];
                
        }
             
         const char *seperator = " ";
         char *token = strtok(orignal_command, seperator);
         strcpy(command, token);
         total_args = 0;
         while( (token =  strtok(NULL,seperator))!=NULL)
         {
             args[total_args] = (char*)malloc(1024);
              args[total_args] = token;
                 total_args++;

         }
    }
};

#endif /* defined(__traceroute__Command__) */
