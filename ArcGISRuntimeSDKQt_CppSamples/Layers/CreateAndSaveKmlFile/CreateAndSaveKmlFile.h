// [WriteFile Name=CreateAndSaveKmlFile, Category=Layers]
// [Legal]
// Copyright 2019 Esri.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// [Legal]

#ifndef CREATEANDSAVEKMLFILE_H
#define CREATEANDSAVEKMLFILE_H

namespace Esri
{
namespace ArcGISRuntime
{
class Map;
class MapQuickView;
class KmlDocument;
class GraphicsOverlay;
class Point;
class Polyline;
class Polygon;
}
}

#include <QObject>
#include <QUrl>
#include "Geometry.h"

class CreateAndSaveKmlFile : public QObject
{
  Q_OBJECT

  Q_PROPERTY(Esri::ArcGISRuntime::MapQuickView* mapView READ mapView WRITE setMapView NOTIFY mapViewChanged)
  Q_PROPERTY(bool busy MEMBER m_busy NOTIFY busyChanged)

public:
  explicit CreateAndSaveKmlFile(QObject* parent = nullptr);
  ~CreateAndSaveKmlFile();

  static void init();

  Q_INVOKABLE void saveKml(QUrl url);

signals:
  void mapViewChanged();
  void busyChanged();

private:
  Esri::ArcGISRuntime::MapQuickView* mapView() const;
  void setMapView(Esri::ArcGISRuntime::MapQuickView* mapView);

  Esri::ArcGISRuntime::Map* m_map = nullptr;
  Esri::ArcGISRuntime::MapQuickView* m_mapView = nullptr;
  Esri::ArcGISRuntime::KmlDocument* m_kmlDocument = nullptr;
  Esri::ArcGISRuntime::GraphicsOverlay* m_graphicsOverlay = nullptr;
  Esri::ArcGISRuntime::Point* m_point = nullptr;
  Esri::ArcGISRuntime::Polyline* m_polyline = nullptr;
  Esri::ArcGISRuntime::Polygon* m_polygon = nullptr;

  bool m_busy = false;

  Esri::ArcGISRuntime::Geometry createPoint() const;
  Esri::ArcGISRuntime::Geometry createPolyline() const;
  Esri::ArcGISRuntime::Geometry createPolygon() const;
  Esri::ArcGISRuntime::Geometry createEnvelope() const;

  void addGraphics();
  void addToKmlDocument(const Esri::ArcGISRuntime::Geometry &geometry);

};

#endif // CREATEANDSAVEKMLFILE_H
