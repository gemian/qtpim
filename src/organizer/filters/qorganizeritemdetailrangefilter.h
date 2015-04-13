/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtOrganizer module of the Qt Toolkit.
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

#ifndef QORGANIZERITEMDETAILRANGEFILTER_H
#define QORGANIZERITEMDETAILRANGEFILTER_H

#include <QtOrganizer/qorganizeritemdetail.h>
#include <QtOrganizer/qorganizeritemfilter.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemDetailRangeFilterPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemDetailRangeFilter : public QOrganizerItemFilter
{
public:
    QOrganizerItemDetailRangeFilter();
    QOrganizerItemDetailRangeFilter(const QOrganizerItemFilter &other);

    enum RangeFlag {
        IncludeLower = 0,
        IncludeUpper = 1,
        ExcludeLower = 2,
        ExcludeUpper = 0
    };
    Q_DECLARE_FLAGS(RangeFlags, RangeFlag)

    void setDetail(QOrganizerItemDetail::DetailType detailType, int field = -1);
    QOrganizerItemDetail::DetailType detailType() const;
    int detailField() const;

    void setMatchFlags(QOrganizerItemFilter::MatchFlags flags);
    QOrganizerItemFilter::MatchFlags matchFlags() const;

    void setRange(const QVariant &min, const QVariant &max, RangeFlags flags = 0);
    QVariant minValue() const;
    QVariant maxValue() const;
    RangeFlags rangeFlags() const;

private:
    Q_DECLARE_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemDetailRangeFilter)
};
Q_DECLARE_OPERATORS_FOR_FLAGS(QOrganizerItemDetailRangeFilter::RangeFlags)

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMDETAILRANGEFILTER_H
