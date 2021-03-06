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
 * along with OpenXcom.  If not, see <http:///www.gnu.org/licenses/>.
 */
#ifndef OPENXCOM_BATTLESCAPESTATE_H
#define OPENXCOM_BATTLESCAPESTATE_H

#include "../Engine/State.h"
#include "Position.h"
#include <list>

namespace OpenXcom
{

class Surface;
class Map;
class ImageButton;
class InteractiveSurface;
class Text;
class Bar;
class NumberText;
class BattleUnit;
class SavedBattleGame;
class BattleItem;
class Window;
class BattleState;
class Timer;

enum BattleActionType { BA_NONE, BA_THROW, BA_AUTOSHOT, BA_SNAPSHOT, BA_AIMEDSHOT, BA_STUN, BA_HIT };

#define DEFAULT_WALK_SPEED 40
#define DEFAULT_BULLET_SPEED 20
#define DEFAULT_ANIM_SPEED 100

/**
 * Battlescape screen which shows the tactical battle
 */
class BattlescapeState : public State
{
private:
	Surface *_icons, *_rank;
	Map *_map;
	InteractiveSurface *_btnUnitUp, *_btnUnitDown, *_btnMapUp, *_btnMapDown, *_btnShowMap, *_btnKneel;
	InteractiveSurface *_btnSoldier, *_btnCenter, *_btnNextSoldier, *_btnNextStop, *_btnShowLayers, *_btnHelp;
	InteractiveSurface *_btnEndTurn, *_btnAbort;
	ImageButton *_reserve;
	ImageButton *_btnReserveNone, *_btnReserveSnap, *_btnReserveAimed, *_btnReserveAuto;
	ImageButton *_btnLeftHandItem, *_btnRightHandItem;
	Text *_txtName;
	NumberText *_numTimeUnits, *_numEnergy, *_numHealth, *_numMorale, *_numLayers, *_numAmmoLeft, *_numAmmoRight;
	Bar *_barTimeUnits, *_barEnergy, *_barHealth, *_barMorale;
	Timer *_stateTimer, *_animTimer;
	SavedBattleGame *_battleGame;

	BattleActionType _selectedAction;
	BattleItem *_selectedItem;
	Position _target;
	std::list<BattleState*> _states;
	bool _targeting;

	void checkActionFinished();
	void handleItemClick(BattleItem *item);
	void drawItemSprite(BattleItem *item, Surface *surface);
public:
	/// Creates the Battlescape state.
	BattlescapeState(Game *game);
	/// Cleans up the Battlescape state.
	~BattlescapeState();
	/// init
	void init();
	/// think
	void think();
	/// Handler for clicking the map.
	void mapClick(Action *action);
	/// Handler for clicking the Unit Up button.
	void btnUnitUpClick(Action *action);
	/// Handler for clicking the Unit Down button.
	void btnUnitDownClick(Action *action);
	/// Handler for clicking the Map Up button.
	void btnMapUpClick(Action *action);
	/// Handler for clicking the Map Down button.
	void btnMapDownClick(Action *action);
	/// Handler for clicking the Show Map button.
	void btnShowMapClick(Action *action);
	/// Handler for clicking the Kneel button.
	void btnKneelClick(Action *action);
	/// Handler for clicking the Soldier button.
	void btnSoldierClick(Action *action);
	/// Handler for clicking the Center button.
	void btnCenterClick(Action *action);
	/// Handler for clicking the Next Soldier button.
	void btnNextSoldierClick(Action *action);
	/// Handler for clicking the Next Stop button.
	void btnNextStopClick(Action *action);
	/// Handler for clicking the Show Layers button.
	void btnShowLayersClick(Action *action);
	/// Handler for clicking the Help button.
	void btnHelpClick(Action *action);
	/// Handler for clicking the End Turn button.
	void btnEndTurnClick(Action *action);
	/// Handler for clicking the Abort button.
	void btnAbortClick(Action *action);
	/// Handler for clicking the left hand item button.
	void btnLeftHandItemClick(Action *action);
	/// Handler for clicking the right hand item button.
	void btnRightHandItemClick(Action *action);
	/// updates soldier name/rank/tu/energy/health/morale
	void updateSoldierInfo(BattleUnit *unit);
	/// handlestates timer.
	void handleState();
	/// Animate other stuff.
	void animate();
	/// Get target position.
	Position getTarget() const;
	/// Get game.
	Game *getGame() const;
	/// Get map.
	Map *getMap() const;
	/// Push a state at the front of the list.
	void statePushFront(BattleState *bs);
	/// Push a state at the second of the list.
	void statePushNext(BattleState *bs);
	/// Push a state at the back of the list.
	void statePushBack(BattleState *bs);
	/// Remove current state.
	void popState();
	/// Set state think interval.
	void setStateInterval(Uint32 interval);
	/// Get selected item.
	BattleItem *getSelectedItem() const;
};

}

#endif
