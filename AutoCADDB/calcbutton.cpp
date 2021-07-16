#include "calcbutton.h"

CalcButton::CalcButton(const QString &text, QWidget *parent)
                       : QToolButton(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setText(text);
}
//! [0]

//! [1]
QSize CalcButton::sizeHint() const
//! [1] //! [2]
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 20;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
