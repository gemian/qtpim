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

#include "qcontactmanagerenginefactory.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
  \class QContactManagerEngineFactory
  \brief The QContactManagerEngineFactory class provides the interface for
 plugins that implement QContactManagerEngine functionality.

  \inmodule QtContacts

  \ingroup contacts-backends

  This class provides a simple interface for the creation of
  manager engine instances.  Each factory has a specific id
  associated with it, which forms the \c managerName parameter
  when creating \l QContactManager objects.

  More information on writing a contacts engine plugin is available in
  the \l{Qt Contacts Manager Engines} documentation.

  \sa QContactManager, QContactManagerEngine
 */

/*!
  A default, empty destructor.
 */
QContactManagerEngineFactory::~QContactManagerEngineFactory()
{
}

/*!
  \internal
 */
QStringList QContactManagerEngineFactory::keys() const
{
    return QStringList() << managerName();
}

/*!
  \fn QContactManagerEngineFactory::engine(const QMap<QString, QString>& parameters, QContactManager::Error* error)

  This function is called by the QContactManager implementation to
  create an instance of the engine provided by this factory.

  The \a parameters supplied can be ignored or interpreted as desired.

  If a supplied parameter results in an unfulfillable request, or some other error
  occurs, this function may return a null pointer, and the client developer will get an
  invalid QContactManager in return.  Any error should be stored in the supplied \a error
  reference.
 */

/*!
  \fn QContactManagerEngineFactory::managerName() const

  This function should return a unique string that identifies
  the engines provided by this factory.

  Typically this would be of the form "org.qt-project.Qt.SampleContactEngine", with
  the appropriate domain and engine name substituted.
 */

/*!
  \fn QContactManagerEngineFactory::supportedImplementationVersions() const

  This function should return a list of versions of the engine which this factory can instantiate.
 */
QList<int> QContactManagerEngineFactory::supportedImplementationVersions() const
{
    return QList<int>();
}

#include "moc_qcontactmanagerenginefactory.cpp"

QT_END_NAMESPACE_CONTACTS
