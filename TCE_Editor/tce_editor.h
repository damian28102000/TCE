#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>

#include "projectsettings.h"
#include "tile.h"
#include "graphics_scene.h"
#include "ui_tce_editor.h"

class TCE_Editor : public QMainWindow
{
    Q_OBJECT

public:
    TCE_Editor(QWidget *parent = Q_NULLPTR);

private:
    Ui::TCE_EditorClass ui;
    QMenuBar* menu;
    QMenu* helpMenu;

    QAction* aboutAct;
    QAction* helpAct;
    QAction* projSet;
    QAction* exportAct;

    QLabel* currentX;
    QLabel* currentY;
    QLabel* info;
    QComboBox* color;

    QVBoxLayout* mainLayout;
    QHBoxLayout* currentLayout;
    QHBoxLayout* changeLayout;

    QGraphicsView* view;
    GraphicsScene* scene;


    void createMenus();
    void createActions();

protected:
    void aboutMessage();
    void errorMessage();
    void helpMessage();
    void exportWorld();
    void createLayout();
    void projectSettings();
    void createWorld(unsigned int);
    void changeWorld(unsigned int);

};
