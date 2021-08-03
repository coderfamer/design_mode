#ifndef _SERVER_H
#define _SERVER_H

#include <cstdint>
#include <set>
#include <unordered_map>
#include <memory>
#include <functional>

#include "observer.h"

enum
{
    WXA = 0,
    WXGH,
    WXPYQ,
    WXMAX
};


class Server : public Observer
{
public:
    // void Register(uint8_t _msgtype, std::function<void(const unsigned char *, int)> func);
    void Reg(int _msgtype, std::shared_ptr<Subject>  sub,
     std::function<void(const unsigned char *, int)> func);
    void Notify(int _type);
    void Notify() override;
private:
    // 已注册对象列表
    std::set<std::shared_ptr<Subject>> subjects_;
    // 通知入口
    std::unordered_map<int, std::function<void(const unsigned char *, int)>> sub_notify_;

};


#endif // server