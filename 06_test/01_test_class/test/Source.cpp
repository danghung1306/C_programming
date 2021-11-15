#include <iostream>

using namespace std;

class cha {
public:
    cha()
    {
        cout << "Hello tao là cha" << endl;
    }
protected:
    void choCon()
    {
        cout << "Cai nay cho con" << endl;
    }
};

class con : public cha {
public:
    con()
    {
        cout << "T la con ne" << endl;
    }
    void kethua()
    {
        choCon();
    }

};

int main()
{
    cha* objCha;
    objCha->choCon();
}