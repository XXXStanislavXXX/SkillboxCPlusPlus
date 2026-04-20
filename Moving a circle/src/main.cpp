#include "main.h"

int main(int argc, char *argv[]) {
    return runApplication(argc, argv);
}

int runApplication(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/MovingCircle/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}

