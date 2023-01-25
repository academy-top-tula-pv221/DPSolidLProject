#include <iostream>

using namespace std;

class Rectangle
{
protected:
    int width;
    int height;
public:
    virtual int GetWidth() { return width; }
    virtual int GetHeight() { return height; }

    virtual void SetWidth(int value) { width = value; }
    virtual void SetHeight(int value) { height = value; }

    int Area() { return width * height; }
};
class Square : public Rectangle
{
    //int GetWidth() override { return width; }
    //int GetHeight() override { return height; }

    void SetWidth(int value) 
    { 
        width = value;
        height = value;
    }
    void SetHeight(int value)
    { 
        height = value;
        width = value;
    }
};
void TestRectangleArea(Rectangle* rect) 
{
    if (typeid(rect) == typeid(Square))
    {
        rect->SetWidth(5);
        if (rect->Area() != 25)
            throw new exception("invalid area for square");
    }
    else
    {
        rect->SetHeight(10);
        rect->SetWidth(5);
        if (rect->Area() != 50)
            throw new exception("invalid area for rectangle");
    }
    
}

class IAmountOperations
{
protected:
    int amount;
public:
    virtual void SetAmount(int money) = 0;
    virtual void GetProcents(float rate) = 0;
    int& Amount() { return amount; }
};

class Account : public IAmountOperations
{
public:
    void SetAmount(int money) override
    {
        if (money < 0)
            throw exception("negative money");
        amount = money;
    }
    void GetProcents(float rate) override
    {
        for (int i = 0; i < 12; i++)
            amount += amount * rate;
        if (amount >= 100)
            amount += 50;
    }
    
};

class MicroAccount : public IAmountOperations
{
public:
    void SetAmount(int money) override
    {
        if (money < 0)
            throw exception("negative money");
        if (money > 100)
            throw exception("money too much");
        amount = money;
    }

    void GetProcents(float rate) override
    {
        for (int i = 0; i < 12; i++)
            amount += amount * rate;
    }
};

void AccountInit(IAmountOperations* account, int money)
{
    account->SetAmount(money);
    cout << account->Amount();
}


int main()
{
    /*
    Rectangle* rect = new Square();
    try
    {
        TestRectangleArea(rect);
    }
    catch (exception* e)
    {
        cout << "error: " << e->what() << "\n";
    }
    */

    IAmountOperations* acc = new MicroAccount();
    AccountInit(acc, 200);
}
