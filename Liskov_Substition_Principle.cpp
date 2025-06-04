#include <iostream>

using namespace std;

class Two_wheeler
{
public:
    virtual void turnOnEngine() = 0;
    virtual void accelerate(int n) = 0;
};


class MotorCycle:public Two_wheeler
{
public:
    void turnOnEngine()
    {
        cout << __FUNCTION__ << endl;
        cout << "Engine is On of MotorCycle" << endl;
    }
    void accelerate(int n)
    {
        cout << __FUNCTION__ << endl;
        cout << "New Acceleration = " << n+10 << endl;
    }
};

class BiCycle:public Two_wheeler
{
public:
    void turnOnEngine()
    {
        cout << __FUNCTION__ << endl;
        cout << "No Engine in Bicycle throw Error" << endl;
        throw "No Engine";
    }
    void accelerate(int n)
    {
        cout << __FUNCTION__ << endl;
        cout << "New Acceleration = " << n+2 << endl;
    }
};

int main()
{
    cout << "LISKOV SUBSTRITION PRINCIPLE " << endl;
    cout << "Subclass should extend the capability of parent class and Not narrow it down" << endl;
    MotorCycle m;
    m.turnOnEngine();
    m.accelerate(10);

    BiCycle b;
    try
    {
        b.turnOnEngine();

    }
    catch(exception e)
    {
        cout << "Caught Exception = " << e.what() << endl;
    }

    b.accelerate(3);


    return 0;
}
