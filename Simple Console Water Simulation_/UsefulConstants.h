#pragma once
#include <time.h>

constexpr int gridSizeX = 110, gridSizeY = 27;

constexpr double clockTicksToSeconds = 1. / CLOCKS_PER_SEC;
constexpr double clockTicksToMs = clockTicksToSeconds * 1000;

// 0 - unrestricted
constexpr int renderStepsPerSecond = 4;
constexpr int simulationStepsPerSecond = 20;

constexpr double msPerRenderStep = (1. / (renderStepsPerSecond + 1))*1000.;
constexpr double msPerSimulationStep = (1. / simulationStepsPerSecond)*1000.;

constexpr int waterLevels = 10;
constexpr int waterMaxOnTile = 7;

constexpr bool fillWithRandomValues = true;