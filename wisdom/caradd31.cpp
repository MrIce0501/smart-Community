#include"caradd31.h"
#include<QGridLayout>
#include<QMessageBox>

carAdd31::carAdd31(wisdom*w,QWidget*parent)
    :QDialog(parent){


    QIcon submitIcon(":/new/prefix1/img/finish.png");                    //图标的声明
    QIcon upLoadIcon(":/new/prefix1/img/upload.png");
    QIcon backIcon(":/new/prefix1/img/back.png");

    setWindowTitle("添加车位信息");
    label1=new QLabel(tr("照片"));
    label2=new QLabel(tr("姓名"));
    label3=new QLabel(tr("车位"));
    label4=new QLabel(tr("车牌号"));
    label5=new QLabel(tr("联系电话"));
    line1=new QLineEdit;
    line2=new QLineEdit;
    line3=new QLineEdit;
    line4=new QLineEdit;
    submitButton=new QPushButton(tr("确定"));
    submitButton->setIcon(submitIcon);
    submitButton->show();
    cancelButton=new QPushButton(tr("取消"));
    cancelButton->setIcon(backIcon);
    cancelButton->show();
    uploadButton=new QPushButton(tr("上传"));
    uploadButton->setIcon(upLoadIcon);
    uploadButton->show();
    QVBoxLayout *layout1=new QVBoxLayout;
    layout1->addWidget(label1);
    layout1->addWidget(label2);
    layout1->addWidget(label3);
    layout1->addWidget(label4);
    layout1->addWidget(label5);

    QVBoxLayout *layout2=new QVBoxLayout;
    layout2->addWidget(uploadButton);
    layout2->addWidget(line1);
    layout2->addWidget(line2);
    layout2->addWidget(line3);
    layout2->addWidget(line4);

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
    connect(submitButton,SIGNAL(clicked(bool)),this,SLOT(submit()));


    update();
}
void carAdd31::cancel(){

    this->close();
    wis->show();

}

void carAdd31::submit(){
    QString name=line1->text();
    QString park=line2->text();
    QString carNumber=line3->text();
    int telephone=line4->text().toInt();
    QJsonObject json;
    json.insert("name",QString(name));
    json.insert("park",QString(park));
    json.insert("carNumber",QString(carNumber));
    json.insert("telephone",telephone);

    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray=document.toJson(QJsonDocument::Compact);
    QString json_str(byteArray);
    QFile file("../wisdom/wisdom/car31.txt");
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
void carAdd31::loadStyleSheet(const QString &sheetName)
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
void carAdd31::update(){
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
