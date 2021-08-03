#pragma onece

class Subject
{
public:

private:

};

class Observer
{
public:
    // virtual void Reg(uint8_t _msgtype, std::shared_ptr<Subject>  sub,
    //  std::function<void(const unsigned char *, int)> func) = 0;
    virtual void Notify() = 0;
private:
};