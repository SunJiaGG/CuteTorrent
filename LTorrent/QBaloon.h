#ifndef QBALLOONTIP_H
#define QBALLOONTIP_H
#include <QWidget>
#include <QSystemTrayIcon>
class QBalloonTip : public QWidget
{
	
public:
	enum QBaloonType
	{
		Error,
		TorrentCompleted,
		UpdateNotyfy,
		Info
	};
	static QWidget *showBalloon(const QString& title,
		const QString& msg,QBaloonType type, QVariant data,const QSystemTrayIcon::MessageIcon& icon=QSystemTrayIcon::Information ,
		int timeout=0, bool showArrow = true,QWidget* parrent=0);
	static void hideBalloon();

private:
	QBalloonTip(const QString& title,const QString& msg,QBaloonType type, QVariant data,
		const QSystemTrayIcon::MessageIcon& icon, QWidget* parent=0);
	~QBalloonTip();
	void balloon(int, bool);

protected:
/*	void paintEvent(QPaintEvent *);*/
	void resizeEvent(QResizeEvent *);
	void mousePressEvent(QMouseEvent *e);
	void timerEvent(QTimerEvent *e);

private:
	QSystemTrayIcon::MessageIcon cuurentIcon;
	QPixmap pixmap;
	QBaloonType currentType;
	QVariant currentData;
	int timerId;

};
#endif