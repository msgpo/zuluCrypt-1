#ifndef KEYDIALOG_H
#define KEYDIALOG_H

#include <QDialog>
#include <QString>
#include <QCloseEvent>
#include <QFileDialog>
#include <QDir>
#include <QMenu>
#include <QTableWidget>

#include "../zuluCrypt-gui/dialogmsg.h"
#include "managepartitionthread.h"
#include "../zuluCrypt-gui/miscfunctions.h"
#include "../zuluCrypt-cli/constants.h"
#include "plugin_path.h"
#include "../zuluCrypt-gui/zuluoptions.h"
#include "../zuluCrypt-gui/socketsendkey.h"
#include "../zuluCrypt-gui/openvolumereadonly.h"
#include "mainwindow.h"

namespace Ui {
class keyDialog;
}

class keyDialog : public QDialog
{
	Q_OBJECT
public:
	keyDialog( QWidget * parent,QTableWidget *,QString path );
	~keyDialog();
	void ShowUI( void );
	void HideUI( void ) ;
signals:
	void mounted( QString ) ;
	void cryptoOpen( QString ) ;
	void hideUISignal( void ) ;
public slots:
	void slotMountComplete( int,QString ) ;
private slots:
	void pbMountPointPath( void ) ;
	void pbPluginEntryClicked( QAction * ) ;
	void keyTextChanged( QString ) ;
	void rbPlugIn( bool ) ;
	void rbKey( bool ) ;
	void rbKeyFile( bool ) ;
	void pbOpen( void ) ;
	void pbCancel( void ) ;
	void pbPlugin( void );
	void pbKeyFile( void ) ;
	void cbMountReadOnlyStateChanged( int ) ;
	void volumeMiniProperties( QString ) ;
private:
	void enableAll( void ) ;
	void disableAll( void ) ;
	void closeEvent( QCloseEvent * );
	Ui::keyDialog * m_ui;
	QString m_path ;
	QMenu * m_menu ;
	QTableWidget * m_table ;
};

#endif // KEYDIALOG_H
