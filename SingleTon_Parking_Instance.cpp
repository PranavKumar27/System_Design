#include <iostream>


using namespace std;

class SingleTon
{
    string ParkingName;
    int floors;
    int vehicles;
    static SingleTon* instancePtr;
    static mutex m;

    SingleTon(){}

    SingleTon(string name,int f,int v)
    {
        ParkingName = name;
        floors = f;
        vehicles = v;
    }

public:
    static SingleTon* getInstance(string name,int f,int v)
    {
        if(instancePtr == nullptr)
        {
            //m.lock();
            instancePtr = new SingleTon(name,f,v);
            //m.unlock();
        }
        return instancePtr;
    }
    void update_Parking(string name,int f,int v)
    {
        ParkingName = name;
        floors = f;
        vehicles = v;
    }
    void print()
    {
        cout << "name = " << ParkingName << " No of Floors = " << floors << " No of Vehicles = " << vehicles << endl;
    }
};

SingleTon* SingleTon::instancePtr = nullptr;
//SingleTon::m = false;

int main()
{
    cout << "Testing Singleton Parking Lot" << endl;

    SingleTon *instance = SingleTon::getInstance("Alpha_MLCP",2,5);

    instance->print();

    cout << "Address of instance = " << instance << endl;

    instance->update_Parking("Beta_MLCP",3,7);

    instance->print();

    cout << "Address of instance = " << instance << endl;


    return 0;
}
