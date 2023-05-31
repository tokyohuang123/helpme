#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_gain, &QPushButton::clicked, this, &MainWindow::onTriangleButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTriangleButtonClicked()
{
    qDebug() << "这是一个三角形";
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(ui->groupBox_limiting_amplifier_settings);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255, 255, 255));

    QPolygonF triangle;
    triangle << QPointF(0, 0) << QPointF(ui->pushButton_gain->width(), 0) << QPointF(ui->pushButton_gain->width() / 2, ui->pushButton_gain->height());
    painter.drawPolygon(triangle);
    ui->groupBox_limiting_amplifier_settings->raise();
}
