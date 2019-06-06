/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:08:04 by eduriez           #+#    #+#             */
/*   Updated: 2019/05/26 20:44:39 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet(): AMovable() {
}

Bullet::Bullet(Pos pos): AMovable(pos) {
    _collidable = true;
    _shape.setC('*');
}


Bullet::~Bullet() {
}

Bullet::Bullet(const Bullet &src) {
	(void)src;
}

Bullet &Bullet::operator=(const Bullet &rhs) {
	(void)rhs;
	return (*this);
}

void	Bullet::update(const EventManager &event_manager, AEntity *entities, AEntity &player) {
	_velocity.setY(1);
    move();
	(void)event_manager;
	(void)entities;
	(void)player;
}
