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
#ifndef OPENXCOM_MAPDATASET_H
#define OPENXCOM_MAPDATASET_H

#include <string>
#include <vector>

namespace OpenXcom
{

class MapData;
class SurfaceSet;
class ResourcePack;
class MapModel;

/**
 * Represents a Terrain Map Datafile.
 * Which corresponds to an Xcom MCD & PCK file.
 * The list of map datafiles is stored in RuleSet, but referenced in RuleTerrain.
 * @sa http://www.ufopaedia.org/index.php?title=MCD
 */
class MapDataSet
{
private:
	std::string _name;
	int _size;
	std::vector<MapData*> _objects;
	std::vector<MapModel*> _models;
	SurfaceSet *_surfaceSet;
	bool _loaded;
public:
	MapDataSet(std::string name, int size);
	~MapDataSet();
	/// Get the dataset name (used for MAP generation).
	std::string getName();
	/// Get the dataset size.
	int getSize();
	/// Get objects in this dataset.
	std::vector<MapData*> *getObjects();
	/// Get surfaces in this dataset.
	SurfaceSet *getSurfaceset();
	/// Load the objects from an MCD file.
	void load(ResourcePack *res);
	///	Unload to free memory.
	void unload();
};

}

#endif
