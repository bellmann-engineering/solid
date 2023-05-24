#include <cmath>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// abstract classes, Shape and Print
class Shape
{
public:
  virtual float getArea() = 0;
  virtual ~Shape() {}
};

class Print
{
public:
  virtual void print(float value) = 0;
  virtual ~Print() {}
};

// concrete classes to print different styles using Print class
class Style_A : public Print
{
public:
  ~Style_A() {}
  void print(float value) { cout << "A: The area is " << value << endl; }
};

class Style_B : public Print
{
public:
  ~Style_B() {}
  void print(float value)
  {
    cout << "B: The given shape has an area of " << value << endl;
  }
};

class Style_C : public Print
{
public:
  ~Style_C() {}
  void print(float value) { cout << "C: Answer: " << value << endl; }
};

class Rectangle : public Shape
{
private:
  float width, height;

public:
  Rectangle(float width, float height) : width(width), height(height) {}
  ~Rectangle() {}
  float getArea() { return (width * height); }
};

class Square : public Shape
{
private:
  float width;

public:
  Square(float width) : width(width) {}
  float getArea() { return (width * width); }
};

class Triangle : public Shape
{
private:
  float base, height;

public:
  Triangle(float base, float height) : base(base), height(height) {}
  ~Triangle() {}
  float getArea() { return (0.5f * base * height); }
};

class Circle : public Shape
{
private:
  float radius;

public:
  Circle(float radius) : radius(radius) {}
  ~Circle() {}
  float getArea() { return ((float(M_PI)) * radius * radius); }
};

// container class to take in shape & printing style to print accordingly
class Box
{
private:
  unique_ptr<Shape> shape;
  unique_ptr<Print> printStyle;

public:
  Box(unique_ptr<Shape> shape, unique_ptr<Print> printStyle)
      : shape(std::move(shape)), printStyle(std::move(printStyle)) {}
  
  void displayShape()
  {
    if (shape != nullptr && printStyle != nullptr)
    {
      printStyle->print(shape->getArea());
    }
    else
    {
      cout << "Failed to display shape(s) with printing style(s)" << endl;
    }
  }
};

int main()
{
  vector<unique_ptr<Box>> boxOfShapes;

  boxOfShapes.push_back(make_unique<Box>(make_unique<Rectangle>(10.f, 5.f), make_unique<Style_A>()));
  boxOfShapes.push_back(make_unique<Box>(make_unique<Square>(7.f), make_unique<Style_B>()));
  boxOfShapes.push_back(make_unique<Box>(make_unique<Triangle>(10.f, 5.f), make_unique<Style_C>()));
  boxOfShapes.push_back(make_unique<Box>(make_unique<Circle>(4.f), make_unique<Style_A>()));

  for (const auto& box : boxOfShapes)
  {
    box->displayShape();
  }

  return 0;
}
