#ifndef MAINTAIN41_H
#define MAINTAIN41_H


#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include"wisdom.h"

class wisdom;
class maintain41:public QDialog{
    Q_OBJECT
public:
    explicit maintain41(wisdom *w,QWidget*parent=0);
private:
    QLabel*label1;
    QLabel*label2;
    QLabel*label3;
    QLabel*label4;
    QLineEdit*line1;
    QLineEdit*line2;
    QLineEdit*line3;
    QTextEdit*text;
    QPushButton* submitButton;
    QPushButton* cancelButton;
    wisdom* wis;
public slots:
    void cancel();
    void submit();
    void loadStyleSheet(const QString &sheetName);
    void update();

};


#endif // MAINTAIN41_H
