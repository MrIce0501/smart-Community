#ifndef REGISTER_H
#define REGISTER_H

#include<QDialog>
#include<QToolBox>
#include<QTableWidget>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonParseError>
#include<QDebug>
#include<QGridLayout>
#include<QWidget>
#include<QProgressBar>
#include<QTimer>
#include<QTableView>
#include<QTextEdit>
#include<QRadioButton>
#include<QGroupBox>
#include<QDateTime>
#include<QVector>
#include<QMessageBox>
#include<QStandardItemModel>
#include<QHeaderView>
#include"wisdom.h"
#include"log00.h"

class wisdom;
class log00;



class register1:public QDialog{
    Q_OBJECT
public:
    explicit register1(log00*l,QWidget*parent=0);
private:
    QLabel*label1;
    QLabel*label2;
    QLabel*label3;
    QLabel*label4;
    QLineEdit*line1;
    QLineEdit*line2;
    QLineEdit*line3;
    QGroupBox*groupBox;
    QRadioButton*radio1;
    QRadioButton*radio2;
    QRadioButton*radio3;
    QPushButton*submitButton;
    QPushButton*cancelButton;
    log00*log;
    wisdom* wis;



public slots:
    void cancel();
    void registerPress();
    void loadStyleSheet(const QString &sheetName);
    void update();


};

#endif // REGISTER_H
