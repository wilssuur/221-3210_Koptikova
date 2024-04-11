#include "cridentialwidget.h"
#include "ui_cridentialwidget.h"

CridentialWidget::CridentialWidget(const QString &site,
                                   const int id,
                                   QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CridentialWidget)
    , m_id(id)
{
    ui->setupUi(this);
    ui->Site->setText(site);
}

CridentialWidget::~CridentialWidget()
{
    delete ui;
}

void CridentialWidget::on_btnLoginCopy_clicked()
{
    qDebug() << "*** presseed login" << m_id;
    emit decryptLogin(m_id);
}


void CridentialWidget::on_btnPassCopy_clicked()
{
    qDebug() << "*** presseed pass" << m_id;
    emit decryptPassword(m_id);
}
