#include <iostream>
namespace zhuravleva
{
  const double pi = 3.14;

  struct point_t {
    double x, y;
  };

  struct rectangle_t {
    double width, height;
    point_t pos;
  };

  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double factor) = 0;
  };

  class Rectangle : public Shape
  {
  public:
    Rectangle(double width, double heihg, point_t point);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
  private:
    double width_, height_;
    point_t center_;
  };

  class Ellipse : public Shape
  {
  public:
    Ellipse(double radHor, double radVer, point_t p);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
  private:
    double radiusHor_, radiusVer_;
    point_t center_;
  };

  class Rubber : public Shape
  {
  public:
    Rubber(double outerRadius, double innerRadius, const point_t& center);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
  private:
    double outerRadius_;
    double innerRadius_;
    point_t center_;
  };
};

zhuravleva::Rectangle::Rectangle(double width, double heigh, point_t point):
  Shape(),
  width_(width),
  height_(heigh),
  center_(point)
{
  if (width <= 0 || heigh <= 0)
  {
    throw std::invalid_argument("Invalid size");
  }
}
double zhuravleva::Rectangle::getArea() const
{
  return width_ * height_;
}
zhuravleva::rectangle_t zhuravleva::Rectangle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width = width_;
  frameRect.height = height_;
  frameRect.pos = center_;
  return frameRect;
}
void zhuravleva::Rectangle::move(point_t point)
{
  center_ = point;
}
void zhuravleva::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
void zhuravleva::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Scale coefficient must be positive");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}

zhuravleva::Ellipse::Ellipse(double radHor, double radVer, point_t p):
  Shape(),
  radiusHor_(radHor),
  radiusVer_(radVer),
  center_(p)
{
  if (radHor <= 0.0 || radVer <= 0.0)
  {
    throw std::invalid_argument("Invalid radius");
  }
}
double zhuravleva::Ellipse::getArea() const
{
  return pi * radiusHor_ * radiusVer_;
}
zhuravleva::rectangle_t zhuravleva::Ellipse::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width = radiusHor_ * 2;
  frameRect.height = radiusVer_ * 2;
  frameRect.pos = center_;
  return frameRect;
}
void zhuravleva::Ellipse::move(point_t p)
{
  center_ = p;
}
void zhuravleva::Ellipse::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
void zhuravleva::Ellipse::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Scale coefficient must be positive");
  }
  radiusHor_ *= coefficient;
  radiusVer_ *= coefficient;
}

zhuravleva::Rubber::Rubber(double outerRadius, double innerRadius, const point_t& center):
  Shape(),
  outerRadius_(outerRadius),
  innerRadius_(innerRadius),
  center_(center)
{
  if (outerRadius <= 0 || innerRadius <= 0)
  {
    throw std::invalid_argument("Radii must be positive");
  }
  if (innerRadius >= outerRadius)
  {
    throw std::invalid_argument("Inner radius must be less than outer radius");
  }
}
double zhuravleva::Rubber::getArea() const
{
  return pi * (outerRadius_ * outerRadius_ - innerRadius_ * innerRadius_);
}
zhuravleva::rectangle_t zhuravleva::Rubber::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width = outerRadius_ * 2;
  frameRect.height = outerRadius_ * 2;
  frameRect.pos = center_;
  return frameRect;
}
void zhuravleva::Rubber::move(point_t p)
{
  center_ = p;
}
void zhuravleva::Rubber::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
void zhuravleva::Rubber::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Scale coefficient must be positive");
  }
  outerRadius_ *= coefficient;
  innerRadius_ *= coefficient;
}


int main()
{
  
}