/*
 * main.cpp
 * -------------------------------------------------------------------------
 * begin                 : 2012-02-03
 * copyright             : Copyright (C) 2012 by Felix Morgner
 * email                 : felix.morgner@gmail.com
 * =========================================================================
 *                                                                         |
 *   This program is free software; you can redistribute it and/or modify  |
 *   it under the terms of the GNU General Public License as published by  |
 *   the Free Software Foundation; either version 2 of the License, or     |
 *   (at your option) any later version.                                   |
 *                                                                         |
 *   This program is distributed in the hope that it will be useful,       |
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        |
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         |
 *   GNU General Public License for more details.                          |
 *                                                                         |
 *   You should have received a copy of the GNU General Public License     |
 *   along with this program; if not, write to the                         |
 *                                                                         |
 *   Free Software Foundation, Inc.,                                       |
 *   59 Temple Place Suite 330,                                            |
 *   Boston, MA  02111-1307, USA.                                          |
 * =========================================================================
 *
 * This is a demo application for the CQueensSolver class.
 *
 * Usage:
 *
 *   Run with default values (all 8):
 *     Queens
 *  
 *   Run with specified number of queens (asumes same number of columns and rows):
 *     Queens [queen_count]
 *  
 *   Run with specified number of queens and columns (asumes same number of rows as columns):
 *     Queens [queen_count] [column_count]
 *  
 *   Run with specified number of queens, columns and rows:
 *     Queens [queen_count] [column_count] [row_count]
 *  
 *
 */

#include <iostream>
#include "CQueensSolver.h"

using namespace std;

CQueensSolver goSolver = CQueensSolver();

void PrintGrid();

int main (int argc, const char * argv[])
	{	
	int nNumQueens = 0;
	int nWidth = 0;
	int nHeight = 0;
	
	switch (argc)
		{
  	case 2:
			nNumQueens = atoi(argv[1]);
			nWidth = atoi(argv[1]);
			nHeight = atoi(argv[1]);
    	break;
			
		case 3:
			nNumQueens = atoi(argv[1]);
			nWidth = atoi(argv[2]);
			nHeight = atoi(argv[2]);
			break;

		case 4:
			nNumQueens = atoi(argv[1]);
			nWidth = atoi(argv[2]);
			nHeight = atoi(argv[3]);
			break;

  	default:
			nNumQueens = 8;
			nWidth = 8;
			nHeight = 8;
    	break;
		}	

	goSolver.SetWidth(nWidth);
	goSolver.SetHeight(nHeight);
	goSolver.SetNumQueens(nNumQueens);
	
	if(goSolver.Solve())
		{
		PrintGrid();
		}
	else
		{
		cout << "The grid could not be solved." << endl;
		}
		
  return 0;
	}
	
void PrintGrid()
	{
	grid_t vGrid = goSolver.GetGrid();
	column_t vColumn = vGrid.front();
	
	for(int nColumn = 0; nColumn < vGrid.size(); nColumn++)
		{
		for(int nRow = 0; nRow < vColumn.size(); nRow++)
		  {
			if(vGrid[nColumn][nRow])
				{
				cout << "Q ";
				}
			else
				{
				cout << "• ";
				}
			}
		cout << endl;
		}
	}
