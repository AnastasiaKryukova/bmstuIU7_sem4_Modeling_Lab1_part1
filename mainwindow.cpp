#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString a = ui->lineEdit->text();
    QString b = ui->lineEdit_2->text();
    double aa = a.toDouble();
    double bb = b.toDouble();
    double h = 0.01; //Шаг, с которым будем пробегать по оси Ox
    int N = (bb - aa) / h + 2; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x(N), y(N), xx(N), yy(N); //Массивы координат точек


int i = 0;

x.push_back(0);
y.push_back(0);

for (double X = aa; X <= bb; X += h)
{
    x[i] = X;
    y[i] = 1/(bb - aa);
    i++;
    x.push_back(x[i]);
    y.push_back(y[i]);
}

    ui->widget->clearGraphs();//Если нужно, но очищаем все графики

    //Добавляем один график в widget
    ui->widget->addGraph();

    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    ui->widget->graph(0)->setData(x, y);

    //Подписываем оси Ox и Oy
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("f(x)");

    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(aa, bb);//Для оси Ox

    ui->widget->yAxis->setRange(0, (1/(bb-aa))+0.05);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->widget->replot();




    xx.push_back(0);
    yy.push_back(0);


for (double X = aa; X <= bb; X += h)
{
    xx[i] = X;
    yy[i] = (X-aa)/(bb - aa);
    i++;

    xx.push_back(xx[i]);
    yy.push_back(yy[i]);
}


ui->widget_2->clearGraphs();//Если нужно, но очищаем все графики

//Добавляем один график в widget
ui->widget_2->addGraph();

//Говорим, что отрисовать нужно график по нашим двум массивам x и y
ui->widget_2->graph(0)->setData(xx, yy);

//Подписываем оси Ox и Oy
ui->widget_2->xAxis->setLabel("x");
ui->widget_2->yAxis->setLabel("F(x)");

//Установим область, которая будет показываться на графике
ui->widget_2->xAxis->setRange(aa, bb);//Для оси Ox

ui->widget_2->yAxis->setRange(0, ((bb-aa)/(bb-aa))+0.05);//Для оси Oy

//И перерисуем график на нашем widget
ui->widget_2->replot();


}

