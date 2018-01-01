#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "rgbcolorviewmodel.h"
#include "hsvcolorviewmodel.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<HSVColorViewModel>("LampkiAppSwipe.HSVColorViewModel", 1, 0, "HSVColorViewModel");
    qmlRegisterType<RGBColorViewModel>("LampkiAppSwipe.RGBColorViewModel", 1, 0, "RGBColorViewModel");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
