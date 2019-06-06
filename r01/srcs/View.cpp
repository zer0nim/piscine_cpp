/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   View.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:45:34 by eduriez           #+#    #+#             */
/*   Updated: 2019/05/26 21:54:57 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "View.hpp"
#include <iostream>
#include <ncurses.h>

int View::width = 0;
int View::height = 0;

View::View() {
};

View::View(View const &src) {
	*this = src;
};

View::~View() {
};

View &View::operator=(View const &rhs) {
	(void)rhs;
    return *this;
}

void    View::update(AEntity *entities, AEntity &player) {

	Pos		pos_to_print;
	Shape	shape_to_print;

	erase();
	while (entities != NULL)
	{
		pos_to_print = entities->getPos();
		shape_to_print = entities->getShape();
		if (pos_to_print.getX() >= 0 && pos_to_print.getX() <= 0 + View::width
			&& pos_to_print.getY() >= 0 && pos_to_print.getY() <= 0 + View::height)
			this->drawElem(pos_to_print, shape_to_print);
		entities = entities->next;
	}
	pos_to_print = player.getPos();
	shape_to_print = player.getShape();
	this->drawElem(pos_to_print, shape_to_print);
	refresh();
}

void	View::drawElem(const Pos &pos, const Shape &shape)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < shape.getHeight())
	{
		while (j < shape.getWidth())
		{
			mvprintw(pos.getY() + i, pos.getX() + j, "%c", shape.getC());
			j++;
		}
		j = 0;
		i++;
	}
}
