
#include "ui_mainwindow.h"

#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , render(new render_area)
{
    ui->setupUi(this);

    this->setWindowTitle("Projet Path Finding");

    ui->main_Layout->addWidget(render);

    //Connection with signals

    //slider brush size
    connect(ui->brush_Size_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_brush_size(int)));
    //slider tree size
    connect(ui->tree_Size_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_tree_size(int)));
    //slider segment size
    connect(ui->segment_Size_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_segment_size(int)));
    //slider angle
    connect(ui->angle_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_angle(int)));


    //button reset
    connect(ui->resetButton,SIGNAL(clicked()), this->render, SLOT(reset_grid()));
    //button search
    connect(ui->searchButton,SIGNAL(clicked()), this->render, SLOT(launch_algo()));
    //algo select
    connect(ui->Algo_select,SIGNAL(activated(int)), this->render, SLOT(update_algo_select(int)));
    //Slider speed
    connect(ui->speedSlider,SIGNAL(valueChanged(int)), this->render, SLOT(update_algo_speed(int)));
}


MainWindow::~MainWindow()
{
    delete ui;
}
