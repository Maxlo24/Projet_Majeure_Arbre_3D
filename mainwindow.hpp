#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

#include "render_area.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class render_area;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    render_area *render;

private slots:
    void get_groupBox_select();

};
#endif // MAINWINDOW_H
