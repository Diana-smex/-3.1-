#pragma once

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include "storage.h"  

class QtWidgetsApplication : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication(QWidget* parent = nullptr);
    ~QtWidgetsApplication();

protected:
   
    void paintEvent(QPaintEvent* event) override;      // Для отрисовки кругов
    void mousePressEvent(QMouseEvent* event) override; // Для кликов мыши
    void keyPressEvent(QKeyEvent* event) override;     // Для клавиши Delete
    void resizeEvent(QResizeEvent* event) override;    // Для изменения размера

private:
    Storage m_storage;  // наш контейнер для хранения кругов
};