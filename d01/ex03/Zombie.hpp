#ifndef  ZOMBIE_HPP
# define  ZOMBIE_HPP

# include <iostream>

class   Zombie {
    public:
        Zombie();
        Zombie(std::string type, std::string name);
        ~Zombie();
        void        announce() const;
        void        setType(std::string type);
        void        setName(std::string name);
        std::string getType() const;
        std::string getName() const;
    private:
        std::string _type;
        std::string _name;
};

#endif