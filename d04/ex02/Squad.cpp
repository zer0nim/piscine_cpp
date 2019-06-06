#include "Squad.hpp"
#include <iostream>

Squad::Squad(): _spaceMsList(NULL), _count(0) {
};

Squad::Squad(Squad const &src) {
    *this = src;
};

Squad::~Squad() {
    SpaceMsList *curnt = _spaceMsList;
    while (_spaceMsList) {
        curnt = _spaceMsList;
        _spaceMsList = _spaceMsList->next;
        delete curnt->spaceMarine;
        delete curnt;
    }
};

Squad &Squad::operator=(Squad const &rhs) {
    if (this != &rhs) {
        SpaceMsList *newSpaceMsList = NULL;
        SpaceMsList *oldSpaceMsList = rhs.getSpaceMsList();
        while (oldSpaceMsList) {
            newSpaceMsList = new SpaceMsList();
            newSpaceMsList->spaceMarine = oldSpaceMsList->spaceMarine->clone();
            newSpaceMsList->next = oldSpaceMsList->next;
            oldSpaceMsList = oldSpaceMsList->next;
        }
        this->_spaceMsList = newSpaceMsList;
        this->_count = rhs.getCount();
    }
    return *this;
}

int Squad::getCount() const { return _count; }

ISpaceMarine* Squad::getUnit(int index) const {
    if (index > _count - 1)
        return NULL;

    SpaceMsList *curnt = _spaceMsList;
    for (int i = 0; curnt && i < index; ++i) {
        curnt = curnt->next;
    }
    return curnt->spaceMarine;
}

int Squad::push(ISpaceMarine* spaceMarine) {
    if (spaceMarine == NULL) {
        std::cout << "Error push value is NULL" << std::endl;
        return _count;
    }

    bool exist = false;
    SpaceMsList *curnt = _spaceMsList;
    for (int i = 0; curnt; ++i) {
        if (curnt->spaceMarine == spaceMarine)
            exist = true;
        curnt = curnt->next;
    }
    if (exist) {
        std::cout << "Error value already exist" << std::endl;
        return _count;
    }

    curnt = _spaceMsList;
    if (curnt == NULL) {
        _spaceMsList = new SpaceMsList();
        _spaceMsList->spaceMarine = spaceMarine;
        _spaceMsList->next = NULL;
    } else {
        for (int i = 0; curnt && curnt->next; ++i) {
            curnt = curnt->next;
        }
        curnt->next = new SpaceMsList();
        curnt->next->spaceMarine = spaceMarine;
        curnt->next->next = NULL;
    }

    return ++_count;
}

SpaceMsList *Squad::getSpaceMsList() const { return _spaceMsList; }
