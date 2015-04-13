/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtContacts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QCONTACTONLINEACCOUNT_H
#define QCONTACTONLINEACCOUNT_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactOnlineAccount : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactOnlineAccount)
#else
    static const DetailType Type;
#endif

    enum OnlineAccountField {
        FieldAccountUri = 0,
        FieldServiceProvider,
        FieldProtocol,
        FieldCapabilities,
        FieldSubTypes
    };

    enum SubType {
        SubTypeSip = 0,
        SubTypeSipVoip,
        SubTypeImpp,
        SubTypeVideoShare
    };

    enum Protocol {
        ProtocolUnknown = 0,
        ProtocolAim,
        ProtocolIcq,
        ProtocolIrc,
        ProtocolJabber,
        ProtocolMsn,
        ProtocolQq,
        ProtocolSkype,
        ProtocolYahoo
    };

    void setAccountUri(const QString& accountUri) {setValue(FieldAccountUri, accountUri);}
    QString accountUri() const {return value(FieldAccountUri).toString();}

    void setServiceProvider(const QString& serviceProvider) {setValue(FieldServiceProvider, serviceProvider);}
    QString serviceProvider() const {return value(FieldServiceProvider).toString();}

    void setProtocol(Protocol protocol) {setValue(FieldProtocol, protocol);}
    Protocol protocol() const {return Protocol(value(FieldProtocol).toInt());}

    void setCapabilities(const QStringList& capabilities) {setValue(FieldCapabilities, capabilities);}
    QStringList capabilities() const {return value<QStringList>(FieldCapabilities);}

    void setSubTypes(const QList<int> &subTypes) {setValue(FieldSubTypes, QVariant::fromValue(subTypes));}
    QList<int> subTypes() const {return value< QList<int> >(FieldSubTypes);}
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTONLINEACCOUNT_H
