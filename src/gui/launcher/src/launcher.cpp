#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "launcher/launcher.hpp"
#include "calculator_controller/calculator_controller.hpp"

namespace Launcher
{
    int start(int argc, char *argv[])
    {
        QGuiApplication app(argc, argv);

        QQmlApplicationEngine engine;

        CalculatorController *calculatorController = new CalculatorController(&app);
        qmlRegisterSingletonInstance("controller", 1, 0, "CalculatorController", calculatorController);

        QObject::connect(
            &engine,
            &QQmlApplicationEngine::objectCreationFailed,
            &app,
            []()
            { QCoreApplication::exit(-1); },
            Qt::QueuedConnection);
        engine.loadFromModule("launcher", "Main");

        return app.exec();
    }
} // namespace Launcher
