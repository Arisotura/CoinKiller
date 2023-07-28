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

#ifndef LEVELEDITORWINDOW_H
#define LEVELEDITORWINDOW_H

#include <QListView>
#include <QComboBox>
#include <QDockWidget>
#include <QUndoStack>
#include <QUndoView>

#include "filesystem.h"
#include "levelview.h"
#include "levelminimap.h"
#include "ctpk.h"
#include "levelmanager.h"
#include "areaeditorwidget.h"
#include "tilesetpalette.h"
#include "spriteeditorwidget.h"
#include "entranceeditorwidget.h"
#include "zoneeditorwidget.h"
#include "locationeditorwidget.h"
#include "patheditorwidget.h"
#include "progresspatheditorwidget.h"
#include "spriteidswidget.h"
#include "eventeditorwidget.h"
#include "settingsmanager.h"
#include "windowbase.h"
#include "layermask.h"

namespace Ui {
class LevelEditorWindow;
}

class LevelEditorWindow : public WindowBase
{

    Q_OBJECT

public:
    explicit LevelEditorWindow(LevelManager* lvlMgr, int initialArea);
    ~LevelEditorWindow();
    void closeEvent(QCloseEvent *event);

#ifdef USE_KDE_BLUR
protected:
    void paintEvent(QPaintEvent* evt) override;
#endif

public slots:
    void handleSelectionChanged(Object* obj);
    void deselect();
    void updateEditors();
    void scrollTo(int x, int y);
    void handleEditMade();

private slots:
    void toggleLayer(bool toggle);

    void toggleSprites(bool toggle);

    void toggleEntrances(bool toggle);

    void togglePaths(bool toggle);

    void toggleLocations(bool toggle);

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionZoom_100_triggered();

    void on_actionZoom_Maximum_triggered();

    void on_actionZoom_Minimum_triggered();

    void on_actionSave_triggered();

    void on_actionCopy_triggered();

    void on_actionFullscreen_toggled(bool arg1);

    void on_actionGrid_toggled(bool arg1);

    void on_actionCheckerboard_toggled(bool arg1);

    void on_actionRenderLiquids_toggled(bool arg1);

    void on_actionRenderCameraLimits_toggled(bool arg1);

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionDelete_triggered();

    void setSelSprite(int spriteId);

    void toolboxTabsCurrentChanged(int index);

    void on_actionAddArea_triggered();

    void on_actionDeleteCurrentArea_triggered();

    void on_actionRaise_triggered();

    void on_actionLower_triggered();

    void on_actionRaiseLayer_triggered();

    void on_actionLowerLayer_triggered();

    void handleAreaIndexChange(int index);

    void handleMgrUpdate();

    void on_actionSelectAll_triggered();

    void on_actionSetBackgroundColor_triggered();

    void on_actionResetBackgroundColor_triggered();

    void on_actionSelectAfterPlacement_toggled(bool arg1);

    void on_actionHideStatusbar_toggled(bool hide);

    void on_actionShowMinimap_toggled(bool checked);

    void on_actionShowToolbox_toggled(bool checked);

    void on_actionShowHistory_toggled(bool checked);

    void updateDockedWidgetCheckboxes();

    void on_actionToggle3DOverlay_toggled(bool arg1);

    void on_actionToggle2DTile_toggled(bool arg1);

    void historyStateChanged(int index);

private:
    Ui::LevelEditorWindow *ui;

    LevelManager* lvlMgr;
    SettingsManager* settings;

    Level* level;
    Tileset* tileset;
    LevelView* levelView;
    LevelMiniMap* miniMap;

    AreaEditorWidget* areaEditor;
    TilesetPalette* tilesetPalette;
    SpriteEditorWidget* spriteEditor;
    EntranceEditorWidget* entranceEditor;
    ZoneEditorWidget* zoneEditor;
    LocationEditorWidget* locationEditor;
    PathEditorWidget* pathEditor;
    ProgressPathEditorWidget* progPathEditor;
    SpriteIdWidget* spriteIds;
    EventEditorWidget* eventEditor;

    QComboBox* areaSelector;

    QLabel* editStatus;

    void changeEvent(QEvent* event);

    void updateAreaSelector(int index = -1);

//    quint8 layerMask;
    float zoom;

    void loadArea(int id, bool closeLevel = true, bool init = false);
    bool closeLvlOnClose = true;

    bool unsavedChanges = false;

#ifdef USE_KDE_BLUR
    void setBlurStylesheet();
#endif

    QDockWidget* toolboxDock;
    QTabWidget* toolboxTabs;

    QDockWidget* minimapDock;
    QDockWidget* historyDock;

    QUndoStack* undoStack;
    QUndoView* undoView;

    QAction* actionUndo;
    QAction* actionRedo;

    int prevHistoryIndex = 0;
};

#endif // LEVELEDITORWINDOW_H
