#include "observer.h"

#include <iostream>
#include <functional>
#include <vector>

class Wxa : public Subject
{
public:
    ~Wxa() {
        std::cout << "bye!! Wxa" << std::endl;
    }
public:
    void Processwxa(const unsigned char *, int) { cnt_++;std::cout << std::to_string(cnt_) + ",Process wxa!!!" << std::endl;}

    void Processpeer(const unsigned char *, int) { peercnt_++;std::cout << std::to_string(peercnt_) + ",Process wxpeer!!!" << std::endl; }

private:
    uint8_t peercnt_ = 0;
    uint8_t cnt_ = 0;
};


class Wxf : public Subject 
{
public:
    ~Wxf() {
        std::cout << "bye!! Wxf" << std::endl;
    }
public:
    void ProcessWxf(const unsigned char *, int) { cnt_++;std::cout << std::to_string(cnt_) + ",Process wxf!!" << std::endl;}

private:
    uint8_t cnt_ = 0;
};


class Server : public ObServer
{
public:
    void hello();
};


int main()
{
    Server server;
    const unsigned char * data = (const unsigned char *)"dajiahao";
    int len = 20;

    std::shared_ptr<Wxa> wxa(new Wxa);
    std::shared_ptr<Wxf> wxf(new Wxf);

    server.Reg(0, wxa, std::bind(&Wxa::Processwxa, wxa, std::placeholders::_1, std::placeholders::_2));
    server.Reg(1, wxa, std::bind(&Wxa::Processpeer, wxa, std::placeholders::_1, std::placeholders::_2));
    server.Reg(2, wxa, std::bind(&Wxf::ProcessWxf, wxf, std::placeholders::_1, std::placeholders::_2));

    std::vector<int> vec = {1, 2, 0, 1, 2, 1, 0, 2, 4};

    // server.Notify();
    for (auto &v : vec) {
        server.Notify(v, data, len);
    }
    
    return 0;
}