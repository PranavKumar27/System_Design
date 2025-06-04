#include <iostream>

using namespace std;



class KeyBoard
{
    int type_of_keyboard;
public:
    KeyBoard(){}
    KeyBoard(int o)
    {
        type_of_keyboard = o;
    }
    void wired()
    {
        cout << "Keyboard is wired" << endl;
        type_of_keyboard = 1;
    }
    void wireless()
    {
        cout << "Keyboard is wireless" << endl;
        type_of_keyboard = 2;
    }
    void Gaming()
    {
        cout << "Keyboard is Gaming" << endl;
        type_of_keyboard = 3;
    }
    void type()
    {
        if(type_of_keyboard == 1)
            cout << "Keyboard is wired" << endl;
        else if(type_of_keyboard == 2 )
            cout << "Keyboard is wireless" << endl;
        else
           cout << "Keyboard is Gaming" << endl;
    }
};


class Mouse
{
    int type_of_Mouse;
public:
    Mouse()
    {

    }
    Mouse(int o)
    {
        type_of_Mouse = o;
    }
    void type()
    {
        if(type_of_Mouse == 1)
            cout << "Mouse is wired" << endl;
        else if(type_of_Mouse == 2 )
            cout << "Mouse is wireless" << endl;
        else
           cout << "Mouse is Gaming" << endl;
    }

};

class Computer_System
{
    KeyBoard k;
    Mouse m;
public:
    Computer_System()
    {
        k.wired();
        m = Mouse(2);
    }
};

class Linux_Computer_System
{
    KeyBoard k;
    Mouse m;
public:
    Linux_Computer_System(KeyBoard key,Mouse mu)
    {
        k=key;
        m=mu;
        m.type();
        k.type();
    }
};

int main()
{
    cout << "Dependency Inversion Principle" << endl;

    cout << "Before Dependency inversion Here Class are dependent on concrete Class" << endl;
    Computer_System C1,C2;



    cout << "After Dependency inversion Here Class are dependent on interfaces and passobj has capability to vary" << endl;

    KeyBoard k(2);
    Mouse m(3);

    KeyBoard k2(3);
    Mouse m2(2);
    Linux_Computer_System L1(k,m),L2(k2,m2);

    return 0;
}
