class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {

      const int m=1e9+7;
      const int SIZE=26;
      vector<vector<long long>> T(SIZE,vector<long long>(SIZE,0));
      for(int i=0;i<SIZE;i++)
      {
        for(int j=1;j<=nums[i];j++)
        {
            T[i][(i+j)% SIZE]++;
        }
      } 
        vector<vector<long long> > T_exp=matrixPower(T,t,m);
        vector<long long> freq(SIZE,0);
        for(char c : s)
        {
            freq[c - 'a']++;

        }
        long long total=0;
        for(int j=0;j<SIZE;j++)
        {
            long long sum=0;
            for(int i=0;i<SIZE;i++){
            sum=(sum + freq[i]* T_exp[i][j])%m;
            }
            total =(total+sum)%m; 
        }
        return total;
    }

    private:
    
private:
    vector<vector<long long>> multiplyMatrix(const vector<vector<long long>>& A,
                                             const vector<vector<long long>>& B,
                                             int mod) {
        int SIZE = A.size();
        vector<vector<long long>> result(SIZE, vector<long long>(SIZE, 0));
        for (int i = 0; i < SIZE; i++) {
            for (int k = 0; k < SIZE; k++) {
                for (int j = 0; j < SIZE; j++) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return result;
    }

    vector<vector<long long>> matrixPower(vector<vector<long long>> base,
                                          int exp, int mod) {
        int SIZE = base.size();
        vector<vector<long long>> result(SIZE, vector<long long>(SIZE, 0));
        for (int i = 0; i < SIZE; i++)
            result[i][i] = 1; // Identity matrix

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = multiplyMatrix(result, base, mod);
            }
            base = multiplyMatrix(base, base, mod);
            exp /= 2;
        }
        return result;
    }

};