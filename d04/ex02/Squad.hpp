#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"

struct SpaceMsList {
    ISpaceMarine    *spaceMarine;
    SpaceMsList     *next;
};

class Squad: public ISquad {
    public:
        Squad();
        Squad(Squad const &src);
        virtual ~Squad();

        Squad &operator=(Squad const &rhs);

        virtual int push(ISpaceMarine *spaceMarine);

        virtual ISpaceMarine*   getUnit(int i) const;
        virtual int             getCount() const;
        SpaceMsList*            getSpaceMsList() const;
    private:
        SpaceMsList    *_spaceMsList;
        int             _count;
};

#endif
