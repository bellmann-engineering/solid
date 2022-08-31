/******************************************************************************
Brief Description: Exercise to rework code to satisfy SOLID principles
******************************************************************************/
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// abstract classes, Shape and Print
class Shape {
public:
  virtual float getArea() = 0;
  virtual ~Shape() {}
};

class Print {
public:
  virtual void print(float value) = 0;
  virtual ~Print() {}
};

// concrete classes to print different styles using Print class
class Style_A : public Print {
public:
  ~Style_A() {}
  void print(float value) { cout << "A: The area is " << value << endl; }
};

class Style_B : public Print {
public:
  ~Style_B() {}
  void print(float value) {
    cout << "B: The given shape has an area of " << value << endl;
  }
};

class Style_C : public Print {
public:
  ~Style_C() {}
  void print(float value) { cout << "C: Answer: " << value << endl; }
};

class Rectangle : public Shape {
private:
  float width, height;

public:
  Rectangle(float width, float height) : width(width), height(height) {}
  ~Rectangle() {}
  float getArea() { return (width * height); }
};

class Square : public Shape {
private:
  float width;

public:
  Square(float width) : width(width) {}
  float getArea() { return (width * width); }
};

class Triangle : public Shape {
private:
  float base, height;

public:
  Triangle(float base, float height) : base(base), height(height) {}
  ~Triangle() {}
  float getArea() { return (0.5f * base * height); }
};

class Circle : public Shape {
private:
  float radius;

public:
  Circle(float radius) : radius(radius) {}
  ~Circle() {}
  float getArea() { return ((float(M_PI)) * radius * radius); }
};

// container class to take in shape & printing style to print accordingly
class Box {
private:
  Shape *shape;
  Print *printStyle;

public:
  Box(Shape *shape, Print *printStyle) : shape(shape), printStyle(printStyle) {}
  ~Box() {
    delete shape;
    delete printStyle;
  }
  void displayShape() {
    if (shape != nullptr && printStyle != nullptr) {
      printStyle->print(shape->getArea());
    } else {
      cout << "Failed to display shape(s) with printing style(s)" << endl;
    }
  }
};

int main() {
  vector<Box *> boxOfShapes;
  vector<Box *>::const_iterator it;

  boxOfShapes.push_back(new Box(new Rectangle(10.f, 5.f), new Style_A));
  boxOfShapes.push_back(new Box(new Square(7.f), new Style_B));
  boxOfShapes.push_back(new Box(new Triangle(10.f, 5.f), new Style_C));
  boxOfShapes.push_back(new Box(new Circle(4.f), new Style_A));

  for (it = boxOfShapes.begin(); it != boxOfShapes.end(); ++it) {
    (*it)->displayShape();
  }

  for (it = boxOfShapes.begin(); it != boxOfShapes.end(); ++it) {
    delete (*it);
  }
  return 0;
}

/*
A: The area is 50
B: The given shape has an area of 49
C: Answer: 25
A: the area is 50.2655
*/
