/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMovable.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:12:35 by eduriez           #+#    #+#             */
/*   Updated: 2019/05/26 20:03:22 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMOVABLE_HPP
# define AMOVABLE_HPP

# include "AEntity.hpp"

class AMovable : public AEntity
{
	public:
		AMovable();
		AMovable(Pos pos);
		virtual ~AMovable();
		virtual bool	checkCollision(AEntity *list_entities);
		void	move();
	protected:
		Pos		_velocity;
		float	_speed;
};

#endif
