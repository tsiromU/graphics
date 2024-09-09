#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <complex>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QVector<double> x, y;

    double xBegin;
    double xEnd;
    double yBegin;
    double yEnd;
    int N = 1000;
    double dx;

    void createSinVect();
    void createCosVect();
    void createTgVect ();

};
#endif // MAINWINDOW_H
