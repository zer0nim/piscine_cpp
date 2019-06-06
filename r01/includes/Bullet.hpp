/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 00:05:48 by emarin            #+#    #+#             */
/*   Updated: 2019/05/26 20:06:50 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include "AMovable.hpp"

class Bullet : public AMovable {
	public:
		Bullet(Pos pos);
		Bullet(Bullet const &src);
		virtual	~Bullet();

		Bullet &operator=(Bullet const &rhs);

		virtual void	update(const EventManager &event_manager, AEntity *entities, AEntity &player);
	protected:
		Bullet();
};

#endif
