#ifndef TRACKS_H
#define TRACKS_H

#include <QWidget>
#include <QGraphicsView>

class Tracks : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Tracks(QWidget *parent = nullptr);
    enum Object {
        gleiskanten,
        gleisknoten,
        entwurfselement_HO,
        entwurfselement_KM,
        entwurfselement_UH,
        entwurfselement_LA
    };

    Object getCurrentObject() const;
    void setCurrentObject(Object newCurrentObject);

signals:

private:
    void addGleiskanten();
    Object currentObject;

};

#endif // TRACKS_H
