#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort>
#include <QDebug>
#include <QMessageBox>

QString port_name;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    opendev = false;
    buttonchange = false;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        port_name = info.portName();
        ui->comboBox->addItem(info.portName());
    }
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::serialReceive(){
    QByteArray data;
    data=serial->readAll();
    ui->label->setText(data);
    qDebug()<<data;
}


void MainWindow::on_opencloseButton_toggled(bool checked){
    if(checked == true){
        serial = new QSerialPort(this);
        if(!serial->open(QIODevice::ReadWrite)){
            ui->opencloseButton->setText("Disconnect");
            ui->statusbar->showMessage(QString("Connected to port %1.").arg(port_name),2000);
            opendev = true;
        }
        else{
            QMessageBox::critical(this,tr("fail"),serial->errorString());
        }
    }
    else{
        ui->opencloseButton->setText("Connect");
        QMessageBox::critical(this,tr("Disconnect"),"Communication end");

        if(serial->isOpen()){
            serial->close();
            opendev = false;
        }
        ui->statusbar->showMessage(QString("Disconnected"),2000);

    }
}

void MainWindow::on_featuresButton_clicked(){
    if(opendev == true){
        serial->setPortName("ttyUSB1");
        serial->setBaudRate(QSerialPort::Baud115200);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        serial->open(QIODevice::ReadWrite);
        connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceive()));

        buttonchange =true;
        ui->statusbar->showMessage(QString("Features Determined"),2000);
    }
}

void MainWindow::on_ATControlButton_clicked(){
    if(buttonchange == true){
        rx_Data[0]='A';
        rx_Data[1]='T';
        rx_Data[2]=0x0D;
        rx_Data[3]=0x0A;
        serial->write(rx_Data);
    }
}
void MainWindow::on_ATResetButton_clicked(){
    if(buttonchange == true){
        rx_Data[0]='A';
        rx_Data[1]='T';
        rx_Data[2]='+';
        rx_Data[3]='R';
        rx_Data[4]='S';
        rx_Data[5]='T';
        rx_Data[6]=0x0D;
        rx_Data[7]=0x0A;
        serial->write(rx_Data);
    }
}

void MainWindow::on_CWMODEButton_clicked(){
    if(buttonchange == true){
        rx_Data[0]='A';
        rx_Data[1]='T';
        rx_Data[2]='+';
        rx_Data[3]='C';
        rx_Data[4]='W';
        rx_Data[5]='M';
        rx_Data[6]='O';
        rx_Data[7]='D';
        rx_Data[8]='E';
        rx_Data[9]='=';
        rx_Data[10]='3';
        rx_Data[11]=0x0D;
        rx_Data[12]=0x0A;
        serial->write(rx_Data);
    }
}

void MainWindow::on_CMUXButton_clicked(){
    if(buttonchange == true){
        rx_Data[0]='A';
        rx_Data[1]='T';
        rx_Data[2]='+';
        rx_Data[3]='C';
        rx_Data[4]='I';
        rx_Data[5]='P';
        rx_Data[6]='M';
        rx_Data[7]='U';
        rx_Data[8]='X';
        rx_Data[9]='=';
        rx_Data[10]='1';
        rx_Data[11]=0x0D;
        rx_Data[12]=0x0A;
        serial->write(rx_Data);
    }
}

void MainWindow::on_CIPSERVERButton_clicked(){
    if(buttonchange == true){
        rx_Data[0]='A';
        rx_Data[1]='T';
        rx_Data[2]='+';
        rx_Data[3]='C';
        rx_Data[4]='I';
        rx_Data[5]='P';
        rx_Data[6]='S';
        rx_Data[7]='E';
        rx_Data[8]='R';
        rx_Data[9]='V';
        rx_Data[10]='E';
        rx_Data[11]='R';
        rx_Data[12]='=';
        rx_Data[13]='1';
        rx_Data[14]=',';
        rx_Data[15]='8';
        rx_Data[16]='0';
        rx_Data[17]=0x0D;
        rx_Data[18]=0x0A;
        serial->write(rx_Data);
    }
}

void MainWindow::on_CIFSRButton_clicked(){
    if(buttonchange == true){
        rx_Data[0]='A';
        rx_Data[1]='T';
        rx_Data[2]='+';
        rx_Data[3]='C';
        rx_Data[4]='I';
        rx_Data[5]='P';
        rx_Data[6]='S';
        rx_Data[7]='F';
        rx_Data[8]='R';
        rx_Data[9]=0x0D;
        rx_Data[10]=0x0A;
        serial->write(rx_Data);
    }
}
void MainWindow::on_CIPSENDButton_clicked(){
    if(buttonchange == true){
        rx_Data[0]='A';
        rx_Data[1]='T';
        rx_Data[2]='+';
        rx_Data[3]='C';
        rx_Data[4]='I';
        rx_Data[5]='P';
        rx_Data[6]='S';
        rx_Data[7]='E';
        rx_Data[8]='N';
        rx_Data[9]='D';
        rx_Data[10]='=';
        rx_Data[11]='0';
        rx_Data[12]=',';
        rx_Data[13]='3';
        rx_Data[14]='0';
        rx_Data[18]=0x0D;
        rx_Data[19]=0x0A;
        serial->write(rx_Data);
    }
}

void MainWindow::on_CIPCLOSEButton_clicked(){
    if(buttonchange == true){
         rx_Data[0]='A';
         rx_Data[1]='T';
         rx_Data[2]='+';
         rx_Data[3]='C';
         rx_Data[4]='I';
         rx_Data[5]='P';
         rx_Data[6]='C';
         rx_Data[7]='L';
         rx_Data[8]='O';
         rx_Data[9]='S';
         rx_Data[10]='E';
         rx_Data[11]='=';
         rx_Data[12]='0';
         rx_Data[13]=0x0D;
         rx_Data[14]=0x0A;
         serial->write(rx_Data);
    }
}

void MainWindow::on_CLOSEButton_clicked(){
    if(buttonchange == true){
        rx_Data[0]='A';
        rx_Data[1]='T';
        rx_Data[2]='+';
        rx_Data[3]='C';
        rx_Data[4]='I';
        rx_Data[5]='P';
        rx_Data[6]='S';
        rx_Data[7]='E';
        rx_Data[8]='R';
        rx_Data[9]='V';
        rx_Data[10]='E';
        rx_Data[11]='R';
        rx_Data[12]='=';
        rx_Data[13]='0';
        rx_Data[14]=0x0D;
        rx_Data[15]=0x0A;
        serial->write(rx_Data);
    }
}

void MainWindow::on_EspIPAddrButton_clicked(){
    if(buttonchange == true){
        rx_Data[0]='A';
        rx_Data[1]='T';
        rx_Data[2]='+';
        rx_Data[3]='C';
        rx_Data[4]='I';
        rx_Data[5]='P';
        rx_Data[6]='A';
        rx_Data[7]='P';
        rx_Data[8]='?';
        rx_Data[9]=0x0D;
        rx_Data[10]=0x0A;
        serial->write(rx_Data);
    }
}

void MainWindow::on_pushButton_clicked(){
    if(buttonchange == true){
        QString str = ui->lineEdit->text();
        str.append("\r\n");
        serial->write(str.toLatin1());
    }
}

void MainWindow::on_pushButton_2_clicked(){
    QMessageBox::information(this,tr("About Features"),"Baud Rate: 115200\r\n"
                                                       "Data Bits: Data8\r\n"
                                                       "Parity: NoParity\r\n"
                                                       "Stop Bits: OneStop\r\n"
                                                       "Flow Control: NoFlowControl\r\n");
}
