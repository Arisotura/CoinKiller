/*
    Copyright 2015 StapleButter

    This file is part of CoinKiller.

    CoinKiller is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    CoinKiller is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along
    with CoinKiller. If not, see http://www.gnu.org/licenses/.
*/

#ifndef LEVELVIEW_H
#define LEVELVIEW_H

#include <QWidget>
#include <QLayout>
#include <QList>

#include "filesystem.h"

class LevelView : public QWidget
{
    Q_OBJECT
public:
    explicit LevelView(QWidget *parent, SarcFilesystem* level);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    SarcFilesystem* levelArchive;
    QImage* imgtest; // REMOVE ME!!!


    // MOVE THIS SHIT ELSEWHERE!!!!! TEST!!!
    struct BgdatObject
    {
        quint16 id;
        quint16 x, y; // [RoadrunnerWMC] signed position??? needs investigation
        quint16 width, height;

        // extra crap, but it's all zeroes
    };

    QList<BgdatObject> objects;
};

#endif // LEVELVIEW_H