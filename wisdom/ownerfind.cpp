#include"ownerfind.h"
#include<QMessageBox>
#include<QGridLayout>

ownerFind::ownerFind(QWidget*parent)
    :QDialog(parent){

    QIcon addIcon(":/new/prefix1/img/add.png");
    QIcon deleteIcon(":/new/prefix1/img/delete.png");
    QIcon assistantIcon(":/new/prefix1/img/assistant.png");
    QIcon editIcon(":/new/prefix1/img/edit.png");
    QIcon submitIcon(":/new/prefix1/img/finish.png");
    QIcon upLoadIcon(":/new/prefix1/img/upload.png");
    QIcon peopleIcon(":/new/prefix1/img/dayOff.png");
    QIcon lightIcon(":/new/prefix1/img/light.png");
    QIcon shareIcon(":/new/prefix1/img/share.png");
    QIcon findIcon(":/new/prefix1/img/find.png");
    QIcon sendIcon(":/new/prefix1/img/send.png");
    QIcon clockIcon(":/new/prefix1/img/clock.png");
    QIcon backIcon(":/new/prefix1/img/back.png");
    QIcon computerIcon(":/new/prefix1/img/computer.png");
    QIcon messageIcon(":/new/prefix1/img/message.png");
    QIcon purseIcon(":/new/prefix1/img/purse.png");
    QIcon startIcon(":/new/prefix1/img/start.png");

    setWindowTitle(tr("业主查询"));
    label1=new QLabel("请输入查询的姓名：");
    label2=new QLabel("姓名");
    label3=new QLabel("家庭住址");
    label4=new QLabel("联系电话");
    line1=new QLineEdit;
    line2=new QLineEdit;
    line3=new QLineEdit;
    line4=new QLineEdit;

    label2->hide();
    label3->hide();
    label4->hide();
    line2->hide();
    line3->hide();
    line4->hide();

    findButton=new QPushButton(tr("查找"));
    findButton->setIcon(findIcon);
    findButton->show();
    cancelButton=new QPushButton(tr("取消"));
    cancelButton->setIcon(backIcon);
    cancelButton->show();


    QVBoxLayout *layout1=new QVBoxLayout;
    layout1->addWidget(label2);
    layout1->addWidget(label3);
    layout1->addWidget(label4);

    QVBoxLayout *layout2=new QVBoxLayout;
    layout2->addWidget(line2);
    layout2->addWidget(line3);
    layout2->addWidget(line4);

    QVBoxLayout *layout3=new QVBoxLayout;
    layout3->addWidget(findButton);
    layout3->addWidget(cancelButton);

    QGridLayout *mainLayout2=new QGridLayout;
    mainLayout2->addLayout(layout1,0,0);
    mainLayout2->addLayout(layout2,0,1);

    mainLayout1=new QGridLayout;
    mainLayout1->addWidget(label1,0,0,1,4);
    mainLayout1->addWidget(line1,1,0,1,3);
    mainLayout1->addLayout(mainLayout2,2,0,4,2,Qt::AlignTop);
    mainLayout1->addLayout(layout3,0,3,5,1,Qt::AlignTop);


    setLayout(mainLayout1);
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));
    connect(findButton,SIGNAL(clicked()),this,SLOT(find()));

    update();
}
void ownerFind::cancel(){

    this->close();
    wis->show();

}
void ownerFind::find(){
    QFile file("../wisdom/wisdom/owner21.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtInput(&file);
    QString str="";
    QString text=line1->text();
    QString str1;
    QString str2;
    QString str3;
    if(text==""){
        QMessageBox::information(this,tr("输入为空"),tr("输入为空，请检查是否正确输入。"));
    }
    else{
        while(!txtInput.atEnd()){
            str=txtInput.readLine();
            QByteArray json_byte= str.toLatin1();
            QJsonParseError jsonError;
            QJsonDocument parseDoc=QJsonDocument::fromJson(json_byte,&jsonError);
            if(jsonError.error==QJsonParseError::NoError){
                if(parseDoc.isObject()){
                    QJsonObject jsonObj=parseDoc.object();
                    if(jsonObj.contains("name")){
                        QJsonValue nameValue=jsonObj.take("name");
                        if(nameValue.isString()){
                            str1=nameValue.toString();
                            qDebug()<<str1;

                        }
                    }
                    if(jsonObj.contains("address")){
                        QJsonValue addressValue=jsonObj.take("address");
                        if(addressValue.isString()){
                            str2=addressValue.toString();
                            qDebug()<<str2;

                        }
                    }
                    if(jsonObj.contains("telephone")){
                        QJsonValue telephoneValue=jsonObj.take("telephone");
                        if(telephoneValue.isDouble()){
                            int n3=telephoneValue.toInt();
                            str3=tr("%1").arg(n3);
                            qDebug()<<str3;


                        }
                    }
                    if(txtInput.atEnd()){
                        if(str1!=text){
                            QMessageBox::information(this,tr("查找失败"),tr("该用户不存在"));
                        }
                    }
                    if(str1==text){
                        mainLayout1->setRowStretch(0,0);
                        mainLayout1->setRowStretch(1,0);
                        mainLayout1->setRowStretch(2,1);
                        label1->hide();
                        label2->show();
                        label3->show();
                        label4->show();
                        line1->hide();
                        line2->show();
                        line3->show();
                        line4->show();
                        line2->setText(str1);
                        line3->setText(str2);
                        line4->setText(str3);
                        line2->setEnabled(false);
                        line3->setEnabled(false);
                        line4->setEnabled(false);
                        findButton->setEnabled(false);
                        break;
                    }

                }
            }
        }
    }
    file.close();
}
void ownerFind::loadStyleSheet(const QString &sheetName)
{
    QFile file(sheetName);
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void ownerFind::update(){
    QString str1;
    QString str="";
    QFile file1("../wisdom/wisdom/color.txt");
    if(!file1.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtInput(&file1);

    while(!txtInput.atEnd()){
        str=txtInput.readLine();
        QByteArray json_byte= str.toLatin1();
        QJsonParseError jsonError;
        QJsonDocument parseDoc=QJsonDocument::fromJson(json_byte,&jsonError);
        if(jsonError.error==QJsonParseError::NoError){
            if(parseDoc.isObject()){
                QJsonObject jsonObj=parseDoc.object();
                if(jsonObj.contains("color")){
                    QJsonValue colorValue=jsonObj.take("color");
                    if(colorValue.isString()){
                        str1=colorValue.toString();
                    }
                }
            }
        }
        qDebug()<<str1;
        if(str1=="blue"){
            this->loadStyleSheet(QString("../wisdom/qss/blue.qss"));
        }
        else if(str1=="black"){
            this->loadStyleSheet(QString("../wisdom/qss/black.qss"));
        }
        else if(str1=="navy"){
            this->loadStyleSheet(QString("../wisdom/qss/navy.qss"));
        }
        else if(str1=="grey"){
            this->loadStyleSheet(QString("../wisdom/qss/grey.qss"));
        }
    }
    file1.close();
}



