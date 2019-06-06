#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "AMovable.hpp"

class Player : public AMovable {
	public:
		Player();
		Player(Player const &src);
		virtual ~Player();

		Player &operator=(Player const &rhs);

		void	update(const EventManager &event_manager, AEntity *entities, AEntity &player);
};

#endif
