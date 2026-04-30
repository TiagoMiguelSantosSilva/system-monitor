#ifdef _WIN32
    #include <WinSock2.h> // sockets, bind, listen , accept
    #include <WS2tcpip.h> // inet_addr, sockaddr_in
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <uistd.h>
#endif