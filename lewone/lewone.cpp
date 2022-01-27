#include "lewone.h"
#include <qt_windows.h>

lewone::lewone() : isConnected(false), restart(false), size(0, 0)
{
    HRESULT r = OleInitialize(0);
    if (r != S_OK && r != S_FALSE)
    {
        qInfo() << "Qt: OleInitialize fail " << r;
    }
    lw = new lwsoft();
}

lewone::~lewone()
{
    free(bmpBuff);
    delete lw;
    OleUninitialize();
}

lwsoft *lewone::getObj()
{
    return lw;
}

void lewone::consumeFrame(uint8_t *data,int width,int height)
{
    isConnected = true;
    BmpHead m_BMPHeader = {0};
    InfoHead m_BMPInfoHeader = {0};
    char bfType[2] = {'B', 'M'};
    int header_size = sizeof(bfType) + sizeof(BmpHead) + sizeof(InfoHead);

    m_BMPHeader.imageSize = 3 * width * height + header_size;
    m_BMPHeader.startPosition = header_size;
    m_BMPInfoHeader.Length = sizeof(InfoHead);
    m_BMPInfoHeader.width = width;
    m_BMPInfoHeader.height = height;
    m_BMPInfoHeader.colorPlane = 1;
    m_BMPInfoHeader.bitColor = 24;
    m_BMPInfoHeader.realSize = 3 * width * height;

    bmpBuff = realloc(bmpBuff, header_size + width * (height + 8) * 3);

    memcpy(bmpBuff, bfType, sizeof(bfType));
    memcpy((uint8_t *)bmpBuff + sizeof(bfType), &m_BMPHeader, sizeof(m_BMPHeader));
    memcpy((uint8_t *)bmpBuff + sizeof(m_BMPHeader) + sizeof(bfType), &m_BMPInfoHeader, sizeof(m_BMPInfoHeader));

    for (int scan = 1; scan < height; scan++)
    {
        memcpy((uint8_t *)bmpBuff + header_size + width * (height - scan) * 3, (uint8_t *)data + width * scan * 3, width * 3);
    }
    
    lw->SetDisplayInput(QString::number((int)bmpBuff));
    size.setWidth(width);
    size.setHeight(height);
    QDateTime time = QDateTime::currentDateTime(); //获取当前时间
    LNFTime = time.toTime_t();
}

void lewone::consumeStop()
{
    isConnected = false;
}

uint lewone::getLNFT()
{
    QDateTime time = QDateTime::currentDateTime(); //获取当前时间
    return time.toTime_t() - LNFTime;
}

void lewone::setReDecoder()
{
    restart = true;
    stopDecoder();
}

const bool lewone::getStatus()
{
    return isConnected;
}

bool lewone::getReStart()
{
    return restart;
}

void lewone::setRest(bool rest)
{
    restart = rest;
}

const int lewone::x()
{
    return size.width();
}

const int lewone::y()
{
    return size.height();
}
