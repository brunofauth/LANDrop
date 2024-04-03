#pragma once

#include <QCoreApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QStringList>


class CliArguments {
    public:
        QCommandLineOption noStartupNotification;
};


QCommandLineParser& MakeCliParser(const QCoreApplication& app);
QCommandLineParser& GetCliParser();
const CliArguments& GetCliArgDefs();


