#include "render_area.hpp"
#include <QDebug>

render_area::render_area(QWidget *parent)
    :QWidget(parent),mouse_point(),is_left_clicked(),is_right_clicked()
{
    this->width = 790; //this->size().width();
    this->height = 550;//this->size().height();

    std::cout<<width<<std::endl;
    std::cout<<height<<std::endl;

    this->brush_size = 2;


    this->running = false;
    this->algo_select = 0;
    this->algo_delay = -1;

    init_fig();
}

render_area::~render_area()
{

}

void render_area::init_fig()
{
    std::cout<<"Init graph ..."<<std::endl;

    this->setCursor(Qt::CrossCursor);

    node *n1 = new node({0,0});
    n1->Parent()=n1;
    structure_tree_choice treeStructure;
    L_system lSys = treeStructure.fractal_plant();

    //rules[B] = {Rules(1.0,{A})};
    /*node *n2 = new node({0,50});
    node *n3 = new node({-25,75});
    node *n4 = new node({25,75});

    n1->Parent()=n1;
    n2->Parent()=n1;
    n3->Parent()=n2;
    n4->Parent()=n2;

    vector<node*> vec = {n1,n2,n3,n4};
    this->render_tree = tree(vec);*/
    tree tree({n1});
    tree.incrementTree(lSys,n1);
    vector<node*> lastDataCopy = tree.getLastData();
    for (node * lnode: lastDataCopy)
    {
        tree.incrementTree(lSys,lnode);
    }


    this->render_tree = tree;

    std::cout<<"Init OK"<<std::endl;

}


void render_area::paintEvent(QPaintEvent*)
{

    //Initialize painters
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QBrush brush = painter.brush();
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QPen pen;

    pen.setWidth(brush_size);
    pen.setColor(Qt::black);
    painter.setPen(pen);

    painter.setBrush(brush);
    for(int i = 0;i<render_tree.size();i++)
    {
        paint_segment(&painter,render_tree(i)->Coord(),render_tree(i)->Parent()->Coord());
    }


}

void render_area::paint_segment(QPainter *painter,vec2 p1, vec2 p2){
//    std::cout<<p1<<p2<<std::endl;
    painter->drawLine(this->width/2+p1.x,this->height-50-p1.y,this->width/2+p2.x,this->height-50-p2.y);

}

void render_area::cleanGrid() {

    repaint();
}

void render_area::launch_algo(){
    this->cleanGrid();

    this->running = true;
    this->setCursor(Qt::ForbiddenCursor);
    std::cout<<"Algo selected : "<<this->algo_select<<std::endl;
    std::cout<<"Searching ..."<<std::endl;

    std::cout<<"End"<<std::endl;
    this->running = false;
    this->setCursor(Qt::CrossCursor);
    repaint();
}

void render_area::mouseMoveEvent(QMouseEvent *event)
{
    mouse_point=vec2(event->x(),event->y());
    paint();
    repaint();
}

void render_area::mousePressEvent(QMouseEvent *event)
{
    mouse_point=vec2(event->x(),event->y());

    if(event->button() == Qt::LeftButton){
        is_left_clicked=true;
    }
    if (event->button() == Qt::RightButton){
        is_right_clicked=true;
    }
    paint();
    repaint();
}

void render_area::mouseReleaseEvent(QMouseEvent*)
{
    is_left_clicked=false;
    is_right_clicked=false;
    repaint();
}


void render_area::update_algo_speed(int speed){
    this->algo_delay = 40*(speed-2);
    std::cout<<"Algo delay : "<<this->algo_delay<<std::endl;
}

void render_area::update_brush_size(int size){

    this->brush_size = size;
    std::cout<<"Brush size : "<<this->brush_size<<std::endl;
    repaint();
}

void render_area::update_tree_size(int size){

    std::cout<<"Tree size : "<<size<<std::endl;
    repaint();
}

void render_area::update_segment_size(int size){

    std::cout<<"Segment size : "<<size<<std::endl;
    repaint();
}

void render_area::update_angle(int size){

    std::cout<<"Angle : "<<size<<std::endl;
    repaint();
}


void render_area::update_algo_select(int select){
    this->algo_select = select;
    std::cout<<"Algo selected : "<<this->algo_select<<std::endl;
}

void render_area::reset_grid(){
    init_fig();
    repaint();
}

// function called whe user is painting with the mouse
void render_area::paint(){
    int i = mouse_point.x/dx;
    int j = mouse_point.y/dy;

}


void render_area::give_label(QLabel *label){
    this->cpt_label = label;
}
