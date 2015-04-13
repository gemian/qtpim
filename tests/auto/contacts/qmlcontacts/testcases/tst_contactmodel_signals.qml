/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtPim module of the Qt Toolkit.
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

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

ContactsSignalingTestCase {
    name: "ContactModelSignalsTests"
    id: contactModelSignalsTests

    // This test case is a unit test for contact model
    // so it does not require updates to contacts.
    ContactModel {
        id: model
        autoUpdate: false
    }

    IdFilter {
        id: filter
        ids: []
    }

    function test_settingTheFilterSendsSignal() {
        listenToSignalFromObject("filterChanged", model)
        model.filter = filter;
        verifySignalReceived();
    }

    IdFilter {
        id: oldFilter
        ids: []
    }

    IdFilter {
        id: newFilter
        ids: []
    }

    function test_changingTheFilterSendsSignal() {
        model.filter = oldFilter;

        listenToSignalFromObject("filterChanged", model)
        model.filter = newFilter;
        verifySignalReceived();
    }

    IdFilter {
        id: nonNullFilter
        ids: []
    }

    function test_removingTheFilterSendsSignal() {
        model.filter = nonNullFilter;

        listenToSignalFromObject("filterChanged", model)
        model.filter = null;
        verifySignalReceived();
    }

    IdFilter {
        id: theSameFilter
        ids: []
    }

    function test_settingTheSameFilterDoesNotSendSignal() {
        model.filter = theSameFilter;

        listenToSignalFromObject("filterChanged", model)
        model.filter = theSameFilter;
        verifyNoSignalReceived();
    }

    function init() {
        initSignalingTest();
    }
}
