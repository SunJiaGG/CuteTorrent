#pragma once
#include <QAbstractItemModel>
#include "Torrent.h"
class FileTabelModel :
	public QAbstractItemModel
{
private:
	QList<file_info> dataContainer;
public:
	FileTabelModel(QObject *parent = 0);
	~FileTabelModel(void);

	 QModelIndex index( int row, int column, const QModelIndex &parent = QModelIndex( ) ) const;

	 QModelIndex parent( const QModelIndex &child ) const;

	 int rowCount( const QModelIndex &parent = QModelIndex( ) ) const;

	 int columnCount( const QModelIndex &parent = QModelIndex( ) ) const;

	 QVariant data( const QModelIndex &index, int role = Qt::DisplayRole ) const;

	

	 QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

	 Qt::ItemFlags flags( const QModelIndex &index ) const;

	void UpdateSource(QList<file_info> newData);
};
