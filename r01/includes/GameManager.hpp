#ifndef GAMEMANAGER_HPP
# define GAMEMANAGER_HPP

#include "EventManager.hpp"
#include "ClockTime.hpp"
#include "AEntity.hpp"
#include "Player.hpp"
#include "View.hpp"

class GameManager {
    public:
        GameManager();
        GameManager(GameManager const &src);
        ~GameManager();

        GameManager &operator=(GameManager const &rhs);

        void    exec();
    private:
		bool	cleanEntityList(void);
		void    AddEntity(AEntity *newEntity);
		void	removeEntity(AEntity *to_remove);
		void	spawnNewEnemy(void);

        AEntity         *_entities;
        Player          *_player;
        View            _view;
        EventManager    _eventManager;
};

#endif
