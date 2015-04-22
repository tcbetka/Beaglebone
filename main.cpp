#include <QCoreApplication>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

QSerialPort* serial;
QList<QSerialPortInfo> systemPorts;

bool configure_port();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    serial = new QSerialPort();
    systemPorts = QSerialPortInfo::availablePorts();

    bool success = configure_port();

    if (success) {
        qDebug() << "Port configured successfully!";
    } else {
        qDebug() << "Port not configured.";
    }


    return a.exec();
}

bool configure_port()
{
    bool flag = false;

    systemPorts = QSerialPortInfo::availablePorts();

    // Set desired port interface
    foreach( const QSerialPortInfo p, systemPorts )
    {
        if( p.portName().contains("ttyO4")) {
            serial->setPort(p);
        }
    }

    // Note: QSerialPort inherits from QIODevice
    if( serial->open(QIODevice::ReadWrite) )
    {
        // Set the baud rate
        flag = serial->setBaudRate(QSerialPort::Baud9600);

        // Set number of data bits
        flag = serial->setDataBits(QSerialPort::Data8);

        // Set stop bit
        flag = serial->setStopBits(QSerialPort::OneStop);

        // Set parity
        flag = serial->setParity(QSerialPort::NoParity);

        // Set flow control
        flag = serial->setFlowControl(QSerialPort::NoFlowControl);
    }

    return flag;
}
