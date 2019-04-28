#ifndef CARADD31_H
#define CARADD31_H


#include<QDialog>
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include"wisdom.h"

class wisdom;
class carAdd31:public QDialog{
    Q_OBJECT
public:
    explicit carAdd31(wisdom *w,QWidget*parent=0);
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
    void submit();
    void cancel();
    void loadStyleSheet(const QString &sheetName);
    void update();
};

#endif // CARADD31_H
