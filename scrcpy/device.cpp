#include "device.h"

#include "./decoder/decoder.h"
#include "./decoder/avframeconvert.h"
#include "./decoder/tcpserver.h"
#include "./decoder/stream.h"
#include "./decoder/videosocket.h"
#include "./decoder/videobuffer.h"
#include "./controller/controller.h"
#include "./controller/action.h"

Device::Device(QObject *parent) : QObject(parent),
                                  decoder(new Decoder()), stream(new Stream()),action(new Action)
{

    connect(decoder, &Decoder::onNewFrame, this, &Device::consumeNewFrame, Qt::DirectConnection);
    connect(stream, &Stream::onStreamStop, this, &Device::stop, Qt::DirectConnection);
}

Device::~Device()
{
    stream->stopDecode();
}

const QString Device::getDeviceName()
{
    return deviceName;
}

void Device::setVideoSocket(VideoSocket *videoSocket)
{
    stream->setDecoder(decoder);
    stream->setVideoSocket(videoSocket);
    stream->startDecode();
}

void Device::setDeviceSocket(QTcpSocket *socket)
{
    if (controller.isNull())
    {
        controller = new Controller();
        action->setCtl(controller);
    }
    controller->setDeviceSocket(socket);
}

void Device::consumeNewFrame()
{
    auto videoBuffer = decoder->getVideoBuff();
    videoBuffer->lock();
    auto AVFrame = videoBuffer->consumeRenderedFrame(AV_PIX_FMT_BGR24);
    consumeFrame(AVFrame->data[0],AVFrame->width,AVFrame->height);
    emit newFrame();
    videoBuffer->unLock();
}

void Device::stop()
{
    consumeStop();
}

void Device::stopDecoder()
{
    stream->stopDecode();
}

void Device::consumeFrame(uint8_t *data,int width,int height)
{
    qInfo() << "consumed Device Frame";
}
void Device::consumeStop()
{
    qInfo() << "consumeStop ";
}

void Device::setDeviceName(QString deviceName)
{
    this->deviceName = deviceName;
}

std::shared_ptr<Action> Device::getAction()
{
    return action;
}
