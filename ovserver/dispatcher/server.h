#ifndef _SERVER_H
#define _SERVER_H

#include <cstdint>

enum
{
    WXA = 0,
    WXGH,
    WXPYQ
};


class Server {
public:
    void Register(uint8_t _msgtype);
private:
};


#endif // server