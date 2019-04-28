#ifndef CARFIND_H
#define CARFIND_H

#include<QDialog>
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include"wisdom.h"
class wisdom;

class carFind31:public QDialog{
    Q_OBJECT
public:
    explicit carFind31(QWidget*parent=0);

private:
    QPushButton*findButton;
    QLineEdit* lineEdit;
    QString findText;
public slots:
    void find11Press();
    QString getFindText();
    void loadStyleSheet(const QString &sheetName);
    void update();



};

#endif // CARFIND_H
