#ifndef VIEW_HPP
# define VIEW_HPP

#include "AEntity.hpp"
#include "Player.hpp"

class View {
    public:
		static int width;
		static int height;

        View();
        View(View const &src);
        ~View();
        View &operator=(View const &rhs);

        void    update(AEntity *entities, AEntity &player);
    private:
		void	drawElem(const Pos &pos, const Shape &shape);
};

#endif
