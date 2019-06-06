#ifndef POS_HPP
# define POS_HPP

# include <iostream>

class Pos {
    public:
        Pos();
        Pos(float x, float y);
        Pos(Pos const &src);
        ~Pos();

        Pos &operator=(Pos const &rhs);

        int		getX() const;
        int		getY() const;
        float   getFloatX() const;
        float   getFloatY() const;

        void    setX(float x);
        void    setY(float y);
    private:
        float   _x;
        float   _y;
};

std::ostream    &operator<<(std::ostream &o, Pos const &i);

#endif
