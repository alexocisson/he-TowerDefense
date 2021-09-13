#ifndef ALLYDIALOG_H
#define ALLYDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QListWidget>
#include <QComboBox>
#include <QLabel>


class AllyDialog : public QDialog
{
    Q_OBJECT

public:
    AllyDialog(int, QVector<int>);
    void construct(int, QVector<int>);
private slots:
    void addSlot();
signals:
    void addSignal(int lvl, int place);
    void closed();
    void selectedSignal(int);
private:
    QVBoxLayout* vLayout;
    QHBoxLayout* hLayout;
    QHBoxLayout* hLayout0;
    QHBoxLayout* hLayout1;
    QPushButton* add;
    QPushButton* cancel;
    QRadioButton* radio1;
    QRadioButton* radio2;
    QRadioButton* radio3;
    QGroupBox *groupBox;
    QComboBox * comboBoxPlace;
    QLabel* label;
    QVector<int> listPlace;
};

#endif // ALLYDIALOG_H
