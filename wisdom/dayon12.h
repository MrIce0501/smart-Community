#ifndef DAYON12_H
#define DAYON12_H


#include<QDialog>
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include"wisdom.h"
class wisdom;

class dayon12:public QDialog{
    Q_OBJECT
public:
    explicit dayon12(wisdom *w,QWidget*parent=0);
private:
    QLabel*label1;
    QLabel*label2;
    QLabel*label3;
    QLabel*label4;
    QLineEdit*line1;
    QLineEdit*line2;
    QLineEdit*line3;
    QLineEdit*line4;
    QPushButton* findButton;
    QPushButton* submitButton;
    QPushButton* cancelButton;
    QGridLayout *mainLayout;
    wisdom* wis;
public slots:
    void cancel();
    void find();
    void submit();
    void loadStyleSheet(const QString &sheetName);
    void update();

};
#endif // DAYON12_H
