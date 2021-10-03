#include <QQuickStyle>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "database.h"
#include "annotationcontroller.h"
#include "annotationmodel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QQuickStyle::setStyle("Material");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    AnnotationController *controller = new AnnotationController();
    AnnotationModel *model = new AnnotationModel();
    controller->setAnnotationModel(model);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
