/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -v -c ConfigurationIf -p confif.h:confif.cpp -i genivi-dbus-types.h ../genivi-positioning-configuration-qt.xml org.genivi.positioning.Configuration
 *
 * qdbusxml2cpp is Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "confif.h"

/*
 * Implementation of interface class ConfigurationIf
 */

ConfigurationIf::ConfigurationIf(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

ConfigurationIf::~ConfigurationIf()
{
}
