/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:40:49 by eduriez           #+#    #+#             */
/*   Updated: 2019/05/26 20:04:50 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

#include <iostream>
# include "EventManager.hpp"
# include "Pos.hpp"
# include "Shape.hpp"

class AEntity
{
	public:
		AEntity();
		AEntity(Pos pos);
		virtual ~AEntity();
		virtual void	update(const EventManager &event_manager, AEntity *entities, AEntity &player) = 0;
		virtual bool	checkCollision(AEntity *list_entities) = 0;

		Pos	getPos() const;
		Shape	getShape() const;
		bool	getCollidable() const;

		AEntity			*next;
	protected:
		Pos				_pos;
		Shape			_shape;
		bool			_collidable;
};

#endif
