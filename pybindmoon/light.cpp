#include "light.h"

#include "../scrcpy/controller/action.h"

light::light(lewone *_lew) : adb(new Adbprocess())
{
    lew = _lew;
    mlwsoft = lew->getObj();
    action = lew->getAction();
}

light::~light()
{
}

bool light::status()
{
    return lew->getStatus();
}

void light::hold(int x, int y, quint64 id)
{
    action->fingerHold(QRect(x, y, lew->x(), lew->y()), id);
}
void light::move(int x, int y, quint64 id)
{
    action->fingerMove(QRect(x, y, lew->x(), lew->y()), id);
}
void light::release(int x, int y, quint64 id)
{
    action->fingerRelease(QRect(x, y, lew->x(), lew->y()), id);
}
void light::click(int x, int y, quint64 id)
{
    action->click(QRect(x, y, lew->x(), lew->y()), id);
}
void light::sendText(string text)
{
    action->sendText(QString::fromStdString(text));
}
void light::sendTextEx(string text)
{
    action->sendTextEx(QString::fromStdString(text));
}
void light::goHome()
{
    action->goHome();
}
void light::onClear(int num)
{
    action->onClear(num);
}

int light::setDict(int index, string file, string pwd)
{
    return mlwsoft->SetDict(index,
                            QString::fromStdString(file),
                            QString::fromStdString(pwd));
}

int light::useDict(int index)
{
    return mlwsoft->UseDict(index);
}

string light::ocr(int x1, int y1, int x2, int y2, string color_format, double sim, string linesign, int isbackcolor)
{
    return mlwsoft->Ocr(x1, y1, x2, y2,
                        QString::fromStdString(color_format),
                        sim,
                        QString::fromStdString(linesign),
                        isbackcolor)
        .toStdString();
}

int light::findStr(int x1, int y1, int x2, int y2, string str_format, string color_format, double sim, int isbackcolor)
{
    return mlwsoft->FindStr(x1, y1, x2, y2,
                            QString::fromStdString(str_format),
                            QString::fromStdString(color_format),
                            sim,
                            isbackcolor);
}

string light::findStrEx(int x1, int y1, int x2, int y2, string str_format, string color_format, double sim, int isbackcolor)
{
    return mlwsoft->FindStrEx(x1, y1, x2, y2,
                              QString::fromStdString(str_format),
                              QString::fromStdString(color_format),
                              sim,
                              isbackcolor)
        .toStdString();
}

int light::findStrFast(int x1, int y1, int x2, int y2, string str_format, string color_format, double sim, int isbackcolor)
{
    return mlwsoft->FindStrFast(x1, y1, x2, y2,
                                QString::fromStdString(str_format),
                                QString::fromStdString(color_format),
                                sim,
                                isbackcolor);
}

string light::findStrFastEx(int x1, int y1, int x2, int y2, string str_format, string color_format, double sim, int isbackcolor)
{
    return mlwsoft->FindStrFastEx(x1, y1, x2, y2,
                                  QString::fromStdString(str_format),
                                  QString::fromStdString(color_format),
                                  sim,
                                  isbackcolor)
        .toStdString();
}

string light::fetchLattice(int x1, int y1, int x2, int y2, string color_format, int isBackColor)
{
    return mlwsoft->FetchLattice(x1, y1, x2, y2,
                                 QString::fromStdString(color_format),
                                 isBackColor)
        .toStdString();
}

int light::finPic(int x1, int y1, int x2, int y2, string pic_name, string delta_color, double sim, int dir)
{
    return mlwsoft->FindPic(x1, y1, x2, y2,
                            QString::fromStdString(pic_name),
                            QString::fromStdString(delta_color),
                            sim,
                            dir);
}

string light::finPicEx(int x1, int y1, int x2, int y2, string pic_name, string delta_color, double sim, int dir)
{
    return mlwsoft->FindPicEx(x1, y1, x2, y2,
                              QString::fromStdString(pic_name),
                              QString::fromStdString(delta_color),
                              sim,
                              dir)
        .toStdString();
}

int light::findBrightPoint(int x1, int y1, int x2, int y2, int lower, int Upper)
{
    return mlwsoft->FindBrightPoint(x1, y1, x2, y2, lower, Upper);
}

int light::findColor(int x1, int y1, int x2, int y2, string color, double sim, int dir)
{
    return mlwsoft->FindColor(x1, y1, x2, y2,
                              QString::fromStdString(color), sim, dir);
}

int light::capture(int x1, int y1, int x2, int y2, string file)
{
    return mlwsoft->Capture(x1, y1, x2, y2, QString::fromStdString(file));
}

int light::x()
{
    return mlwsoft->x();
}

int light::y()
{
    return mlwsoft->y();
}

int light::idx()
{
    return mlwsoft->idx();
}

int light::setPath(string path)
{
    return mlwsoft->SetPath(QString::fromStdString(path));
}

string light::getPath()
{
    return mlwsoft->GetPath().toStdString();
}

string light::ver()
{
    return "0.0.1";
}

void light::setAdbPatch(std::string path)
{
    adb->setAdbPatch(QString::fromStdString(path));
    adb->setSerial(lew->getDeviceName());
}

std::vector<std::vector<std::string>> light::uiAutoMator()
{
    auto tmp = adb->uiautomator();
    std::vector<std::vector<std::string>> ret;
    for (auto uilist : tmp)
    {
        std::vector<std::string> list;
        for (auto ui : uilist)
        {
            list.push_back(ui.toStdString());
        }
        ret.push_back(list);
    }
    return ret;
}

std::vector<std::vector<std::string>> light::uiFind(std::string text, int type)
{
    auto tmp = adb->uiFind(QString::fromStdString(text), Adbprocess::TEXT);
    std::vector<std::vector<std::string>> ret;
    for (auto uilist : tmp)
    {
        std::vector<std::string> list;
        for (auto ui : uilist)
        {
            list.push_back(ui.toStdString());
        }
        ret.push_back(list);
    }
    return ret;
}

std::vector<std::vector<int>> light::uiGetBounds(std::string text, int type)
{
    auto tmp  = adb->uiGetBounds(QString::fromStdString(text), Adbprocess::TEXT);

    std::vector<std::vector<int>> ret;
    for (auto uilist : tmp)
    {
        std::vector<int> list;
        for (auto ui : uilist)
        {
            list.push_back(ui);
        }
        ret.push_back(list);
    }
    return ret; 
}

bool light::uiClickBounds(std::string text)
{
    auto tmp = adb->uiGetBounds(QString::fromStdString(text), Adbprocess::TEXT);
    for (auto uilist : tmp)
    {
        if (uilist.size() == 4)
        {
            int x = (uilist.at(0) + uilist.at(2)) / 2;
            int y = (uilist.at(1) + uilist.at(3)) / 2;
            action->click(QRect(x, y, lew->x(), lew->y()), 0);
            return true;
        }
    }
    return false;
}