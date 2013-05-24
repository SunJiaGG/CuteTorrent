#include "QTorrentListView.h"
QTorrentListView::QTorrentListView(QWidget* parent ) : QListView(parent)
{

}

void	QTorrentListView::mousePressEvent ( QMouseEvent * event )
{
		QModelIndex index = indexAt(event->pos());
		
	if (index.isValid()) {
		selectionModel()->select(index, QItemSelectionModel::ClearAndSelect);
	} else {
		clearSelection();
	}
}
QTorrentListView::~QTorrentListView(){};
