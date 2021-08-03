#include <iostream>
#include <functional>
#include <vector>

class A
{
public:
    void func() { std::cout << "A calling" << std::endl; }
};

class B
{
public:
    void fund() { std::cout << "B calling" << std::endl; }

};


int main()
{
    using func = std::function<void()>;

    std::vector<func> vec;
    A a;
    B b;
    func fna = std::bind(&A::func, &a);
    func fnb = std::bind(&B::fund, &b);
    vec.push_back(fna);
    vec.push_back(fnb);

    for (auto v : vec) {
        v();
    }

    return 0;
}