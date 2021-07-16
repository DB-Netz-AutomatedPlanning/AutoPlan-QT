#ifndef CALCBUTTON_H
#define CALCBUTTON_H

#include <QToolButton>

class CalcButton : public QToolButton
{
    Q_OBJECT

public:
    explicit CalcButton(const QString &text, QWidget *parent = nullptr);

    QSize sizeHint() const override;
};
//! [0]

#endif
