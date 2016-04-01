#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nerve = new IdealNerve();
    setCentralWidget(ui->customPlot);
    connect(ui->actionDraw_1, SIGNAL(triggered()), this, SLOT(draw_1()));
    connect(ui->actionDraw_2, SIGNAL(triggered()), this, SLOT(draw_2()));
    connect(ui->actionCalcul, SIGNAL(triggered()), this, SLOT(calcul()));
    connect(ui->actionDraw_Nullcline, SIGNAL(triggered()), this, SLOT(drawnullcline()));
    connect(ui->actionDraw_All, SIGNAL(triggered()), this, SLOT(drawAll()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawnullcline()
{
    QVector<double> t;
    QVector<double> f;
    QVector<double> g;
    QFile file("datanullcline.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        QStringList e = line.split(";");
        t.push_back(e.at(0).toDouble());
        g.push_back(e.at(1).toDouble());
        f.push_back(e.at(2).toDouble());
        line = in.readLine();
    }

    ui->customPlot->clearGraphs();
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(t, f);
    ui->customPlot->graph(0)->setPen(QPen(Qt::red));
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setData(t, g);
    ui->customPlot->graph(1)->setPen(QPen(Qt::green));
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->yAxis->setRange(0, 0.6);
    ui->customPlot->xAxis->setRange(0, 0.5);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
}

void MainWindow::draw_2()
{
    QVector<double> t;
    QVector<double> f;
    QFile file("data.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        QStringList e = line.split(";");
        t.push_back(e.at(0).toDouble());
        f.push_back(e.at(2).toDouble());
        line = in.readLine();
    }

    ui->customPlot->clearGraphs();
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(t, f);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->yAxis->setRange(0.1, 0.6);
    ui->customPlot->xAxis->setRange(0, 1);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();


}

void MainWindow::draw_1()
{
    QVector<double> t;
    QVector<double> f;
    QFile file("data.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        QStringList e = line.split(";");
        t.push_back(e.at(0).toDouble());
        f.push_back(e.at(1).toDouble());
        line = in.readLine();
    }

    ui->customPlot->clearGraphs();
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(t, f);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->yAxis->setRange(0.1, 0.6);
    ui->customPlot->xAxis->setRange(0, 1);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
}

void MainWindow::drawAll()
{
    QVector<double> t_n;
    QVector<double> d_n;

    QFile file1("data.csv");
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in1(&file1);
    QString line1 = in1.readLine();
    while (!line1.isNull()) {
        QStringList e = line1.split(";");
        t_n.push_back(e.at(0).toDouble());
        d_n.push_back(e.at(1).toDouble());
        line1 = in1.readLine();
    }

    QVector<double> t;
    QVector<double> f;
    QVector<double> g;
    QFile file("datanullcline.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        QStringList e = line.split(";");
        t.push_back(e.at(0).toDouble());
        g.push_back(e.at(1).toDouble());
        f.push_back(e.at(2).toDouble());
        line = in.readLine();
    }

    ui->customPlot->clearGraphs();
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(t, f);
    ui->customPlot->graph(0)->setPen(QPen(Qt::green));
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setData(t, g);
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setData(t_n, d_n);
    ui->customPlot->graph(2)->setPen(QPen(Qt::blue));
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->yAxis->setRange(0, 0.6);
    ui->customPlot->xAxis->setRange(0, 0.5);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
}

void MainWindow::calcul()
{
    state_type x = {-0.140, 0.2};
    Data *d = new Data();
    runge_kutta4<state_type> rk4;
    integrate_adaptive(rk4, *nerve, x, 0.0, 1.0 , 0.00001, *d);
}
