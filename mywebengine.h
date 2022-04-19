#ifndef MYWEBENGINE_H
#define MYWEBENGINE_H

#include <QWidget>
#include <QWebEngineView>
#include <qwebengineview.h>
#include <QUrl>
#include <QMouseEvent>
#include <QApplication>

class Mywebengine : public QWebEngineView
{
public:
    explicit Mywebengine(QWidget *parent=nullptr);
    ~Mywebengine();




protected:
    QWebEngineView* createWindow(QWebEnginePage::WebWindowType type) override;
private slots:
    void slot_LinkHovered(const QString& url);
private:
    QUrl	url_;
    QVector<QObject * > mvchildObj;
protected:
    bool event(QEvent* evt)override;


    bool eventFilter(QObject *obj, QEvent *ev)override;

};
#endif // MYWEBENGINE_H
