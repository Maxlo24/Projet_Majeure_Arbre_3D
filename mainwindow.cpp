
#include "ui_mainwindow.h"

#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    this->setWindowTitle("Projet Tree Generator");


    render = new render_area(ui->ruleDescription);
    ui->main_Layout->addWidget(render);
    //render->giveDescriptionText(ui->ruleDescription);



    //Connection with signals

    //slider brush size
    connect(ui->brush_Size_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_brush_size(int)));
    //slider tree size
    connect(ui->tree_Size_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_tree_size(int)));
    //slider segment size
    connect(ui->segment_Size_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_segment_size(int)));
    //slider alpha
    connect(ui->alpha_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_alpha(int)));
    connect(ui->alpha_random,SIGNAL(valueChanged(int)),this->render ,SLOT(update_alpha_random(int)));
    //slider beta
    connect(ui->beta_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_beta(int)));
    connect(ui->beta_random,SIGNAL(valueChanged(int)),this->render ,SLOT(update_beta_random(int)));
    //slider gamma
    connect(ui->gamma_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_gamma(int)));
    connect(ui->gamma_random,SIGNAL(valueChanged(int)),this->render ,SLOT(update_gamma_random(int)));
    //slider ratio
    connect(ui->ratio_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_ratio(int)));
    //Rotation
    connect(ui->rotation_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_rotation_y(int)));
    //Rotation
    connect(ui->vertical_rotation_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_rotation_x(int)));




    //button reset
    connect(ui->resetButton,SIGNAL(clicked()), this->render, SLOT(reset_grid()));
    //button search
    connect(ui->searchButton,SIGNAL(clicked()), this->render, SLOT(launch_algo()));
    //button generate
    connect(ui->generateButton,SIGNAL(clicked()), this->render, SLOT(generate_obj()));
    //algo select
    connect(ui->Algo_select,SIGNAL(activated(int)), this->render, SLOT(update_algo_select(int)));
    //Slider speed
    connect(ui->speedSlider,SIGNAL(valueChanged(int)), this->render, SLOT(update_algo_speed(int)));
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_addLetter_clicked()
{
    QString letter = ui->addLettert->toPlainText();
    const char *c= letter.toStdString().c_str();
    render->addLetter(*c);
}

void MainWindow::on_addRule_clicked()
{
    QString letter = ui->letter_rulet->toPlainText();
    const char *c= letter.toStdString().c_str();
    QString rule = ui->rulet->toPlainText();
    render->addRule(*c,rule.toStdString());
}

void MainWindow::on_changeAxiom_clicked()
{
    QString axiom = ui->axiom->toPlainText();
    render->changeAxiom(axiom.toStdString());
}

void MainWindow::on_resetRule_clicked()
{
    render->resetRule();
}
