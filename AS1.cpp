#include<iostream>
using namespace std;
class complex{
public:
    float real,img;
    complex(){}
    complex operator+(complex);
    complex operator*(complex);
    friend ostream &operator<<(ostream&,complex&);
    friend istream &operator>>(istream&,complex&);
};
complex complex::operator+(complex obj)
{
    complex temp
    temp.real = real + obj.real;
    temp.img = img + obj.img;
    return(temp);
}
istream &operator>>(istream &is,complex &obj)
{
    is>>obj.real;
    is>>obj.img;
    return is;
}
ostream &operator<<(ostream &out,complex &obj)
{
    out<<""<<obj.real;
    out<<"+"<<obj.img<<"i";
    return out;
}
complex complex::operator*(complex obj)
{
    complex temp;
    temp.real= real*obj.real - img*obj.img;
    temp.img= img*obj.img + real*obj.img;
    return temp;
}
int main()
{
    complex a,b,c,d;
    cout<<"\nThe first complex number is: ";
    cout<<"\nEnter real and img: ";
    cin>>a;
    cout<<"\nThe second complex number is: ";
    cout<<"\nEnter real and img: ";
    cin>>b;
    c = a+b;
    cout<<"\nThe Arithmetic operations";
    cout<<"\nAddition = ";
    cout<<c;
    d = a*b;
    cout<<"\nMultiplication = ";
    cout<<d;
    cout<<endl;
    return 0;
}
