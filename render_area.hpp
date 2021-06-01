#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP

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
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

#include "graph2d.hpp"
#include "cell.hpp"
#include "vec2.hpp"
#include "bfs_algo.hpp"
#include "dfs_algo.hpp"
#include "astar_algo.hpp"
#include "dijkstra_algo.hpp"
#include "maze_generator.hpp"

using std::vector;

//forward declaration of QLabel
class QLabel;


//The main class wher all the human/machine interaction are managed
class render_area : public QWidget
{
    Q_OBJECT
public:
    //constructor
    render_area(QWidget *parent = 0);
    ~render_area();

    void init_fig();
    void update_brush_type(states type);

    void give_label(QLabel *label);


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
    /** Function to get the cell wher the mouse is*/
    void paint();
    /** Function to paint the cell*/
    void brush_paint_cell(int i, int j, states color);


private slots:
    // functions called by the GUI
    void update_grid_size(int size);
    void update_brush_size(int size);
    void update_algo_select(int select);
    void update_algo_speed(int speed);
    void reset_grid();
    void launch_algo();
    void generateMaze();


private: //attributes

    graph2D<cell> graph;

    int width;
    int height;

    void fillNeighbors();
    void cleanGrid();

    vector<int> start_point;
    vector<int> end_point;

    int graph_size_select;
    states graph_brush_type;
    int graph_brush_size;

    int algo_select;

    int algo_delay;

    bool running;

    int dx;
    int dy;

    /** The current position of the click of the mouse */
    vec2 mouse_point;
    /** Indicates if the mouse is currently clicked or not */
    bool is_left_clicked;
    bool is_right_clicked;

    QLabel *cpt_label;

};



#endif // RENDER_AREA_HPP
