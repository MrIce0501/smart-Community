#ifndef LOG00_H
#define LOG00_H
#include<QDialog>
#include<QToolBox>
#include<QTableWidget>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonParseError>
#include<QDebug>
#include<QGridLayout>
#include<QWidget>
#include<QProgressBar>
#include<QTimer>
#include<QTableView>
#include<QTextEdit>
#include<QRadioButton>
#include<QGroupBox>
#include<QDateTime>
#include<QVector>
#include<QMessageBox>
#include<QStandardItemModel>
#include<QHeaderView>
#include"wisdom.h"
#include"register.h"

class wisdom;
class register1;


class log00:public QDialog{
    Q_OBJECT
public:
    explicit log00(QWidget*parent=0);
private:
    QLabel*label1;
    QLabel*label2;
    QLineEdit*line1;
    QLineEdit*line2;
    QPushButton*log0;
    QPushButton*register0;
    QLabel*label0;
    QLabel*label00;
    wisdom*wis;
    register1*r;

public slots:
    void log();
    void register2();
    void loadStyleSheet(const QString &sheetName);
    void update();

};


#endif // LOG00_H
