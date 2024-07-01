#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <complex>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    xBegin = ui->lineEdit  ->text().toDouble();
//    xEnd   = ui->lineEdit_2->text().toDouble();
//    yBegin = ui->lineEdit_3->text().toDouble();
//    yEnd   = ui->lineEdit_4->text().toDouble();

//    ui->field ->xAxis->setRange(xBegin,xEnd);
//    ui->field ->yAxis->setRange(yBegin,yEnd);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_2_clicked()
{
    xBegin = ui->lineEdit  ->text().toDouble();
    xEnd   = ui->lineEdit_2->text().toDouble();
    yBegin = ui->lineEdit_3->text().toDouble();
    yEnd   = ui->lineEdit_4->text().toDouble();

    ui->field ->xAxis->setRange(xBegin,xEnd);
    ui->field ->yAxis->setRange(yBegin,yEnd);

    dx = (xEnd-xBegin)/N;

    //Q_UNUSED(yBegin);
    //Q_UNUSED(yEnd);


    for(int i = 0; i < N; i++){
        double xValue = xBegin + (double)i*dx;
        double yValue = tan(xValue);
        if(ui->radioButton->isChecked())
            yValue = cos(xValue);
        else if(ui->radioButton_2->isChecked())
            yValue = sin(xValue);
        x.push_back(xValue);
        y.push_back(yValue);
        qDebug() << xValue << yValue;
    }
    ui->field->addGraph();
    ui->field->graph(0)->addData(x,y);
    ui->field->replot();
    x.erase(x.begin(), x.end());
    y.erase(y.begin(), y.end());
    ui->field->graph(0)->data()->clear();
}


