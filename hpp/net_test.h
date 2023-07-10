//
// Created by xuniji on 2023/6/30.
//

#ifndef UNTITLED3_NET_TEST_H
#define UNTITLED3_NET_TEST_H

#endif //UNTITLED3_NET_TEST_H

#include <sys/unistd.h>
#include <sys/types.h>

#ifdef WIN64

#include <winsock.h>

#endif
#ifdef linux
#include <sys/errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#endif

#include <istream>
#include <string>
#include <cstring>
#include <csignal>
#include <thread>

struct conf {
    int port = 8032;//端口
    int buff_size = 2 >> 10;//缓存大小
    const char *ip = "0.0.0.0";

} conf_;

namespace net {
//    void socket_test() {
//        static int sockfd = 0;
//#ifdef WIN64
//        //向Windows申请网络授权 WSAStartup 函数通过进程启动 Winsock DLL 的使用。
//        // Declare some variables
//        WSADATA wsaData;
//        // Initialize Winsock
//        int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//        switch (iResult) {
//            case WSASYSNOTREADY:
//                printf("基础网络子系统尚未准备好进行网络通信。\n");
//                break;
//            case WSAVERNOTSUPPORTED:
//                printf("此特定 Windows 套接字实现不提供请求的 Windows 套接字支持版本。\n");
//                break;
//            case WSAEINPROGRESS:
//                printf("正在执行阻止 Windows 套接字 1.1 操作。\n");
//                break;
//            case WSAEPROCLIM:
//                printf("已达到 Windows 套接字实现支持的任务数的限制。\n");
//                break;
//            case WSAEFAULT:
//                printf("lpWSAData 参数不是有效的指针。\n");
//                break;
//        }
//        if (iResult != NO_ERROR) {
//            wprintf(L"Error at WSAStartup()\n");
//            exit(-97);
//        }
//#endif
//        sockaddr_in servaddr;
//        sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//        if (sockfd == -1) {
//            printf("初始化socket对象失败");
////            WSACleanup();
//            exit(-98);
//        }
//        memset(&servaddr, 0, sizeof(servaddr));
//        servaddr.sin_family = AF_INET;
//        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
//        servaddr.sin_port = htons(conf_.port);
////        sockaddr_in servaddr = {
////                .sin_family = AF_INET,
////                .sin_addr.s_addr = htonl(INADDR_ANY),
////                .sin_port = htons(conf_.port)
////        };
//        if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == EOF) {
//            printf("绑定端口失败");
//            exit(-99);
//        }
//        if (listen(sockfd, conf_.buff_size) == -1) {
//            printf("监听端口失败");
//            exit(-100);
//        }
//        auto exit_ = [](int sig) {
//            if (sockfd != 0) {
//#ifdef linux
//                close(sockfd);
//#endif
//#ifdef WIN64
//                closesocket(sockfd);
//                WSACleanup();
//#endif
//            }
//            printf("关闭socket\n");
//            exit(sig);
//        };
//        signal(SIGINT, exit_);
//
//        void conn(int connfd);
//        while (1) {
//            int connCode = accept(sockfd, nullptr, nullptr);
//            if (connCode != -1){
//                thread ct(conn, connCode);
//                ct.detach();
//            }
////            conn(&connfd);
//        }
//    }
//
//    void socket_send_test() {
//        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
//        char buff[conf_.buff_size];
//        struct sockaddr_in servaddr;
//        servaddr.sin_family = AF_INET;
//
//        servaddr.sin_addr.s_addr = inet_addr("192.168.3.22");
//        servaddr.sin_port = htons(conf_.port);
//        int conn = connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
//        char msg[conf_.buff_size], result[conf_.buff_size];
//        scanf("%s", msg);
//        send(conn, msg, strlen(msg), 0);
//        recv(conn, result, conf_.buff_size - 1, 0);
//    }
//
//    void conn(int connfd) {
//        cout << "出现连接:" << connfd << endl;
//        if (-1 == connfd) {
//            printf("Accept error(%d): %s\n", errno, strerror(errno));
//            exit(1);
//        }
//        char *buff = (char *) malloc(conf_.buff_size);
//        while (1) {
//            memset(buff, 0, sizeof(buff));
//            if (recv(connfd, buff, conf_.buff_size - 1, 0) < 1) {
//                cout << "断开连接:" << connfd << endl;
//                free(buff);
//                return;
//            }
//            printf("收到connfd:%d,消息: %s\n", connfd, buff);
//            if (send(connfd, buff, strlen(buff), 0) <= 0) {
//                printf("断开连接");
//                free(buff);
//                return;
//            }
//        }
//    }
}