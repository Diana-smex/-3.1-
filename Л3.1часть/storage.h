#ifndef STORAGE_H
#define STORAGE_H

#include <QVector>
#include "circle.h"

class Storage {
public:
    Storage();

    void addCircle(const CCircle& circle);
    void removeCircle(int index);
    CCircle& getCircle(int index);
    int getCount() const;
    void clear();

    QVector<CCircle>& getCircles();

private:
    QVector<CCircle> m_circles;
};

#endif // STORAGE_H