#include "Shape.hpp"

Shape::Shape(): _width(1), _height(1), _c(' ') {
}

Shape::Shape(int width, int height, char c)\
: _width(width), _height(height), _c(c) {
}

Shape::Shape(Shape const &src) {
    *this = src;
}

Shape::~Shape() {
}

Shape &Shape::operator=(Shape const &rhs) {
    if (this != &rhs) {
        this->_width = rhs.getWidth();
        this->_height = rhs.getHeight();
        this->_c = rhs.getC();
    }
    return *this;
}

std::ostream    &operator<<(std::ostream &o, Shape const &i) {
    o << "{width:" << i.getWidth() << " height:" << i.getHeight() << " c:" << i.getC() << "}";
    return o;
}

int		Shape::getWidth() const { return _width; }
int		Shape::getHeight() const { return _height; }
char	Shape::getC() const { return _c; }

void	Shape::setC(char c) { _c = c; }
void    Shape::setWidth(int width) { _width = width; }
void    Shape::setHeight(int height) { _height = height; }
