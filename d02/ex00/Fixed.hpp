#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
    public:
        Fixed();
        Fixed(Fixed const &src);
        ~Fixed();

        Fixed &operator=(Fixed const &rhs);
        int getRawBits() const;
        void setRawBits(int const raw);
    private:
        int _fixedPointVal;
        static const int _fractionalBitsNb;
};

#endif
