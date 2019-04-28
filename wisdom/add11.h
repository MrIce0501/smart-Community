#ifndef ADD11_H
#define ADD11_H

#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonParseError>
#include<QDebug>
#include<QFile>
#include<QDialog>
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QTextStream>
#include"wisdom.h"
class wisdom;
class add11:public QDialog{
    Q_OBJECT
public:
    explicit add11(wisdom *w,QWidget*parent=0);

private:
    QLabel*label1;
    QLabel*label2;
    QLabel*label3;
    QLabel*label4;
    QLabel*label5;
    QLineEdit*line1;
    QLineEdit*line2;
    QLineEdit*line3;
    QLineEdit*line4;
    QPushButton* submitButton;
    QPushButton* cancelButton;
    QPushButton* uploadButton;
    wisdom* wis;

public slots:

    //void upLoad();
    void submit();
    void cancel();
    void loadStyleSheet(const QString &sheetName);
    void update();
};

#endif // ADD11_H
