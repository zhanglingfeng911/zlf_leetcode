//
// Created by zlf on 2021/3/31.
//
#include<iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

long long gcd(long long m, long long n) {
    return n == 0 ? m : gcd(n, m % n);

}

#include <stdio.h>

inline long long max(long long a, long long b) { return (a > b ? a : b); }

inline long long min(long long a, long long b) { return (a > b ? b : a); }
//定义fm[k][i]表示当选中了k个学生，并且以第i个学生为结尾，所产生的最大乘积；
/*因为有正有负，负负得正，所以要维护两个dp数组，一个存储最大，一个存储最小。
 * 那么fm[k+1][i+1]=max(fm[k][i]*stu[i+1],fn[k][i]*stu[i+1])，
 *  即当选中了k个学生后，再选择第i+1编号学生，所产生的最大乘积；
 * 然而，并不能保证上一次选择的就是第i个学生，所以要遍历子数组fm[k]，
  令j从i到1，并且j与i+1之间小于间隔D，遍历fm[k][j]，以及fn[k][j]；
    同理fn[k+1][i+1]=min(fn[k][i]*stu[i+1],fm[k][i]*stu[i+1])。
最后，遍历一遍fm[K][i]求得最大值（i从1～N）。
 *
 * */
int main03() {
    int N, K, D, i, j, k;
    long long stu[51], fm[11][51], fn[11][51], ans;//fm是最大值 fn是最小值  1 <= n <= 50  -50 <= ai <= 50 1 <= k <= 10, 1 <= d <= 50
    //n 个学生 选k个学生 每个学生能力为ai 两个学生之间编号不能超过d
    while (~scanf("%d", &N)) {
        for (i = 0; i < N; scanf("%lld", &stu[++i]));
        scanf("%d %d", &K, &D);
        for (i = 0; i <= K; ++i)
            for (j = 0; j <= N; fm[i][j] = fn[i][j] = 0, ++j);
        for (i = 1, ans = (1LL << 63); i <= N; ++i) {
            fm[1][i] = fn[1][i] = stu[i];
            for (k = 2; k <= K; ++k) {
                for (j = i - 1; j > 0 && i - j <= D; --j) {
                    fm[k][i] = max(fm[k][i], max(fm[k - 1][j] * stu[i], fn[k - 1][j] * stu[i]));
                    fn[k][i] = min(fn[k][i], min(fn[k - 1][j] * stu[i], fm[k - 1][j] * stu[i]));
                }
            }
            ans = max(ans, fm[K][i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main01() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int k, d;
        cin >> k >> d;
        vector<vector<long long>> dp_max(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> dp_min(n, vector<long long>(k + 1, 0));
        for (int i = 0; i < n; i++) {
            dp_max[i][1] = a[i];
            dp_min[i][1] = a[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 2; j <= k; j++) {
                for (int m = max(0, i - d); m <= i - 1; m++) {
                    dp_max[i][j] = max(dp_max[i][j], max(dp_max[m][j - 1] * a[i], dp_min[m][j - 1] * a[i]));
                    dp_min[i][j] = min(dp_min[i][j], min(dp_min[m][j - 1] * a[i], dp_max[m][j - 1] * a[i]));
                }
            }
        }
        long long max_value = dp_max[k - 1][k];
        for (int i = k; i < n; i++) {
            max_value = max(max_value, dp_max[i][k]);
        }
        cout << max_value << endl;
    }
    return 0;
}


/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int getMax(vector<int>& v, int n, int k, int d)
{
	//状态： 以第i个人为最后一个人，总共选了j个人的最大值
	vector<vector<int>> maxValue(n + 1, vector<int>(k + 1, 0));
	vector<vector<int>> minValue(n + 1, vector<int>(k + 1, 0));

	//初始化
	int ret = 0;
	for (int i = 1; i <= n; ++i)
	{
		maxValue[i][1] = minValue[i][1] = v[i - 1];
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 2; j <= k; ++j)
		{
			for (int m = i - 1; m >= max(i - d, 1); --m)
			{
				maxValue[i][j] = max(maxValue[i][j], max(maxValue[m][j - 1] * v[i - 1], minValue[m][j - 1] * v[i - 1]));
				minValue[i][j] = min(maxValue[i][j], min(maxValue[m][j - 1] * v[i - 1], minValue[m][j - 1] * v[i - 1]));
			}
		}
		ret = max(maxValue[i][k], minValue[i][k]);
	}
	return ret;
}

int main()
{
	int n, k, d;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cin >> k;
	cin >> d;
	cout << getMax(v, n, k, d);
	return 0;
}
*/



#include <iostream>
#include <algorithm>

using namespace std;
//因为题目的取值范围最多50个人，最多选10个。所以数组长度分别取51，11
long long maxVal[51][11];
//存放当前选取第i个人(已经选了j个人)最大值记录。(第i个人必选)
long long minVal[51][11];
//存放当前选取第i个人(已经选了j个人)最小值记录。(第i个人必选)

int a[51];

//存放个人能力值
int main02(void) {
    int N, K, D;
    long long result = 0;
    //返回输出结果

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    cin >> K >> D;

    for (int i = 0; i < N; ++i) {
        maxVal[i][0] = minVal[i][0] = a[i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 1; j < K; ++j)
        {
            for (int c = i - 1; c >= max(i - D,0); --c)
            {
                maxVal[i][j] = max(maxVal[i][j], max(maxVal[c][j - 1] * a[i], minVal[c][j - 1] * a[i]));
                minVal[i][j] = min(minVal[i][j], min(maxVal[c][j - 1] * a[i], minVal[c][j - 1] * a[i]));
            }
        }
        result = max(result, max(maxVal[i][K - 1], minVal[i][K - 1]));
    }

    cout << result << endl;
    getchar();
    return 0;
}

int main()
{
    int n;
    while (cin>>n)
    {
        vector<int>a(n+1);
        for (int i = 0; i < n; ++i) {
            cin>>a[i+1];
        }
        int k,d;
        cin>>k>>d;
        vector<vector<long long >>fMax(n+1,vector<long long >(k+1));
        vector<vector<long long >>fMin(n+1,vector<long long >(k+1));

        for(int i=1;i<=n;i++){
            fMax[i][1]=a[i];
            fMin[i][1]=a[i];
        }

        long  long maxValue=a[1];
        for (int i = 1; i <=n; ++i)
        {
            for (int j = 2; j <=k; ++j)
            {
                for (int l = i-1; l>=max(i-d,1) ; --l)
                {
                    fMax[i][j]=max(fMax[i][j],max(fMax[l][j-1]*a[i],fMin[l][j-1]*a[i]));
                    fMin[i][j]=min(fMin[i][j],min(fMax[l][j-1]*a[i],fMin[l][j-1]*a[i]));

                }
            }

            maxValue=max(max(maxValue,fMax[i][k]),fMin[i][k]);

        }
        cout<<maxValue<<endl;

    }
    return 0;
}