#include "Human.hpp"
#include <iostream>

typedef void (Human::*attackFunc)(std::string const & target);
struct FuncPtrStruct {
    std::string key;
    attackFunc func;
};

void Human::meleeAttack(std::string const & target) {
    std::cout << "Melee attack on " << target << std::endl;
}
void Human::rangedAttack(std::string const & target) {
    std::cout << "Ranged attack on " << target << std::endl;
}
void Human::intimidatingShout(std::string const & target) {
    std::cout << "Intimidating shout on " << target << std::endl;
}


void Human::action(std::string const & action_name, std::string const & target) {
    FuncPtrStruct attacks[] = {
        {"meleeAttack", &Human::meleeAttack},
        {"rangedAttack", &Human::rangedAttack},
        {"intimidatingShout", &Human::intimidatingShout}
    };

    attackFunc func = NULL;
    int len = (sizeof(attacks)/sizeof(*attacks));
    for (int i = 0; i < len; ++i) {
        if (attacks[i].key.compare(action_name) == 0) {
            func = attacks[i].func;
            break;
        }
    }

    if (func != NULL)
        (this->*func)(target);
    else
        std::cerr << "Error ! action_name: \"" << action_name << "\" not recognized" << std::endl;
}
