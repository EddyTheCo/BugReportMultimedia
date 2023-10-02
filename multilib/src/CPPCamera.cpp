#include"CPPCamera.hpp"

#include <QGuiApplication>
#if QT_CONFIG(permissions)
#include <QPermission>
#endif


Q_INVOKABLE void Permision_h::getPermission(void)
{

#if QT_CONFIG(permissions)
    QCameraPermission cPermission;
    switch (qApp->checkPermission(cPermission)) {
    case Qt::PermissionStatus::Undetermined:
        qApp->requestPermission(cPermission, this,
                                &Permision_h::getPermission);
        return;
    case Qt::PermissionStatus::Denied:
        return;
    case Qt::PermissionStatus::Granted:
        emit gotPermission();
        return;
    }
#endif
}

namespace fooCamera
{
QString fooPrint(void)
{
    return "https://forum.qt.io/post/762513";
}
}
