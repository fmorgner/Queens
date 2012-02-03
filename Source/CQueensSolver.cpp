/*
 * QueensSolver.cpp
 * -------------------------------------------------------------------------
 * begin                 : 2012-02-03
 * copyright             : Copyright (C) 2012 by Felix Morgner
 * email                 : felix.morgner@gmail.com
 * =========================================================================
 *                                                                         |
 *   This program is free software; you can redistribute it and/or modify  |
 *   it under the terms of the GNU General Public License as published by  |
 *   the Free Software Foundation; either version 3 of the License, or     |
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
 * Interface implementation for the CQueensSolver class. Objects of this
 * class can be used to solve the so calles "N Queens Problem". The problem
 * is to place N queens on a chessboard so that no 2 queens attack each
 * other.
 *
 */

#include <iostream>
#include "CQueensSolver.h"

CQueensSolver::CQueensSolver(int nWidth, int nHeight, int nNumQueens)
	{
	m_nWidth = nWidth;
	m_nHeight = nHeight;
	m_nNumQueens = nNumQueens;
	}

CQueensSolver::CQueensSolver()
	{
	m_nWidth = 0;
	m_nHeight = 0;
	m_nNumQueens = 0;
	}

CQueensSolver::~CQueensSolver()
	{
	}

bool CQueensSolver::Solve()
	{
	if (!m_nHeight && !m_nWidth && !m_nNumQueens)
		{
		return false;
		}
	
	if(m_nNumQueens > m_nWidth || m_nNumQueens > m_nHeight)
		{
		return false;
		}
	
	for(int nHeight = 0; nHeight < m_nHeight; nHeight++)
		{
		std::vector<bool> vColumn;
		
		for(int nWidth = 0; nWidth < m_nWidth; nWidth++)
			{
			vColumn.push_back(false);
			}
		
		m_vGrid.push_back(vColumn);
		}

	return Solve(0);
	}

bool CQueensSolver::Solve(int nQueenIndex)
	{
	if(nQueenIndex == m_vGrid.size() || nQueenIndex == m_nNumQueens)
		{
		return true;
		}
	for(int nCurrentRow = 0; nCurrentRow < m_vGrid[nQueenIndex].size(); nCurrentRow++)
		{
		if(IsSafe(nCurrentRow, nQueenIndex))
			{
			PlaceQueen(nCurrentRow, nQueenIndex);
			if(Solve(nQueenIndex+1))
				{
				return true;
				}
			RemoveQueen(nCurrentRow, nQueenIndex);
			}
		}
	
	return false;
	}

bool CQueensSolver::IsSafe(int nRow, int nColumn)
	{
	if(nColumn <= m_vGrid.size() && nColumn >= 0)
		{
		std::vector<bool> vColumn = m_vGrid.at(nColumn);

		if(nRow <= vColumn.size() && nRow >= 0)
			{
			if(nColumn == 0)
				{
				return !vColumn[nRow];
				}
			else
				{
				for(int nColumnIndex = nColumn - 1; nColumnIndex >= 0; nColumnIndex--)
					{
					std::vector<bool> vBlockColumn = m_vGrid[nColumnIndex];
					
					int nUpwardDiagonal = nRow + nColumn - nColumnIndex;
					int nDownwardDiagonal = nRow - nColumn + nColumnIndex;
					
					if(vBlockColumn[nRow])
						{
						return false;
						}
					else if(nUpwardDiagonal >= 0 && nUpwardDiagonal <= vBlockColumn.size() && vBlockColumn[nUpwardDiagonal])
						{
						return false;
						}
					else if(nDownwardDiagonal >= 0 && nDownwardDiagonal <= vBlockColumn.size() && vBlockColumn[nDownwardDiagonal])
						{
						return false;
						}
					}
				}
			}
		}
	return true;
	}
	
void CQueensSolver::PlaceQueen(int nRow, int nColumn)
	{
  m_vGrid[nColumn][nRow] = true;
	}
	
void CQueensSolver::RemoveQueen(int nRow, int nColumn)
	{
  m_vGrid[nColumn][nRow] = false;
	}
