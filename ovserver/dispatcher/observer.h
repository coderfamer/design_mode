#pragma onece

#include <unordered_map>
#include <functional>
#include <memory>
#include <set>

class Subject
{
public:
    virtual ~Subject() {}
    virtual void Update() {}

};

struct Subinfo
{
    std::function<void(const unsigned char *data, int len)> func;
    std::shared_ptr<Subject> sub;
};

class ObServer
{
    using Sub = std::shared_ptr<Subject>;
    using Func = std::function<void(const unsigned char *, int len)>;

public:
    virtual ~ObServer() {}
public:
    /*
    * 被观察者注册接口
    */
    virtual void Reg(Sub _sub) {
        obsubs_.emplace(_sub);
    }

    virtual void Notify() {
        for (auto & sub : obsubs_) {
            sub->Update();
        }
    }

public:
    /*
    * 被观察者注册接口，自由定制触发调用接口
    */
    virtual void Reg(unsigned int _id, Sub  _sub, Func _func) {
        subs_[_id].func = _func;
        subs_[_id].sub = _sub;
    }

    virtual void Notify(uint _id, const unsigned char * _data, int _len) {
        auto iter = subs_.find(_id);
        if (iter != subs_.end()) {
            subs_[_id].func(_data, _len);
        }
    }

private:
    std::unordered_map<unsigned int, Subinfo> subs_;
    std::set<Sub> obsubs_;
};