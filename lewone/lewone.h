#ifndef LEWONE_H
#define LEWONE_H

#include "lw.h"
#include "../scrcpy/device.h"

//定义相应的bmp数据头结构体
/** must needed. pack */
#pragma pack(1)
typedef struct
{
    long imageSize;
    long blank;
    long startPosition;
} BmpHead;

typedef struct
{
    long Length;
    long width;
    long height;
    unsigned short colorPlane;
    unsigned short bitColor;
    long zipFormat;
    long realSize;
    long xPels;
    long yPels;
    long colorUse;
    long colorImportant;
} InfoHead;
#pragma pack()

using namespace lw;

class lewone : public Device
{
    Q_OBJECT
private:
    QSize size;
    lwsoft *lw = Q_NULLPTR;
    void *bmpBuff = Q_NULLPTR;
    uint LNFTime;
    bool isConnected;
    bool restart;
    
public:
    lewone(/* args */);
    ~lewone();
    virtual void consumeFrame(uint8_t *data,int width,int height);
    virtual void consumeStop();
    lwsoft *getObj();
    uint getLNFT();
    void setReDecoder();
    const bool getStatus();
    bool getReStart();
    void setRest(bool rest);

    const int x();
    const int y();
  
};

#endif // MYLE_H
