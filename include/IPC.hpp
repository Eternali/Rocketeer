#pragma once

// #include <cstdlib>
#include <stdio.h>
// #include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include <fcntl.h>
#include <limits.h>
#include <pthread.h>

// #include <iostream>
// #include <linux/stat.h>

#include "settings.hpp"

class IPC {
public:
    IPC(char *wname, char *rname, int rbufsize = 64);
    ~IPC();
    int writer(char *msg);
    int reader();
    
    char *wname;
    char *rname;
    int rbufsize;
private:
    int _wf;
    int _rf;

    int _timeout = 10000;
};
