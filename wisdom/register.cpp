#include"register.h"



register1::register1(log00*l,QWidget*parent)
    :QDialog(parent){

    QIcon submitIcon(":/new/prefix1/img/finish.png");
    QIcon backIcon(":/new/prefix1/img/back.png");

    label1=new QLabel("用户名");
    label2=new QLabel("设置密码");
    label3=new QLabel("再次输入密码");
    line1=new QLineEdit;
    line2=new QLineEdit;
    line3=new QLineEdit;
    groupBox=new QGroupBox;
    radio1=new QRadioButton("物业管理人员");
    radio2=new QRadioButton("物业人员");
    radio3=new QRadioButton("业主");
    submitButton=new QPushButton("提交");
    submitButton->setIcon(submitIcon);
    cancelButton=new QPushButton("取消");
    cancelButton->setIcon(backIcon);

    log=new log00;
    log=l;

    QHBoxLayout* layout1=new QHBoxLayout;
    layout1->addStretch();
    layout1->addWidget(radio1);
    layout1->addWidget(radio2);
    layout1->addWidget(radio3);
    layout1->addStretch();
    groupBox->setLayout(layout1);

    QHBoxLayout*layout=new QHBoxLayout;
    layout->addStretch();
    layout->addWidget(submitButton);
    layout->addWidget(cancelButton);
    layout->addStretch();

    QGridLayout*mainLayout=new QGridLayout;
    mainLayout->addWidget(label1,1,1,1,1);
    mainLayout->addWidget(label2,2,1,1,1);
    mainLayout->addWidget(label3,3,1,1,1);
    mainLayout->addWidget(line1,1,2,1,1);
    mainLayout->addWidget(line2,2,2,1,1);
    mainLayout->addWidget(line3,3,2,1,1);
    mainLayout->addWidget(groupBox,4,1,1,2);
    mainLayout->addLayout(layout,5,1,1,2);




    setLayout(mainLayout);
    setWindowTitle("注册");
    setFixedWidth(360);

    connect(submitButton,SIGNAL(clicked()),this,SLOT(registerPress()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));

    update();
}

/*********************
*函数功能：联系button
*********************/

void register1::cancel(){
    this->close();
    log->show();
}


/*********************
*函数功能：联系button
*********************/
void register1::registerPress(){
    QString text1=line1->text();
    QString text2=line2->text();
    QString text3=line3->text();
    int n=0;
    if(radio1->isChecked()){
        n=1;
    }
    else if(radio2->isChecked()){
        n=2;
    }
    else if(radio3->isChecked())
    {
        n=3;
    }
    if(text1==""||text2==""||text3==""||n==0){
        QMessageBox::information(this,tr("输入为空"),tr("请检查信息是否全部完成，请从新输入。"));
        return;
    }
    else if(text2!=text3){
        QMessageBox::information(this,tr("输入有误"),tr("输入的两次密码不同，请从新输入。"));
        return;
    }
    else{
        QJsonObject json;
        json.insert("name",QString(text1));
        json.insert("keyword",QString(text2));
        json.insert("identity",n);
        json.insert("state",1);

        QJsonDocument document;
        document.setObject(json);
        QByteArray byteArray=document.toJson(QJsonDocument::Compact);
        QString json_str(byteArray);

        QFile file("../wisdom/wisdom/log00.txt");
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){
            QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
        }
        QTextStream txtOutPut(&file);
        txtOutPut<<json_str<<endl;
        QMessageBox::information(this,tr("注册成功"),tr("注册成功"));
        this->close();
        file.close();
        wis=new wisdom;
        wis->show();


    }
}

void register1::loadStyleSheet(const QString &sheetName)
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

void register1::update(){
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

