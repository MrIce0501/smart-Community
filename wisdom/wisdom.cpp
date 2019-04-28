#include<wisdom.h>




wisdom::wisdom(QWidget*parent)
    :QDialog(parent){
    /*********************
    *作者：欧阳澍崟
    *日期：7.13
    *更新时间：7.20
    *********************/




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
    QIcon keywordIcon(":/new/prefix1/img/keyword.png");


    toolbox=new QToolBox;
    tabWidget1=new QTabWidget;
    tabWidget2=new QTabWidget;
    tabWidget3=new QTabWidget;
    tabWidget4=new QTabWidget;
    tabWidget5=new QTabWidget;

    //人事管理模块
    widget1=new QWidget;
    button11=new QPushButton("工作人员维护");
    button12=new QPushButton("请销假");
    button13=new QPushButton("批假");
    button14=new QPushButton("出勤登记");
    QVBoxLayout *layout1=new QVBoxLayout;
    layout1->addWidget(button11);
    layout1->addWidget(button12);
    layout1->addWidget(button13);
    layout1->addWidget(button14);
    layout1->addStretch();
    widget1->setLayout(layout1);

    //人事管理模块——————————工作人员维护
    widget11=new QWidget;
    addBt11=new QPushButton("添加");
    addBt11->setIcon(addIcon);
    deleteBt11=new QPushButton("编辑");
    deleteBt11->setIcon(editIcon);

    QVBoxLayout *layout11=new QVBoxLayout;
    layout11->addWidget(addBt11);
    layout11->addWidget(deleteBt11);
    widget11->setLayout(layout11);

    //人事管理模块——————————请销假
    widget12=new QWidget;
    dayOffBt=new QPushButton("请假");
    dayOffBt->setIcon(lightIcon);
    dayOnBt=new QPushButton("销假");
    dayOnBt->setIcon(sendIcon);
    QVBoxLayout *layout12=new QVBoxLayout;
    layout12->addWidget(dayOffBt);
    layout12->addWidget(dayOnBt);

    widget12->setLayout(layout12);

    //人事管理模块——————————批假
    widget13=new QWidget;
    admitBt13=new QPushButton("批准");
    admitBt13->setIcon(submitIcon);
    refuseBt13=new QPushButton("驳回");
    putInBt13=new QPushButton("导入");
    putInBt13->setIcon(upLoadIcon);
    tableView13=new QTableView;
    model=new QStandardItemModel;

    model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    model->setHorizontalHeaderItem(1,new QStandardItem("请假时间"));
    model->setHorizontalHeaderItem(2,new QStandardItem("请假原因"));
    model->setHorizontalHeaderItem(3,new QStandardItem("状态"));
    tableView13->setModel(model);
    tableView13->setSelectionBehavior(QAbstractItemView::SelectItems);
    tableView13->setColumnWidth(2,170);

    QHBoxLayout*layout133=new QHBoxLayout;
    layout133->addStretch();
    layout133->addWidget(putInBt13);
    layout133->addWidget(admitBt13);

    QVBoxLayout *layout13=new QVBoxLayout;

    layout13->addWidget(tableView13);
    layout13->addLayout(layout133);

    widget13->setLayout(layout13);

    //人事管理模块——————————出勤登记
    widget14=new QWidget;
    Line14=new QLineEdit;
    logBt14=new QPushButton("登记");
    logBt14->setIcon(clockIcon);
    timer =new QTimer;
    timer->start(1000);
    QHBoxLayout*layout144=new QHBoxLayout;
    layout144->addStretch();
    layout144->addWidget(logBt14);
    layout144->addStretch();
    QVBoxLayout *layout14=new QVBoxLayout;
    layout14->addWidget(Line14);
    layout14->addLayout(layout144);
    widget14->setLayout(layout14);




    //业主管理模块
    widget2=new QWidget;
    button21 = new QPushButton( "业主登记");
    button22 = new QPushButton( "业主信息修改");
    button23 = new QPushButton( "业主查询");
    QVBoxLayout *layout2=new QVBoxLayout;
    layout2->addWidget(button21);
    layout2->addWidget(button22);
    layout2->addWidget(button23);
    layout2->addStretch();
    widget2->setLayout(layout2);

    //业主管理模块——————————————————业主登记
    widget21=new QWidget;
    log21=new QPushButton("登记");
    log21->setIcon(peopleIcon);
    QVBoxLayout *layout21=new QVBoxLayout;
    layout21->addWidget(log21);
    widget21->setLayout(layout21);

    //业主管理模块——————————————————业主信息修改
    widget22=new QWidget;
    modifyBt22=new QPushButton("修改");
    modifyBt22->setIcon(editIcon);
    QVBoxLayout *layout22=new QVBoxLayout;
    layout22->addWidget(modifyBt22);
    widget22->setLayout(layout22);

    //业主管理模块——————————————————业主信息查询
    widget23=new QWidget;
    findBt23=new QPushButton("查询");
    findBt23->setIcon(findIcon);
    QVBoxLayout *layout23=new QVBoxLayout;
    layout23->addWidget(findBt23);
    widget23->setLayout(layout23);



    //车位管理模块
    widget3=new QWidget;
    button31 = new QPushButton( "车位信息维护");
    button32 = new QPushButton( "业主车位申请");
    button33 = new QPushButton( "车位出租");
    QVBoxLayout *layout3=new QVBoxLayout;
    layout3->addWidget(button31);
    layout3->addWidget(button32);
    layout3->addWidget(button33);
    layout3->addStretch();
    widget3->setLayout(layout3);

    //车位管理模块————————————————————————车位信息维护
    widget31=new QWidget;
    addBt31=new QPushButton("添加");
    addBt31->setIcon(addIcon);
    deleteBt31=new QPushButton("编辑");
    deleteBt31->setIcon(editIcon);
    QVBoxLayout *layout31=new QVBoxLayout;
    layout31->addWidget(addBt31);
    layout31->addWidget(deleteBt31);
    widget31->setLayout(layout31);

    //车位管理模块————————————————————————业主车位申请
    widget32=new QWidget;
    applyBt32=new QPushButton("申请");
    applyBt32->setIcon(computerIcon);
    QVBoxLayout *layout32=new QVBoxLayout;
    layout32->addWidget(applyBt32);
    widget32->setLayout(layout32);


    //车位管理模块————————————————————————业主车位出租
    widget33=new QWidget;
    rentBt33=new QPushButton("购买");
    rentBt33->setIcon(purseIcon);
    label33=new QLabel("剩余车位：");
    label333=new QLabel;
    label331=new QLabel("总车位：");
    label332=new QLabel(QString("%1").arg(max));
    label330=new QLabel;
    label330->setScaledContents(true);
    label330->setFixedSize(560,300);
    label330->setPixmap(QString("../wisdom/img/1.jpg"));
    QVBoxLayout*layout331=new QVBoxLayout;
    layout331->addWidget(label331);
    layout331->addWidget(label33);
    layout331->addStretch();

    QVBoxLayout*layout332=new QVBoxLayout;
    layout332->addWidget(label332);
    layout332->addWidget(label333);
    layout332->addStretch();

    QGridLayout *layout33=new QGridLayout;
    layout33->addLayout(layout331,0,0);
    layout33->addLayout(layout332,0,1);
    layout33->addWidget(label330,1,0,1,2);
    layout33->addWidget(rentBt33,2,1);
    widget33->setLayout(layout33);


    //维修管理模块
    widget4=new QWidget;
    button41 = new QPushButton( "业主报修");
    button42 = new QPushButton( "维修跟踪");
    button43 = new QPushButton( "评价");
    button44 = new QPushButton( "物业维修进度");//*************************
    QVBoxLayout *layout4=new QVBoxLayout;
    layout4->addWidget(button41);
    layout4->addWidget(button42);
    layout4->addWidget(button43);
    layout4->addWidget(button44);
    layout4->addStretch();
    widget4->setLayout(layout4);

    //维修管理模块————————————————————————————业主报修
    widget41=new QWidget;
    label41=new QLabel;
    label41->setScaledContents(true);
    label41->setFixedSize(560,300);
    label41->setPixmap(QString("../wisdom/img/3.jpg"));
    maintainBt41=new QPushButton("报修");
    maintainBt41->setIcon(assistantIcon);
    QVBoxLayout *layout41=new QVBoxLayout;
    layout41->addWidget(label41);
    layout41->addWidget(maintainBt41);
    layout41->addStretch();
    widget41->setLayout(layout41);

    //维修管理模块————————————————————————————维修跟踪
    widget42=new QWidget;
    label42=new QLabel;
    label42->setPixmap(QString("../wisdom/img/2.jpg"));
    label42->setScaledContents(true);
    label42->setFixedSize(560,300);
    find422=new QPushButton("查询");
    find422->setIcon(findIcon);
    track42=new QPushButton("跟踪");
    track42->setIcon(startIcon);
    backBt42=new QPushButton("返回");
    backBt42->setIcon(backIcon);
    line42=new QLineEdit;
    label420=new QLabel("请输入查询的业主姓名：");
    groupBox42=new QGroupBox;
    radio421=new QRadioButton("要求已发送");
    radio422=new QRadioButton("物业已收到");
    radio423=new QRadioButton("派人检查中");
    radio424=new QRadioButton("维修中...");
    radio425=new QRadioButton("维修已完成");
    progressBar42=new QProgressBar;
    progressBar42->setRange(0,500000);
    QHBoxLayout*layout423=new QHBoxLayout;
    layout423->addWidget(radio421);
    layout423->addWidget(radio422);
    layout423->addWidget(radio423);
    layout423->addWidget(radio424);
    layout423->addWidget(radio425);



    QGridLayout *main=new QGridLayout;
    main->addLayout(layout423,0,0,1,5);
    main->addWidget(progressBar42,1,0,1,6);

    groupBox42->setLayout(main);
    groupBox42->hide();
    backBt42->setEnabled(false);
    track42->setEnabled(false);

    QGridLayout *layout42=new QGridLayout;

    layout42->addWidget(groupBox42,0,0,1,3);
    layout42->addWidget(label42,1,0,1,3);
    layout42->addWidget(label420,2,0,1,1);
    layout42->addWidget(line42,2,1,1,2);
    layout42->addWidget(find422,3,0,1,1);
    layout42->addWidget(track42,3,1,1,1);
    layout42->addWidget(backBt42,3,2,1,1);

    widget42->setLayout(layout42);


    //维修管理模块————————————————————————————评价
    widget43=new QWidget;
    text43=new QTextEdit;

    label43=new QLabel("评价");//*********************************************补充星星
    groupBox43=new QGroupBox("请选择满意度：");
    radio431=new QRadioButton("1星");
    radio432=new QRadioButton("2星");
    radio433=new QRadioButton("3星");
    radio434=new QRadioButton("4星");
    radio435=new QRadioButton("5星");
    QGridLayout*layout431=new QGridLayout;
    layout431->addWidget(label43,0,0,1,1);
    layout431->addWidget(text43,0,1,5,1);
    QHBoxLayout*layout433=new QHBoxLayout;
    layout433->addWidget(radio431);
    layout433->addWidget(radio432);
    layout433->addWidget(radio433);
    layout433->addWidget(radio434);
    layout433->addWidget(radio435);
    layout433->setSpacing(10);
    layout433->setMargin(15);
    groupBox43->setLayout(layout433);
    groupBox43->adjustSize();

    submitBt43=new QPushButton("提交");
    submitBt43->setIcon(submitIcon);
    QVBoxLayout *layout43=new QVBoxLayout;
    layout43->addWidget(groupBox43);
    layout43->addLayout(layout431);
    layout43->addWidget(submitBt43);
    layout43->addStretch();
    widget43->setLayout(layout43);

    //维修管理模块————————————————————————————维修进度
    widget44=new QWidget;
    label44=new QLabel;//**********************************************进度条
    label44->setScaledContents(true);
    label44->setFixedSize(560,300);
    label44->setPixmap(QString("../wisdom/img/4.jpg"));
    report44=new QPushButton("反馈");
    report44->setIcon(shareIcon);
    report44->setEnabled(false);
    find44=new QPushButton("查询");
    find44->setIcon(findIcon);
    line44=new QLineEdit;
    line441=new QLineEdit;
    line442=new QLineEdit;
    line443=new QLineEdit;
    label443=new QLabel("输入维修进度：");
    label440=new QLabel("请输入业主的姓名：");
    label443->hide();
    line443->hide();
    QGridLayout *layout44=new QGridLayout;
    layout44->addWidget(label44,0,0,1,3);
    layout44->addWidget(label440,1,0,1,1);
    layout44->addWidget(line44,1,1,1,2);
    layout44->addWidget(label443,2,0,1,1);
    layout44->addWidget(line443,2,1,1,2);

    layout44->addWidget(find44,3,1,1,1);
    layout44->addWidget(report44,3,2,1,1);
    widget44->setLayout(layout44);




    //系统管理模块
    widget5=new QWidget;
    button51 = new QPushButton( "个人信息");
    button52 = new QPushButton( "系统初始化");
    QVBoxLayout *layout5=new QVBoxLayout;
    layout5->addWidget(button51);
    layout5->addWidget(button52);
    layout5->addStretch();
    widget5->setLayout(layout5);

    //系统管理模块————————————————————————————————个人信息
    widget51=new QWidget;
    label510=new QLabel;
    label510->setScaledContents(true);
    label510->setPixmap(QString(":/new/prefix1/img/contact.png"));
    label510->setFixedSize(100,100);

    label51=new QLabel("个人信息");
    label511=new QLabel("姓名:");
    label512=new QLabel("身份:");
    label513=new QLabel("输入密码：");
    label514=new QLabel("再次输入密码：");
    label515=new QLabel;
    label516=new QLabel;
    line511=new QLineEdit;
    line512=new QLineEdit;
    modify51=new QPushButton("修改密码");
    modify51->setIcon(keywordIcon);
    submit51=new QPushButton("确定");
    submit51->setIcon(submitIcon);
    cancel51=new QPushButton("取消");
    cancel51->setIcon(backIcon);

    submit511=new QPushButton("确定");
    submit511->setIcon(submitIcon);
    cancel511=new QPushButton("取消");
    cancel511->setIcon(backIcon);
    change51=new QPushButton("更改主题");
    change51->setIcon(computerIcon);


    radio511=new QRadioButton("蓝色经典");
    radio512=new QRadioButton("黑色商务");
    radio513=new QRadioButton("灰色空间");
    radio514=new QRadioButton("军蓝情怀");

    QHBoxLayout *layout555=new QHBoxLayout;
    layout555->addStretch();
    layout555->addWidget(radio511);
    layout555->addWidget(radio512);
    layout555->addWidget(radio513);
    layout555->addWidget(radio514);
    layout555->addStretch();
    layout555->setSpacing(10);
    layout555->setMargin(15);

    groupBox51=new QGroupBox;
    groupBox51->setLayout(layout555);
    groupBox51->hide();

    cancel51->hide();
    submit51->hide();
    cancel511->hide();
    submit511->hide();
    label513->hide();
    label514->hide();
    line511->hide();
    line512->hide();

    QHBoxLayout*layout510=new QHBoxLayout;
    layout510->addStretch();
    layout510->addWidget(label510);
    layout510->addStretch();

    QHBoxLayout*layout511=new QHBoxLayout;
    layout511->addStretch();
    layout511->addWidget(label511);
    layout511->addWidget(label515);
    layout511->addStretch();

    QHBoxLayout*layout514=new QHBoxLayout;
    layout514->addStretch();
    layout514->addWidget(label512);
    layout514->addWidget(label516);
    layout514->addStretch();

    QHBoxLayout*layout512=new QHBoxLayout;
    layout512->addStretch();
    layout512->addWidget(label513);
    layout512->addWidget(line511);
    layout512->addStretch();

    QHBoxLayout*layout513=new QHBoxLayout;
    layout513->addStretch();
    layout513->addWidget(label514);
    layout513->addWidget(line512);
    layout513->addStretch();

    QHBoxLayout*layout515=new QHBoxLayout;
    layout515->addStretch();
    layout515->addWidget(modify51);
    layout515->addWidget(submit51);
    layout515->addWidget(cancel51);
    layout515->addStretch();

    QHBoxLayout*layout516=new QHBoxLayout;
    layout516->addStretch();
    layout516->addWidget(change51);
    layout516->addWidget(submit511);
    layout516->addWidget(cancel511);
    layout516->addStretch();

    QHBoxLayout*layout517=new QHBoxLayout;
    layout517->addStretch();
    layout517->addWidget(groupBox51);
    layout517->addStretch();

    QVBoxLayout *layout51=new QVBoxLayout;
    layout51->addLayout(layout510);
    layout51->addLayout(layout511);
    layout51->addLayout(layout514);
    layout51->addLayout(layout512);
    layout51->addLayout(layout513);
    layout51->addLayout(layout515);
    layout51->addLayout(layout517);
    layout51->addLayout(layout516);
    layout51->addStretch();
    layout51->setSpacing(20);

    widget51->setLayout(layout51);

    //系统管理模块————————————————————————————————系统初始化
    widget52=new QWidget;
    initialise=new QPushButton("初始化");
    initialise->setIcon(messageIcon);
    QVBoxLayout *layout52=new QVBoxLayout;
    layout52->addWidget(initialise);
    widget52->setLayout(layout52);




    //toolBox
    toolbox->addItem(widget1, "人事管理模块");
    toolbox->addItem(widget2, "业主管理模块");
    toolbox->addItem(widget3, "车位管理模块");
    toolbox->addItem(widget4, "维修管理模块");
    toolbox->addItem(widget5, "系统管理模块");
    toolbox->layout()->setSpacing(0);

    //tabWidget
    tabWidget1->addTab(widget11, "工作人员维护");
    tabWidget1->addTab(widget12,"请/销假");
    tabWidget1->addTab(widget13,"批假");
    tabWidget1->addTab(widget14,"出勤登记");
    tabWidget1->show();


    tabWidget2->addTab(widget21,"业主登记");
    tabWidget2->addTab(widget22,"业主信息修改");
    tabWidget2->addTab(widget23,"业主信息查询");
    tabWidget2->hide();

    tabWidget3->addTab(widget31,"车位信息维护");
    tabWidget3->addTab(widget32,"业主车位申请");
    tabWidget3->addTab(widget33,"车位出租");
    tabWidget3->hide();

    tabWidget4->addTab(widget41,"业主报修");
    tabWidget4->addTab(widget42,"维修跟踪");
    tabWidget4->addTab(widget43,"评价");
    tabWidget4->addTab(widget44,"物业维修进度");
    tabWidget4->hide();

    tabWidget5->addTab(widget51,"个人信息");
    tabWidget5->addTab(widget52,"系统初始化");
    tabWidget5->hide();



    Layout = new QGridLayout();
    Layout->addWidget(toolbox,0,0);
    Layout->addWidget(tabWidget1,0,1);
    Layout->addWidget(tabWidget2,0,2);
    Layout->addWidget(tabWidget3,0,3);
    Layout->addWidget(tabWidget4,0,4);
    Layout->addWidget(tabWidget5,0,5);

    Layout -> setColumnStretch(0, 1);
    Layout -> setColumnStretch(1, 3);
    Layout -> setColumnStretch(2, 0);
    Layout -> setColumnStretch(3, 0);
    Layout -> setColumnStretch(4, 0);
    Layout -> setColumnStretch(5, 0);


    Layout->setMargin(0);
    //==================================================================================================
    tabWidget1->setStyleSheet("QTabWidget:pane {border-top:0px solid #e8f3f9;background:  transparent; }");
    tabWidget2->setStyleSheet("QTabWidget:pane {border-top:0px solid #e8f3f9;background:  transparent; }");
    tabWidget3->setStyleSheet("QTabWidget:pane {border-top:0px solid #e8f3f9;background:  transparent; }");
    tabWidget4->setStyleSheet("QTabWidget:pane {border-top:0px solid #e8f3f9;background:  transparent; }");
    tabWidget5->setStyleSheet("QTabWidget:pane {border-top:0px solid #e8f3f9;background:  transparent; }");


    QPalette palette;
    setAutoFillBackground(true);
    QPixmap pixmap(QString(":/new/prefix1/img/9.jpg"));
    palette.setBrush(backgroundRole(),QBrush(pixmap));
    this->setPalette(palette);

    update();


    //==================================================================================================

    this->setLayout(Layout);
    this->setFixedSize(800,480);
    this->setWindowTitle("智慧小区");

    connect(button11, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked1()));
    connect(button12, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked1()));
    connect(button13, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked1()));
    connect(button14, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked1()));
    connect(button21, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked2()));
    connect(button22, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked2()));
    connect(button23, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked2()));
    connect(button31, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked3()));
    connect(button32, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked3()));
    connect(button33, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked3()));
    connect(button41, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked4()));
    connect(button42, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked4()));
    connect(button43, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked4()));
    connect(button44, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked4()));
    connect(button51, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked5()));
    connect(button52, SIGNAL(clicked(bool)),this, SLOT(OnButtonClicked5()));
    connect(toolbox,SIGNAL(currentChanged(int)),this,SLOT(tool_tab()));

    connect(addBt11,SIGNAL(clicked(bool)),this,SLOT(add11Press()));
    connect(deleteBt11,SIGNAL(clicked(bool)),this,SLOT(delete11Press()));
    connect(dayOffBt,SIGNAL(clicked(bool)),this,SLOT(dayOffPress()));
    connect(dayOnBt,SIGNAL(clicked(bool)),this,SLOT(dayOnPress()));
    connect(timer,&QTimer::timeout,this,&wisdom::timerUpdate);
    connect(logBt14,SIGNAL(clicked(bool)),this,SLOT(logPress()));
    connect(log21,SIGNAL(clicked(bool)),this,SLOT(ownerLogPress()));
    connect(modifyBt22,SIGNAL(clicked(bool)),this,SLOT(ownerModifyPress()));
    connect(findBt23,SIGNAL(clicked(bool)),this,SLOT(ownerFindPress()));
    connect(addBt31,SIGNAL(clicked()),this,SLOT(carAddPress()));
    connect(deleteBt31,SIGNAL(clicked()),this,SLOT(carDeletePress()));
    connect(maintainBt41,SIGNAL(clicked()),this,SLOT(maintainPress()));
    connect(admitBt13,SIGNAL(clicked()),this,SLOT(admitPress13()));
    connect(putInBt13,SIGNAL(clicked()),this,SLOT(putInPress13()));

    connect(radio421,SIGNAL(clicked()),this,SLOT(progressbar42()));
    connect(radio422,SIGNAL(clicked()),this,SLOT(progressbar42()));
    connect(radio423,SIGNAL(clicked()),this,SLOT(progressbar42()));
    connect(radio424,SIGNAL(clicked()),this,SLOT(progressbar42()));
    connect(radio425,SIGNAL(clicked()),this,SLOT(progressbar42()));
    connect(button33,SIGNAL(clicked()),this,SLOT(carleft()));
    connect(applyBt32,SIGNAL(clicked()),this,SLOT(carleft0()));
    connect(initialise,SIGNAL(clicked(bool)),this,SLOT(initialise1()));
    connect(find422,SIGNAL(clicked()),this,SLOT(find42()));
    connect(backBt42,SIGNAL(clicked()),this,SLOT(back42()));
    connect(find44,SIGNAL(clicked()),this,SLOT(find440()));
    connect(submitBt43,SIGNAL(clicked()),this,SLOT(submit43()));
    connect(report44,SIGNAL(clicked()),this,SLOT(report440()));
    connect(modify51,SIGNAL(clicked()),this,SLOT(keywordChange()));
    connect(submit51,SIGNAL(clicked()),this,SLOT(submitPress51()));
    connect(toolbox,SIGNAL(currentChanged(int)),this,SLOT(identity5()));
    connect(rentBt33,SIGNAL(clicked()),this,SLOT(rentPress()));
    connect(cancel511,SIGNAL(clicked()),this,SLOT(cancel511Press()));
    connect(cancel51,SIGNAL(clicked()),this,SLOT(cancel51Press()));
    connect(submit511,SIGNAL(clicked()),this,SLOT(submit511Press()));
    connect(change51,SIGNAL(clicked()),this,SLOT(change51Press()));

    mSysTrayIcon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/new/prefix1/img/5.png");
    mSysTrayIcon->setIcon(icon);
    mSysTrayIcon->setToolTip(QObject::trUtf8("智慧小区"));
    mSysTrayIcon->show();


 /*********************************************************
  * 函数！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
**************************************************************/
}

/*********************
*函数功能：链接toolbox和tabwidget
*********************/


void wisdom::tool_tab(){
    QWidget *a=new QWidget;
    a=toolbox->currentWidget();
    if(a==widget1){
        tabWidget1->show();
        tabWidget2->close();
        tabWidget3->close();
        tabWidget4->close();
        tabWidget5->close();
        Layout -> setColumnStretch(0, 1);
        Layout -> setColumnStretch(1, 3);
        Layout -> setColumnStretch(2, 0);
        Layout -> setColumnStretch(3, 0);
        Layout -> setColumnStretch(4, 0);
        Layout -> setColumnStretch(5, 0);

    }
    else if(a==widget2){
        tabWidget1->close();
        tabWidget2->show();
        tabWidget3->close();
        tabWidget4->close();
        tabWidget5->close();
        Layout -> setColumnStretch(0, 1);
        Layout -> setColumnStretch(1, 0);
        Layout -> setColumnStretch(2, 3);
        Layout -> setColumnStretch(3, 0);
        Layout -> setColumnStretch(4, 0);
        Layout -> setColumnStretch(5, 0);
    }
    else if(a==widget3){
        tabWidget1->close();
        tabWidget2->close();
        tabWidget3->show();
        tabWidget4->close();
        tabWidget5->close();
        Layout -> setColumnStretch(0, 1);
        Layout -> setColumnStretch(1, 0);
        Layout -> setColumnStretch(2, 0);
        Layout -> setColumnStretch(3, 3);
        Layout -> setColumnStretch(4, 0);
        Layout -> setColumnStretch(5, 0);
    }
    else if(a==widget4){
        tabWidget1->close();
        tabWidget2->close();
        tabWidget3->close();
        tabWidget4->show();
        tabWidget5->close();
        Layout -> setColumnStretch(0, 1);
        Layout -> setColumnStretch(1, 0);
        Layout -> setColumnStretch(2, 0);
        Layout -> setColumnStretch(3, 0);
        Layout -> setColumnStretch(4, 3);
        Layout -> setColumnStretch(5, 0);
    }
    else if(a==widget5){
        tabWidget1->close();
        tabWidget2->close();
        tabWidget3->close();
        tabWidget4->close();
        tabWidget5->show();
        Layout -> setColumnStretch(0, 1);
        Layout -> setColumnStretch(1, 0);
        Layout -> setColumnStretch(2, 0);
        Layout -> setColumnStretch(3, 0);
        Layout -> setColumnStretch(4, 0);
        Layout -> setColumnStretch(5, 3);
    }

}

/*********************
*函数功能：联系button
*********************/

void wisdom::OnButtonClicked1()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());

    if (btn == button11)
    {
        tabWidget1->setCurrentWidget(widget11);
    }
    else if(btn==button12){
        tabWidget1->setCurrentWidget(widget12);
    }
    else if(btn==button13){
        tabWidget1->setCurrentWidget(widget13);
    }
    else if(btn==button14){
        tabWidget1->setCurrentWidget(widget14);
    }


}

/*********************
*函数功能：联系button
*********************/
void wisdom::OnButtonClicked2()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());

    if (btn == button21)
    {
        tabWidget2->setCurrentWidget(widget21);
    }
    else if(btn==button22){
        tabWidget2->setCurrentWidget(widget22);
    }
    else if(btn==button23){
        tabWidget2->setCurrentWidget(widget23);
    }



}

/*********************
*函数功能：联系button
*********************/
void wisdom::OnButtonClicked3()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());

    if (btn == button31)
    {
        tabWidget3->setCurrentWidget(widget31);
    }
    else if(btn==button32){
        tabWidget3->setCurrentWidget(widget32);
    }
    else if(btn==button33){
        tabWidget3->setCurrentWidget(widget33);
    }


}
/*********************
*函数功能：联系button
*********************/
void wisdom::OnButtonClicked4()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());

    if (btn == button41)
    {
        tabWidget4->setCurrentWidget(widget41);
    }
    else if(btn==button42){
        tabWidget4->setCurrentWidget(widget42);
    }
    else if(btn==button43){
        tabWidget4->setCurrentWidget(widget43);
    }
    else if(btn==button44){
        tabWidget4->setCurrentWidget(widget44);
    }


}

/*********************
*函数功能：联系button
*********************/
void wisdom::OnButtonClicked5()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());

    if (btn == button51)
    {
        tabWidget5->setCurrentWidget(widget51);
    }
    else if(btn==button52){
        tabWidget5->setCurrentWidget(widget52);
    }


}
/*********************
*函数功能：联系button
*********************/
void wisdom::add11Press(){
    this->hide();
    add=new add11(this);
    add->show();
}
/*********************
*函数功能：联系button
*********************/
void wisdom::delete11Press(){
    this->hide();
    delete1=new delete11(this);
    delete1->show();
}
/*********************
*函数功能：联系button
*********************/
void wisdom::dayOffPress(){
    this->hide();
    dayoff1=new dayoff12(this);
    dayoff1->show();
}
/*********************
*函数功能：联系button
*********************/
void wisdom::dayOnPress(){
    this->hide();
    dayon1=new dayon12(this);
    dayon1->show();
}
/*********************
*函数功能：更新时间显示
*********************/
void wisdom::timerUpdate(){
    QDateTime time=QDateTime::currentDateTime();
    QString str=time.toString("yyyy-MM-dd hh:mm:ss dddd");
    Line14->setText(str);

}
/*********************
*函数功能：联系button
*********************/
void wisdom::logPress(){
    QDateTime time=QDateTime::currentDateTime();
    QString str=time.toString("yyyy-MM-dd hh:mm:ss dddd");
    QMessageBox::information(this,tr("登记成功"),tr("登记时间为 %1").arg(str));
}

/*********************
*函数功能：联系button
*********************/
void wisdom::ownerLogPress(){
    this->hide();
    own=new ownerLog21(this);
    own->show();
}

/*********************
*函数功能：联系button
*********************/
void wisdom::ownerModifyPress(){
    this->hide();
    modify=new ownerModify22(this);
    modify->show();
}

/*********************
*函数功能：联系button
*********************/
void wisdom::ownerFindPress(){
    ownerF=new ownerFind(this);
    ownerF->show();
}

/*********************
*函数功能：联系button
*********************/
void wisdom::carAddPress(){
    this->hide();
    carAdd=new carAdd31(this);
    carAdd->show();
}
/*********************
*函数功能：联系button
*********************/
void wisdom::carDeletePress(){
    this->hide();
    carDelete=new carDelete31(this);
    carDelete->show();
}
/*********************
*函数功能：联系button
*********************/
void wisdom::carApplyPress(){
    this->hide();
    carApply=new carApply32(this);
    carApply->show();
}
/*********************
*函数功能：联系button
*********************/
void wisdom::maintainPress(){
    this->hide();
    maintain=new maintain41(this);
    maintain->show();
}
/*********************
*函数功能：联系button
*********************/
void wisdom::progressbar42(){
    QRadioButton* btn = qobject_cast<QRadioButton*>(sender());
    if(btn==radio421){
        int n=progressBar42->value();
        if(n>=100000){
            n=0;
        }
        for(int i = n; i <= 100000; i++)
              {
                  progressBar42->setValue(i);
              }
    }
    else if(btn==radio422){
        int n=progressBar42->value();
        if(n>=200000){
            n=100000;
        }
        for(int i = n; i <= 200000; i++)
              {
                  progressBar42->setValue(i);
              }
    }
    else if(btn==radio423){
        int n=progressBar42->value();
        if(n>=300000){
            n=200000;
        }
        for(int i = n; i <= 300000; i++)
              {
                  progressBar42->setValue(i);
              }
    }
    else if(btn==radio424){
        int n=progressBar42->value();
        if(n>=400000){
            n=300000;
        }
        for(double i = n; i <= 400000; i++)
              {
                  progressBar42->setValue(i);
              }
    }
    else if(btn==radio425){
        int n=progressBar42->value();
        if(n>=500000){
            n=400000;
        }
        for(int i = n; i <= 500000; i++)
              {
                  progressBar42->setValue(i);
              }
    }
}
/*********************
*函数功能：联系button
*********************/
void wisdom::putInPress13(){
    int i=0;
    QFile file("../wisdom/wisdom/dayoff12.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtInput(&file);
    QString str="";


    QString str1;
    QString str2;
    QString str3;
    QString str4;
    QCheckBox *check=new QCheckBox;
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
                        if(str4=="not pass"){
                            check->setChecked(false);
                        }
                        else if(str4=="pass"){
                            check->setChecked(true);
                        }
                    }
                }
            }
        }
        QStandardItem *item1 = new QStandardItem(QString(str1));
        QStandardItem *item2 = new QStandardItem(QString(str2));
        QStandardItem *item3 = new QStandardItem(QString(str3));
        QStandardItem *item4 = new QStandardItem(QString(str4));

        model->setItem(i,0,item1);
        model->setItem(i,1,item2);
        model->setItem(i,2,item3);
        model->setItem(i,3,item4);
        i++;

    }
    tableView13->setModel(model);

    file.close();
}

/*********************
*函数功能：联系button
*********************/
void wisdom::carleft(){
    QString str;
    int n=0;
    QFile file("../wisdom/wisdom/apply32.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtInput(&file);
    while(!txtInput.atEnd()){
        str=txtInput.readLine();
        n++;
    }
    n=max-n;
    label333->setText(QString("%1").arg(n));

}
/*********************
*函数功能：联系button
*********************/
void wisdom::carleft0(){
    QString str;
    int n=0;
    QFile file("../wisdom/wisdom/apply32.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtInput(&file);
    while(!txtInput.atEnd()){
        str=txtInput.readLine();
        n++;
    }
    if(n==max){
        QMessageBox::information(this,tr("车位已满"),tr("抱歉，本小区车位已满。"));
    }
    else{
        carApplyPress();
    }
}
/*********************
*函数功能：联系button
*********************/
void wisdom::initialise1(){
    QFile file1("../wisdom/wisdom/add11.txt");
    if(!file1.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file1.close();

    QFile file2("../wisdom/wisdom/apply32.txt");
    if(!file2.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file2.close();

    QFile file3("../wisdom/wisdom/car31.txt");
    if(!file3.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file3.close();

    QFile file4("../wisdom/wisdom/dayoff12.txt");
    if(!file4.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file4.close();

    QFile file5("../wisdom/wisdom/owner21.txt");
    if(!file5.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file5.close();

    QFile file6("../wisdom/wisdom/temp.txt");
    if(!file6.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file6.close();

    QFile file7("../wisdom/wisdom/log00.txt");
    if(!file7.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file7.close();

    QFile file8("../wisdom/wisdom/evaluate43.txt");
    if(!file8.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file8.close();

    QFile file9("../wisdom/wisdom/maintain41.txt");
    if(!file9.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file9.close();

}

/*********************
*函数功能：联系button
*********************/
void wisdom::find42(){
    QString text=line42->text();
    QFile file("../wisdom/wisdom/maintain41.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtInput(&file);
    int n=0;
    int m=0;
    QString str1;
    QString str="";
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
                    if(jsonObj.contains("state")){
                        QJsonValue stateValue=jsonObj.take("state");
                        if(stateValue.isDouble()){
                            n=stateValue.toInt();
                            qDebug()<<n;
                        }
                    }
                    if(txtInput.atEnd()){
                        if(str1!=text){
                            QMessageBox::information(this,tr("查找失败"),tr("该用户不存在"));
                        }
                    }
                    if(str1==text){
                        m=n*5000;
                    }
                }
            }
        }
    }
    progressBar42->setValue(m);
    if(m<=100000){
        radio421->setChecked(true);
    }
    else if(m<=200000){
        radio422->setChecked(true);
    }
    else if(m<=300000){
        radio423->setChecked(true);
    }
    else if(m<=400000){
        radio424->setChecked(true);
    }
    else if(m<=500000){
        radio425->setChecked(true);
    }
    label42->hide();
    backBt42->setEnabled(true);
    track42->setEnabled(true);
    groupBox42->show();

}

/*********************
*函数功能：联系button
*********************/
void wisdom::back42(){
    label42->show();
    backBt42->setEnabled(false);
    track42->setEnabled(false);
    groupBox42->hide();
}
/*********************
*函数功能：联系button
*********************/
void wisdom::submit43(){
    int n;
    if(radio431->isChecked()){
        n=1;
    }
    else if(radio432->isChecked()){
        n=2;
    }
    else if(radio433->isChecked()){
        n=3;
    }
    else if(radio434->isChecked()){
        n=4;
    }
    else if(radio435->isChecked()){
        n=5;
    }
    else{
        QMessageBox::information(this,tr("未完成"),tr("请检查是否填写完全"));
        return;
    }
    QString evaluate=text43->toPlainText();
    if(evaluate==""){
        QMessageBox::information(this,tr("未完成"),tr("请检查是否填写完全"));
        return;
    }
    else{
        QJsonObject json;
        json.insert("star",n);
        json.insert("evaluate",QString(evaluate));

        QJsonDocument document;
        document.setObject(json);
        QByteArray byteArray=document.toJson(QJsonDocument::Compact);
        QString json_str(byteArray);
        QFile file("../wisdom/wisdom/evaluate43.txt");
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){
            QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
        }
        QTextStream txtOutPut(&file);
        txtOutPut<<json_str<<endl;
        QMessageBox::information(this,tr("添加成功"),tr("感谢您的评价。"));
        file.close();
        text43->setEnabled(false);
        radio431->setEnabled(false);
        radio432->setEnabled(false);
        radio433->setEnabled(false);
        radio434->setEnabled(false);
        radio435->setEnabled(false);
    }
}
/*********************
*函数功能：联系button
*********************/
void wisdom::find440(){
    QFile file("../wisdom/wisdom/maintain41.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtInput(&file);
    int n=0;
    QString str;
    QString str1;
    QString str2;
    QString text=line44->text();
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
                    if(jsonObj.contains("state")){
                        QJsonValue stateValue=jsonObj.take("state");
                        if(stateValue.isDouble()){
                            n=stateValue.toInt();
                            str2=tr("%1").arg(n);
                            qDebug()<<str2;

                        }
                    }
                    if(txtInput.atEnd()){
                        if(str1!=text){
                            QMessageBox::information(this,tr("查找失败"),tr("该用户不存在"));
                        }
                    }
                    if(str1==text){
                        line44->hide();
                        label440->hide();
                        line443->show();
                        label443->show();
                        line443->setText(QString("%1").arg(n));
                        report44->setEnabled(true);
                        find44->setEnabled(false);

                    }
                }
            }
        }

    }
    file.close();
}
/*********************
*函数功能：联系button
*********************/
void wisdom::report440(){
    QString text1=line443->text();
    QString text=line44->text();

    QFile file2("../wisdom/wisdom/temp.txt");
    if(!file2.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file2.close();
    QFile file1("../wisdom/wisdom/maintain41.txt");
    if(!file1.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txt(&file1);
    QString str;
    QString str1;
    QString str2;
    QString str3;
    QString str4;
    QString str5;
    QString str11;
    QString str33;
    QString str44;
    int n=0;
    int m=0;
    int n1=0;
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
                if(jsonObj.contains("telephone")){
                    QJsonValue telephoneValue=jsonObj.take("telephone");
                    if(telephoneValue.isDouble()){
                        n=telephoneValue.toInt();
                        str2=tr("%1").arg(n);
                        qDebug()<<str2;


                    }
                }
                if(jsonObj.contains("address")){
                    QJsonValue addressValue=jsonObj.take("address");
                    if(addressValue.isString()){
                        str3=addressValue.toString();
                        qDebug()<<str3;
                    }
                }
                if(jsonObj.contains("reason")){
                    QJsonValue reasonValue=jsonObj.take("reason");
                    if(reasonValue.isString()){
                        str4=reasonValue.toString();
                        qDebug()<<str4;

                    }
                }
                if(jsonObj.contains("state")){
                    QJsonValue stateValue=jsonObj.take("reason");
                    if(stateValue.isDouble()){
                        n1=stateValue.toInt();
                        str5=tr("%1").arg(n1);
                        qDebug()<<str5;

                    }
                }
            }
        }
        if(text==str1){
            m=n;
            str11=str1;
            str33=str3;
            str44=str4;

        }
        else{
            QFile file2("../wisdom/wisdom/temp.txt");
            if(!file2.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text)){
                QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
            }
            QTextStream temp(&file2);
            QJsonObject json;
            json.insert("name",QString(str1));
            json.insert("telephone",n);
            json.insert("address",QString(str3));
            json.insert("reason",QString(str4));
            json.insert("state",n1);
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
    QFile file4("../wisdom/wisdom/maintain41.txt");
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
    int m1=text1.toInt();
    QJsonObject json1;
    json1.insert("name",QString(str11));
    json1.insert("telephone",m);
    json1.insert("address",QString(str33));
    json1.insert("reason",QString(str44));
    json1.insert("state",m1);



    QJsonDocument document1;
    document1.setObject(json1);
    QByteArray byteArray1=document1.toJson(QJsonDocument::Compact);
    QString json_str1(byteArray1);

    QTextStream txtOutPut(&file4);
    txtOutPut<<json_str1<<endl;
    QMessageBox::information(this,tr("更新成功"),tr("更新成功"));
    file4.close();
}
/*********************
*函数功能：身份认证
*********************/
void wisdom::identity5(){
    QWidget *a=new QWidget;
    a=toolbox->currentWidget();
    if(a==widget5){
        QString str1;
        int n=0;
        int m=0;
        QFile file("../wisdom/wisdom/log00.txt");
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
            QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
        }
        QTextStream txtInput(&file);
        QString str="";
        while(!txtInput.atEnd()){
            //+++++++++++++++++++++++++++++++++++++++++==这里有个bug
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
                    if(jsonObj.contains("identity")){
                        QJsonValue identityValue=jsonObj.take("identity");
                        if(identityValue.isDouble()){
                            m=identityValue.toInt();
                            qDebug()<<m;

                        }
                    }
                    if(jsonObj.contains("state")){
                        QJsonValue stateValue=jsonObj.take("state");
                        if(stateValue.isDouble()){
                            n=stateValue.toInt();
                            qDebug()<<n;

                        }
                    }
                    if(n==1){
                        label515->setText(str1);
                        if(m==1){
                            label516->setText("物业管理人员");
                        }
                        else if(m==2){
                            label516->setText("物业人员");
                        }
                        else if(m==3){
                            label516->setText("业主");
                        }
                        break;
                    }
                }
            }
        }
        file.close();
    }

}


void wisdom::keywordChange(){
    cancel51->show();
    submit51->show();
    label513->show();
    label514->show();
    line511->show();
    line512->show();
    change51->hide();
    modify51->setEnabled(false);
}

void wisdom::submitPress51(){
    QString text1=line511->text();
    QString text2=line512->text();
    QString line=label515->text();
    if(text1!=text2){
        QMessageBox::information(this,tr("输入有误"),tr("请检查两次的输入是否相同。"));
        return;

    }
    else{
        QFile file2("../wisdom/wisdom/temp.txt");
        if(!file2.open(QIODevice::WriteOnly|QIODevice::Truncate)){
            QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
        }
        file2.close();

        QFile file("../wisdom/wisdom/log00.txt");
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
            QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
        }
        QTextStream txtInput(&file);
        QString str1;
        QString str2;
        QString str;
        int nn=0;
        int mm=0;
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
                    if(jsonObj.contains("state")){
                        QJsonValue stateValue=jsonObj.take("state");
                        if(stateValue.isDouble()){
                            mm=stateValue.toInt();
                            qDebug()<<mm;
                        }
                    }
                }
            }
            if(str1==line){
                QFile file2("../wisdom/wisdom/temp.txt");
                if(!file2.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text)){
                    QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
                }
                QTextStream temp(&file2);
                QJsonObject json;
                json.insert("name",QString(str1));
                json.insert("keyword",QString(text1));
                json.insert("identity",nn);
                json.insert("state",mm);

                QJsonDocument document;
                document.setObject(json);
                QByteArray byteArray=document.toJson(QJsonDocument::Compact);
                QString json_str(byteArray);
                temp<<json_str<<endl;
                file2.close();
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
                json.insert("state",mm);
                QJsonDocument document;
                document.setObject(json);
                QByteArray byteArray=document.toJson(QJsonDocument::Compact);
                QString json_str(byteArray);
                temp<<json_str<<endl;
                file2.close();
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
        QMessageBox::information(this,tr("修改成功"),tr("修改成功"));

    }
}

/*********************
*函数功能：关闭函数
*********************/
void wisdom::closeEvent(QCloseEvent *e)
{
    QFile file1("../wisdom/wisdom/temp.txt");
    if(!file1.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file1.close();
    QString str1;
    QString str2;
    int n=0;
    int m=0;
    QFile file("../wisdom/wisdom/log00.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtInput(&file);
    QString str="";
    while(!txtInput.atEnd()){
        //+++++++++++++++++++++++++++++++++++++++++==这里有个bug
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
                        m=identityValue.toInt();
                        qDebug()<<m;

                    }
                }
                if(jsonObj.contains("state")){
                    QJsonValue stateValue=jsonObj.take("state");
                    if(stateValue.isDouble()){
                        n=stateValue.toInt();
                        qDebug()<<n;

                    }
                }

            }
        }
        QFile file2("../wisdom/wisdom/temp.txt");
        if(!file2.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text|QIODevice::Truncate)){
            QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
        }
        QTextStream temp(&file2);
        QJsonObject json;
        json.insert("name",QString(str1));
        json.insert("keyword",QString(str2));
        json.insert("identity",m);
        json.insert("state",0);

        QJsonDocument document;
        document.setObject(json);
        QByteArray byteArray=document.toJson(QJsonDocument::Compact);
        QString json_str(byteArray);
        temp<<json_str<<endl;
        qDebug()<<json_str;
        file2.close();
    }
    file.close();

    //存储数据
    //保存用户的登录状态及个性化设置
    //下次登陆自动update()用户的个人设置
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

    //m_flag p判断窗口状态
    closeDialog = new CloseDialog;
    if (closeDialog->m_flag == 3)//窗口不关闭
                {
                e->ignore();
            }
    else if (closeDialog->m_flag == 1)//隐藏到后台
            {
                //什么都不用做
            }
    closeDialog->exec();

}

/*********************
*函数功能：联系button
*********************/
void wisdom::rentPress(){
    rent=new rent43;
    rent->show();
}
void wisdom::loadStyleSheet(const QString &sheetName)
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

/*********************
*函数功能：联系button
*********************/
void wisdom::cancel51Press(){

    cancel51->hide();
    submit51->hide();
    label513->hide();
    label514->hide();
    line511->hide();
    line512->hide();
    change51->show();
    modify51->setEnabled(true);
}
/*********************
*函数功能：联系button
*********************/
void wisdom::admitPress13(){
    int i=0;
    QFile file2("../wisdom/wisdom/temp.txt");
    if(!file2.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file2.close();

    QFile file("../wisdom/wisdom/dayoff12.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtInput(&file);
    QString str="";

    QString str1;
    QString str2;
    QString str3;
    QString str4;


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
            }
        }
        QStandardItem *item1 = new QStandardItem(QString(str1));
        QStandardItem *item2 = new QStandardItem(QString(str2));
        QStandardItem *item3 = new QStandardItem(QString(str3));
        QStandardItem *item4 = new QStandardItem(QString("pass"));

        model->setItem(i,0,item1);
        model->setItem(i,1,item2);
        model->setItem(i,2,item3);
        model->setItem(i,3,item4);
        i++;

        QFile file2("../wisdom/wisdom/temp.txt");
        if(!file2.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text)){
            QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
        }
        QTextStream temp(&file2);
        QJsonObject json;
        json.insert("name",QString(str1));
        json.insert("time",QString(str2));
        json.insert("reason",QString(str3));
        json.insert("state",QString("pass"));
        QJsonDocument document;
        document.setObject(json);
        QByteArray byteArray=document.toJson(QJsonDocument::Compact);
        QString json_str(byteArray);
        temp<<json_str<<endl;
        file2.close();
    }
    file.close();

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
}
/*********************
*函数功能：联系button
*********************/
void wisdom::change51Press(){
    groupBox51->show();
    submit511->show();
    cancel511->show();
    change51->setEnabled(false);
    modify51->hide();
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
            radio511->setChecked(true);
        }
        else if(str1=="black"){
            radio512->setChecked(true);
        }
        else if(str1=="grey"){
            radio513->setChecked(true);
        }
        else if(str1=="navy"){
            radio514->setChecked(true);
        }

    }


}
/*********************
*函数功能：联系button
*********************/
void wisdom::cancel511Press(){



    groupBox51->hide();
    submit511->hide();
    cancel511->hide();
    change51->setEnabled(true);
    modify51->show();
}
/*********************
*函数功能：联系button
*********************/
void wisdom::submit511Press(){
    QFile file2("../wisdom/wisdom/color.txt");
    if(!file2.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    file2.close();

    QString s;
    if(radio511->isChecked()){
        s="blue";
    }
    else if(radio512->isChecked()){
        s="black";
    }
    else if(radio513->isChecked()){
        s="grey";
    }
    else if(radio514->isChecked()){
        s="navy";
    }
    qDebug()<<s;
    QJsonObject json;
    json.insert("color",QString(s));
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray=document.toJson(QJsonDocument::Compact);
    QString json_str(byteArray);
    qDebug()<<json_str;


    QFile file("../wisdom/wisdom/color.txt");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtOutPut(&file);
    txtOutPut<<json_str<<endl;
    file.close();

//=========================================================

    QString str1;
    QFile file1("../wisdom/wisdom/color.txt");
    if(!file1.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("失败"),tr("文件不存在"));
    }
    QTextStream txtInput(&file1);
    QString str="";
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
    QMessageBox::information(this,tr("更改成功"),tr("更改成功"));
}
/*********************
*函数功能：更新状态
*********************/
void wisdom::update(){
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


