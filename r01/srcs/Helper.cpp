#include "AEntity.hpp"

void    AddEntity(AEntity **entityList, AEntity *newEntity) {
    if (entityList == NULL)
        *entityList = newEntity;
    else {
        AEntity *curnt = *entityList;
        while (curnt && curnt->next)
            curnt = curnt->next;
        curnt->next = newEntity;
    }
}