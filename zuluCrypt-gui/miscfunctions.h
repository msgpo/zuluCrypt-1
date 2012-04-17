/*
 * 
 *  Copyright (c) 2011
 *  name : mhogo mchungu
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MISCFUNCTIONS_H
#define MISCFUNCTIONS_H

#include <QString>
#include <QStringList>
#include <blkid/blkid.h>
#include <QProcess>
#include <QFile>
#include <QFile>
#include <QDir>
#include <QTableWidget>
#include <QMessageBox>

#include "../zuluCrypt-cli/constants.h"

class UIMsg
{
public:
	UIMsg(void) ;
	UIMsg(QWidget *) ;
	void setParent(QWidget *);
	void UIMessage(QString,QString);
	int UIMessageWithConfirm(QString,QString);
private:
	QWidget * parent ;
	QPushButton * m_yes ;
	QPushButton * m_no  ;
};

class miscfunctions
{
public:
	static QStringList luksEmptySlots(QString volumePath) ;
	static bool isLuks(QString volumePath) ;
	static QStringList deviceProperties(QString device) ;
	static void addToFavorite(QString dev, QString m_point);
	static QStringList readFavorites(void);
	static void removeFavoriteEntry(QString);
	static bool exists(QString);
	static void addItemToTable(QTableWidget *,QString,QString) ;
	static void addItemToTableWithType(QTableWidget *,QString ,QString,QString);
	static bool canCreateFile(QString);
	static QString resolveHomeSymbol(QString);
	static QString hashPath(QString p);
	static QString cryptMapperPath(void);
	static void debug(QString);
};

#endif // MISCFUNCTIONS_H
