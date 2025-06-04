#include <iostream>
#include <string>

using namespace std;

class Marker
{
    string brand;
    string color;
    int price;
    int qty;
public:
    Marker(string brand,string color,int price,int qty)
    {
        this->brand = brand;
        this->color = color;
        this->price = price;
        this->qty = qty;
    }
    int calculate_Price()
    {
        int sum = price*qty;
        cout << "calculated_Price = " << sum << endl << endl;
        return sum;
    }
    void saveToDB()
    {
        cout << "Data being Saved to DB now\n" << endl;
    }
    void print_Invoice(int total)
    {
        cout << "GENERATED iNVOICE - sTYPE 1\n" << endl;
        cout << "Marker Details \nBrand : " << brand << "\nColor : "
        << color << "\nPrice for each Marker : " << price
        << "$\nQuantity = " << qty << "\nTotal Price = " << total << "$" << endl;
    }

};

class Calculate
{
    int price;
    int qty;
public:
    Calculate(int price,int qty)
    {
        this->price = price;
        this->qty = qty;
    }
    int calculate_Price()
    {
        int sum = price*qty;
        cout << "calculated_Price = " << sum << endl << endl;
        return sum;
    }
};

class S_Marker
{
    string brand;
    string color;
    int price;
    int qty;
public:
    S_Marker(string brand,string color,int price,int qty)
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

class DB_details
{
public:
    void saveToDB()
    {
        cout << "Data being Saved to saveToDB now\n" << endl;
    }
    void saveToFile()
    {
        cout << "Data being Saved to saveToFile now\n" << endl;
    }
    void saveToCloud()
    {
        cout << "Data being Saved to saveToCloud now\n" << endl;
    }
    void saveToLRU_Cache()
    {
        cout << "Data being Saved to saveToLRU_Cache now\n" << endl;
    }

};



int main()
{
    cout << "Implementing S --> SINGLE RESPONSINILITY PRINCIPLE " << endl;
    cout << "Approach without implementing Single Responsibity - A class should have 1 reason to change" << endl;
    Marker m("Cello","Blue",10,2);
    int sum = m.calculate_Price();
    m.saveToDB();
    m.print_Invoice(sum);

    cout << "\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";

    cout << "Approach with implementing Single Responsibity - A class has only 1 reason to change" << endl;

    Calculate C(20,4);
    sum = C.calculate_Price();

    DB_details d;
    d.saveToLRU_Cache();

    S_Marker S("Reynolds","Red",20,4);
    S.print_Invoice(sum);


    return 0;
}
