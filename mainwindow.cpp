#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPortInfo>
#include <QDebug>
#include <QFileDialog>

const char COMMAND_ECHO[] = {'F','E', 1};
const char COMMAND_RESTART[] = {'F','R',1};
const char COMMAND_IAP[] = {'F','I', (char)255};

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
                serial->setPortName(info.portName());
                ui->ports->addItem( info.portName());
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(programming_time()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fresh_com_clicked()
{
    ui->ports->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
                serial->setPortName(info.portName());
                ui->ports->addItem( info.portName());
    }
}

void MainWindow::on_view_file_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open bin file"), tr("*.bin"), tr("BIN files"));
    qDebug() << fileName;
    if (!fileName.isEmpty()) {
        ui->file_name->setText(fileName);
    }
}

void MainWindow::on_start_clicked()
{
    static bool start_program = false;

    if (start_program == false) {
        serial->setPortName(ui->ports->currentText());
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);

        if (serial->open(QIODevice::ReadWrite)) {
            ui->file_name->setEnabled(false);
            ui->view_file->setEnabled(false);
            ui->progress->setEnabled(true);
            ui->start->setText("СТОП");
            serial->write(COMMAND_RESTART,3);
            timer->start(200);
            start_program = true;
        } else ui->state_load->setText("Порт не может быть открыт!");
    } else {
        start_program = false;
        serial->close();
        ui->start->setText("СТАРТ");
        ui->file_name->setEnabled(true);
        ui->view_file->setEnabled(true);
        ui->progress->setEnabled(false);
        ui->progress->setValue(0);
        ui->state_load->setText("Ожидание . . .");
        timer->stop();
    }

}

void MainWindow::programming_time()
{
    static quint32 data_length = 0;
    static bool icon = false;

    if (serial->bytesAvailable()) {
        QByteArray com_data = serial->readAll();
        qDebug() << com_data;

        for (int i = 0; i < com_data.size(); ++i) {
            static QByteArray bin;
            static char data[256];
            static QFile file;
            static bool send_full = false;

            if (com_data.at(i) == '>') {
                ui->state_load->setText("Устройство определенно");

                file.setFileName(ui->file_name->text());
                if (file.open(QIODevice::ReadOnly)) {
                    bin = file.readAll();
                    qDebug() << "File is open. \n";
                    qDebug() << "*.bin size is " << bin.size();
                } else {
                    qDebug() << "Error: *.BIN file is not accessible!\n";
                    ui->state_load->setText("Ошибка открытия файла");
                    return;
                }

                serial->write(COMMAND_IAP, 3);

                for (int i = 0; i < 256; ++i)
                    data[i] = bin.at(i);

                send_full = false;
                serial->write(data, 256);
                data_length += 256;
            }

            if (com_data.at(i) == '*') {

                if (send_full == true) {
                    //serial->write("FJ1");
                    file.close();
                    data_length = 0;
                    bin = "";
                    qDebug() << "End fireware!";
                    on_start_clicked();
                    return;
                }

                for (quint32 i = 0; i < 256; ++i) {
                    if ((i + data_length) <= (uint)bin.size())
                        data[i] = bin.at(i + data_length);
                    else {
                        for (; i < 256; ++i) data[i] = 0xFF;
                        send_full = true;
                    }
                    ui->state_load->setText("Программирование . . .");
                }

                serial->write(COMMAND_IAP, 3);
                serial->write(data, 256);
                data_length += 256;
            }

            if (bin.size() != 0)
                ui->progress->setValue((data_length*100)/bin.size());
        }
    }

    if (icon == true) {
        icon = false;
        ui->label->setPixmap(QPixmap(":/images/icon.jpg"));
    } else {
        icon = true;
        ui->label->setPixmap(QPixmap(":/images/icon2.jpg"));
    }
}
