/*
 * Copyright 2011 OpenXcom Developers.
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

#include "UfopaediaSaved.h"
#include "../Ruleset/ArticleDefinition.h"

namespace OpenXcom {
	/**
	 * Constructor
	 */
	UfopaediaSaved::UfopaediaSaved() : _current_index(0)
	{
	}
	
	/**
	 * Destructor
	 */
	UfopaediaSaved::~UfopaediaSaved()
	{
	}
	
	/**
	 * Insert an article to the visible list using insertion sort. Access to the list is by index.
	 * @param article Article definition of the article to insert.
	 */
	void UfopaediaSaved::insertArticle(ArticleDefinition *article)
	{
		// TODO: use insertion sort here!
		_visible_articles.push_back(article);
	}
	
	/**
	 * Fill an ArticleList with the currently visible ArticleIds of the given section. 
	 * @param section Article section to find, e.g. "XCOM Crafts & Armaments", "Alien Lifeforms", etc.
	 * @param data Article definition list object to fill data in.
	 */
	void UfopaediaSaved::getSectionList(std::string section, ArticleDefinitionList &data)
	{
		ArticleDefinitionList::iterator it;
		
		for (it=_visible_articles.begin(); it!=_visible_articles.end(); it++)
		{
			if ((*it)->section == section)
			{
				data.push_back(*it);
			}
		}
	}
	
	/**
	 * set the current index to an article in the list found by a definition object. 
	 * @param article Article definition of the selected article.
	 */
	void UfopaediaSaved::setCurrentArticle(ArticleDefinition *article)
	{
		_current_index = getArticleIndex(article->id);
	}
	
	/**
	 * move the current index to the next article. 
	 * @returns Article definition of the newly selected article, 0 on error.
	 */
	ArticleDefinition *UfopaediaSaved::goNextArticle()
	{
		if (_current_index == _visible_articles.size() - 1)
		{
			// goto first
			_current_index = 0;
		}
		else
		{
			_current_index++;
		}
		
		return _visible_articles[_current_index];
	}
	
	/**
	 * move the current index to the previous article. 
	 * @returns Article definition of the newly selected article, 0 on error.
	 */
	ArticleDefinition *UfopaediaSaved::goPrevArticle()
	{
		if (_current_index == 0)
		{
			// goto last
			_current_index = _visible_articles.size() - 1;
		}
		else
		{
			_current_index--;
		}

		return _visible_articles[_current_index];
	}

	
	/**
	 * Checks, if article id is in the visible list. 
	 * @param article_id Article id to find.
	 * @returns true, if article id was found.
	 */
	bool UfopaediaSaved::isArticleAvailable(std::string &article_id)
	{
		return (-1 != getArticleIndex(article_id));
	}

	/**
	 * Gets the index of the selected article_id in the visible list. 
	 * If the id is not found, returns -1.
	 * @param article_id Article id to find.
	 * @returns Index of the given article id in the internal list, -1 if not found.
	 */
	int UfopaediaSaved::getArticleIndex(std::string &article_id)
	{
		ArticleDefinitionList::iterator it;
		int index = 0;
		
		for (it=_visible_articles.begin(); it!=_visible_articles.end(); it++, index++)
		{
			if ((*it)->id == article_id)
			{
				return index;
			}
		}
		return -1;
	}
	
}
