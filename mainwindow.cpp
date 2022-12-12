#include "mainwindow.h"

TSignal<double> signal1(100);
HarmonicGenerator<float, int, float, int> generator(10, 1000, 0, 40000);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QVector<double> y(signal1.getSignalSize());
    for (int i=0; i<signal1.getSignalSize(); ++i)
    {
      y[i] = i;
    }

    float val = generator.generatePoint();
    char mass[10] = {0};
    itoa(val, mass, 10);
    signal1.addPoint(val);

    ui->customPlot->graph(0)->setData(y, signal1.getVector());
    ui->customPlot->replot();

    QString freqSTR = ui->freq->text();
    if (freqSTR.toStdString() != "")
        generator.setFreq(freqSTR.toInt());

    QString samplingFreqSTR = ui->samplingFreq->text();
    if (samplingFreqSTR.toStdString() != "")
        generator.setSamplingFreq(samplingFreqSTR.toInt());

    QString phaseSTR = ui->phase->text();
    if (phaseSTR.toStdString() != "")
        generator.setPhase(phaseSTR.toFloat());
}


void MainWindow::makePlot()
{
    QVector<double> y(signal1.getSignalSize());
    y.fill(0, signal1.getSignalSize());

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(y, signal1.getVector());

    ui->customPlot->xAxis->setLabel("time");
    ui->customPlot->yAxis->setLabel("amplitude");

    ui->customPlot->xAxis->setRange(0, signal1.getSignalSize());
    ui->customPlot->yAxis->setRange(generator.getAmp() * 1.2, -1 * generator.getAmp() * 1.2 );
    ui->customPlot->replot();
}


void MainWindow::on_maxGraphPoint_editingFinished()
{
    QString maxGraphPointSTR = ui->maxGraphPoint->text();
    if (maxGraphPointSTR.toStdString() != "")
    {
        signal1.setMaxSignalSize(maxGraphPointSTR.toInt());
        ui->customPlot->xAxis->setRange(0, signal1.getSignalSize());
    }
}


void MainWindow::on_maxAmp_editingFinished()
{
    QString maxAmpSTR = ui->maxAmp->text();
    if (maxAmpSTR.toStdString() != "")
    {
        generator.setAmp(maxAmpSTR.toFloat());
        ui->customPlot->yAxis->setRange(generator.getAmp() * 1.2, -1 * generator.getAmp() * 1.2 );
    }
}

