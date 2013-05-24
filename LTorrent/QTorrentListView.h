#ifndef _Q_TOR_LIST_VIEW
#define _Q_TOR_LIST_VIEW


#include <QListView>
#include <QMouseEvent>


class QTorrentListView : public QListView
{
	Q_OBJECT
protected:
	virtual void	mousePressEvent ( QMouseEvent * event );
public:
	QTorrentListView(QWidget* parent = 0);
	virtual ~QTorrentListView();
};





#endif