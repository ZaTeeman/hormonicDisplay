#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

#include "harmonicGenerator.h"
#include "tsignal.h"

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
    void on_pushButton_clicked();

    void makePlot();

    void on_maxGraphPoint_editingFinished();

    void on_maxAmp_editingFinished();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
