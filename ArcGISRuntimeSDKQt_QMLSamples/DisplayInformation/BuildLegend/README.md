# Build a legend

This sample demonstrates how to build a legend for all the operational layers in the map.

![](screenshot.png)

## How it works
The sample utilizes the `autoFetchLegendInfos` property on the Map. This property will cause the map to recursively loop through all of the operational layers in the map (including sublayers), and request the `LegendInfo` for each item. All of the resulting LegendInfo objects are passed into the LegendInfoListModel. A QML ListView directly consumes this model, and separates each item by using a `section`.

## Features
- MapView
- Map
- Basemap
- ArcGISMapImageLayer
- ArcGISSublayerListModel
- ArcGISTiledLayer
- FeatureLayer
- ServiceFeatureTable
- LegendInfo
