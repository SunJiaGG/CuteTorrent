#include <QThread>
#include "TorrentManager.h"
class MetaDataDownloadWaiter : public QThread
{
	Q_OBJECT
signals:
	void DownloadCompleted(openmagnet_info ti);
public:
	MetaDataDownloadWaiter(QString metaLink,QObject* parrent=NULL, bool autoAdd=false);
	~MetaDataDownloadWaiter();
private:
	bool _autoAdd;
	QString MetaLink;
	TorrentManager * _tManager;
protected:
	void run();
};


