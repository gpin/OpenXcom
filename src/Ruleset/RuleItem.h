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
#ifndef OPENXCOM_RULEITEM_H
#define OPENXCOM_RULEITEM_H

#include <string>
#include <vector>

enum ItemDamageType { DT_NONE, DT_AP, DT_IN, DT_HE, DT_LASER, DT_PLASMA, DT_STUN, DT_MELEE, DT_ACID, DT_SMOKE };
enum BattleType { BT_FIREARM, BT_AMMO, BT_MELEE, BT_GRENADE, BT_PROXIMITYGRENADE, BT_MEDIKIT, BT_SCANNER };

namespace OpenXcom
{

/**
 * Represents a specific type of item.
 * Contains constant info about an item like
 * storage size, sell price, etc.
 * @sa Item
 */
class RuleItem
{
private:
	std::string _type;
	float _size;
	int _cost, _time;
	bool _equip, _twoHanded;
	int _bigSprite, _floorSprite, _handSprite, _bulletSprite;
	int _fireSound, _hitSound, _hitAnimation;
	int _power, _accuracyAuto, _accuracySnap, _accuracyAimed;
	std::vector<std::string> _compatibleAmmo;
	ItemDamageType _damageType;
	BattleType _battleType;
public:
	/// Creates a blank item ruleset.
	RuleItem(std::string type);
	/// Cleans up the item ruleset.
	~RuleItem();
	/// Gets the item's type.
	std::string getType() const;
	/// Gets the item's size.
	float getSize() const;
	/// Sets the item's size.
	void setSize(float size);
	/// Gets the item's cost.
	int getCost() const;
	/// Sets the item's cost.
	void setCost(int cost);
	/// Gets the item's transfer time.
	int getTransferTime() const;
	/// Sets the item's transfer time.
	void setTransferTime(int time);
	/// Gets if the item is equippable.
	bool getEquippable() const;
	/// Sets if the item is equippable.
	void setEquippable(bool equip);
	/// Gets the item's reference in BIGOBS.PCK for use in inventory.
	int getBigSprite() const;
	/// Sets the item's reference in BIGOBS.PCK for use in inventory.
	void setBigSprite(int sprite);
	/// Gets the item's reference in FLOOROB.PCK for use in inventory.
	int getFloorSprite() const;
	/// Sets the item's reference in FLOOROB.PCK for use in inventory.
	void setFloorSprite(int sprite);
	/// Gets the item's reference in HANDOB.PCK for use in inventory.
	int getHandSprite() const;
	/// Sets the item's reference in HANDOB.PCK for use in inventory.
	void setHandSprite(int sprite);
	/// Gets if the item is two-handed.
	bool getTwoHanded() const;
	/// Sets if the item is two-handed.
	void setTwoHanded(bool flag);
	/// Gets the item's bullet sprite reference.
	int getBulletSprite() const;
	/// Sets the item's bulet sprite reference.
	void setBulletSprite(int sprite);
	/// Gets the item's fire sound.
	int getFireSound() const;
	/// Sets the item's fire sound.
	void setFireSound(int sound);
	/// Gets the item's hit sound.
	int getHitSound() const;
	/// Sets the item's hit sound.
	void setHitSound(int sound);
	/// Gets the item's hit animation.
	int getHitAnimation() const;
	/// Sets the item's hit animation.
	void setHitAnimation(int animation);
	/// Gets the item's power.
	int getPower() const;
	/// Sets the item's power.
	void setPower(int power);
	/// Gets the item's accuracy.
	int getAccuracySnap() const;
	/// Sets the item's accuracy.
	void setAccuracySnap(int accuracy);
	/// Gets list of compatible ammo.
	std::vector<std::string> *getCompatibleAmmo();
	/// Gets the item's damage type.
	ItemDamageType getDamageType() const;
	/// Sets the item's damage type.
	void setDamageType(ItemDamageType damageType);
	/// Gets the item's type.
	BattleType getBattleType() const;
	/// Sets the item's type.
	void setBattleType(BattleType type);
};

}

#endif
