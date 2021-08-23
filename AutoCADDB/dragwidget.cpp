/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include "dragwidget.h"
#include <QVBoxLayout>
//! [0]
DragWidget::DragWidget(QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(50, 50);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);


    QLabel *boatIcon = new QLabel(this);
   // boatIcon->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/Ersatzsignal.svg"));
    boatIcon->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/Ersatzsignal.svg").scaled(110,25));
    boatIcon->move(10, 10);
    boatIcon->show();
    boatIcon->setAttribute(Qt::WA_DeleteOnClose);


    QLabel *Haltetafel = new QLabel(this);
    Haltetafel->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/Haltetafel.svg").scaled(110,25));
    Haltetafel->move(10, 50);
    Haltetafel->show();
    Haltetafel->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *Hauptsignal = new QLabel(this);
    Hauptsignal->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/Hauptsignal.svg").scaled(110,25));
    Hauptsignal->move(10, 100);
    Hauptsignal->show();
    Hauptsignal->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *HauptsignalAus = new QLabel(this);
    HauptsignalAus->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/HauptsignalAus.svg").scaled(110,25));
    HauptsignalAus->move(10, 150);
    HauptsignalAus->show();
    HauptsignalAus->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *HauptsignalEin = new QLabel(this);
    HauptsignalEin->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/HauptsignalEin.svg").scaled(110,33));
    HauptsignalEin->move(10, 200);
    HauptsignalEin->show();
    HauptsignalEin->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *Hauptsignalschirm = new QLabel(this);
    Hauptsignalschirm->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/Hauptsignalschirm.svg").scaled(110,30));
    Hauptsignalschirm->move(10, 250);
    Hauptsignalschirm->show();
    Hauptsignalschirm->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *KsMehrabschnitts = new QLabel(this);
    KsMehrabschnitts->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/KsMehrabschnitts.svg").scaled(110,30));
    KsMehrabschnitts->move(10, 300);
    KsMehrabschnitts->show();
    KsMehrabschnitts->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *Mehrabschnittssignal = new QLabel(this);
    Mehrabschnittssignal->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/Mehrabschnittssignal.svg").scaled(110,25));
    Mehrabschnittssignal->move(10, 350);
    Mehrabschnittssignal->show();
    Mehrabschnittssignal->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *Radsensor = new QLabel(this);
    Radsensor->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/Radsensor.svg").scaled(40,10));
    Radsensor->move(10, 400);
    Radsensor->show();
    Radsensor->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *Rangierhalttafel = new QLabel(this);
    Rangierhalttafel->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/Rangierhalttafel.svg").scaled(110,25));
    Rangierhalttafel->move(10, 450);
    Rangierhalttafel->show();
    Rangierhalttafel->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *Schutzhalt = new QLabel(this);
    Schutzhalt->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/Schutzhalt.svg").scaled(110,30));
    Schutzhalt->move(10, 500);
    Schutzhalt->show();
    Schutzhalt->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *StumpfgleisFruhhaltanzeiger = new QLabel(this);
    StumpfgleisFruhhaltanzeiger->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/StumpfgleisFruhhaltanzeiger.svg").scaled(115,30));
    StumpfgleisFruhhaltanzeiger->move(10, 550);
    StumpfgleisFruhhaltanzeiger->show();
    StumpfgleisFruhhaltanzeiger->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *Vorsichtsignal = new QLabel(this);
    Vorsichtsignal->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/Vorsichtsignal.svg").scaled(110,30));
    Vorsichtsignal->move(10, 600);
    Vorsichtsignal->show();
    Vorsichtsignal->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *vorsignal = new QLabel(this);
    vorsignal->setPixmap(QPixmap(":/icons/assets/fifteenSvgs/vorsignal.svg").scaled(110,25));
    vorsignal->move(10, 650);
    vorsignal->show();
    vorsignal->setAttribute(Qt::WA_DeleteOnClose);



}
//! [0]

void DragWidget::dragEnterEvent(QDragEnterEvent *event)
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

void DragWidget::dragMoveEvent(QDragMoveEvent *event)
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

void DragWidget::dropEvent(QDropEvent *event)
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
void DragWidget::mousePressEvent(QMouseEvent *event)
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
