void findNQueens(vector<vector<string>>&res, vector<string>&r, vector<int>&colUsed, vector<int>&Incline1, vector<int>&Incline2, int row)
{
	int len = r.size();
	if (row == len)
	{
		res.push_back(r);
		return;
	}
	for (int col = 0;col < len; col++)
	{
		if (colUsed[col] == 0 && Incline1[row - col + len - 1] == 0 && Incline2[row + col] == 0)
		{
			colUsed[col] = 1;
			Incline1[row - col + len - 1] = 1; 
			Incline2[row + col] = 1;
			r[row][col] = 'Q';
			findNQueens(res, r, colUsed, Incline1, Incline2, row + 1);
			colUsed[col] = 0;
			Incline1[row - col + len - 1] = 0;
			Incline2[row + col] = 0;
			r[row][col] = '.';
		}
			
	}

	
}
vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>>res;
	if (n == 0)
		return res;
	vector<int>colUsed(n, 0);
	vector<int>Incline1(2 * n - 1, 0);
	vector<int>Incline2(2 * n - 1, 0);
		vector<string>r(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			r[i].push_back('.');
	}
	findNQueens(res, r, colUsed, Incline1, Incline2, 0);
	return res;	
}
