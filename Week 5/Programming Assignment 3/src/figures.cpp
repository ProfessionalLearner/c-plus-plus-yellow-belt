#include <string>
#include <memory>
#include <cmath>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Figure {
public:
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
};

class Rect : public Figure {
public:
	Rect(const int& width, const int& height)
	: width_(width),
	height_(height) {
	}

	string Name() const override {
		return "RECT";
	}

	double Perimeter() const override {
		return 2 * width_ + 2 * height_;
	}

	double Area() const override {
		return width_ * height_;
	}
private:
	const int width_;
	const int height_;
};

class Triangle : public Figure {
public:
	Triangle(const int& side_one, const int& side_two, const int& side_three)
	: side_one_(side_one),
	side_two_(side_two),
	side_three_(side_three) {
	}

	string Name() const override {
		return "TRIANGLE";
	}

	double Perimeter() const override {
		return side_one_ + side_two_ + side_three_;
	}

	double Area() const override {
		double s = Perimeter() / 2.0;
		return sqrt(s * (s - side_one_) * (s - side_two_) * (s - side_three_));
	}
private:
	const int side_one_;
	const int side_two_;
	const int side_three_;
};

class Circle : public Figure {
public:
	Circle(const int& radius)
	: radius_(radius) {
	}

	string Name() const override {
		return "CIRCLE";
	}

	double Perimeter() const override {
		return 2 * pi * radius_;
	}

	double Area() const override {
		return pi * (radius_* radius_);
	}
private:
	const double pi = 3.14;
	const int radius_;
};

shared_ptr<Figure> CreateFigure(istream& in) {
	string name;
	in >> name;
	if(name == "RECT") {
		int width, height;
		in >> width >> height;
		return make_shared<Rect>(width, height);
	} else if(name == "TRIANGLE") {
		int side_one, side_two, side_three;
		in >> side_one >> side_two >> side_three;
		return make_shared<Triangle>(side_one, side_two, side_three);
	} else {
		int radius;
		in >> radius;
		return make_shared<Circle>(radius);
	}
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
