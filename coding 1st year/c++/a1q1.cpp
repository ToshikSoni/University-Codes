#include <iostream>
#include <string>

class Vehicle
{
public:
    Vehicle(std::string make, std::string model, int year)
        : make_(make), model_(model), year_(year) {}

    void virtual startEngine()
    {
        std::cout << "Vehicle engine has started." << std::endl;
    }

    void virtual stopEngine()
    {
        std::cout << "Vehicle engine has stopped." << std::endl;
    }

protected:
    std::string make_;
    std::string model_;
    int year_;
};

class Car : public Vehicle
{
public:
    Car(std::string make, std::string model, int year, int numDoors, float engineCapacity)
        : Vehicle(make, model, year), numDoors_(numDoors), engineCapacity_(engineCapacity) {}

    void startEngine() override
    {
        Vehicle::startEngine();
        std::cout << "Car engine has started." << std::endl;
    }

    void stopEngine() override
    {
        Vehicle::stopEngine();
        std::cout << "Car engine has stopped." << std::endl;
    }

    void honkHorn()
    {
        std::cout << "Horn has been honked." << std::endl;
    }

private:
    int numDoors_;
    float engineCapacity_;
};

int main()
{
    Vehicle v("Honda", "Civic", 2020);
    v.startEngine();
    v.stopEngine();

    Car c("Toyota", "Camry", 2022, 4, 2.5);
    c.startEngine();
    c.honkHorn();
    c.stopEngine();

    return 0;
}
