/*
 * 
 *  Copyright (c) 2013
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
#ifndef AUTO_MOUNT_HELPER_H
#define AUTO_MOUNT_HELPER_H

#include <QThreadPool>
#include <QString>
#include <QStringList>
#include "bin_path.h"
#include <QProcess>

#include <sys/inotify.h>

class auto_mount_helper :public QObject, public QRunnable
{
	Q_OBJECT
public:
	explicit auto_mount_helper( QObject * parent = 0 );
	~auto_mount_helper() ;
	void start( QString device,int type,u_int32_t mask ) ;
signals:
	void deviceRemoved( QString ) ;
	void getVolumeSystemInfo( QStringList ) ;
	void getVolumeInfo( QStringList ) ;
private:
	bool deviceIsSystem( void ) ;
	bool deviceMatchLVMFormat( void ) ;
	void volumeProperties( void ) ;
	void deviceFromDev( void ) ;
	void deviceFromDevMapper( void ) ;
	void run( void ) ;
	bool m_deviceFromDev ;
	bool m_deviceFromDevMapper ;
	QString m_device ;
	int m_type ;
	u_int32_t m_mask ;
};

#endif // AUTO_MOUNT_HELPER_H
