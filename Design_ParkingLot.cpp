#include <iostream>


using namespace std;

class ParkingLot
{
    string ParkingName;
    int floors;
    int vehicles;
    static ParkingLot* instancePtr;
    list<ParkingFloor> parkingFloor;
    //static mutex m;

    ParkingLot(){}

    ParkingLot(string name,int f,int v)
    {
        ParkingName = name;
        floors = f;
        vehicles = v;
    }

public:
    static ParkingLot* getInstance(string name,int f,int v)
    {
        if(instancePtr == nullptr)
        {
            //m.lock();
            instancePtr = new ParkingLot(name,f,v);
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

ParkingLot* ParkingLot::instancePtr = nullptr;



class ParkingSLOTType
{
    double charges;
    int duration;
    
public:
    ParkingSLOTType()
    {
        charges = 0.0;
        duration = 0;
    }
    
    int getCharge(int time)
    {
        duration = time;
        if(t == 1)
        {
            return duration*70;
        }
        else if(t==2)
        {
            return duration*90;
        }
        else if(t==3)
        {
            return duration*100;
        }
        else 
            return 1000;
            
    }
    
};

class ParkingFloor
{
    string name;
    map<ParkingSLOTType<map<string,ParkingSLOT>> mp;
    
public:
    ParkingFloor(){}
    void relevant_Parking(VehicleDetails V_Details)
    {
        // search in map and give the Parking slot available
        VehicleType type = V_Details.V.getVehicleType();
        ParkingSLOT s = getCorrectParkingSlot(type);
        
        for(auto s:mp)
        {
            // If parking availble return True;
        }
    }
};


class Ticket
{
    VehicleDetails V;
    int entryTime;
    int exitTime;
    
    Ticket(VehicleDetails v,int t)
    {
        entryTime = t;
        V = v;
    }
    int getDuration(int exit)
    {
        exitTime = exit;
        int time_Diff = exitTime - entryTime;
        return time_Diff;
    }
};

class Payment
{
    ParkingSLOTType p;
    Ticket t;
public:
    Payment(ParkingFloor p,Ticket t)
    {
        this->p = p;
        this->t = t;
    }
    int Pay(int cardNo)
    {
        int time_now = 100;
        int charge = p.getCharge(t.getDuration(time_now));
        if(cardNo!=0)
        {
            cout << "Payment done Balance is clear . Amount deducted = " << charge << endl;
        }
        return charge;  
    }
};


class ParkingSLOT
{
    string name;
    bool isAvailable;
    VehicleDetails VD;
    ParkingSLOTType parkingslotType;
    
public:
    ParkingSLOT(string name,ParkingSLOTType slotType )
    {
        isAvailable = true;
        this->name = name;
        parkingslotType = slotType;
    }
    
    void addVehicle(VehicleDetails V)
    {
        VD = v;
        isAvailable = false;
    }
    bool removeVehicle(VehicleDetails V)
    {
        //VD = null;
        isAvailable = true;
    }
};


class VehicleType
{
    string Type;
public:
    VehicleType(){}
    VehicleType(int n)
    {
        if(n==1)
            VehicleType = "SMALL";
        else if(n==2)
            VehicleType = "MEDIUM";
        else if(n==3)
            VehicleType = "LARGE";
        else
            VehicleType = "UNKNOWN";
    }
    string getVehicleType()
    {
        return type;
    }
};

class VehicleDetails
{
    VehicleType V;
    string License_Plate;
public:
    VehicleDetails(VehicleType V,string s)
    {
        this->V = V;
        License_Plate = s;
    }
};


int main()
{
    cout << "Testing Singleton Parking Lot" << endl;

    ParkingLot *instance = ParkingLot::getInstance("Alpha_MLCP",2,5);

    instance->print();

    cout << "Address of instance = " << instance << endl;

    instance->update_Parking("Beta_MLCP",3,7);

    instance->print();

    cout << "Address of instance = " << instance << endl;


    return 0;
}
