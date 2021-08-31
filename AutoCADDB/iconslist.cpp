#include "iconslist.h"
#include "ui_iconslist.h"
#include <QRegularExpression>
#include <QtWidgets>
IconsList::IconsList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IconsList)
{
    ui->setupUi(this);
    this->setWindowTitle("Symbols");
    pixmap=new QPixmap(170, 30);
    pixmap->fill(Qt::transparent);
    painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/Hauptsignal.svg"));
    painter->end();

    ui->label_21->setPixmap(*pixmap);


    pixmap=new QPixmap(170, 20);
    pixmap->fill(Qt::transparent);
    painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
    painter->end();

    ui->lbl_mehra->setPixmap(*pixmap);

    pixmap=new QPixmap(170, 20);
    pixmap->fill(Qt::transparent);
    painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
    painter->end();

    ui->lbl_shrim->setPixmap(*pixmap);

    pixmap=new QPixmap(170, 20);
    pixmap->fill(Qt::transparent);
    painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, 30, 13, QPixmap(":/icons/assets/smallSvgs/mehra.svg"));
    painter->end();

    ui->lbl_expanded->setPixmap(*pixmap);

    pixmap=new QPixmap(170, 20);
    pixmap->fill(Qt::transparent);
    painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
    painter->end();

    ui->lbl_stump->setPixmap(*pixmap);

    pixmap=new QPixmap(170, 20);
    pixmap->fill(Qt::transparent);
    painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
    painter->end();

    ui->lbl_vorsignal->setPixmap(*pixmap);

    pixmap=new QPixmap(170, 20);
    pixmap->fill(Qt::transparent);
    painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
    painter->end();

    ui->lbl_rightSignal->setPixmap(*pixmap);



}

IconsList::~IconsList()
{
    delete ui;
}

void IconsList::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void IconsList::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void IconsList::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->move(event->position().toPoint() - offset);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

//! [1]
void IconsList::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->position().toPoint()));
    if (!child)
        return;

    QPixmap pixmap = child->pixmap(Qt::ReturnByValue);

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->position().toPoint() - child->pos());
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);
//! [2]

//! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->position().toPoint() - child->pos());
//! [3]

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}




void IconsList::on_checkBox_clicked()
{
    qInfo() << "Jhala baba ";
     if (ui->sh1->isChecked() && ui->checkBox->isChecked()) {

            pixmap=new QPixmap(170, 30);
            pixmap->fill(Qt::transparent);
            painter=new QPainter(pixmap);
            painter->drawPixmap(0, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/Hauptsignal.svg"));
            painter->drawPixmap(13, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/haputArrow.svg"));
            painter->drawPixmap(-16, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/hauptBox.svg"));

             painter->end();

             ui->label_21->setPixmap(*pixmap);

    }
   else if (ui->checkBox->isChecked()) {
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);
        painter->drawPixmap(0, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/Hauptsignal.svg"));
         painter->drawPixmap(13, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/haputArrow.svg"));
         painter->end();

         ui->label_21->setPixmap(*pixmap);
       // ui->label_21->clear();
    } else  if(ui->sh1->isChecked()) {
        ui->label_21->clear();
      pixmap=new QPixmap(170, 30);
      pixmap->fill(Qt::transparent);
      painter=new QPainter(pixmap);

      painter->drawPixmap(0, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/Hauptsignal.svg"));
       painter->drawPixmap(-16, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/hauptBox.svg"));

       painter->end();

       ui->label_21->setPixmap(*pixmap);
  }
    else {
        ui->label_21->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);
        painter->drawPixmap(0, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/Hauptsignal.svg"));
        painter->end();

         ui->label_21->setPixmap(*pixmap);
    }

}


void IconsList::on_sh1_clicked()
{
    if (ui->sh1->isChecked() && ui->checkBox->isChecked()) {

            pixmap=new QPixmap(170, 30);
            pixmap->fill(Qt::transparent);
            painter=new QPainter(pixmap);
            painter->drawPixmap(0, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/Hauptsignal.svg"));
            painter->drawPixmap(13, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/haputArrow.svg"));
            painter->drawPixmap(-16, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/hauptBox.svg"));

             painter->end();

             ui->label_21->setPixmap(*pixmap);

    }
    else if(ui->sh1->isChecked()) {
          ui->label_21->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/Hauptsignal.svg"));
         painter->drawPixmap(-16, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/hauptBox.svg"));

         painter->end();

         ui->label_21->setPixmap(*pixmap);
    }
    else if (ui->checkBox->isChecked()) {
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);
        painter->drawPixmap(0, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/Hauptsignal.svg"));
         painter->drawPixmap(13, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/haputArrow.svg"));
         painter->end();

         ui->label_21->setPixmap(*pixmap);
       // ui->label_21->clear();
    }
    else {
        ui->label_21->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);
        painter->drawPixmap(0, 0, 50, 20, QPixmap(":/icons/assets/smallSvgs/Hauptsignal.svg"));
        painter->end();

         ui->label_21->setPixmap(*pixmap);
    }
}


void IconsList::on_sh1_mehra_clicked()
{
    if (ui->sh1_mehra->isChecked()) {
            pixmap=new QPixmap(170, 30);
            pixmap->fill(Qt::transparent);
            painter=new QPainter(pixmap);
            painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
            painter->drawPixmap(-10, 0, 50, 12, QPixmap(":/icons/assets/smallSvgs/mehraBox.svg"));
            painter->end();
            ui->lbl_mehra->setPixmap(*pixmap);
        }
        else {
            ui->lbl_mehra->clear();
            pixmap=new QPixmap(170, 30);
            pixmap->fill(Qt::transparent);
            painter=new QPainter(pixmap);
            painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
            painter->end();
            ui->lbl_mehra->setPixmap(*pixmap);
        }
}


//probability 6 times

void IconsList::on_chk_ersatz_clicked()
{
    if (ui->chk_ersatz->isChecked() && ui->chk_shrimsh1->isChecked() && ui->chk_gegen->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(10, 0, 50,  13, QPixmap(":/icons/assets/smallSvgs/schrimArrow.svg"));
        painter->drawPixmap(-10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/shrimBox.svg"));
        painter->drawPixmap(-3, 0, 20, 13, QPixmap(":/icons/assets/smallSvgs/shrimGegen.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else if ((ui->chk_ersatz->isChecked() && ui->chk_shrimsh1->isChecked() ) || (ui->chk_shrimsh1->isChecked() && ui->chk_ersatz->isChecked())){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(10, 0, 50,  13, QPixmap(":/icons/assets/smallSvgs/schrimArrow.svg"));
        painter->drawPixmap(-10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/shrimBox.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);

    }
    else if (ui->chk_ersatz->isChecked() && ui->chk_gegen->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(10, 0, 50,  13, QPixmap(":/icons/assets/smallSvgs/schrimArrow.svg"));
        painter->drawPixmap(-3, 0, 20, 13, QPixmap(":/icons/assets/smallSvgs/shrimGegen.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else if (ui->chk_ersatz->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(10, 0, 50,  13, QPixmap(":/icons/assets/smallSvgs/schrimArrow.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else if (ui->chk_gegen->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(-3, 0, 20, 13, QPixmap(":/icons/assets/smallSvgs/shrimGegen.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else if (ui->chk_shrimsh1->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(-10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/shrimBox.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else{
        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        ui->lbl_shrim->setPixmap(*pixmap);
    }

}


void IconsList::on_chk_shrimsh1_clicked()
{
    if (ui->chk_ersatz->isChecked() && ui->chk_shrimsh1->isChecked() && ui->chk_gegen->isChecked()){
        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(10, 0, 50,  13, QPixmap(":/icons/assets/smallSvgs/schrimArrow.svg"));
        painter->drawPixmap(-10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/shrimBox.svg"));
        painter->drawPixmap(-3, 0, 20, 13, QPixmap(":/icons/assets/smallSvgs/shrimGegen.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else if ((ui->chk_shrimsh1->isChecked() && ui->chk_ersatz->isChecked()) || (ui->chk_ersatz->isChecked() && ui->chk_shrimsh1->isChecked())){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(10, 0, 50,  13, QPixmap(":/icons/assets/smallSvgs/schrimArrow.svg"));
        painter->drawPixmap(-10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/shrimBox.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else if (ui->chk_shrimsh1->isChecked() && ui->chk_gegen->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(-10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/shrimBox.svg"));
        painter->drawPixmap(-3, 0, 20, 13, QPixmap(":/icons/assets/smallSvgs/shrimGegen.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else if (ui->chk_shrimsh1->isChecked()){
        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(-10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/shrimBox.svg"));

    }
    else if (ui->chk_ersatz->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(10, 0, 50,  13, QPixmap(":/icons/assets/smallSvgs/schrimArrow.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else if (ui->chk_gegen->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(-3, 0, 20, 13, QPixmap(":/icons/assets/smallSvgs/shrimGegen.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }

    else{
        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        ui->lbl_shrim->setPixmap(*pixmap);
    }
}


void IconsList::on_chk_gegen_clicked()
{
    if (ui->chk_ersatz->isChecked() && ui->chk_shrimsh1->isChecked() && ui->chk_gegen->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(10, 0, 50,  13, QPixmap(":/icons/assets/smallSvgs/schrimArrow.svg"));
        painter->drawPixmap(-10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/shrimBox.svg"));
        painter->drawPixmap(-3, 0, 20, 13, QPixmap(":/icons/assets/smallSvgs/shrimGegen.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else if (ui->chk_gegen->isChecked() && ui->chk_shrimsh1->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(-10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/shrimBox.svg"));
        painter->drawPixmap(-3, 0, 20, 13, QPixmap(":/icons/assets/smallSvgs/shrimGegen.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else if (ui->chk_ersatz->isChecked() && ui->chk_gegen->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/schrimArrow.svg"));
        painter->drawPixmap(-10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/shrimBox.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else if (ui->chk_gegen->isChecked()){
        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(-10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/shrimBox.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else if (ui->chk_ersatz->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(10, 0, 50,  13, QPixmap(":/icons/assets/smallSvgs/schrimArrow.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }

    else if (ui->chk_shrimsh1->isChecked()){

        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        painter->drawPixmap(-10, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/shrimBox.svg"));

        painter->end();
        ui->lbl_shrim->setPixmap(*pixmap);
    }
    else{
        ui->lbl_shrim->clear();
        pixmap=new QPixmap(170, 30);
        pixmap->fill(Qt::transparent);
        painter=new QPainter(pixmap);

        painter->drawPixmap(0, 0, 50, 13, QPixmap(":/icons/assets/smallSvgs/Mehrabschnittsignal.svg"));
        ui->lbl_shrim->setPixmap(*pixmap);
    }
}

//Expanded Signal

void IconsList::on_chc_sh1exp_clicked()
{
    //schnittArrow
    //expandedSignal
}


void IconsList::on_chk_exp_clicked()
{
    //schnittArrow
    //expandedSignal
}


// T arrow

void IconsList::on_chk_T_clicked()
{
    //stumpArrow
    //stumpT
    //sh1
}


void IconsList::on_chk_stumpA_clicked()
{
    //stumpArrow
    //stumpT
    //sh1
}


void IconsList::on_chk_sh1stump_clicked()
{
    //stumpArrow
    //stumpT
    //sh1
}

//vorsignal
void IconsList::on_chk_backArrow_clicked()
{
    //vorarrow
    //ersatz
}


void IconsList::on_chk_backerstaz_clicked()
{
    //vorarrow
    //ersatz
}


//front arrow

void IconsList::on_chk_frontarrow_clicked()
{
    //rightarrow
    //rightarrowersatz
}


void IconsList::on_chk_ersatzRght_clicked()
{
    //rightarrow
    //rightarrowersatz
}

