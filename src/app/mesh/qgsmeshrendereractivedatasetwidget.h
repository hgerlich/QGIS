/***************************************************************************
    qgsmeshrendereractivedatasetwidget.h
    -------------------------------------
    begin                : June 2018
    copyright            : (C) 2018 by Peter Petrik
    email                : zilolv at gmail dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSMESHRENDERERACTIVEDATASETWIDGET_H
#define QGSMESHRENDERERACTIVEDATASETWIDGET_H

#include "ui_qgsmeshrendereractivedatasetwidgetbase.h"
#include "qgis_app.h"

#include <QWidget>

class QgsMeshLayer;

/**
 * Widget for selection of active dataset group from tree view.
 * Also selects the active scalar and vector dataset by slider
 *
 * At the moment, it is not possible to select different vector and
 * scalar dataset
 */
class APP_EXPORT QgsMeshRendererActiveDatasetWidget : public QWidget, private Ui::QgsMeshRendererActiveDatasetWidgetBase
{
    Q_OBJECT

  public:

    /**
     * A widget to hold the renderer scalar settings for a mesh layer.
     * \param parent Parent object
     */
    QgsMeshRendererActiveDatasetWidget( QWidget *parent = nullptr );
    ~QgsMeshRendererActiveDatasetWidget() = default;

    //! Associates mesh layer with the widget
    void setLayer( QgsMeshLayer *layer );

    //! Gets index of the selected/active scalar dataset
    int activeScalarDataset() const;

    //! Gets index of the selected/active vector dataset
    int activeVectorDataset() const;

    //! Synchronizes widgets state with associated mesh layer
    void syncToLayer();

  signals:

    //! Emitted when active scalar dataset changed
    void activeScalarDatasetChanged( int index );

    //! Emitted when active vector dataset changed
    void activeVectorDatasetChanged( int index );

    //! Emitted when any settings related to rendering changed
    void widgetChanged();

  private slots:
    void onActiveGroupChanged();
    void onActiveDatasetChanged( int value );
    void updateMetadata( int datasetIndex );

  private:
    int datasetIndex() const;

    QgsMeshLayer *mMeshLayer = nullptr; // not owned
    int mActiveScalarDataset = -1;
    int mActiveVectorDataset = -1;
};

#endif // QGSMESHRENDERERSCALARSETTINGSWIDGET_H
