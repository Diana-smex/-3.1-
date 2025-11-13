#include "circle.h"
#include <QPainter>

CCircle::CCircle(const QPoint& center, int radius)
    : m_center(center), m_radius(radius), m_selected(false) {
}

void CCircle::draw(QPainter& painter) const {
    if (m_selected) {
        painter.setPen(QPen(Qt::red, 2));
        painter.setBrush(QBrush(Qt::lightGray));
    }
    else {
        painter.setPen(QPen(Qt::blue, 2));
        painter.setBrush(QBrush(Qt::white));
    }
    painter.drawEllipse(m_center, m_radius, m_radius);
}

bool CCircle::contains(const QPoint& point) const {
    int dx = point.x() - m_center.x();
    int dy = point.y() - m_center.y();
    return (dx * dx + dy * dy) <= (m_radius * m_radius);
}

void CCircle::setSelected(bool selected) {
    m_selected = selected;
}

bool CCircle::isSelected() const {
    return m_selected;
}