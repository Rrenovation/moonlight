#include <qaxobject.h>
#include <QMutex>
#include <QPointer>

class myQAxObject : public QAxObject
{
public:
    explicit myQAxObject(QObject *parent = nullptr) : QAxObject(parent), mutex(new QMutex){

                                                                         };
    explicit myQAxObject(const QString &c, QObject *parent = nullptr) : QAxObject(c, parent){

                                                                        };
    explicit myQAxObject(IUnknown *iface, QObject *parent = nullptr) : QAxObject(iface, parent){

                                                                       };
    ~myQAxObject()
    {
    }

    int myQAxObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
    {
        Lock();
        _id = QAxObject::qt_metacall(_c, _id, _a);
        Ulock();
        return _id;
    }
    inline void Lock()
    {
        mutex->lock();
    }
    inline void Ulock()
    {
        mutex->unlock();
    }

private:
    std::unique_ptr<QMutex> mutex;
};
