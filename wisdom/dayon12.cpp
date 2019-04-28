#include"dayon12.h"
#include<QGridLayout>
#include<QMessageBox>


dayon12::dayon12(wisdom*w,QWidget*parent)
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

    setWindowTitle(tr("销假"));
    label4=new QLabel("请输入销假人的姓名:");
    label1=new QLabel("姓名");
    label2=new QLabel("请假时间");
    label3=new QLabel("请假原因");
    label1->hide();
    label2->hide();
    label3->hide();
    line1=new QLineEdit;
    line2=new QLineEdit;
    line3=new QLineEdit;
    line4=new QLineEdit;
    line1->hide();
    line2->hide();
    line3->hide();


    findButton=new QPushButton(tr("查询"));
    findButton->setIcon(findIcon);
    findButton->show();
    submitButton=new QPushButton(tr("撤销"));
    submitButton->setIcon(deleteIcon);
    submitButton->show();
    submitButton->setEnabled(false);
    cancelButton=new QPushButton(tr("取消"));
    cancelButton->setIcon(backIcon);
    cancelButton->show();
    QVBoxLayout *layout1=new QVBoxLayout;
    layout1->addWidget(label1);
    layout1->addWidget(label2);
    layout1->addWidget(label3);

    QVBoxLayout *layout2=new QVBoxLayout;
    layout2->addWidget(line1);
    layout2->addWidget(line2);
    layout2->addWidget(line3);

    QVBoxLayout *layout3=new QVBoxLayout;
    layout3->addWidget(findButton);
    layout3->addWidget(submitButton);
    layout3->addWidget(cancelButton);

    QGridLayout*mainLayout1=new QGridLayout;
    mainLayout1->addLayout(layout1,0,0);
    mainLayout1->addLayout(layout2,0,1);

    mainLayout=new QGridLayout;
    mainLayout->addWidget(label4,0,0,1,3);
    mainLayout->addWidget(line4,1,0,1,2);
    mainLayout->addLayout(mainLayout1,2,0,4,2,Qt::AlignTop);
    mainLayout->addLayout(layout3,0,2,5,1,Qt::AlignTop);

    setLayout(mainLayout);
    wis=new wisdom;
    wis=w;

    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));
    connect(findButton,SIGNAL(clicked()),this,SLOT(find()));
    connect(submitButton,SIGNAL(clicked()),this,SLOT(submit()));

    update();
}

void dayon12::cancel(){

    this->close();
    wis->show();

}
void dayon12::find(){

    QFile file("../wisdom/wisdom/dayoff12.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
        QTextStream txtInput(&file);
        QString str="";
        QString text=line4->text();

        QString str1;
        QString str2;
        QString str3;
        QString str4;
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
                        if(jsonObj.contains("time")){
                            QJsonValue timeValue=jsonObj.take("time");
                            if(timeValue.isString()){
                                str2=timeValue.toString();
                                qDebug()<<str2;

                            }
                        }
                        if(jsonObj.contains("reason")){
                            QJsonValue reasonValue=jsonObj.take("reason");
                            if(reasonValue.isString()){
                                str3=reasonValue.toString();
                                qDebug()<<str3;


                            }
                        }
                        if(jsonObj.contains("state")){
                            QJsonValue stateValue=jsonObj.take("state");
                            if(stateValue.isString()){
                                str4=stateValue.toString();
                                qDebug()<<str4;
                            }
                        }

                        if(txtInput.atEnd()){
                            if(str1!=text){
                                QMessageBox::information(this,tr("查找失败"),tr("该用户不存在"));
                            }
                        }
                        if(str1==text){
                            mainLayout->setRowStretch(0,0);
                            mainLayout->setRowStretch(1,0);
                            mainLayout->setRowStretch(2,1);
                            label4->hide();
                            label1->show();
                            label2->show();
                            label3->show();
                            line4->hide();
                            line1->show();
                            line2->show();
                            line3->show();

                            line1->setText(str1);
                            line2->setText(str2);
                            line3->setText(str3);

                            line1->setEnabled(false);
                            line2->setEnabled(false);
                            line3->setEnabled(false);
                            findButton->setEnabled(false);
                            submitButton->setEnabled(true);
                            break;
                        }
                    }
                }
            }
        }
    file.close();
}

void dayon12::submit(){
    QFile file2("../wisdom/wisdom/temp.txt");
    if(!file2.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file2.close();

    QFile file1("../wisdom/wisdom/dayoff12.txt");
    if(!file1.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }

    QTextStream txt(&file1);
    QString str;
    QString str1;
    QString str2;
    QString str3;
    QString str4;

    QString text=line4->text();

    while(!txt.atEnd()){
        str=txt.readLine();
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
                if(jsonObj.contains("time")){
                    QJsonValue timeValue=jsonObj.take("time");
                    if(timeValue.isString()){
                        str2=timeValue.toString();
                        qDebug()<<str2;


                    }
                }
                if(jsonObj.contains("reason")){
                    QJsonValue reasonValue=jsonObj.take("reason");
                    if(reasonValue.isString()){
                        str3=reasonValue.toString();
                        qDebug()<<str3;
                    }
                }
                if(jsonObj.contains("state")){
                    QJsonValue stateValue=jsonObj.take("state");
                    if(stateValue.isString()){
                        str4=stateValue.toString();
                        qDebug()<<str4;
                    }
                }
            }
        }
        if(text==str1){

        }
        else{
            QFile file2("../wisdom/wisdom/temp.txt");
            if(!file2.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text)){
                QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
            }
            QTextStream temp(&file2);
            QJsonObject json;
            json.insert("name",QString(str1));
            json.insert("time",QString(str2));
            json.insert("reason",QString(str3));
            json.insert("state",QString(str4));
            QJsonDocument document;
            document.setObject(json);
            QByteArray byteArray=document.toJson(QJsonDocument::Compact);
            QString json_str(byteArray);
            temp<<json_str<<endl;
            file2.close();
        }
    }
    file1.close();
    QFile file3("../wisdom/wisdom/temp.txt");
    QFile file4("../wisdom/wisdom/dayoff12.txt");
    if(!file4.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream temp2(&file4);
    if(!file3.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream temp1(&file3);
    QString s;
    while(!temp1.atEnd()){
        s=temp1.readLine();
        temp2<<s<<endl;
    }
    file3.close();
    file4.close();


    QMessageBox::information(this,tr("撤销成功"),tr("撤销成功"));
    this->close();
    wis->show();
}
void dayon12::loadStyleSheet(const QString &sheetName)
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

void dayon12::update(){
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

