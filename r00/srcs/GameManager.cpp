#include "GameManager.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>

GameManager::GameManager() : _entities(NULL) {
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	getmaxyx(stdscr, View::height, View::width);
    _player = new Player();
}

GameManager::GameManager(GameManager const &src) {
    *this = src;
}

GameManager::~GameManager() {
    // need to destroy alls entities, players, ...
	endwin();
    delete _player;
}

GameManager &GameManager::operator=(GameManager const &rhs) {
    if (this != &rhs)
        ;
    return *this;
}

void    GameManager::exec() {
	int	input;
	while (_eventManager.getAppRunning())
	{
        ClockTime::updateDeltaTime();
		input = getch();
		_eventManager.update(input);
		if (_eventManager.getSpawnEnemy())
			this->spawnNewEnemy();
        _player->update(_eventManager, _entities, *_player);

        if (_eventManager.getShoot())
            AddEntity(new Bullet(Pos(_player->getPos().getX(), _player->getPos().getY() - 1)));
		if (this->cleanEntityList())
		{
        	AEntity *curnt = _entities;
        	while (curnt) {
            	curnt->update(_eventManager, _entities, *_player);
            	curnt = curnt->next;
        	}
        	_view.update(_entities, *_player);
		}
		else
		{
			erase();
			mvprintw(View::height / 2, View::width / 2, "You're dead !");
			refresh();
			while (getch() != ESCAPE_KEY);
			_eventManager.update(ESCAPE_KEY);
		}
	}
}

void    GameManager::AddEntity(AEntity *newEntity) {
    if (_entities == NULL)
        _entities = newEntity;
    else {
        AEntity *curnt = _entities;
        while (curnt && curnt->next) {
            curnt = curnt->next;
        }
        curnt->next = newEntity;
    }
}

bool	GameManager::cleanEntityList(void)
{
	AEntity		*entities;
	AEntity		*to_remove_next;
	bool		player_in_life;
	Pos			player_pos;
	Pos			entity_pos;

	player_in_life = true;
	entities = this->_entities;
	player_pos = this->_player->getPos();
	while (player_in_life && entities != NULL)
	{
		entity_pos = entities->getPos();
		if (entities->checkCollision(this->_entities) || \
			(entities->getPos().getY() > View::height || entities->getPos().getY() < -10 \
			|| entities->getPos().getX() > View::width || entities->getPos().getX() < 0 ))
		{
			to_remove_next = entities->next;
			this->removeEntity(entities);
			entities = to_remove_next;
		}
		else if (this->_player->checkCollision(this->_entities))
			player_in_life = false;
		else
			entities = entities->next;
	}
	return (player_in_life);
}

void	GameManager::removeEntity(AEntity *to_remove)
{
	AEntity	*entities;
	AEntity	*prev;

	if (this->_entities == to_remove)
	{
		this->_entities = to_remove->next;
		delete to_remove;
	}
	else
	{
		entities = this->_entities;
		while (entities != to_remove)
		{
			prev = entities;
			entities = entities->next;
		}
		prev->next = to_remove->next;
		delete to_remove;
	}
}

void	GameManager::spawnNewEnemy(void) {
	int	rand_x;
	int	y;

	rand_x = rand() % View::width;
	y = -1;
	this->AddEntity(new Enemy(Pos(rand_x, y)));
}
