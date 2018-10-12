#pragma once

template<typename T>
void setElementIn1DArray(T array[], int x, int y, int maxX, T value)
{
	array[maxX * y + x] = value;
}

template<typename T>
void addToElementIn1DArray(T array[], int x, int y, int maxX, T value)
{
	array[maxX * y + x] += value;
}

template<typename T>
T getElementIn1DArray(const T array[], int x, int y, int maxX)
{
	return array[maxX * y + x];
}

template<typename T>
T& getReferenceToElementIn1DArray(T array[], int x, int y, int maxX)
{
	return array[maxX * y + x];
}

bool isBorder(int x, int y, int maxX, int maxY);

void indexToXY(int i, int &x, int &y, int maxX);