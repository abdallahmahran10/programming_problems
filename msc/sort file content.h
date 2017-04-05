
#include "../common.h" 
class RowData
{
private:
	vector<string> row;
public:
	string mRowDataStr;
	RowData(string rowDataStr)
	{
		mRowDataStr = rowDataStr;
		istringstream ss(mRowDataStr);
		while (ss)
		{
		  string s;
		  if (!getline( ss, s, ',' )) break;
		  row.push_back( s );
		}
	}
	bool operator<(const RowData &rhs) const { return row[1] < rhs.row[1]; }
};

void sortFileContent()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif

	// Implementation
	vector <RowData> rows;
	string line;
	while(true)
	{
		if(!getline(cin, line))
			break;
		if(!line.length())
			continue;
		RowData rd(line);
		rows.push_back(rd);
	}
	std::sort(rows.begin(), rows.end());
	F(rows.size())
	{
		PRINT_STR(rows[i].mRowDataStr);
	}
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
}

void testCase0()
{
	sortFileContent();
}