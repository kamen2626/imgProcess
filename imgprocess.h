#ifndef IMGPROCESS_H
#define IMGPROCESS_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QImage>
#include <QFile>
#include <QLabel>
#include <edgenum.h>

#include "imgutils.h"

#include "opencv2/opencv.hpp"//添加Opencv相关头文件
#include "opencv2/highgui/highgui.hpp"

using namespace cv ;
using namespace std;

class ImgProcess : public QMainWindow
{
    Q_OBJECT

public:
    ImgProcess(QWidget *parent = 0);
    ~ImgProcess();


private:
    int m_width;
    int m_height;
    QString fileName;
    QImage *img;
    QImage *oldImage;
    QLabel *imgLabel;

    QMenu *file;
    QMenu *edit;
    QMenu *imgProcess;
    QMenu *colorimg;
    QMenu *screenimg;

    QAction *open;
    QAction *close;
    QAction *save;
    QAction *reshow;

    QAction *lastImg;
    QAction *roll;
    QAction *backRoll;

    QAction *oppo;
    QAction *edge;

    QAction *gray;
    QAction *binImg;

    QAction *screen;


public:
    void createAction();
    void createMenu();
    void showedge(int);
    void scaleImg();
    int Otsu(QImage*);                      //二值化阈值计算
    std::vector<int> Histogram(QImage*);

public slots:
    void openfile();
    void closefile();
    void savefile();
    void Rshow();
    void toLast();

    void oppoimg();
    void rollimg();
    void backroll();
    void findedge();

    void graying();
    void bining();

    void screening();
};


#endif // IMGPROCESS_H
