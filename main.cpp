#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ViewModels/colorviewmodel.h"
#include "ViewModels/gradientviewmodel.h"
#include "ViewModels/settingsviewmodel.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<ColorViewModel>("LampkiAppSwipe.ColorViewModel", 1, 0, "ColorViewModel");
    qmlRegisterType<GradientViewModel>("LampkiAppSwipe.GradientViewModel", 1, 0, "GradientViewModel");
    qmlRegisterType<settingsViewModel>("LampkiAppSwipe.SettingsViewModel", 1, 0, "SettingsViewModel");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
