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
        int     getRawBits() const;
        void    setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;
    private:
        int _fixedPointVal;
        static const int _fractionalBitsNb;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &i);

#endif
