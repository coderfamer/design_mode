#include "server.h"

#include <iostream>

void Server::Reg(int _msgtype, std::shared_ptr<Subject>  _sub,
 std::function<void(const unsigned char *, int)> _func)
{
    subjects_.emplace(_sub);
    sub_notify_[_msgtype] = _func;
}


void Server::Notify()
{
    const unsigned char *data = (const unsigned char *)"hello observer";
    uint8_t len = 20;
    for (auto sub : sub_notify_) {
        if (sub.second) {
            sub.second(data, len);
        }
    }
}


void Server::Notify(int _type)
{
    const unsigned char *data = (const unsigned char *)"hello observer";
    uint8_t len = 20;
    auto iter = sub_notify_.find(_type);
    if (iter != sub_notify_.end()) {
        (iter->second)(data, len);
        // std::cout << iter->first << std::endl;
        // (sub_notify_[_type])(data, len);
    }
}