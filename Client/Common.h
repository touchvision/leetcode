#ifndef  CHATROOM_COMMON_H
#define CHATROOM_COMMON_H
 
#include <iostream>
#include <list>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Ĭ�Ϸ�������IP��ַ
#define SERVER_IP "127.0.0.1"
 
// �������˿ں�
#define SERVER_PORT 8888
 
// int epoll_create(int size)�е�size
// Ϊepoll֧�ֵ��������
#define EPOLL_SIZE 5000
 
// ��������С65535
#define BUF_SIZE 0xFFFF
    
// ���û���¼��Ļ�ӭ��Ϣ
#define SERVER_WELCOME "Welcome you join to the chat room! Your chat ID is: Client #%d"
 
// �����û��յ���Ϣ��ǰ׺
#define SERVER_MESSAGE "ClientID %d say >> %s"
#define SERVER_PRIVATE_MESSAGE "Client %d say to you privately >> %s"
#define SERVER_PRIVATE_ERROR_MESSAGE "Client %d is not in the chat room yet~"
// �˳�ϵͳ
#define EXIT "EXIT"
 
// ����������������Ψһ�Ŀͻ�
#define CAUTION "There is only one int the char room!"
 
 
// ע���µ�fd��epollfd��
// ����enable_et��ʾ�Ƿ�����ETģʽ�����ΪTrue�����ã�����ʹ��LTģʽ
static void addfd( int epollfd, int fd, bool enable_et )
{
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events = EPOLLIN;
    if( enable_et )
        ev.events = EPOLLIN | EPOLLET;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
    // ����socketΪ������ģʽ
    // �׽������̷��أ�����I/O�Ƿ���ɣ��ú������ڵ��̻߳��������
    //eg. ��recv(fd...)ʱ���ú������̷��أ��ڷ���ʱ���ں����ݻ�û׼���û᷵��WSAEWOULDBLOCK�������
    fcntl(fd, F_SETFL, fcntl(fd, F_GETFD, 0)| O_NONBLOCK);
    printf("fd added to epoll!\n\n");
}
 
//������Ϣ�ṹ���ڷ���˺Ϳͻ���֮�䴫��
struct Msg
{
    int type;
    int fromID;
    int toID;
    char content[BUF_SIZE];
 
};
#endif