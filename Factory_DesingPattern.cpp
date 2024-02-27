#include <iostream>

class Shape()
{
    public:
        virtual ~Shape();
        virtual void Draw() const = 0; 

};

class Circle : public Shape
{
    void Draw() const override { cout << "this is a circle\n"; }
};

class Triangle : public Shape
{
    void Draw() const override { cout << "this is a Triangle\n"; }
};

class Square : public Shape
{
    void Draw() const override { cout << "this is a Square \n"; }
};

class Factory
{
    virtual ~Factory() {};
    Shape* CreateShape() const = 0; 
};

class CircleFactory : public Factory
{
    Shape* CreateShape() { return new Circle();}
};


class TriangleFactory : public Factory
{
    Shape* CreateShape() { return new Triangle();}
};


class CircleFactory : public Factory
{
    Shape* CreateShape() { return new Circle();}
};

void Client(const Factory& fact)
{
    Shape *s = fact.createShape();
    s.Draw();
}


int main()
{
    CircleFactory *Cf = new CircleFactory();
    Client(CircleFactory);
    
    return 0;
}
