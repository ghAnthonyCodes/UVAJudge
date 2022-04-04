#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <string>

#define ii std::pair<int, int>
#define vii std::vector<ii>
#define vvii std::vector<vii>

struct bsd_t {
   int baseAddr;
   int dimensions;
   int elementSize;
   vii bounds;
};

int main() {

   int N, R;
   int B, S, D;
   int Ld, Ud;
   char Asc[12], Rsc[12];
   std::string As, Rs;
   std::map<std::string, bsd_t> M;

   scanf("%d %d", &N, &R);
   for (int n=0; n<N; n++) {
      
      scanf("%s %d %d %d", &Asc[0], &B, &S, &D);
      As = Asc;
      M[As] = bsd_t();
      M[As].baseAddr = B;
      M[As].elementSize = S;
      M[As].dimensions = D;
      for (int d=0; d<D; d++) {
         scanf("%d %d", &Ld, &Ud);
         M[As].bounds.push_back({ Ld, Ud });
      }
   }

   for (int r=0; r<R; r++) {
      scanf("%s", &Rsc[0]);
      Rs = Rsc;

      std::vector<int> I;
      int ai;
      // Calc ans
      for (int i=0; i<M[Rs].dimensions; i++) {
         scanf("%d", &ai);
         I.push_back(ai);
      }

      int CD = M[Rs].elementSize;
      int ans = CD*I[I.size()-1] - CD*M[Rs].bounds[I.size()-1].first + M[Rs].baseAddr;
      int prev = CD;
      for (int i=I.size()-2; i>=0; i--) {
         int Cd = prev*(M[Rs].bounds[i+1].second - M[Rs].bounds[i+1].first + 1);
         ans += I[i]*Cd;
         ans -= Cd*M[Rs].bounds[i].first;
         prev = Cd;
      }
      printf("%s[%d", Rs.c_str(), I[0]);
      for (int i=1; i<I.size(); i++)
         printf(", %d", I[i]);
      printf("] = %d\n", ans);
      
      
   }
   return 0;
}
