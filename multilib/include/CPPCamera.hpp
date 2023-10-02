#include<QObject>
#include <QtQml/qqmlregistration.h>

//foo namespace to force the linker to link the backing library,
//so I can use the resource file system for importing qml modules and do not care of the corresponding pluging
//https://forum.qt.io/post/762513
namespace fooCamera
{
QString fooPrint(void);
};


#include <QtCore/QtGlobal>

#if defined(WINDOWS_MULTI)
# define MULTI_EXPORT Q_DECL_EXPORT
#else
#define MULTI_EXPORT Q_DECL_IMPORT
#endif

class MULTI_EXPORT Permision_h: public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    Permision_h(QObject *parent = nullptr):QObject(parent)
        {

        };

    Q_INVOKABLE void getPermission(void);

signals:
    void gotPermission();

};
