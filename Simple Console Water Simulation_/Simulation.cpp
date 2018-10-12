#include "Simulation.h"
#include "Array1DThatIsActually2D.h"
#include <cstdlib>
#include "UsefulConstants.h"

void advanceSimulation(short*& state, int gridSizeX, int gridSizeY)
{
	short* nextState = new short[gridSizeX * gridSizeY];
	for (int i = 0; i < gridSizeX * gridSizeY; i++)
		nextState[i] = state[i];

	for (int y = 0; y < gridSizeY; y++)
	{
		for (int x = 0; x < gridSizeX; x++)
		{
			short level = getElementIn1DArray(state, x, y, gridSizeX);
			if (level > 0)
			{
				short upL = getElementIn1DArray(state, x, y - 1, gridSizeX);
				short downL = getElementIn1DArray(state, x, y + 1, gridSizeX);

				if (level > waterMaxOnTile && upL != -1 && upL < level)
				{
					addToElementIn1DArray(nextState, x, y - 1, gridSizeX, (short)1);
					addToElementIn1DArray(nextState, x, y, gridSizeX, (short)-1);
				}
				else if (downL != -1 && downL < waterMaxOnTile)
				{
					addToElementIn1DArray(nextState, x, y + 1, gridSizeX, (short)1);
					addToElementIn1DArray(nextState, x, y, gridSizeX, (short)-1);
				}
				else
				{
					short leftL = getElementIn1DArray(state, x - 1, y, gridSizeX);
					short rightL = getElementIn1DArray(state, x + 1, y, gridSizeX);

					bool canFlowRight = (rightL != -1) && (rightL < level);
					bool canFlowLeft = (leftL != -1) && (leftL < level);

					if (level >= 2 && canFlowRight && canFlowLeft)
					{
						//flow left
						addToElementIn1DArray(nextState, x - 1, y, gridSizeX, (short)1);
						addToElementIn1DArray(nextState, x, y, gridSizeX, (short)-1);

						//flow right
						addToElementIn1DArray(nextState, x + 1, y, gridSizeX, (short)1);
						addToElementIn1DArray(nextState, x, y, gridSizeX, (short)-1);
					}
					else
					{
						int randDir = std::rand() % 2 ? 1 : -1;

						short sideL = randDir == -1 ? leftL : rightL;
						short otherSideL = randDir == -1 ? rightL : leftL;

						bool canFlowSide = (sideL != -1) && (sideL < level);
						bool canFlowOtherSide = (otherSideL != -1) && (otherSideL < level);

						if (canFlowSide)
						{
							addToElementIn1DArray(nextState, x + randDir, y, gridSizeX, (short)1);
							addToElementIn1DArray(nextState, x, y, gridSizeX, (short)-1);
						}
						else if (canFlowOtherSide)
						{
							addToElementIn1DArray(nextState, x - randDir, y, gridSizeX, (short)1);
							addToElementIn1DArray(nextState, x, y, gridSizeX, (short)-1);
						}
					}
				}
			}
		}
	}

	delete[] state;
	state = nextState;
}
