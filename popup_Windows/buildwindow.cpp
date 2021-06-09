#include "buildwindow.hpp"
#include "ui_buildwindow.h"
#include <stdlib.h>

BuildWindow::BuildWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuildWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Build");
    ui->stackedWidget->setCurrentIndex(0);
}

BuildWindow::~BuildWindow()
{
    delete ui;
}

void BuildWindow::set_tree(tree tree)
{
    this->render_tree = tree;
    ui->tree_name->setText(QString::fromStdString(tree.Name()));
    ui->node_number->setText(QString::number(tree.getData().size()));
}

void BuildWindow::on_pushButton_2_clicked()
{
    this->close();
}

void BuildWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    std::cout<<"Building ..."<<std::endl;
    obj_generator mesh = obj_generator(render_tree);
    mesh.generate(ui->progressBar);
    std::cout<<"Done !"<<std::endl;
    ui->stackedWidget->setCurrentIndex(0);
    this->close();
}
