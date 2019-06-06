#ifndef SHAPE_HPP
# define SHAPE_HPP

# include <iostream>

class Shape {
    public:
        Shape();
        Shape(int width, int height, char c);
        Shape(Shape const &src);
        ~Shape();

        Shape &operator=(Shape const &rhs);

        int		getWidth() const;
        int		getHeight() const;
        char	getC() const;

        void    setC(char c);
        void    setWidth(int width);
        void    setHeight(int height);

    private:
        int		_width;
        int		_height;
        char	_c;
};

std::ostream    &operator<<(std::ostream &o, Shape const &i);

#endif