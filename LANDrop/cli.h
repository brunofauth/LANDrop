#pragma once

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QStringList>


class CliArguments {
    public:
        QCommandLineOption noStartupNotification;
};


QCommandLineParser& MakeCliParser();
QCommandLineParser& GetCliParser();
const CliArguments& GetCliArgDefs();


