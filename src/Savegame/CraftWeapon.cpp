/*
 * Copyright 2010 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "CraftWeapon.h"
#include "../Ruleset/RuleCraftWeapon.h"

namespace OpenXcom
{

/**
 * Initializes a craft weapon of the specified type.
 * @param rules Pointer to ruleset.
 * @param ammo Initial ammo.
 */
CraftWeapon::CraftWeapon(RuleCraftWeapon *rules, int ammo) : _rules(rules), _ammo(ammo)
{
}

/**
 *
 */
CraftWeapon::~CraftWeapon()
{
}

/**
 * Loads the craft weapon from a YAML file.
 * @param node YAML node.
 */
void CraftWeapon::load(const YAML::Node &node)
{
	node["ammo"] >> _ammo;
}

/**
 * Saves the base to a YAML file.
 * @param out YAML emitter.
 */
void CraftWeapon::save(YAML::Emitter &out) const
{
	out << YAML::BeginMap;
	out << YAML::Key << "type" << YAML::Value << _rules->getType();
	out << YAML::Key << "ammo" << YAML::Value << _ammo;
	out << YAML::EndMap;
}

/**
 * Returns the ruleset for the craft weapon's type.
 * @return Pointer to ruleset.
 */
RuleCraftWeapon *const CraftWeapon::getRules() const
{
	return _rules;
}

/**
 * Returns the ammo contained in this craft weapon.
 * @return Weapon ammo.
 */
int CraftWeapon::getAmmo() const
{
	return _ammo;
}

/**
 * Changes the ammo contained in this craft weapon.
 * @param ammo Weapon ammo.
 */
void CraftWeapon::setAmmo(int ammo)
{
	_ammo = ammo;
	if (_ammo > _rules->getAmmoMax())
	{
		_ammo = _rules->getAmmoMax();
	}
}

/**
 * Rearms this craft weapon's ammo.
 */
void CraftWeapon::rearm()
{
	setAmmo(_ammo + _rules->getRearmRate());
}

}
