/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:55:42 by eduriez           #+#    #+#             */
/*   Updated: 2019/05/26 18:10:05 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"

AEntity::AEntity(): next(NULL), _collidable(false) {
}

AEntity::AEntity(Pos pos): next(NULL), _pos(pos), _collidable(false) {
}

AEntity::~AEntity() {
}

Pos	AEntity::getPos() const { return _pos; }
Shape	AEntity::getShape() const { return _shape; }
bool	AEntity::getCollidable() const { return _collidable; }
