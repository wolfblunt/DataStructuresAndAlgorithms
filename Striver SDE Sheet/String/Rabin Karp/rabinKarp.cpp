// Rabin-Karp Algorithm

int mod = 1e6;
void rabinKarp(string source, string target, vector<int> &ans)
{
	if(source == "" || target == "")
	{
		return;
	}

	int m = target.size();
	int power = 1;
	int targetCode = 0;
	for(int i=0;i<m;i++)
	{
		power = (power*31) % mod;
		targetCode = (targetCode*31 + target[i]) % mod;
	}

	int hashCode = 0;
	int n = source.size();
	for(int i=0;i<n;i++)
	{
		hashCode = (hashCode*31 + source[i]) % mod;
		if(i<m-1)
		{
			continue;
		}
		if(i>=m)
		{
			hashCode = (hashCode - source[i-m]*power) % mod; 
		}

		if(hashCode < 0)
		{
			hashCode += mod;
		}

		if(hashCode == targetCode)
		{
			if(source.substr(i-m+1, m) == target)
			{
				ans.push_back(i-m+2);
			}
		}
	}

}

vector<int> stringMatch(string text, string pattern) {
	vector<int> ans;
	rabinKarp(text, pattern, ans);
	return ans;
}