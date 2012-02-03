/*
 * QueensSolver.h
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
 * Interface declaration for the CQueensSolver class. Objects of this class
 * can be used to solve the so calles "N Queens Problem". The problem is to
 * place N queens on a chessboard so that no 2 queens attack each other.
 *
 */

#ifndef Queens_Solver_h
#define Queens_Solver_h

#import <vector>

typedef std::vector<std::vector<bool> > grid_t;
typedef std::vector<bool> column_t;

class CQueensSolver
	{
	public:
		CQueensSolver();
  	CQueensSolver(int nWidth, int nHeight, int nNumQueens);
		~CQueensSolver();
		
		void SetWidth(int nNewWidth) { m_nWidth = nNewWidth; }
		int  GetWidth() { return m_nWidth; }
		
		void SetHeight(int nNewHeight) { m_nHeight = nNewHeight; }
		int  GetHeight() { return m_nHeight; }
		
		void SetNumQueens(int nNewNumQueens) { m_nNumQueens = nNewNumQueens; }
		int  GetNumQueens() { return m_nNumQueens; }
		
		std::vector<std::vector<bool> > GetGrid() { return m_vGrid; }
	
		bool Solve();
	
	protected:
		bool Solve(int nQueenIndex);
		bool IsSafe(int nRow, int nColumn);

		void PlaceQueen(int nRow, int nColumn);
		void RemoveQueen(int nRow, int nColumn);
		
	protected:
		int m_nWidth;
		int m_nHeight;
		int m_nNumQueens;
		
		std::vector<std::vector<bool> > m_vGrid; 
	};

#endif
