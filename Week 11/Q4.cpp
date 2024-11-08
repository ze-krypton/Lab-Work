#include <iostream>

// ---- Base Class for Shape (Abstraction and Polymorphism) ----
class Shape {
public:
    // Virtual function for calculating area
    virtual double calculateArea() const = 0;  // Pure virtual function (abstract)
    
    // Virtual destructor (important for derived classes)
    virtual ~Shape() {}
    
    // Virtual function for displaying the shape type
    virtual void display() const = 0;
};

// ---- Derived Class: Circle (Inheritance) ----
class Circle : public Shape {
private:
    double radius;  // Encapsulation: Private member

public:
    // Constructor to initialize radius
    Circle(double r) : radius(r) {}

    // Override calculateArea for Circle
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }

    // Override display function for Circle
    void display() const override {
        std::cout << "Shape: Circle, Radius: " << radius << std::endl;
    }
};

// ---- Derived Class: Rectangle (Inheritance) ----
class Rectangle : public Shape {
private:
    double length;  // Encapsulation: Private member
    double width;   // Encapsulation: Private member

public:
    // Constructor to initialize length and width
    Rectangle(double l, double w) : length(l), width(w) {}

    // Override calculateArea for Rectangle
    double calculateArea() const override {
        return length * width;
    }

    // Override display function for Rectangle
    void display() const override {
        std::cout << "Shape: Rectangle, Length: " << length << ", Width: " << width << std::endl;
    }
};

// ---- Factory Class (Factory Method Pattern) ----
class ShapeFactory {
public:
    // Factory method to create shapes
    static Shape* createShape(const std::string& shapeType, double param1, double param2 = 0) {
        if (shapeType == "Circle") {
            return new Circle(param1);  // param1 is the radius
        } 
        else if (shapeType == "Rectangle") {
            return new Rectangle(param1, param2);  // param1 is length, param2 is width
        } 
        else {
            std::cout << "Unknown shape type!" << std::endl;
            return NULL;  // Use NULL instead of nullptr
        }
    }
};

// ---- Main Program ----
int main() {
    // Create shapes using the factory method
    Shape* circle = ShapeFactory::createShape("Circle", 5);  // Create a circle with radius 5
    Shape* rectangle = ShapeFactory::createShape("Rectangle", 4, 6);  // Create a rectangle with length 4 and width 6
    
    // Display shapes and their areas
    if (circle) {
        circle->display();  // Display circle properties
        std::cout << "Area of Circle: " << circle->calculateArea() << std::endl;  // Calculate and display area
        delete circle;  // Free memory
    }

    if (rectangle) {
        rectangle->display();  // Display rectangle properties
        std::cout << "Area of Rectangle: " << rectangle->calculateArea() << std::endl;  // Calculate and display area
        delete rectangle;  // Free memory
    }

    return 0;
}

