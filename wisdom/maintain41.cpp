#include"maintain41.h"
#include<QGridLayout>
#include<QMessageBox>

maintain41::maintain41(wisdom*w,QWidget*parent)
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

    setWindowTitle("业主报修");
    label1=new QLabel(tr("业主姓名"));
    label2=new QLabel(tr("联系方式"));
    label3=new QLabel(tr("住址"));
    label4=new QLabel(tr("原因"));
    line1=new QLineEdit;
    line2=new QLineEdit;
    line3=new QLineEdit;
    text=new QTextEdit;
    submitButton=new QPushButton(tr("提交"));
    submitButton->setIcon(submitIcon);
    submitButton->show();
    cancelButton=new QPushButton(tr("取消"));
    cancelButton->setIcon(backIcon);
    cancelButton->show();

    QVBoxLayout *layout1=new QVBoxLayout;
    layout1->addWidget(label1);
    layout1->addWidget(label2);
    layout1->addWidget(label3);
    layout1->addWidget(label4);
    layout1->addStretch();
    layout1->setSpacing(14);

    QVBoxLayout *layout2=new QVBoxLayout;
    layout2->addWidget(line1);
    layout2->addWidget(line2);
    layout2->addWidget(line3);
    layout2->addWidget(text);
    layout2->addStretch();

    QVBoxLayout *layout3=new QVBoxLayout;
    layout3->addWidget(submitButton);
    layout3->addWidget(cancelButton);
    layout3->addStretch();


    QGridLayout *mainLayout=new QGridLayout;
    mainLayout->addLayout(layout1,0,0);
    mainLayout->addLayout(layout2,0,1);
    mainLayout->addLayout(layout3,0,2);
    setLayout(mainLayout);

    wis=new wisdom;
    wis=w;
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));
    connect(submitButton,SIGNAL(clicked()),this,SLOT(submit()));
    update();


}

void maintain41::cancel(){

    this->close();
    wis->show();

}

void maintain41::submit(){
    QString name=line1->text();
    int telephone=line2->text().toInt();
    QString address=line3->text();
    QString reason=text->toPlainText();
    QJsonObject json;
    json.insert("name",QString(name));
    json.insert("telephone",telephone);
    json.insert("address",QString(address));
    json.insert("reason",QString(reason));
    json.insert("state",0);


    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray=document.toJson(QJsonDocument::Compact);
    QString json_str(byteArray);
    QFile file("../wisdom/wisdom/maintain41.txt");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtOutPut(&file);
    txtOutPut<<json_str<<endl;
    QMessageBox::information(this,tr("添加成功"),tr("添加成功"));
    file.close();
    this->close();
    wis->show();


}
void maintain41::loadStyleSheet(const QString &sheetName)
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
void maintain41::update(){
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

