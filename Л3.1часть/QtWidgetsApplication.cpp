#include "QtWidgetsApplication.h"
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>

QtWidgetsApplication::QtWidgetsApplication(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("Lab 3 - Circles");
    resize(800, 600);
    setMinimumSize(400, 300);
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
}

QtWidgetsApplication::~QtWidgetsApplication()
{
}

void QtWidgetsApplication::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (int i = 0; i < m_storage.getCount(); ++i) {
        m_storage.getCircle(i).draw(painter);
    }
}

void QtWidgetsApplication::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        QPoint clickPos = event->pos();
        bool ctrlPressed = event->modifiers() & Qt::ControlModifier;

        bool circleClicked = false;

        for (int i = m_storage.getCount() - 1; i >= 0; --i) {
            if (m_storage.getCircle(i).contains(clickPos)) {
                if (!ctrlPressed) {
                    for (int j = 0; j < m_storage.getCount(); ++j) {
                        m_storage.getCircle(j).setSelected(false);
                    }
                }
                m_storage.getCircle(i).setSelected(!m_storage.getCircle(i).isSelected());
                circleClicked = true;
                break;
            }
        }

        if (!circleClicked && !ctrlPressed) {
            for (int i = 0; i < m_storage.getCount(); ++i) {
                m_storage.getCircle(i).setSelected(false);
            }

            CCircle newCircle(clickPos);
            m_storage.addCircle(newCircle);
        }

        update();
    }
}

void QtWidgetsApplication::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Delete) {
        for (int i = m_storage.getCount() - 1; i >= 0; --i) {
            if (m_storage.getCircle(i).isSelected()) {
                m_storage.removeCircle(i);
            }
        }
        update();
    }
}

void QtWidgetsApplication::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    update();
}