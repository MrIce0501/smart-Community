#ifndef CARDELETE_H
#define CARDELETE_H


#include"wisdom.h"
#include<QDialog>
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
class wisdom;
class carDelete31:public QDialog{
    Q_OBJECT
public:
    explicit carDelete31(wisdom* w,QWidget*parent=0);

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
    QLineEdit*line5;
    QPushButton* cancelButton;
    QPushButton* deleteButton;
    QPushButton* findButton;
    QPushButton* editButton;
    QPushButton* submitButton;
    QGridLayout *mainLayout1;
    wisdom* wis;

public slots:

    void cancel();
    void find();
    void edit();
    void submit();
    void delete1();
    void loadStyleSheet(const QString &sheetName);
    void update();

};

#endif // CARDELETE_H
