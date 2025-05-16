#include <iostream>
#include <vector>
using namespace std;
class vech
{
public:
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
};
class car : public vech
{
public:
    void startEngine()
    {
        cout << "Start car" << endl;
    }
    void stopEngine()
    {
        cout << "Stop car" << endl;
    }
};
class bike : public vech
{
public:
    void startEngine()
    {
        cout << "Start bike" << endl;
    }
    void stopEngine()
    {
        cout << "Stop bike" << endl;
    }
};
int main()
{
    vech *vc;
    bike bk;
    car cr;
    vc = &bk;
    vc->startEngine();
    vc->stopEngine();
    vc = &cr;
    vc->startEngine();
    vc->stopEngine();
}