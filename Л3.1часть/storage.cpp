#include "storage.h"

Storage::Storage() {
}

void Storage::addCircle(const CCircle& circle) {
    m_circles.append(circle);
}

void Storage::removeCircle(int index) {
    if (index >= 0 && index < m_circles.size()) {
        m_circles.removeAt(index);
    }
}

CCircle& Storage::getCircle(int index) {
    return m_circles[index];
}

int Storage::getCount() const {
    return m_circles.size();
}

void Storage::clear() {
    m_circles.clear();
}

QVector<CCircle>& Storage::getCircles() {
    return m_circles;
}