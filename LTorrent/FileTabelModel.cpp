#include "FileTabelModel.h"

FileTabelModel::FileTabelModel( QObject *parent /*= 0*/ ) : dataContainer(QList<file_info>())
{
	
}

FileTabelModel::~FileTabelModel( void )
{

}

QModelIndex FileTabelModel::index( int row, int column, const QModelIndex &parent /*= QModelIndex( ) */ ) const
{
	if (!hasIndex(row,column,parent))
	{
		return QModelIndex();
	}
	if (parent.isValid())
	{
		return parent.child(row,column);
	} 
	else
	{
		return createIndex(row,column);
	}
}

QModelIndex FileTabelModel::parent( const QModelIndex &child ) const
{
	if (!child.isValid())
		return QModelIndex();
	return child.parent();
}

int FileTabelModel::rowCount( const QModelIndex &parent /*= QModelIndex( ) */ ) const
{
	return dataContainer.count();
}

int FileTabelModel::columnCount( const QModelIndex &parent /*= QModelIndex( ) */ ) const
{
	return 4;
}

QVariant FileTabelModel::data( const QModelIndex &index, int role /*= Qt::DisplayRole */ ) const
{
	if (!index.isValid())
		return QVariant();
	
	if (role==Qt::DisplayRole)
	{
		int row = index.row();
		int column = index.column();
		if (column>4)
			return QVariant();
		file_info current = dataContainer.at(row);
		switch(column)
		{
		case 0:
			return qVariantFromValue(current.name);
		case 1:
			return qVariantFromValue(StaticHelpers::toKbMbGb(current.size));
		case 2:
			return qVariantFromValue(QString::number(current.progrss,'f',0)+" %");
		case 3:
			return qVariantFromValue(StaticHelpers::filePriorityToString(current.prioiry));
		default:
			return QVariant();
		}
	}
	return QVariant();
}


QVariant FileTabelModel::headerData( int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole */ ) const
{
	return qVariantFromValue("HEADER_DATA"+QString::number(section));
}

Qt::ItemFlags FileTabelModel::flags( const QModelIndex &index ) const
{
	if (!index.isValid())
		return 0;

	return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

void FileTabelModel::UpdateSource( QList<file_info> newData )
{
	dataContainer=newData;
}
