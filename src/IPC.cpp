#include "IPC.hpp"

IPC::IPC(char *wname, char *rname, int rbufsize)
    : wname(wname), rname(rname), rbufsize(rbufsize) {
    mkfifo(this->wname, 0666);
    mkfifo(this->rname, 0666);
    //if ((this->_wfp = fopen(this->wName, "w")) == NULL) {
    //    umask(0);
    //    mknod(this->wName, S_IFIFO|0666, 0);
    //    this->_wfp = fopen(this->wName, "w");
    //}
    //if ((this->_rfp = fopen(this->rName, "r")) == NULL) {
    //    umask(0);
    //    mknod(this->rName, S_IFIFO|0666, 0);
    //    this->_rfp = fopen(this->rName, "r");
    //}
}

IPC::~IPC() {
    close(this->_wf);  // fclose(this->_wf);
    close(this->_rf);  // fclose(this->_rf);
}

int IPC::writer(char *msg) {
    // fputs(message, this->_wfp);
    size_t len = sizeof(msg);
    char msgbuf[len];
    while (1) {
        this->_wf = open(this->wname, O_WRONLY);
        write(this->_wf, msgbuf, snprintf(msgbuf, len, msg));
        close(this->_wf);
        usleep(this->_timeout);
    }
}

int IPC::reader() {
    size_t len;
    char buf[this->rbufsize];
    while (1) {
        this->_rf = open(this->rname, O_RDONLY);
        len = read(this->_rf, buf, this->rbufsize);
        printf(buf);
        close(this->_rf);
    }

    return 0;
}
