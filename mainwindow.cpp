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


    if(ui->radioButton->isChecked())
        createSinVect();
    if(ui->radioButton_2->isChecked())
        createCosVect();
    if(ui->radioButton_3->isChecked())
        createTgVect();

    ui->field->addGraph();
    ui->field->graph(0)->addData(x,y);
    ui->field->replot();
    x.erase(x.begin(), x.end());
    y.erase(y.begin(), y.end());
    ui->field->graph(0)->data()->clear();
}

void MainWindow::createSinVect(){
    for(int i = 0; i < N; i++){
        double xValue = xBegin + (double)i*dx;
        double yValue = sin(xValue);
        x.push_back(xValue);
        y.push_back(yValue);
//        qDebug() << xValue << yValue;
    };
}


void MainWindow::createCosVect(){
    for(int i = 0; i < N; i++){
        double xValue = xBegin + (double)i*dx;
        double yValue = cos(xValue);
        x.push_back(xValue);
        y.push_back(yValue);
//        qDebug() << xValue << yValue;
    }
}
/*there is more efficient way to do it:
 *for(double xValue = xBegin; xValue <=xEnd; xValue+=dx){
 *  double yValue = cos(xValue);
 *  x.push_back(xValue);
 *  y.push_back(yValue);
 *}
 */

void MainWindow::createTgVect(){
    for(int i = 0; i < N; i++){
        double xValue = xBegin + (double)i*dx;
        double yValue = tan(xValue);
        if(tan(xValue+dx) *  tan(xValue+2*dx) < -5){
            qDebug()<< xValue<<qQNaN();
            x.push_back(xValue);
            y.push_back(999);
            x.push_back(xValue+dx);
            y.push_back(qQNaN());
            x.push_back(xValue+2*dx);
            y.push_back(-999);

            i+=2;
            continue;
        }
        x.push_back(xValue);
        y.push_back(yValue);
        qDebug() << xValue << yValue;
    }
}




