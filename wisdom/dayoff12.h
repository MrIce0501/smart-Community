#ifndef DAYOFF12_H
#define DAYOFF12_H

#include<QDialog>
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include"wisdom.h"
class wisdom;

class dayoff12:public QDialog{
    Q_OBJECT
public:
    explicit dayoff12(wisdom *w,QWidget*parent=0);
private:
    QLabel*label1;
    QLabel*label2;
    QLabel*label3;
    QLineEdit*line1;
    QLineEdit*line2;
    QLineEdit*line3;
    QPushButton* submitButton;
    QPushButton* cancelButton;
    wisdom* wis;
public slots:
    void cancel();
    void submit();
    void loadStyleSheet(const QString &sheetName);
    void update();
};


#endif // DAYOFF12_H
