#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "idealnerve.h"
#include "data.h"
#include "iostream"
#include <fstream>
#include <qfile.h>

using namespace std;
using namespace boost::numeric::odeint;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void draw_1();
    void draw_2();
    void drawnullcline();
    void drawAll();
    void calcul();

private:
    ofstream f;
    Ui::MainWindow *ui;
    IdealNerve *nerve;
};

#endif // MAINWINDOW_H
