#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mywebengine.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionforward_triggered();

    void on_actionback_triggered();

protected:
    void resizeEvent(QResizeEvent* );


private:
    Ui::MainWindow *ui;
    Mywebengine* myweb;
};
#endif // MAINWINDOW_H
