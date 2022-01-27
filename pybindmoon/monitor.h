#ifndef MONITOR_H
#define MONITOR_H

#include <QThread>

#include "../lewone/lewone.h"
#include "../scrcpy/adbprocess.h"


class monitor : public QThread
{
private:
    QMap<QString, QPointer<Adbprocess>> adbList;
    QMap<QString,int> conectTimeList;
    QSet<lewone *> deviceList;
    
    int MaxConnectTime = 60;
    int port;
    bool MianthreadExit;
    QString path;
    void run();
public:
    monitor(/* args */);
    ~monitor();
    void pushDevice(lewone *device);
    void setPort(int _port);
    void setAdbPatch(QString _path);
};

#endif