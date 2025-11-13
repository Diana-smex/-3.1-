#ifndef CIRCLE_H
#define CIRCLE_H

#include <QPoint>

class CCircle {
public:
    CCircle(const QPoint& center, int radius = 20);

    void draw(QPainter& painter) const;
    bool contains(const QPoint& point) const;

    void setSelected(bool selected);
    bool isSelected() const;

private:
    QPoint m_center;
    int m_radius;
    bool m_selected;
};

#endif // CIRCLE_H