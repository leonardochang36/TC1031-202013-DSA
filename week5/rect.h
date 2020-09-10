#ifndef rect_h
#define rect_h

#include <iostream>

class Rect
{
private:
    int width;
    int height;

public:
    Rect() {};
    Rect(int w, int h)
    {
        width = w;
        height = h;
    }
    ~Rect() {};

    int perimeter()
    {
        return 2 * (width + height);
    };

    int area()
    {
        return width * height;
    };

    void print()
    {
        std::cout << width << ", " << height << ": " << perimeter() << " - " << area() << std::endl;
    }
};

#endif