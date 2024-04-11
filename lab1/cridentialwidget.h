// CridentialWidget.h
#ifndef CRIDENTIALWIDGET_H
#define CRIDENTIALWIDGET_H

#include <QWidget>

namespace Ui {
class CridentialWidget;
}

class CridentialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CridentialWidget(const QString& site, const int id, QWidget *parent = nullptr);
    ~CridentialWidget();

private slots:
    void on_btnLoginCopy_clicked();
    void on_btnPassCopy_clicked();

signals:
    void decryptPassword(int id);
    void decryptLogin(int id);
private:
    Ui::CridentialWidget *ui;
    int m_id = -1;
};

#endif // CRIDENTIALWIDGET_H
