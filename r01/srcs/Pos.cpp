#include "Pos.hpp"
#include "View.hpp"

Pos::Pos(): _x(0), _y(0) {
}

Pos::Pos(float x, float y): _x(x), _y(y) {
}

Pos::Pos(Pos const &src) {
    *this = src;
}

Pos::~Pos() {
}

Pos &Pos::operator=(Pos const &rhs) {
    if (this != &rhs) {
        this->_x = rhs.getX();
        this->_y = rhs.getY();
    }
    return *this;
}

std::ostream    &operator<<(std::ostream &o, Pos const &i) {
    o << "{x:" << i.getX() << " y:" << i.getY() << "}";
    return o;
}

int		Pos::getX() const { return _x; }
int		Pos::getY() const { return _y; }
float   Pos::getFloatX() const { return _x; }
float   Pos::getFloatY() const { return _y; }

void    Pos::setX(float x) { _x = x; }
void    Pos::setY(float y) { _y = y; }
