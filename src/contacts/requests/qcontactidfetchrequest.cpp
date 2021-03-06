/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtContacts module of the Qt Toolkit.
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

#include "qcontactidfetchrequest.h"

#include "qcontactrequests_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
  \class QContactIdFetchRequest
  \brief The QContactIdFetchRequest class allows a client to asynchronously
    request a list of contact ids from a contacts store manager.


  For a QContactIdFetchRequest, the resultsAvailable() signal will be emitted when the resultant
  contact ids (which may be retrieved by calling ids()), are updated, as well as if
  the overall operation error (which may be retrieved by calling error()) is updated.

  Please see the class documentation of QContactAbstractRequest for more information about
  the usage of request classes and ownership semantics.


  \inmodule QtContacts

  \ingroup contacts-requests
 */

/*! Constructs a new contact id fetch request whose parent is the specified \a parent */
QContactIdFetchRequest::QContactIdFetchRequest(QObject* parent)
    : QContactAbstractRequest(new QContactIdFetchRequestPrivate, parent)
{
}

/*! Frees any memory used by this request */
QContactIdFetchRequest::~QContactIdFetchRequest()
{
}

/*! Sets the filter which will be used to select the contacts whose ids will be returned to \a filter
*/
void QContactIdFetchRequest::setFilter(const QContactFilter& filter)
{
    Q_D(QContactIdFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_filter = filter;
}

/*! Sets the future sort ordering of the result of the request to \a sorting.  This function only has
    effect on the result if called prior to calling \c start()
*/
void QContactIdFetchRequest::setSorting(const QList<QContactSortOrder>& sorting)
{
    Q_D(QContactIdFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_sorting = sorting;
}

/*! Returns the filter which will be used to select the contacts whose ids will be returned
*/
QContactFilter QContactIdFetchRequest::filter() const
{
    Q_D(const QContactIdFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_filter;
}

/*! Returns the sort ordering which will be used to sort the result
*/
QList<QContactSortOrder> QContactIdFetchRequest::sorting() const
{
    Q_D(const QContactIdFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_sorting;
}

/*! Returns the list of ids of contacts which matched the request
*/
QList<QContactId> QContactIdFetchRequest::ids() const
{
    Q_D(const QContactIdFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_ids;
}

#include "moc_qcontactidfetchrequest.cpp"

QT_END_NAMESPACE_CONTACTS
