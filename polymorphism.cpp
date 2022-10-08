#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>


class Shape
{
    protected:
        double height;
        double width;
    public:
        Shape(double h, double w)
        {
            height = h;
            width = w;
        }
        Shape(double length)
        {
            height = length;
            width = length;
        }
        virtual double Area(){
            std::cout << "Shape Area calculated successfully" << std::endl;
            return height * width;
        }
};


class Circle : public Shape
{
    public:
        Circle(double R) : Shape(R){};
        double Area(){
            std::cout << "Circle area calculated successfully" << std::endl;
            return 3.14159 * std::pow(width, 2);
        }
};


int main()
{
    Shape rectangle(4, 5);
    std::cout << "The area of the rectangle is :" 
            << rectangle.Area() << std::endl;


    Circle c1(4);
    std::cout << "The area of the circle is : " 
        << c1.Area() << std::endl;
    return 0;

}
