#ifndef WISDOM_H
#define WISDOM_H
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
#include<QCheckBox>
#include<QApplication>
#include<QCloseEvent>
#include<QPalette>
#include<QPixmap>
#include<QSystemTrayIcon>

#include"rent43.h"
#include"add11.h"
#include"delete11.h"
#include"dayoff12.h"
#include"dayon12.h"
#include"ownerlog21.h"
#include"ownermodify22.h"
#include"ownerfind.h"
#include"caradd31.h"
#include"cardelete31.h"
#include"carfind31.h"
#include"carapply32.h"
#include"maintain41.h"
#include"register.h"
#include"closedialog.h"

class register1;
class add11;
class delete11;
class dayoff12;
class dayon12;
class ownerLog21;
class ownerModify22;
class ownerFind;
class carAdd31;
class carDelete31;
class carFind31;
class carApply32;
class maintain41;
class CloseDialog;
class rent43;

class wisdom:public QDialog{
    Q_OBJECT
public:
    explicit wisdom(QWidget*parent=0);

protected:
    void closeEvent(QCloseEvent *e);

private:
    QToolBox* toolbox;
    QTabWidget *tabWidget1;
    QTabWidget *tabWidget2;
    QTabWidget *tabWidget3;
    QTabWidget *tabWidget4;
    QTabWidget *tabWidget5;
    QPushButton *addBt11;
    QPushButton *button11;
    QPushButton *button12;
    QPushButton *button13;
    QPushButton *button14;
    QPushButton *deleteBt11;
    QTableView *tableView13;
    QStandardItemModel* model;
    QPushButton *refuseBt13;
    QPushButton* putInBt13;
    QLineEdit*line441;

    QPushButton *button21;
    QPushButton *button22;
    QPushButton *button23;
    QPushButton *log21;
    QPushButton *modifyBt22;
    QPushButton *findBt23;
    QPushButton *button31;
    QPushButton *button32;
    QPushButton *button33;
    QPushButton *addBt31;
    QPushButton *deleteBt31;
    QPushButton *findBt31;
    QPushButton *applyBt32;
    QPushButton *rentBt33;
    QPushButton *button41;
    QPushButton *button42;
    QPushButton *button43;
    QPushButton *button44;
    QLabel *label41;
    QLineEdit *edit41;
    QPushButton *maintainBt41;
    QLabel *label42;
    QPushButton* backBt42;
    QLabel *label43;
    QPushButton* submitBt43;
    QPushButton *button51;
    QPushButton *button52;
    QLabel *label51;
    QPushButton* initialise;
    QLabel *label44;
    QPushButton* dayOffBt;
    QPushButton* dayOnBt;
    QPushButton* admitBt13;
    QLineEdit*Line14;
    QPushButton* logBt14;
    QTimer *timer;
    QGridLayout *Layout;
    QLabel*label33;
    QLabel*label333;
    QGroupBox*groupBox43;
    QRadioButton*radio431;
    QRadioButton*radio432;
    QRadioButton*radio433;
    QRadioButton*radio434;
    QRadioButton*radio435;
    QTextEdit*text43;
    QPushButton*track42;
    QGroupBox*groupBox42;
    QRadioButton*radio421;
    QRadioButton*radio422;
    QRadioButton*radio423;
    QRadioButton*radio424;
    QRadioButton*radio425;
    QProgressBar*progressBar42;
    QLabel*label331;
    QLabel*label332;
    QLabel*label330;
    QPushButton*find422;
    QLineEdit* line42;
    QLabel*label420;
    QPushButton*report44;
    QLineEdit*line44;
    QLabel*label440;
    QPushButton*find44;
    QLineEdit*line442;
    QLineEdit*line443;
    QLabel*label443;
    QLabel*label511;
    QLabel*label512;
    QLabel*label513;
    QLabel*label514;
    QLabel*label515;
    QLabel*label516;
    QPushButton*modify51;
    QPushButton*cancel51;
    QPushButton*submit51;
    QLineEdit*line511;
    QLineEdit*line512;
    QLabel*label510;
    QPushButton*change51;
    QGroupBox*groupBox51;
    QRadioButton*radio511;
    QRadioButton*radio512;
    QRadioButton*radio513;
    QRadioButton*radio514;
    QPushButton*submit511;
    QPushButton*cancel511;



    int max=100;


    QWidget* widget1;
    QWidget* widget11;
    QWidget* widget12;
    QWidget* widget13;
    QWidget* widget14;
    QWidget* widget2;
    QWidget* widget21;
    QWidget* widget22;
    QWidget* widget23;
    QWidget* widget3;
    QWidget* widget31;
    QWidget* widget32;
    QWidget* widget33;
    QWidget* widget4;
    QWidget* widget41;
    QWidget* widget42;
    QWidget* widget43;
    QWidget* widget44;
    QWidget* widget5;
    QWidget* widget51;
    QWidget* widget52;
    add11* add;
    delete11* delete1;
    dayoff12* dayoff1;
    dayon12* dayon1;
    ownerLog21*own;
    ownerModify22* modify;
    ownerFind*ownerF;
    carAdd31*carAdd;
    carDelete31*carDelete;
    carFind31*carFind;
    carApply32*carApply;
    maintain41*maintain;
    CloseDialog*closeDialog;
    rent43*rent;
    QSystemTrayIcon*mSysTrayIcon;







public slots:
    void timerUpdate();
    void OnButtonClicked1();
    void OnButtonClicked2();
    void OnButtonClicked3();
    void OnButtonClicked4();
    void OnButtonClicked5();
    void tool_tab();
    void add11Press();
    void delete11Press();

    void dayOffPress();
    void dayOnPress();
    void logPress();
    void ownerLogPress();
    void ownerModifyPress();
    void ownerFindPress();
    void carAddPress();
    void carDeletePress();
    void carApplyPress();
    void maintainPress();
    void progressbar42();
    void putInPress13();
    void carleft();
    void carleft0();
    void initialise1();
    void find42();
    void back42();
    void submit43();
    void find440();
    void report440();
    void identity5();
    void admitPress13();
    void keywordChange();
    void submitPress51();
    void rentPress();
    void loadStyleSheet(const QString &sheetName);
    void cancel51Press();
    void change51Press();
    void submit511Press();
    void cancel511Press();
    void update();



};


#endif // WISDOM_H
