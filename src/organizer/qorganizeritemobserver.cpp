/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtOrganizer module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qorganizeritemobserver.h"

#include <QtCore/qpointer.h>

#include "qorganizermanager.h"
#include "qorganizermanager_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemObserverPrivate
{
public:
    QOrganizerItemId m_id;
    QPointer<QOrganizerManager> m_manager;
    QOrganizerManagerData *m_managerPrivate;
};

/*!
    \class QOrganizerItemObserver
    \brief The QOrganizerItemObserver class is a simple class that emits a signal when a single
           particular item is updated or deleted.
    \inmodule QtOrganizer
    \ingroup organizer-main
 */

/*!
    Constructs a QOrganizerItemObserver to observe the item in \a manager with the given \a itemId
    and a \a parent object.
 */
QOrganizerItemObserver::QOrganizerItemObserver(QOrganizerManager *manager, const QOrganizerItemId &itemId, QObject *parent)
    : QObject(parent), d(new QOrganizerItemObserverPrivate)
{
    d->m_id = itemId;
    d->m_manager = manager;
    d->m_managerPrivate = QOrganizerManagerData::get(manager);
    d->m_managerPrivate->registerObserver(this);
}

/*!
    Destroys this observer.
 */
QOrganizerItemObserver::~QOrganizerItemObserver()
{
    if (d->m_manager.data())
        d->m_managerPrivate->unregisterObserver(this);
    delete d;
}

/*!
    Returns the ID of the item that this object observes.
 */
QOrganizerItemId QOrganizerItemObserver::itemId() const
{
    return d->m_id;
}

/*!
    \fn void QOrganizerItemObserver::itemChanged(const QList<QOrganizerItemDetail::DetailType> &typesChanged)

    This signal is emitted when the observed item is changed in the manager.

    The set of item detail types modified in the reported change is a subset of those listed in \a typesChanged,
    unless \a typesChanged is empty, in which case no limitation on the reported changes may be assumed.
 */

/*!
    \fn void QOrganizerItemObserver::itemRemoved()

    This signal is emitted when the observed item is removed from the manager.
 */

#include "moc_qorganizeritemobserver.cpp"

QT_END_NAMESPACE_ORGANIZER
