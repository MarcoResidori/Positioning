/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -v -c ConfigurationIf -p confif.h:confif.cpp -i genivi-dbus-types.h ../genivi-positioning-configuration-qt.xml org.genivi.positioning.Configuration
 *
 * qdbusxml2cpp is Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef CONFIF_H_1331560215
#define CONFIF_H_1331560215

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "genivi-dbus-types.h"

/*
 * Proxy class for interface org.genivi.positioning.Configuration
 */
class ConfigurationIf: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.genivi.positioning.Configuration"; }

public:
    ConfigurationIf(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~ConfigurationIf();

    Q_PROPERTY(int SatelliteSystem READ satelliteSystem WRITE setSatelliteSystem)
    inline int satelliteSystem() const
    { return qvariant_cast< int >(property("SatelliteSystem")); }
    inline void setSatelliteSystem(int value)
    { setProperty("SatelliteSystem", QVariant::fromValue(value)); }

    Q_PROPERTY(ushort UpdateInterval READ updateInterval WRITE setUpdateInterval)
    inline ushort updateInterval() const
    { return qvariant_cast< ushort >(property("UpdateInterval")); }
    inline void setUpdateInterval(ushort value)
    { setProperty("UpdateInterval", QVariant::fromValue(value)); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QVariantMap> GetProperties()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetProperties"), argumentList);
    }

    inline QDBusPendingReply<GeniviVersion> GetVersion()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetVersion"), argumentList);
    }

    inline QDBusPendingReply<> SetProperty(const QString &name, const QDBusVariant &value)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name) << QVariant::fromValue(value);
        return asyncCallWithArgumentList(QLatin1String("SetProperty"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void PropertyChanged(const QString &name, const QDBusVariant &value);
};

namespace org {
  namespace genivi {
    namespace positioning {
      typedef ::ConfigurationIf Configuration;
    }
  }
}
#endif