#include"closedialog.h"

CloseDialog::CloseDialog()
{

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



    m_flag = 0;//窗口关闭选项的初始化
    QGroupBox *closeSelection = new QGroupBox(tr("关闭选项"));
    hide = new QRadioButton(tr("隐藏到后台"));
    hide->setChecked(true);
    holdOn = new QRadioButton(tr("立即关闭"));

    QVBoxLayout *vLayout1 = new QVBoxLayout;
    vLayout1->addWidget(hide);
    vLayout1->addWidget(holdOn);
    closeSelection->setLayout(vLayout1);

    QHBoxLayout *hLayout1 = new QHBoxLayout;
    okBtn = new QPushButton(tr("确定"));
    okBtn->setIcon(submitIcon);
    cancelBtn = new QPushButton(tr("取消"));
    cancelBtn->setIcon(backIcon);
    hLayout1->addStretch();
    hLayout1->addWidget(okBtn);
    hLayout1->addSpacing(10);
    hLayout1->addWidget(cancelBtn);
    hLayout1->addStretch();

    QHBoxLayout *hLayout2 = new QHBoxLayout;
    closeCbox = new QCheckBox;
    closeCbox->setText(tr("默认此选项，以后不再提示"));
    hLayout2->addWidget(closeCbox);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(closeSelection);
    mainLayout->addLayout(hLayout2);
    mainLayout->addLayout(hLayout1);

    setLayout(mainLayout);
    setWindowTitle(tr("提示"));
    this->resize(400,200);

    connect(okBtn,SIGNAL(clicked()),this,SLOT(ok_PushButton_Clicked()));
    connect(cancelBtn,SIGNAL(clicked()),this,SLOT(cancel_PushButton_Clicked()));

    update();
}

//弹出小窗口关闭
void CloseDialog::closeEvent(QCloseEvent *e)
{
    if (!m_flag)//若直接关闭对话框，m_flag置3
        {
        m_flag = 3;//保持原状态，不关闭
    }
    if(m_flag==-1){
        e->ignore();
    }
}

//确定按钮
void CloseDialog::ok_PushButton_Clicked()
{
    if (hide->isChecked())
        {
        m_flag = 1;//隐藏到后台
    }
    else if (holdOn->isChecked())
        {
        m_flag = 2;//立即关闭
    }
    this->close();
}

//取消按钮
void CloseDialog::cancel_PushButton_Clicked()
{
    m_flag = 3;//保持原状态，不关闭
    this->close();
}
void CloseDialog::loadStyleSheet(const QString &sheetName)
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

void CloseDialog::update(){
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

