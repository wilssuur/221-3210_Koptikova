#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QJsonArray>
#include <QMainWindow>
#include <openssl/evp.h>

class Cridential {
public:
    QString hostname;
    QString login;
    QString password;

};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool readJSON(QByteArray key_hex);
    QByteArray showPinDialog();
    bool loginClicked;
    bool passwordClicked;

public slots:
    void Search(const QString &fragment);
    int decryptFile(const QByteArray &encryptedBytes, const QByteArray &key_hex, QByteArray &decryptedBytes);

private slots:
    void decryptLogin(int id);
    void decryptPassword(int id);
    void on_edtPin_returnPressed();

private:
    Ui::MainWindow *ui;
    QJsonArray m_jsonarray;
    bool m_isStartup = true;
    int m_current_id = -1;
    QByteArray decrypted_creds;
};

#endif // MAINWINDOW_H
