#ifndef VIEWINGWINDOW_H
#define VIEWINGWINDOW_H

#include <QMainWindow>

namespace Ui {
class ViewingWindow;
}

class ViewingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewingWindow(QWidget *parent = nullptr);
    ~ViewingWindow();

private:
    Ui::ViewingWindow *ui;
    int value_in_1st_pair;
    int value_in_2nd_pair;
    int value_in_3rd_pair;
    int value_in_4th_pair;
    int value_in_5th_pair;
    int value_in_6th_pair;
    int value_in_7th_pair;
    int value_in_8th_pair;
    int value_in_9th_pair;
    int value_in_10th_pair;
    int value_in_11th_pair;

private slots:
       void update_label() const ;
       void record_change_in_1st_pair(int);
       void record_change_in_2nd_pair(int);
       void record_change_in_3rd_pair(int);
       void record_change_in_4th_pair(int);
       void record_change_in_5th_pair(int);
       void record_change_in_6th_pair(int);
       void record_change_in_7th_pair(int);
       void record_change_in_8th_pair(int);
       void record_change_in_9th_pair(int);
       void record_change_in_10th_pair(int);
       void record_change_in_11th_pair(int);

};

#endif // VIEWINGWINDOW_H
