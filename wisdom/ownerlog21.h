#ifndef OWNERLOG21_H
#define OWNERLOG21_H

#include"wisdom.h"

class wisdom;

class ownerLog21:public QDialog{
    Q_OBJECT
public:
    explicit ownerLog21(wisdom*w,QWidget*parent=0);
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
    void log();
    void loadStyleSheet(const QString &sheetName);
    void update();
};

#endif // OWNERLOG21_H
