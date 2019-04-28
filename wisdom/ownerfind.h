#ifndef OWNERFIND_H
#define OWNERFIND_H

#include"wisdom.h"

class ownerFind:public QDialog{
    Q_OBJECT
public:
    explicit ownerFind(QWidget*parent=0);

private:
    QLabel*label1;
    QLabel*label2;
    QLabel*label3;
    QLabel*label4;
    QLineEdit*line1;
    QLineEdit*line2;
    QLineEdit*line3;
    QLineEdit*line4;

    QPushButton* cancelButton;
    QPushButton* findButton;
    QGridLayout* mainLayout1;
    wisdom* wis;
public slots:
    void cancel();
    void find();
    void loadStyleSheet(const QString &sheetName);
    void update();
};

#endif // OWNERFIND_H
