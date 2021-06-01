
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
    //slider grid size
    connect(ui->gridSideSlider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_grid_size(int)));
    //button reset
    connect(ui->resetButton,SIGNAL(clicked()), this->render, SLOT(reset_grid()));
    //button search
    connect(ui->searchButton,SIGNAL(clicked()), this->render, SLOT(launch_algo()));
    //algo select
    connect(ui->Algo_select,SIGNAL(activated(int)), this->render, SLOT(update_algo_select(int)));
    //Slider speed
    connect(ui->speedSlider,SIGNAL(valueChanged(int)), this->render, SLOT(update_algo_speed(int)));
    //button Generate Maze
    connect(ui->mazeButton,SIGNAL(clicked()), this->render, SLOT(generateMaze()));

    //Set obstacle readioButton
    ui->ObstacleradioButton->setChecked(true);

    //brush selection
    connect(ui->ObstacleradioButton,SIGNAL(clicked()), this, SLOT(get_groupBox_select()));
    connect(ui->StartradioButton,SIGNAL(clicked()), this, SLOT(get_groupBox_select()));
    connect(ui->EndradioButton,SIGNAL(clicked()), this, SLOT(get_groupBox_select()));

    this->render->give_label(ui->cycle_nbr_txt);
}


MainWindow::~MainWindow()
{
    delete ui;
}

//call update_brush_type function
void MainWindow::get_groupBox_select(){
    if (ui->ObstacleradioButton->isChecked()){
        this->render->update_brush_type(states::obstacle);
    }
    if (ui->StartradioButton->isChecked()){
        this->render->update_brush_type(states::start);
    }
    if (ui->EndradioButton->isChecked()){
        this->render->update_brush_type(states::end);
    }
}
