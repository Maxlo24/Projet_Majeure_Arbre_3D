#ifndef BUILDWINDOW_HPP
#define BUILDWINDOW_HPP

#include <QWidget>
#include "../Tree/tree.hpp"
#include "../3D/obj_generator.hpp"

namespace Ui {
class BuildWindow;
}

class BuildWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BuildWindow(QWidget *parent = nullptr);
    ~BuildWindow();

    void set_tree(tree);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::BuildWindow *ui;
    tree render_tree;
};

#endif // BUILDWINDOW_HPP
