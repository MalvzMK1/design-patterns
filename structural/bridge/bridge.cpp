#include <iostream>
#include <memory>

using namespace std;

// Implementor
class Renderer {
public:
  virtual void render_circle(double radius) = 0;
  virtual ~Renderer() {}
};

// Abstraction
class Shape {
protected:
  unique_ptr<Renderer> renderer;
public:
  Shape(unique_ptr<Renderer> renderer_)
    : renderer(std::move(renderer_)) {}
  virtual void draw() = 0;
  virtual ~Shape() {}
};

// Concrete Implementations
class SVGRenderer : public Renderer {
public:
  void render_circle(double radius) {
    cout << "SVG Renderer rendered a circle with " << radius << " of radius" << endl;
  }
};

class CanvasRenderer : public Renderer {
public:
  void render_circle(double radius) {
    cout << "Canvas Renderer rendered a circle with " << radius << " of radius" << endl;
  }
};

// Refined Abstractions
class Circle : public Shape {
private:
  double radius;
public:
  Circle(double radius_, unique_ptr<Renderer> renderer_)
    : Shape(std::move(renderer_)), radius(radius_) {}
  void draw() override {
    renderer->render_circle(radius);
  }
};

int main() {
  auto svgRenderer = make_unique<SVGRenderer>();
  auto canvasRenderer = make_unique<CanvasRenderer>();

  Circle circle1(10, std::move(svgRenderer));
  Circle circle2(10, std::move(canvasRenderer));

  circle1.draw();
  circle2.draw();

  return 0;
}

