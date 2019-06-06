#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    public:
        Fixed();
        Fixed(const int val);
        Fixed(const float val);
        Fixed(Fixed const &src);
        ~Fixed();

        Fixed   &operator=(Fixed const &rhs);

        bool    operator>(Fixed const &rhs) const;
        bool    operator<(Fixed const &rhs) const;
        bool    operator>=(Fixed const &rhs) const;
        bool    operator<=(Fixed const &rhs) const;
        bool    operator==(Fixed const &rhs) const;
        bool    operator!=(Fixed const &rhs) const;

        Fixed   operator+() const;
        Fixed   operator-() const;
        Fixed   operator+(Fixed const &rhs) const;
        Fixed   operator-(Fixed const &rhs) const;
        Fixed   operator*(Fixed const &rhs) const;
        Fixed   operator/(Fixed const &rhs) const;

        Fixed&  operator++();
        Fixed&  operator--();
        Fixed   operator++(int);
        Fixed   operator--(int);

        int                 getRawBits() const;
        void                setRawBits(int const raw);
        float               toFloat( void ) const;
        int                 toInt( void ) const;
        static Fixed const  &min(Fixed const &lhs, Fixed const &rhs);
        static Fixed        &min(Fixed &lhs, Fixed &rhs);
        static Fixed const  &max(Fixed const &lhs, Fixed const &rhs);
        static Fixed        &max(Fixed &lhs, Fixed &rhs);

    private:
        int     _fixedPointVal;
        static const int _fractionalBitsNb;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &i);

#endif
