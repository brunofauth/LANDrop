#include "cli.h"
#include <optional>


static std::optional<QCommandLineParser> parser = std::nullopt;
static std::optional<CliArguments> argDefs = std::nullopt;


QCommandLineParser& MakeCliParser(const QCoreApplication& app) {
    argDefs = CliArguments {
        .noStartupNotification = QCommandLineOption(
            QStringList() << "N" << "no-startup-notification",
            QCoreApplication::translate("main", "Do not show a startup notification when launching.")),
    };

    parser.emplace();
    parser->setApplicationDescription("Test helper");
    auto optHelp = parser->addHelpOption();
    auto optVersion = parser->addVersionOption();
    parser->addOption(argDefs->noStartupNotification);
    parser->parse(app.arguments());

    if (parser->isSet(optHelp)) {
        parser->showHelp();
    }

    if (parser->isSet(optVersion)) {
        parser->showVersion();
    }

    return *parser;
}

QCommandLineParser& GetCliParser() {
    if (!argDefs)
        throw std::runtime_error(QCoreApplication::translate(
            "Main", "Called GetCliParser before making one!").toUtf8().toStdString());
    return *parser;
}

const CliArguments& GetCliArgDefs() {
    if (!argDefs)
        throw std::runtime_error(QCoreApplication::translate(
            "Main", "Called GetCliArgs before making a parser!").toUtf8().toStdString());
    return *argDefs;
}


