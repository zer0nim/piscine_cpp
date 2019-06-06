/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:25:21 by eduriez           #+#    #+#             */
/*   Updated: 2019/05/26 18:08:52 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AMovable.hpp"

class Enemy : public AMovable {
	public:
		Enemy(Pos pos);
		Enemy(Enemy const &src);
		virtual ~Enemy();

		Enemy &operator=(Enemy const &rhs);

		void	update(const EventManager &event_manager, AEntity *entities, AEntity &player);
	protected:
		Enemy();
};

#endif
