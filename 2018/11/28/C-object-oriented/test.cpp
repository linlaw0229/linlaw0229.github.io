#include <iostream>
using namespace std;

class ICount{
public:
    virtual double Perimeter()= 0;
    virtual double Area() = 0;
};
class IShape{
public:
    void setwidth(int width);
    void setlength(int length);
    int width;
    int length;
};



int main()
{
    printf("test\n");
    return 0;
}