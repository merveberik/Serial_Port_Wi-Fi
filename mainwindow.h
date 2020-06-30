#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
#include <QLineEdit>

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
    void serialReceive();

    void on_opencloseButton_toggled(bool checked);

    void on_featuresButton_clicked();

    void on_ATControlButton_clicked();

    void on_ATResetButton_clicked();

    void on_CWMODEButton_clicked();

    void on_CMUXButton_clicked();

    void on_CIPSERVERButton_clicked();

    void on_CIFSRButton_clicked();

    void on_CIPSENDButton_clicked();

    void on_CIPCLOSEButton_clicked();

    void on_CLOSEButton_clicked();

    void on_EspIPAddrButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    char rx_Data[20];
    char buttonchange, opendev;
    QLineEdit *_QLineEdit;
};
#endif // MAINWINDOW_H
