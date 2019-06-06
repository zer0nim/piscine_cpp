#include "EventManager.hpp"
#include "ClockTime.hpp"
#include <iostream>
#include <ncurses.h>

EventManager::EventManager() {
    resetEvents();
    _lastSpawnTime = ClockTime::curentTime();
    _spawnInterval = 2;
};

EventManager::EventManager(EventManager const &src) {
    *this = src;
};

EventManager::~EventManager() {
};

EventManager &EventManager::operator=(EventManager const &rhs) {
	(void)rhs;
    return *this;
}

void    EventManager::update(const int &input) {

	this->resetEvents();

	// spawn enemy each _spawnInterval
	double diffTime = ClockTime::curentTime() - _lastSpawnTime;
    if (diffTime > _spawnInterval) {
		_lastSpawnTime = ClockTime::curentTime();
        _spawnEnemy = true;
    }

	const	int				inputs[] = {
		ESCAPE_KEY, SPACE_KEY, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
	};
	const 	t_event_func	tab_methods[] = {
		&EventManager::setAppRunning,
		&EventManager::setShoot,
		&EventManager::setVerticalAxisUp,
		&EventManager::setVerticalAxisDown,
		&EventManager::setHorizontalAxisDown,
		&EventManager::setHorizontalAxisUp,
	};
	int						i;
	bool					found;

	i = 0;
	found = false;
	while (!found && i < 6)
	{
		if (inputs[i] == input)
			found = true;
		else
			i++;
	}
	if (found)
		(this->*tab_methods[i])();
}

int     EventManager::getHorizontAxis() const { return _horizontAxis; }
int     EventManager::getVerticalAxis() const { return _verticalAxis; }
bool    EventManager::getSpawnEnemy() const { return _spawnEnemy; }
bool	EventManager::getAppRunning() const { return _app_running; }
bool	EventManager::getShoot() const { return _shoot; }

void	EventManager::setHorizontalAxisDown(void)
{
	this->_horizontAxis = 1;
}

void	EventManager::setHorizontalAxisUp(void)
{
	this->_horizontAxis = -1;
}

void	EventManager::setVerticalAxisDown(void)
{
	this->_verticalAxis = -1;
}

void	EventManager::setVerticalAxisUp(void)
{
	this->_verticalAxis = 1;
}

void	EventManager::setAppRunning(void)
{
	this->_app_running = false;
}

void	EventManager::setShoot(void)
{
	this->_shoot = true;
}

void    EventManager::resetEvents() {
    _horizontAxis = 0;
    _verticalAxis = 0;
    _spawnEnemy = false;
	_app_running = true;
	_shoot = false;
}
