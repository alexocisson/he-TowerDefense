#include "allydialog.h"

AllyDialog::AllyDialog(int money, QVector<int> list)
{
    //instanciation
    vLayout = new QVBoxLayout();
    hLayout = new QHBoxLayout();
    hLayout0 = new QHBoxLayout();
    hLayout1 = new QHBoxLayout();
    add = new QPushButton();
    cancel = new QPushButton();
    comboBoxPlace = new QComboBox();
    label = new QLabel();

    //le label
    label->setText(QString("Place:"));

    //les bouttons
    add->setText("Add");
    cancel->setText("Cancel");

    //choix type allié
    groupBox = new QGroupBox("What kind of ally", this);
    radio1 = new QRadioButton("lvl 1 (100$)");
    radio2 = new QRadioButton("lvl 2 (200$)");
    radio3 = new QRadioButton("lvl 3 (400$)");


    construct(money, list);

    radio1->setChecked(true);
    hLayout->addWidget(radio1);
    hLayout->addWidget(radio2);
    hLayout->addWidget(radio3);
    groupBox->setLayout(hLayout);

    //layout place
    hLayout0->addWidget(label);
    hLayout0->addWidget(comboBoxPlace);

    //layout bouttons
    hLayout1->addWidget(add);
    hLayout1->addWidget(cancel);

    //construction main layout
    vLayout->addWidget(groupBox);
    vLayout->addLayout(hLayout0);
    vLayout->addLayout(hLayout1);
    this->setLayout(vLayout);

    //connctions wesh
    connect(cancel, &QPushButton::clicked, this, &QDialog::close);
    connect(cancel, &QPushButton::clicked, this, &AllyDialog::closed);
    connect(add, &QPushButton::clicked, this, &AllyDialog::addSlot);

    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint | Qt::WindowStaysOnTopHint);
    //setWindowIcon(QIcon("./../graphics/boydown0.png"));
    setWindowIcon(QIcon(":/graphics/graphics/boydown0.png"));
    setWindowTitle("We gonna help you");
}

void AllyDialog::addSlot()
{
    int lvl;
    if(radio1->isChecked())
        lvl=1;
    if(radio2->isChecked())
        lvl=2;
    if(radio3->isChecked())
        lvl=3;
    int place=comboBoxPlace->itemData(comboBoxPlace->currentIndex()).toInt();
    emit addSignal(lvl, place);
    emit closed();
    close();
}

void AllyDialog::construct(int money, QVector<int> list)
{
    if(money>=200)
        radio2->setEnabled(true);
    else
        radio2->setEnabled(false);
    if(money>=400)
        radio3->setEnabled(true);
    else
        radio3->setEnabled(false);

    comboBoxPlace->clear();
    radio1->setChecked(true);

    listPlace=list;
    foreach (int var, listPlace) {
        comboBoxPlace->addItem(QString("%1").arg(var), var);
    }
}
