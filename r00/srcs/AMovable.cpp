/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMovable.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:16:35 by eduriez           #+#    #+#             */
/*   Updated: 2019/05/26 22:57:24 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMovable.hpp"
#include "View.hpp"
#include "ClockTime.hpp"
#include <iostream>
#include <math.h>

AMovable::AMovable() : AEntity(), _speed(20) {
}

AMovable::AMovable(Pos pos) : AEntity(pos), _speed(40) {
}

AMovable::~AMovable() {
}

void	AMovable::move() {
	float velX = fabs(_velocity.getFloatX());
	float velY = fabs(_velocity.getFloatY());

	float add = (ClockTime::deltaTime * _speed);
	float addX = velX > add ? add : velX;
	float addY = velY > add ? add : velY;

	if (_velocity.getFloatX() < 0)
	{
		_velocity.setX(_velocity.getFloatX() + addX);
		_pos.setX(_pos.getFloatX() + addX);
	}
	else if (_velocity.getFloatX() > 0)
	{
		_velocity.setX(_velocity.getFloatX() - addX);
		_pos.setX(_pos.getFloatX() - addX);
	}

	if (_velocity.getFloatY() < 0)
	{
		_velocity.setY(_velocity.getFloatY() + addY);
		_pos.setY(_pos.getFloatY() + addY);
	}
	else if (_velocity.getFloatY() > 0)
	{
		_velocity.setY(_velocity.getFloatY() - addY);
		_pos.setY(_pos.getFloatY() - addY);
	}
}

bool	testColision(Pos a_pos, Shape a_shape, Pos b_pos, Shape b_shape) {
	if (a_pos.getX() < b_pos.getX() + b_shape.getWidth() &&
		a_pos.getX() + a_shape.getWidth() > b_pos.getX() &&
		a_pos.getY() < b_pos.getY() + b_shape.getHeight() &&
		a_shape.getHeight() + a_pos.getY() > b_pos.getY()) {
		return true;
	}
	return false;
}

bool	AMovable::checkCollision(AEntity *list_entities) {

	Pos		pos_current;
	Shape	shape_current;
	Pos		this_pos;
	Shape	this_shape;
	bool	collision;

	this_pos = this->getPos();
	this_shape = this->getShape();
	collision = false;

	while (!collision && list_entities != NULL)
	{
		if (this != list_entities)
		{
			pos_current = list_entities->getPos();
			shape_current = list_entities->getShape();

			if (testColision(this_pos, this_shape, pos_current, shape_current))
				collision = true;
			else
				list_entities = list_entities->next;
		}
		else
			list_entities = list_entities->next;
	}
	return (collision);
}
