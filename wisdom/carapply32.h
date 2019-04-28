#ifndef CARAPPLY_H
#define CARAPPLY_H

#include"wisdom.h"

class carApply32:public QDialog{
    Q_OBJECT
public:
    explicit carApply32(wisdom *w,QWidget*parent=0);
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
    wisdom* wis;
public slots:
    void cancel();
    void submit();
    void loadStyleSheet(const QString &sheetName);
    void update();

};

#endif // CARAPPLY_H
