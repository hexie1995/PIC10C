#include "viewingwindow.h"
#include "ui_viewingwindow.h"


ViewingWindow::ViewingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewingWindow),
    value_in_1st_pair(0),
    value_in_2nd_pair(0),
    value_in_3rd_pair(0),
    value_in_4th_pair(0),
    value_in_5th_pair(0),
    value_in_6th_pair(0),
    value_in_7th_pair(0),
    value_in_8th_pair(0),
    value_in_9th_pair(0),
    value_in_10th_pair(0),
    value_in_11th_pair(0)

{
    ui->setupUi(this);

    QObject::connect( ui->hw1_score ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_1st_pair(int) ) );
    QObject::connect( ui->hw2_score_2 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_2nd_pair(int) ) );
    QObject::connect( ui->hw2_score_3 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_3rd_pair(int) ) );
    QObject::connect( ui->hw2_score_4 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_4th_pair(int) ) );
    QObject::connect( ui->hw2_score_5 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_5th_pair(int) ) );
    QObject::connect( ui->hw2_score_6 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_6th_pair(int) ) );
    QObject::connect( ui->hw2_score_7 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_7th_pair(int) ) );
    QObject::connect( ui->hw2_score_8 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_8th_pair(int) ) );

    QObject::connect( ui->spinBox_2 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_9th_pair(int) ) );
    QObject::connect( ui->spinBox_3 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_10th_pair(int) ) );
    QObject::connect( ui->spinBox_4 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_11th_pair(int) ) );

    QObject::connect( ui->hw2_slider_1 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_1st_pair(int) ) );
    QObject::connect( ui->hw2_slider_2 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_2nd_pair(int) ) );
    QObject::connect( ui->hw2_slider_3 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_3rd_pair(int) ) );
    QObject::connect( ui->hw2_slider_4 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_4th_pair(int) ) );
    QObject::connect( ui->hw2_slider_5 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_5th_pair(int) ) );
    QObject::connect( ui->hw2_slider_6 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_6th_pair(int) ) );
    QObject::connect( ui->hw2_slider_7 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_7th_pair(int) ) );
    QObject::connect( ui->hw2_slider_8 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_8th_pair(int) ) );

    QObject::connect( ui->horizontalSlider ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_9th_pair(int) ) );
    QObject::connect( ui->horizontalSlider_2 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_10th_pair(int) ) );
    QObject::connect( ui->horizontalSlider_3 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( record_change_in_11th_pair(int) ) );


}

ViewingWindow::~ViewingWindow()
{
    delete ui;
}

void ViewingWindow::record_change_in_1st_pair(int value){
     value_in_1st_pair = value;
     update_label();
     return;
 }

 void ViewingWindow::record_change_in_2nd_pair(int value){
     value_in_2nd_pair = value;
     update_label();
     return;
 }

 void ViewingWindow::record_change_in_3rd_pair(int value){
     value_in_3rd_pair = value;
     update_label();
     return;
 }
 void ViewingWindow::record_change_in_4th_pair(int value){
     value_in_4th_pair = value;
     update_label();
     return;
 }
 void ViewingWindow::record_change_in_5th_pair(int value){
     value_in_5th_pair = value;
     update_label();
     return;
 }
 void ViewingWindow::record_change_in_6th_pair(int value){
     value_in_6th_pair = value;
     update_label();
     return;
 }

 void ViewingWindow::record_change_in_7th_pair(int value){
     value_in_7th_pair = value;
     update_label();
     return;
 }

 void ViewingWindow::record_change_in_8th_pair(int value){
     value_in_8th_pair = value;
     update_label();
     return;
 }
 void ViewingWindow::record_change_in_9th_pair(int value){
     value_in_9th_pair = value;
     update_label();
     return;
 }
 void ViewingWindow::record_change_in_10th_pair(int value){
     value_in_10th_pair = value;
     update_label();
     return;
 }
 void ViewingWindow::record_change_in_11th_pair(int value){
     value_in_11th_pair = value;
     update_label();
     return;
 }


void ViewingWindow::update_label() const {
    double x1 = static_cast<double>(value_in_1st_pair);
    double x2 = static_cast<double>(value_in_2nd_pair);
     double x3 = static_cast<double>(value_in_3rd_pair);
     double x4 = static_cast<double>(value_in_4th_pair);
     double x5 = static_cast<double>(value_in_5th_pair);
     double x6 = static_cast<double>(value_in_6th_pair);
     double x7 = static_cast<double>(value_in_7th_pair);
     double x8 = static_cast<double>(value_in_8th_pair);
     double x9 = static_cast<double>(value_in_9th_pair);
     double x10 = static_cast<double>(value_in_10th_pair);
     double x11 = static_cast<double>(value_in_11th_pair);

     QList<int> l {x1,x2,x3,x4,x5,x6,x7,x8};
     double min = *std::min_element(l.begin(), l.end());

     QString text(QString::number((x1+x2+x3+x4+x5+x6+x7+x8-min)/700*25+
                                  x9/100*20+x10/100*20+x11/100*35));
     ui->Ascore->setText(text);
     double high=x9;
     if (x10>x9){
         high = x10;
     }

     QString text2(QString::number((x1+x2+x3+x4+x5+x6+x7+x8-min)/700*25+high/100*30+x11/100*44));
     ui->Bscore->setText(text2);
}



