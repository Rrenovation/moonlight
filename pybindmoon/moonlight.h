#ifndef MOONLIGHT_H
#define MOONLIGHT_H
#include <QCoreApplication>
#include <QThread>

#include "light.h"
#include "monitor.h"
#include "../scrcpy/server.h"
#include "../lewone/lewone.h"

class moonlight : public QThread
{
private:
    QPointer<QCoreApplication> mApp;
    QMap<QString, QPointer<lewone>> deviceList;
    QPointer<Server> server;
    QPointer<monitor> monitors;
    int port;
    bool Running;
    void run();
public:
    moonlight(int _port = 37321, int argc = 0, char **argv = nullptr);
    ~moonlight();
    void loop();
    bool isRunning() const;
    light getLight(std::string deviceName);
    void setAdbPatch(string _path);
};

#endif