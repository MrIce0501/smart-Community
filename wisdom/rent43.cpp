#include"rent43.h"



rent43::rent43(QWidget*parent)                  //收款界面2333333333333333
    :QDialog(parent){
    setWindowTitle("收款");
    label1=new QLabel;
    label1->setScaledContents(true);
    label1->setFixedSize(480,680);
    label1->setPixmap(QString(":/new/prefix1/img/8.png"));
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addStretch();
    layout->addWidget(label1);
    layout->addStretch();
    setLayout(layout);
}
