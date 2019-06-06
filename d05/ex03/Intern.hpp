#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern {
    public:
        Intern();
        ~Intern();

        AForm   *makeForm(std::string name, std::string target);
    private:
};

#endif
