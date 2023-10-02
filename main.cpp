#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "CPPCamera.hpp"
int main(int argc, char *argv[])
{
    auto foo=fooCamera::fooPrint(); //https://forum.qt.io/post/762513
    QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/esterVtech.com/imports");
    qDebug()<<engine.importPathList();


    const QUrl url(u"qrc:/esterVtech.com/imports/Example/qml/window.qml"_qs);
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
			&app, [url](QObject *obj, const QUrl &objUrl) {
			if (!obj && url == objUrl)
			QCoreApplication::exit(-1);
			}, Qt::QueuedConnection);

	engine.load(url);

	return app.exec();
}
