#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>


class Pony
{
    public:
        Pony(std::string name);
        ~Pony();
        void    neighing() const;
    private:
        std::string _name;
};

#endif