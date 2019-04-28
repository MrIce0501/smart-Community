#ifndef CLOSEDIALOG_H
#define CLOSEDIALOG_H

#include"wisdom.h"

class CloseDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CloseDialog();

public:
    QRadioButton *hide;
    QRadioButton *holdOn;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QCheckBox *closeCbox;
    int m_flag;                         //标志，记录隐藏窗口还是关闭 1隐藏到后台，2立即关闭，3不改变，0错误

protected:
    void  closeEvent(QCloseEvent *e);//窗口关闭时调用
public slots:
    void ok_PushButton_Clicked();
    void cancel_PushButton_Clicked();
    void loadStyleSheet(const QString &sheetName);
    void update();
};

#endif // CLOSEDIALOG_H
