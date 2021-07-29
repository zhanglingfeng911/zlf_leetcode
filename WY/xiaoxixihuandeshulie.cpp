//
// Created by zlf on 2021/3/31.
//
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


//童山公爵的代码
//C++版，附上了自己的注释，可能会容易懂一点
#include<iostream>
using namespace std;
int dp[11][100005];    //dp[i][j]表示长度为i，尾数为j的合法数列共有多少个
int main(){
    int n,k,i,j,mod=1000000007;        //mod是题目给出的，防止数字过大
    cin>>n>>k;
    for(i=1;i<=k;i++)
        dp[1][i]=1;        //初始化。长度为1，尾数为i的数列只有一个

    for(i=2;i<=n;i++){
        int sum=0;
        for(j=1;j<=k;j++)
            sum=(sum+dp[i-1][j])%mod;    //dp[i][m]=（所有的dp[i-1][j]相加，再在第i位加上尾数m）- 不合法的数列个数=sum - illegal
        for(j=1;j<=k;j++){
            int p=2;  //这个表示倍数，凡是前一位数字是p*j的都是非法数列，因为 p*j>j && p*j%j==0，违反了第三个条件
            int illegal=0;
            while(p*j<=k){
                illegal=(illegal+dp[i-1][p*j]%mod)%mod;
                p++;
            }
            dp[i][j]=(sum-illegal+mod)%mod;  //原本sum>illegal,但是因为illegal和sum都是求的取模，所以这里sum可能<illegal
        }
    }
    int sum=0;
    for(int i=1;i<=k;i++)
        sum=(sum+dp[n][i])%mod;
    cout<<sum;

}


/*//AC代码：
#include<stdio.h>
#include<string.h>
int dp[15][100005];
const int mod=1000000007;
int main(){
    int n,k,i,j,q;
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(dp,0,sizeof(dp));
        for(i=1;i<=k;i++) dp[1][i]=1;
        for(i=2;i<=n;i++){
            int sum=0;
            for(j=1;j<=k;j++) sum=(sum+dp[i-1][j])%mod;
            for(j=1;j<=k;j++){
                dp[i][j]=sum;
                for(q=j*2;q<=k;q+=j) dp[i][j]=(dp[i][j]-dp[i-1][q]+mod)%mod;
            }
        }
        int res=0;
        for(i=1;i<=k;i++) res=(res+dp[n][i])%mod;
        printf("%d\n",res);
    }
}//用dp[i][j]表示长度为i且必须以j结尾的方法*/




/*
 * state[i][j]表示整个状态空间，其中i(1<=i<=n)表示数列的长度，j(1<=j<=k)表示数列长度为i且以数字j结尾。
递推关系有：state[i][j] += state[i-1][m] (1<=m<=k, 并且(m,j)是个合法的数列)，但是直接按照递推关系，用三层for循环会超时。为此可以先将长度为i-1的合法数列求和(记为sum)。然后对于数列长度为i的每一个j，求出数列长度为i-1时非法的序列个数（记为invalid）,即有state[i][j] = sum - invalid。
对于invalid求取，可以参照素数筛选。算法的时间复杂度大概为O(nkloglogk)
 * import java.util.Scanner;

public class Main {
	static final int mod = 1000000007;

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int k = scanner.nextInt();
		int[][] state = new int[n+1][k+1];

		state[0][1] = 1;

		for(int i=1; i<=n; i++) {
			int sum = 0;
			for(int j=1; j<=k; j++) {
				sum = (sum + state[i-1][j]) % mod;
			}
			for(int j=1; j<=k; j++) {
				int invalid = 0;
				int p = 2;
				while(p*j <= k) {
					invalid = (invalid + state[i-1][p*j]) % mod;
					p++;
				}
				state[i][j] = (sum - invalid + mod) % mod;
			}
		}

		int sum = 0;
		for(int i=1; i<=k; i++) {
			sum = (sum + state[n][i]) % mod;
		}
		System.out.println(sum);

		scanner.close();
	}
}
 *
 * */