#ifndef LIGHT_H
#define LIGHT_H

#include <string>
#include "../lewone/lewone.h"
#include "../scrcpy/adbprocess.h"
using std::string;

class light
{
private:
    lewone *lew;
    lwsoft *mlwsoft;
    std::shared_ptr<Action> action;
    std::shared_ptr<Adbprocess> adb;
public:
    light(lewone *_lew = nullptr);
    ~light();
    bool status();

    //control:
    void hold(int x, int y, quint64 id = 0);
    void move(int x, int y, quint64 id = 0);
    void release(int x, int y, quint64 id = 0);
    void click(int x, int y, quint64 id = 0);

    void sendText(string text);
    void sendTextEx(string text);

    //android-keybord
    void key(uint keyCode);
    void goHome();
    void onClear(int num);

    //ocr
    int setDict(int index, string file, string pwd = "");
    int useDict(int index);
    string ocr(int x1, int y1, int x2, int y2, string color_format, double sim = 0.95, string linesign = "", int isbackcolor = 0);
    int findStr(int x1, int y1, int x2, int y2, string str_format, string color_format, double sim = 0.95, int isbackcolor = 0);
    string findStrEx(int x1, int y1, int x2, int y2, string str_format, string color_format, double sim = 0.95, int isbackcolor = 0);
    int findStrFast(int x1, int y1, int x2, int y2, string str_format, string color_format, double sim = 0.95, int isbackcolor = 0);
    string findStrFastEx(int x1, int y1, int x2, int y2, string str_format, string color_format, double sim = 0.95, int isbackcolor = 0);
    string fetchLattice(int x1, int y1, int x2, int y2, string color_format, int isBackColor = 0);

    //pic
    int finPic(int x1, int y1, int x2, int y2, string pic_name, string delta_color, double sim = 0.95, int dir = 0);
    string finPicEx(int x1, int y1, int x2, int y2, string pic_name, string delta_color, double sim = 0.95, int dir = 0);
    int findBrightPoint(int x1, int y1, int x2, int y2, int lower, int Upper);
    int findColor(int x1, int y1, int x2, int y2,string color,double sim = 0.95, int dir = 0);
    int capture(int x1, int y1, int x2, int y2, string file);

    //base
    int x();
    int y();
    int idx();
    int setPath(string path);
    string getPath();

    //msg:
    string ver();

    //adb UIautomator
    void setAdbPatch(std::string path);
    std::vector<std::vector<std::string>> uiAutoMator();
    std::vector<std::vector<std::string>> uiFind(std::string text, int type = 1);
    std::vector<std::vector<int>> uiGetBounds(std::string text, int type = 1);
    bool uiClickBounds(std::string text);
};

#endif