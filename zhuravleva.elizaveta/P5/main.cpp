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

int main()
{
    
}