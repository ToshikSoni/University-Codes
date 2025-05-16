#include <iostream>
using namespace std;
class Base
{
public:
    void *operator new(size_t size)
    {
        void *p = ::operator new(size);
        return p;
    }
    void operator delete(void *p)
    {
        free(p);
    }
};
int main()
{
    Base *ptr = new Base();
    delete ptr;
}