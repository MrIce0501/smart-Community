#ifndef OWNERMODIFY22_H
#define OWNERMODIFY22_H

#include"wisdom.h"

class ownerModify22:public QDialog{
    Q_OBJECT
public:
    explicit ownerModify22(wisdom*w,QWidget *parent=0);
private:
    QLabel*label1;
    QLabel*label2;
    QLabel*label3;
    QLabel*label4;
    QLineEdit*line1;
    QLineEdit*line2;
    QLineEdit*line3;
    QLineEdit*line4;

    QPushButton* submitButton;
    QPushButton* cancelButton;
    QPushButton* deleteButton;
    QPushButton* editButton;
    QPushButton* findButton;
    QGridLayout* mainLayout1;
    wisdom* wis;

public slots:
    void cancel();
    void find();
    void edit();
    void delete1();
    void submit();
    void loadStyleSheet(const QString &sheetName);
    void update();
};

#endif // OWNERMODIFY22_H
