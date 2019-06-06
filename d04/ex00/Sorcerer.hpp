#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include "Victim.hpp"

class Sorcerer {
    public:
        Sorcerer(std::string name, std::string title);
        Sorcerer(Sorcerer const &src);
        ~Sorcerer();

        Sorcerer &operator=(Sorcerer const &rhs);

        std::string getName() const;
        std::string getTitle() const;

        void        polymorph(Victim const &v) const;
    private:
        Sorcerer();

        std::string _name;
        std::string _title;
};

std::ostream    &operator<<(std::ostream &o, Sorcerer const &i);

#endif