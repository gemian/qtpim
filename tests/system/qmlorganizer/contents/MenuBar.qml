/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Mobility Components.
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

Rectangle {
    id: menuBar;

    property string info;
    BorderImage { source: "images/titlebar.sci"; width: parent.width; height: parent.height + 14; y: -7 }
    gradient: Gradient {
        GradientStop { position: 0.0; color: activePalette.dark }
        GradientStop { position: 1.0; color: Qt.darker(activePalette.dark); }
    }
    Row {
        spacing: 0
        Image {
            id: quitButton
            height: monthButton.height
            width:height
            source: "images/quit.png"
            MouseArea {
                anchors.fill: parent
                onClicked: Qt.quit()
            }
        }

        Button { id: dayButton; text: "Day";onClicked: calendar.state="DayView";}
        Button { id: weekButton; text: "Week";onClicked: calendar.state="WeekView";}
        Button { id: monthButton; text: "Month"; onClicked: calendar.state="MonthView";}
        Button { id: timelineButton; text: "Timeline";onClicked: calendar.state="TimelineView";}
        Button { id: todoButton; text: "Todos";onClicked: calendar.state="TodoView"; }
        Button { id: settingsButton; text: "Settings";onClicked: calendar.state="SettingsView";}

        Text { color: "#f5f210";text:info ; font.bold: true; verticalAlignment: Text.AlignVCenter; style: Text.Sunken;font.pointSize: 6}
    }
}

