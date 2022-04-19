#include "mywebengine.h"

Mywebengine::Mywebengine(QWidget * parent):QWebEngineView(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);

    connect(this->page(), &QWebEnginePage::linkHovered, this, &Mywebengine::slot_LinkHovered);

}

Mywebengine::~Mywebengine()
{

}

QWebEngineView *Mywebengine::createWindow(QWebEnginePage::WebWindowType type)
{
    if(!url_.isEmpty())
    {
        this->load(url_);
        emit QEvent::ChildPolished;//重新加载页面时，手动触发一个ChildPolished事件
    }
//    return this;
    return nullptr;
}

void Mywebengine::slot_LinkHovered(const QString &url)
{
    url_.setUrl(url);
}

bool Mywebengine::event(QEvent *evt)
{
    if (evt->type() == QEvent::ChildPolished)
        {
            qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<" ";
            QChildEvent *child_ev = static_cast<QChildEvent*>(evt);

            QObject *childObj = child_ev->child();
            mvchildObj.append(childObj);
            if (childObj)
            {
                childObj->installEventFilter(this);
            }
        }

        return QWebEngineView::event(evt);

}



bool Mywebengine::eventFilter(QObject *obj, QEvent *ev)
{
    foreach(QObject *childObj,mvchildObj)
        {
            if (obj == childObj)
            {
                if (/*obj == childObj&& */(ev->type() == QEvent::MouseButtonPress|| ev->type() == QEvent::MouseButtonDblClick))
                {
                    QMouseEvent *MouseEvent = static_cast<QMouseEvent *>(ev);
                    int x = MouseEvent->x();
                    int y = MouseEvent->y();
                    qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<" "<<x <<y;
                    return QWebEngineView::eventFilter(obj, ev);
                }
            }
        }
        return QWebEngineView::eventFilter(obj, ev);

}
