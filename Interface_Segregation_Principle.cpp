#include <iostream>

using namespace std;

// Interface
class RestaurantEmployee
{
public:
    virtual void washDishes() = 0;
    virtual void TakeOrder() = 0;
    virtual void ServeFood() = 0;
    virtual void cookFood() = 0;
};

// Wrong Design
// Concrete Class
class waiter:public RestaurantEmployee
{
public:
    void washDishes()
    {
        cout << "washDishes is Not my job -waiter" << endl;
    }
    void TakeOrder()
    {
        cout << "waiter taking orders" << endl;
    }
    void ServeFood()
    {
        cout << "waiter serving order" << endl;
    }
    void cookFood()
    {
        cout << "cookFood is Not my job -waiter" << endl;
    }
};


// Use segregated interface and then extend to waiter

class Waiter_Interface
{
public:
    virtual void TakeOrder() = 0;
    virtual void ServeFood() = 0;
};

class MasterChef_Interface
{
public:
    virtual void cookFood() = 0;
};

class Cleaner_Interface
{
public:
    virtual void washDishes() = 0;
};

class _waiter:public Waiter_Interface
{
public:
    void TakeOrder()
    {
        cout << "waiter taking orders" << endl;
    }
    void ServeFood()
    {
        cout << "waiter serving order" << endl;
    }
};

int main()
{

    cout << "Interface Segregation Principle" << endl;

    cout << " \n Before implementing Interface Segregation\n" << endl;
    waiter w;
    w.TakeOrder();
    w.washDishes();
    w.cookFood();
    w.ServeFood();


    // After implementing Interface Segregation

     cout << "\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
     cout << " \n After implementing Interface Segregation\n" << endl;

    _waiter s;
    s.TakeOrder();
    s.ServeFood();
    return 0;
}
