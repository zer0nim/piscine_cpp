#ifndef EVENTMANAGER_HPP
# define EVENTMANAGER_HPP

# define ESCAPE_KEY 27
# define SPACE_KEY 32

class EventManager {
  public:
    EventManager();
    EventManager(EventManager const &src);
    ~EventManager();

    EventManager &operator=(EventManager const &rhs);

    void    update(const int &input);

    int     getHorizontAxis() const;
    int     getVerticalAxis() const;
    bool    getSpawnEnemy() const;
    bool	getAppRunning() const;
    bool	getShoot() const;

  private:
    void	setHorizontalAxisUp(void);
    void	setHorizontalAxisDown(void);
    void	setVerticalAxisUp(void);
    void	setVerticalAxisDown(void);
    void	setAppRunning(void);
    void	setShoot(void);
    void  resetEvents();

    int     _horizontAxis;
    int     _verticalAxis;
    bool    _spawnEnemy;
    bool	  _app_running;
    bool	  _shoot;
    int     _spawnInterval;
    double  _lastSpawnTime;
};

typedef void (EventManager::*t_event_func)(void);

#endif
