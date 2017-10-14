//
// Created by joe on 10/7/17.
//

#ifndef PW_AUDIOLED_UDP_H
#define PW_AUDIOLED_UDP_H
int udp_setup_socket(int port);
int SendBuffer(unsigned char *buf);
int closeSocket();
#endif //PW_AUDIOLED_UDP_H
