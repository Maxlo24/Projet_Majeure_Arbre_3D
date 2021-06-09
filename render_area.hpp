#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP

#include "ui_mainwindow.h"
#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <QStyle>
#include <QCursor>
#include <QThread>

#include <list>
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <QPlainTextEdit>
#include <QString>


#include "./Tree/tree.hpp"
#include "structure/structure_tree_choice.hpp"
#include "vec2.hpp"
#include "3D/vec3.hpp"
#include "3D/mat3.hpp"
#include "3D/obj_generator.hpp"


using std::vector;
using std::string;


//forward declaration of QLabel
class QLabel;


//The main class wher all the human/machine interaction are managed
class render_area : public QWidget
{
    Q_OBJECT
public:
    //constructor
    render_area(QPlainTextEdit *,QPlainTextEdit *,QPlainTextEdit *, Ui::MainWindow *,QWidget *parent = 0);
    ~render_area();

    void init_fig();

    void giveDescriptionText(QPlainTextEdit *);
    void give_TextEdit(QPlainTextEdit *text);

    QString description_rule();
    QString description_alphabet();
    QString description_axiom();
    void displayRule();

    void changeAlphabet(string);
    void changeRules(string);
    void changeAxiom(string);
    void resetRule();

    void update_tree_name(string);
    void update_tree_radius(float r_start,float r_end);
    tree get_tree();

protected:
    /** Actual drawing function */
    void paintEvent(QPaintEvent *event);

    /** Function called when the mouse is pressed */
    void mousePressEvent(QMouseEvent *event);
    /** Function called when the mouse is moved */
    void mouseMoveEvent(QMouseEvent *event);
    /** Function called when the mouse is released */
    void mouseReleaseEvent(QMouseEvent *event);

    /** Function called in render_area */
    void paint_segment(QPainter *painter,vec3 p1,vec3 p2);

    void draw_tree();

    /** Function to get the cell wher the mouse is*/
    void paint();




private slots:
    // functions called by the GUI
    void update_brush_size(int );
    void update_tree_size(int );
    void update_segment_size(int );
    void update_alpha(int );
    void update_alpha_random(int );
    void update_beta(int );
    void update_beta_random(int );
    void update_gamma(int );
    void update_gamma_random(int );
    void update_ratio(int );
    void update_algo_select(int );
    void update_algo_speed(int );
    void update_rotation_y(int );
    void update_rotation_x(int );
    void update_startColor(int);
    void update_endColor(int);
    void reset_grid();
    void launch_algo();



private: //attributes


    int width;
    int height;

    void cleanGrid();

    float brush_size;
    float rotation_theta_y;
    float rotation_theta_x;
    float scale;
    float scale_prec;

    int algo_select;
    int algo_iter;
    int algo_delay;

    bool running;

    float dx;
    float dy;

    float dx_prec;
    float dy_prec;

    int clickpos_x;
    int clickpos_y;

    /** The current position of the click of the mouse */
    vec2 mouse_point;

    mat3 mat_rotation_y;
    mat3 mat_rotation_x;

    /** Indicates if the mouse is currently clicked or not */
    bool is_left_clicked;
    bool is_right_clicked;

    bool slow_draw;
    int slow_draw_iter;

    QPlainTextEdit *ruleText;
    QPlainTextEdit *axiomText;
    QPlainTextEdit *alphabetText;
    Ui::MainWindow *ui;

    tree render_tree;
    structure_tree_choice treeStructure;
    vector<vector<int>> lst_color;
    vector<int> color_selected;

};



#endif // RENDER_AREA_HPP
