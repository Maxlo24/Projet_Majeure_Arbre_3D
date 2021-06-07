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
    this->algo_iter=3;
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
    slow_draw = false;
    scale = 4;

    dx=0;
    dy=0;
    dx_prec =0;
    dy_prec =0;
    
    tree tree;
    tree.setTree_l_system(treeStructure.fractal_bush());

    //couleur de départ
    int r1 = 91;
    int g1 = 32;
    int b1 = 0;
    //couleur d'arrivée
    int r2 = 0;
    int g2 = 174;
    int b2 = 6;

    tree.Color() = {{r1,g1,b1},{r2,g2,b2}};

    this->render_tree = tree;
    draw_tree();

    mat_rotation_y = mat3(std::cos(0),0,std::sin(0),
                       0,1,0,
                       -std::sin(0),0,std::cos(0));
    mat_rotation_x = mat3(1,0,0,
                       0,std::cos(0),-std::sin(0),
                       0,std::sin(0),std::cos(0));

    std::cout<<"Init OK"<<std::endl;

}


void render_area::paintEvent(QPaintEvent*)
{
    //Initialize painters
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);


    QPen pen;

    vector<vector<int>> c = render_tree.Color();

     int nbVal = render_tree.getMaxNbrParent();
    //pour chaque canal, calcul du différenciel entre chaque teinte (nbVal est le nombre de teintes du dégradé)
    float dr = float(c[1][0] - c[0][0]) / nbVal;
    float dg = float(c[1][1] - c[0][1]) / nbVal;
    float db = float(c[1][2] - c[0][2]) / nbVal;


    if(slow_draw){
        slow_draw_iter+=1;
    }else{
        slow_draw_iter = render_tree.getData().size();
    }
    for(int i = 0;i<slow_draw_iter;i++)
    {
        if (render_tree(i)->getVisible_node())
        {
            int nbrParent = render_tree(i)->getNb_parent();
            //pen.setColor(QColor(int(r1+nbrParent*dr), int(g1+nbrParent*dg), int(b1+nbrParent*db)));
//            pen.setWidth(1+brush_size*(1-float(nbrParent)/nbVal));
            //painter.setPen(pen);
            float degrade = (float(nbrParent)/nbVal);
            degrade = degrade*degrade;
            painter.setPen(QPen(QColor(int(c[0][0]+degrade*nbrParent*dr), int(c[0][1]+degrade*nbrParent*dg), int(c[0][2]+degrade*nbrParent*db)),brush_size));

            paint_segment(&painter,render_tree(i)->Coord(),render_tree(i)->Parent()->Coord());
//             if(slow_draw) std::cout<<"branche : "<<(render_tree(i)->getNb_parent())<<"/"<<nbVal<<std::endl;
        }
    }
}

void render_area::paint_segment(QPainter *painter,vec3 p1, vec3 p2){
//    std::cout<<p1<<p2<<std::endl;

    vec3 np1 = scale*mat_rotation_x*mat_rotation_y*p1;
    vec3 np2 = scale*mat_rotation_x*mat_rotation_y*p2;

    painter->drawLine(this->width/2+np1.x()+dx,this->height-20-np1.y()+dy,this->width/2+np2.x()+dx,this->height-20-np2.y()+dy);
}

void render_area::draw_tree()
{
    render_tree.reset();
    render_tree.generateNextLayer(algo_iter);

}

void render_area::cleanGrid() {

    repaint();
}

void render_area::launch_algo(){
    this->cleanGrid();

    this->running = true;
    draw_tree();
    this->setCursor(Qt::ForbiddenCursor);
    std::cout<<"Algo selected : "<<this->algo_select<<std::endl;
    std::cout<<"Searching ..."<<std::endl;
    slow_draw = true;

    slow_draw_iter = 0;
    if(this->algo_delay >= 0){
        for (auto i=0u;i<render_tree.getData().size() ;i++ ) {
            repaint();
            Sleep(this->algo_delay);
        }
    }
    slow_draw = false;
    std::cout<<"End"<<std::endl;
    this->running = false;
    this->setCursor(Qt::CrossCursor);
    repaint();
}

void render_area::generate_obj()
{
    std::cout<<"Building ..."<<std::endl;
    obj_generator mesh = obj_generator(render_tree,"test");
    mesh.generate();
    std::cout<<"Done !"<<std::endl;
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

    paint();
    if(event->button() == Qt::LeftButton){
        is_left_clicked=true;
    }
    if (event->button() == Qt::RightButton){
        is_right_clicked=true;
    }
    repaint();
}

void render_area::mouseReleaseEvent(QMouseEvent*)
{
    is_left_clicked=false;
    is_right_clicked=false;
    dx_prec = dx;
    dy_prec = dy;
    scale_prec = scale;
//    paint();
    repaint();
}


void render_area::update_algo_speed(int speed){
    this->algo_delay = 40*(speed-2);
    std::cout<<"Algo delay : "<<this->algo_delay<<std::endl;
}

void render_area::update_rotation_y(int angle)
{
    rotation_theta_y = (float(angle)/180)*M_PI;
    std::cout<<"Angle de rotation : "<<angle<<std::endl;
    mat_rotation_y = mat3(std::cos(rotation_theta_y),0,std::sin(rotation_theta_y),
                       0,1,0,
                       -std::sin(rotation_theta_y),0,std::cos(rotation_theta_y));
    repaint();

}

void render_area::update_rotation_x(int angle)
{
    rotation_theta_x = (float(angle)/180)*M_PI;
    std::cout<<"Angle de rotation : "<<angle<<std::endl;
    mat_rotation_x = mat3(1,0,0,
                       0,std::cos(rotation_theta_x),-std::sin(rotation_theta_x),
                       0,std::sin(rotation_theta_x),std::cos(rotation_theta_x));
    repaint();



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

    this->scale = float(size)/10;
    this->scale_prec = scale;
    std::cout<<"Segment size : "<<size<<std::endl;
    repaint();
}

void render_area::update_alpha(int angle){

    render_tree.setAlpha((float(angle)/45)*M_PI/2);
    std::cout<<"Alpha : "<<angle<<std::endl;
    draw_tree();
    repaint();
}

void render_area::update_alpha_random(int coeff)
{
    render_tree.setParamAlphaRandom(float(coeff)/5);
    draw_tree();
    repaint();
}

void render_area::update_beta(int angle){
    render_tree.setBeta((float(angle)/45)*M_PI/2);
    std::cout<<"Beta : "<<angle<<std::endl;
    draw_tree();
    repaint();
}

void render_area::update_beta_random(int coeff)
{
    render_tree.setParamBetaRandom(float(coeff)/5);
    draw_tree();
    repaint();
}

void render_area::update_gamma(int angle){
    render_tree.setGamma((float(angle)/45)*M_PI/2);
    std::cout<<"gamma : "<<angle<<std::endl;
    draw_tree();
    repaint();
}

void render_area::update_gamma_random(int coeff)
{
    render_tree.setParamGammaRandom(float(coeff)/5);
    draw_tree();
    repaint();
}

void render_area::update_ratio(int ratio)
{
    render_tree.setParamScale(1.0f-float(ratio)/100);
    std::cout<<"Ratio : "<<float(ratio)/20<<std::endl;
    draw_tree();
    repaint();
}


void render_area::update_algo_select(int select){
    this->algo_select = select;
    std::cout<<"Algo selected : "<<this->algo_select<<std::endl;

    init_fig();
    switch(algo_select){
        case 0:
            render_tree.setTree_l_system(treeStructure.binary_tree());
            scale=20;
            break;
        case 1:
            render_tree.setTree_l_system(treeStructure.fractal_stick());
            scale =4;
            break;
        case 2:
            render_tree.setTree_l_system(treeStructure.fractal_plant());
            scale =4;
            break;
        case 3:
            render_tree.setTree_l_system(treeStructure.fractal_sym());
            scale =4;
            break;
        case 4:
            render_tree.setTree_l_system(treeStructure.fractal_bush());
            scale =4;
            break;
        case 5:
            render_tree.setTree_l_system(treeStructure.fractal_leaf());
            scale =4;
            break;
        case 6:
            render_tree.setTree_l_system(treeStructure.fractal_fir());
            scale=20;
            break;
        case 7:
            render_tree.setTree_l_system(treeStructure.fractal_dragon());
            scale =4;
            break;
        case 8:
            render_tree.setTree_l_system(treeStructure.fractal_complex1());
            scale =4;
            break;
        case 9:
            render_tree.setTree_l_system(treeStructure.fractal_persil());
            scale =4;
            break;
        case 10:
            render_tree.setTree_l_system(treeStructure.fractal_3D_tree());
            scale =4;
            break;
        case 11:
            render_tree.setTree_l_system(treeStructure.fractal_3D_tree1());
            break;
    };
    scale_prec=scale;
    draw_tree();
    repaint();
}

void render_area::reset_grid(){
    init_fig();
    repaint();
}

// function called whe user is painting with the mouse
void render_area::paint(){
    int i = mouse_point.x;
    int j = mouse_point.y;

    if(is_left_clicked==false && is_right_clicked==false){
        if(i==clickpos_x && j==clickpos_y){
            dx_prec=0;
            dy_prec=0;
            dx=0;
            dy=0;
            update_rotation_x(0);
            update_rotation_y(0);
            scale = 4;
        }
        clickpos_x = i;
        clickpos_y = j;
//        std::cout<<is_left_clicked<<":"<<is_right_clicked<<";"<<clickpos_y<<std::endl;
    }


    if(is_left_clicked==true){
        dx = i-clickpos_x+dx_prec;
        dy = j-clickpos_y+dy_prec;

//        std::cout<<i<<";"<<clickpos_x<<std::endl;
    }


    if(is_right_clicked==true){
        scale = scale_prec-0.1f*(j-clickpos_y);
        //scale = scale_prec+j-clickpos_y;
//        std::cout<<j<<";"<<clickpos_y<<std::endl;
    }
//    std::cout<<is_right_clicked<<";"<<i-clickpos_x<<std::endl;




}


void render_area::give_label(QLabel *label){
    this->cpt_label = label;
}
