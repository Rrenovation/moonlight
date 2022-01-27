#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QtCore>

class Decoder;
class Stream;
class VideoBuffer;
class VideoSocket;
class QTcpSocket;
class Controller;
class Action;

class Device : public QObject
{
    Q_OBJECT
private:
    QString deviceName;
    QPointer<Decoder> decoder;
    QPointer<Stream> stream;
    QPointer<Controller> controller;
    std::shared_ptr<Action> action;

private slots:
    void consumeNewFrame();
    void stop();
signals:
    void newFrame();
public:
    Device(QObject *parent = nullptr);
    virtual ~Device();
    void setVideoSocket(VideoSocket *videoSocket);
    void setDeviceSocket(QTcpSocket *socket);
    void setDeviceName(QString deviceName);
    void stopDecoder();
    virtual void consumeFrame(uint8_t *data,int width,int height);
    virtual void consumeStop();
    const QString getDeviceName();
    std::shared_ptr<Action> getAction();
};

#endif