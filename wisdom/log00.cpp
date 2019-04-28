#include"log00.h"
#include<QGridLayout>
#include<QMessageBox>
#include<QIcon>

log00::log00(QWidget*parent)
    :QDialog(parent){

    setWindowTitle("智慧小区登陆");
    label0=new QLabel;
    label0->setScaledContents(true);
    label0->setPixmap(QString(":/new/prefix1/img/5.png"));
    label0->setFixedSize(100,100);
    label00=new QLabel;
    label00->setScaledContents(true);
    label00->setPixmap(QString(":/new/prefix1/img/6.png"));
    label00->setFixedSize(250,57.5);
    label1=new QLabel("用户名");
    label2=new QLabel("密码");
    line1=new QLineEdit;
    line2=new QLineEdit;
    line2->setEchoMode(QLineEdit::Password);
    log0=new QPushButton("登录");
    register0=new QPushButton("注册");
    QIcon logIcon(":/new/prefix1/img/log .png");
    QIcon registerIcon(":/new/prefix1/img/register.png");
    log0->setIcon(logIcon);
    register0->setIcon(registerIcon);

    QHBoxLayout*layout=new QHBoxLayout;
    layout->addStretch();
    layout->addWidget(log0);
    layout->addWidget(register0);
    layout->addStretch();

    QHBoxLayout*layout2=new QHBoxLayout;
    layout2->addStretch();
    layout2->addWidget(label00);
    layout2->addStretch();

    QHBoxLayout*layout1=new QHBoxLayout;
    layout1->addStretch();
    layout1->addWidget(label0);
    layout1->addStretch();


    QGridLayout*mainLayout=new QGridLayout;
    mainLayout->addLayout(layout1,0,1,1,2);
    mainLayout->addLayout(layout2,1,1,1,2);
    mainLayout->addWidget(label1,2,1,1,1);
    mainLayout->addWidget(line1,2,2,1,1);
    mainLayout->addWidget(label2,3,1,1,1);
    mainLayout->addWidget(line2,3,2,1,1);
    mainLayout->addLayout(layout,4,1,1,2);

    setLayout(mainLayout);
    setFixedWidth(310);
    connect(log0,SIGNAL(clicked()),this,SLOT(log()));
    connect(register0,SIGNAL(clicked()),this,SLOT(register2()));


    QPixmap pixmap = QPixmap(":/new/prefix1/img/7.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this-> setPalette(palette);
    update();


}

void log00::log(){
    bool flag=false;
    QFile file2("../wisdom/wisdom/temp.txt");
    if(!file2.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file2.close();
    QString text1=line1->text();
    QString text2=line2->text();
    QFile file("../wisdom/wisdom/log00.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtInput(&file);
    QString str1;
    QString str2;
    QString str;
    int nn=0;
    if(text1==""||text2==""){
        QMessageBox::information(this,tr("输入为空"),tr("输入为空，请检查用户名和密码是否正确输入。"));
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
                     if(jsonObj.contains("keyword")){
                         QJsonValue keywordValue=jsonObj.take("keyword");
                         if(keywordValue.isString()){
                             str2=keywordValue.toString();
                             qDebug()<<str2;
                         }
                     }
                     if(jsonObj.contains("identity")){
                         QJsonValue identityValue=jsonObj.take("identity");
                         if(identityValue.isDouble()){
                             nn=identityValue.toInt();
                             qDebug()<<nn;
                         }
                     }
                 }
             }
             if(text1==str1&&text2==str2){
                 QFile file2("../wisdom/wisdom/temp.txt");
                 if(!file2.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text)){
                     QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
                 }
                 QTextStream temp(&file2);
                 QJsonObject json;
                 json.insert("name",QString(str1));
                 json.insert("keyword",QString(str2));
                 json.insert("identity",nn);
                 json.insert("state",1);

                 QJsonDocument document;
                 document.setObject(json);
                 QByteArray byteArray=document.toJson(QJsonDocument::Compact);
                 QString json_str(byteArray);
                 temp<<json_str<<endl;
                 file2.close();


                 this->close();
                 wis=new wisdom;
                 wis->show();
                 flag=true;

             }
             else{
                 QFile file2("../wisdom/wisdom/temp.txt");
                 if(!file2.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text)){
                     QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
                 }
                 QTextStream temp(&file2);
                 QJsonObject json;
                 json.insert("name",QString(str1));
                 json.insert("keyword",QString(str2));
                 json.insert("identity",nn);
                 json.insert("state",0);
                 QJsonDocument document;
                 document.setObject(json);
                 QByteArray byteArray=document.toJson(QJsonDocument::Compact);
                 QString json_str(byteArray);
                 temp<<json_str<<endl;
                 file2.close();
             }
             if(txtInput.atEnd()){
                 if(!flag){
                     QMessageBox::information(this,tr("登陆失败"),tr("请检查用户名和密码是否比配"));
                     line2->clear();
                 }
             }
         }
    }
    file.close();
    QFile file3("../wisdom/wisdom/temp.txt");
    QFile file4("../wisdom/wisdom/log00.txt");
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
}

void log00::register2(){
    r=new register1(this);
    this->close();
    r->show();
}
void log00::loadStyleSheet(const QString &sheetName)
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

void log00::update(){
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



