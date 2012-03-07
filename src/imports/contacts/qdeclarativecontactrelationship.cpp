/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtQml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include <QtQml/qqmlinfo.h>
#include "qdeclarativecontactrelationship_p.h"
#include <QDebug>

QTCONTACTS_BEGIN_NAMESPACE

/*!
   \qmlclass Relationship QDeclarativeContactRelationship
   \brief The Relationship element describes a one-to-one relationship
  between a locally-stored contact and another (possibly remote) contact.

   \ingroup qml-contacts-main
   \inqmlmodule QtContacts
   This element is part of the \b{QtContacts} module.

   \sa QContactRelationship
   \sa RelationshipModel
 */

QDeclarativeContactRelationship::QDeclarativeContactRelationship(QObject* parent)
    :QObject(parent)
{

}


/*!
  \qmlproperty int Relationship::first

  This property holds the locally-stored contact which has a relationship of the given type with the second contact.
  */

QDeclarativeContact* QDeclarativeContactRelationship::first() const
{
    QDeclarativeContact *v = new QDeclarativeContact();
    v->setContact(m_relationship.first());
    return v;
}

/*!
  \qmlproperty int Relationship::second

  This property holds the contact with which the first contact has a relationship of the given type.
  */
QDeclarativeContact*  QDeclarativeContactRelationship::second() const
{
    QDeclarativeContact *v = new QDeclarativeContact();
    v->setContact(m_relationship.second());
    return v;
}

/*!
  \qmlproperty string Relationship::type

  This property holds the type of relationship which the source contact has with the destination contacts.
  The value for this property can be one of:
  \list
  \li HasMember
  \li Aggregates
  \li IsSameAs
  \li HasAssistant
  \li HasManager
  \li HasSpouse
  \endlist
  or any other customized relationship type string.
  */

QVariant QDeclarativeContactRelationship::relationshipType() const
{
    return m_relationship.relationshipType();
}

void QDeclarativeContactRelationship::setFirst(QDeclarativeContact* firstContact)
{
    if (firstContact)
        m_relationship.setFirst(firstContact->contact());
}

void QDeclarativeContactRelationship::setSecond(QDeclarativeContact* secondContact)
{
    if (secondContact)
        m_relationship.setSecond(secondContact->contact());
}

void QDeclarativeContactRelationship::setRelationshipType(const QVariant& relationshipType)
{
    if (relationshipType.type() == QVariant::Int) {
        switch (relationshipType.toInt()) {
        case QDeclarativeContactRelationship::HasMember:
            m_relationship.setRelationshipType(QContactRelationship::HasMember);
            break;
        case QDeclarativeContactRelationship::Aggregates:
            m_relationship.setRelationshipType(QContactRelationship::Aggregates);
            break;
        case QDeclarativeContactRelationship::IsSameAs:
            m_relationship.setRelationshipType(QContactRelationship::IsSameAs);
            break;
        case QDeclarativeContactRelationship::HasAssistant:
            m_relationship.setRelationshipType(QContactRelationship::HasAssistant);
            break;
        case QDeclarativeContactRelationship::HasManager:
            m_relationship.setRelationshipType(QContactRelationship::HasManager);
            break;
        case QDeclarativeContactRelationship::HasSpouse:
            m_relationship.setRelationshipType(QContactRelationship::HasSpouse);
            break;
        default:
            //unknown type
            qmlInfo(this) << tr("unknown relationship type:") << relationshipType;
            break;
        }
    } else {
        m_relationship.setRelationshipType(relationshipType.toString());
    }

}


QContactRelationship QDeclarativeContactRelationship::relationship() const
{
    return m_relationship;
}
void QDeclarativeContactRelationship::setRelationship(const QContactRelationship& relationship)
{
    m_relationship = relationship;
    emit valueChanged();
}

#include "moc_qdeclarativecontactrelationship_p.cpp"

QTCONTACTS_END_NAMESPACE
