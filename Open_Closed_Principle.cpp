#include <iostream>

using namespace std;

class Invoice
{
    string brand;
    string color;
    int price;
    int qty;
public:
    Invoice(string brand,string color,int price,int qty)
    {
        this->brand = brand;
        this->color = color;
        this->price = price;
        this->qty = qty;
    }
    void print_Invoice(int total)
    {
        cout << "GENERATED iNVOICE - sTYPE 1\n" << endl;
        cout << "Marker Details \nBrand : " << brand << "\nColor : "
        << color << "\nPrice for each Marker : " << price
        << "$\nQuantity = " << qty << "\nTotal Price = " << total << "$" << " All Prices includes GST "<<endl;
    }
};

// Interface
class DataStore
{
public:
    virtual void save(Invoice inv) = 0;
};

// Here instead of have all save types in single class we have different Class for different storage Types

class DataBase_Save:public DataStore
{
public:
    void save(Invoice inv)
    {
        cout << "Data being Saved to saveToDB now\n" << endl;
    }
};

class File_Save:public DataStore
{
public:
    void save(Invoice inv)
    {
        cout << "Data being Saved to saveToFile now\n" << endl;
    }
};

class Cloud_Save:public DataStore
{
public:
    void save(Invoice inv)
    {
        cout << "Data being Saved to saveToCloud now\n" << endl;
    }
};

class saveToLRU_Cache:public DataStore
{
public:
    void save(Invoice inv)
    {
        cout << "Data being Saved to saveToLRU_Cache now\n" << endl;
    }
};


int main()
{
    cout << "Open Closed Principle" << endl;

    cout << "Interface DataStore is extended for saving in different ways so extended" << endl;

    Invoice inv("Independent","Green",20,4);
    //inv.print_Invoice(100);

    DataBase_Save s;
    s.save(inv);


    return 0;
}
