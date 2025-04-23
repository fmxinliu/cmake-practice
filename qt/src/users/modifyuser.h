#ifndef MODIFYUSER_H
#define MODIFYUSER_H

#include <QDialog>

namespace Ui {
class ModifyUser;
}

class ModifyUser : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyUser(QWidget *parent = Q_NULLPTR);
    ~ModifyUser();

private Q_SLOTS:
    void onModifyUser();
    void onEdit();

private:
    Ui::ModifyUser *ui;
};

#endif // MODIFYUSER_H
