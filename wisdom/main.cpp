#include"wisdom.h"
#include"log00.h"
#include<QApplication>
#include<QSplashScreen>

int main(int argc,char* argv[]){
    QApplication a(argc,argv);

    a.setWindowIcon(QIcon(":/new/prefix1/img/5.png"));
    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":/new/prefix1/img/10.png"));
    splash->show();
    Qt::Alignment topRight=Qt::AlignTop|Qt::AlignRight;
    splash->showMessage(QObject::tr("Setting up the main Window..."),topRight,Qt::red);
    for(int i=0;i<2000;i++){
        splash->repaint();
    }
    splash->showMessage(QObject::tr("Loading the modules..."),topRight,Qt::yellow);
    for(int i=0;i<2000;i++){
        splash->repaint();
    }

    delete splash;

    log00* l=new log00;
    l->show();

    return a.exec();
}
