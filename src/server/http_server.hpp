#include <string>

class http_server
{
private:
    int port_;
    int sock_;
public:
    http_server(int port);
    ~http_server();
};


