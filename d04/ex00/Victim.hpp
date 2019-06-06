#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>

class Victim {
    public:
        Victim();
        Victim(std::string name);
        Victim(Victim const &src);
        ~Victim();

        Victim &operator=(Victim const &rhs);
        std::string getName() const;

        virtual void        getPolymorphed() const;
    protected:
        std::string _name;
};

std::ostream    &operator<<(std::ostream &o, Victim const &i);

#endif