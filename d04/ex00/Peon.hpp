#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : public Victim {
    public:
        Peon();
        Peon(std::string name);
        Peon(Peon const &src);
        ~Peon();

        Peon &operator=(Peon const &rhs);

        virtual void        getPolymorphed() const;
    private:
};

#endif