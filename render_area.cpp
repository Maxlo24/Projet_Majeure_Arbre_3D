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
    this->algo_iter=4;
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

    brush_size = 2;
    algo_iter = 4;
    


    tree tree;
    tree.setTree_l_system(treeStructure.fractal_stick());


    this->render_tree = tree;
    draw_tree();

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

    //couleur de départ
        int r1 = 91;
        int g1 = 32;
        int b1 = 0;
    //couleur d'arrivée
        int r2 = 0;
        int g2 = 174;
        int b2 = 6;

        int nbVal = render_tree.getMaxNbrParent();
    //pour chaque canal, calcul du différenciel entre chaque teinte (nbVal est le nombre de teintes du dégradé)
        int dr = int((r2 - r1) / nbVal);
        int dg = int((g2 - g1) / nbVal);
        int db = int((b2 - b1) / nbVal);

    pen.setColor(Qt::black);
    painter.setPen(pen);

    painter.setBrush(brush);
    for(int i = 0;i<render_tree.size();i++)
    {
        if (render_tree(i)->getVisible_node()  || true)
        {
            int nbrParent = render_tree(i)->getNb_parent();
            pen.setColor(QColor(r1+nbrParent*dr, g1+nbrParent*dg, b1+nbrParent*db));
            painter.setPen(pen);

            paint_segment(&painter,render_tree(i)->Coord(),render_tree(i)->Parent()->Coord());
        }

    }


}

void render_area::paint_segment(QPainter *painter,vec2 p1, vec2 p2){
//    std::cout<<p1<<p2<<std::endl;
    painter->drawLine(this->width/2+p1.x,this->height-20-p1.y,this->width/2+p2.x,this->height-20-p2.y);

}

void render_area::draw_tree()
{
    render_tree.reset();
    for(int i=0;i<algo_iter;i++){
        render_tree.generateNextLayer();
    }
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

    this->algo_iter=size;
    std::cout<<"Tree size : "<<size<<std::endl;
    draw_tree();
    repaint();
}

void render_area::update_segment_size(int size){

    render_tree.setLength(10*size);
    std::cout<<"Segment size : "<<size<<std::endl;
    draw_tree();
    repaint();
}

void render_area::update_angle(int angle){

    render_tree.setAngle((float(angle)/45)*M_PI/2);
    std::cout<<"Angle : "<<angle<<std::endl;
    draw_tree();
    repaint();
}

void render_area::update_ratio(int ratio)
{
    render_tree.setRatio(float(ratio)/20);
    std::cout<<"Ratio : "<<float(ratio)/20<<std::endl;
    draw_tree();
    repaint();
}


void render_area::update_algo_select(int select){
    this->algo_select = select;
    std::cout<<"Algo selected : "<<this->algo_select<<std::endl;

    switch(algo_select){
        case 0:
            render_tree.setTree_l_system(treeStructure.binary_tree());
            break;
        case 1:
            render_tree.setTree_l_system(treeStructure.fractal_stick());
            break;
        case 2:
            render_tree.setTree_l_system(treeStructure.fractal_plant());
            break;
        case 3:
            render_tree.setTree_l_system(treeStructure.fractal_sym());
            break;
        case 4:
            render_tree.setTree_l_system(treeStructure.fractal_bush());
            break;
    };
    draw_tree();
    repaint();
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
