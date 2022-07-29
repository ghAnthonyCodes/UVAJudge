#include <bits/stdc++.h>
using namespace std;

#define vc vector<char>

// input A+, AB-, ...etc -> { 'A', 'B', 'O' }
vc parse_abo(string S) {
  if (S.size() == 3)
    return { 'A', 'B' };
  if (S[0] == 'A')
    return { 'A', 'O' };
  if (S[0] == 'B')
    return { 'B', 'O' };
  return { 'O' };
}

// input A+, AB-, ...etc -> { '+', '-' }
vc parse_rh(string S) {
  if (S[S.size() - 1] == '-')
    return { '-' };
  return { '+', '-' };
}

string reverse_combo(string S) {
  string ret;
  if (S[0] == 'A' && S[1] == 'A')
    ret = "A";
  else if (S[0] == 'A' && S[1] == 'B')
    ret = "AB";
  else if (S[0] == 'B' && S[1] == 'A')
    ret = "AB";
  else if (S[0] == 'A' && S[1] == 'O')
    ret = "A";
  else if (S[0] == 'O' && S[1] == 'A')
    ret = "A";
  else if (S[0] == 'B' && S[1] == 'B')
    ret = "B";
  else if (S[0] == 'B' && S[1] == 'O')
    ret = "B";
  else if (S[0] == 'O' && S[1] == 'B')
    ret = "B";
  else if (S[0] == 'O' && S[1] == 'O')
    ret = "O";
  if (S[2] == '-' && S[3] == '-')
    ret += '-';
  else
    ret += '+';
  return ret;
}

int main() {

  char A[8], B[8], C[8];
  int tc = 1;
  while (1) {
    scanf("%s %s %s", A, B, C);
    string p1 = string(A);
    string p2 = string(B);
    string c = string(C);
    if (p1 == "E" && p2 == "N" && c == "D")
      break;

    if (c == "?") {
      set<string> S;
      vc p1_abo = parse_abo(p1);
      vc p2_abo = parse_abo(p2);
      vc p1_rh = parse_rh(p1);
      vc p2_rh = parse_rh(p2);
      for (char x : p1_abo) {
        for (char y : p2_abo) {
          string abo_combo;
          abo_combo = x;
          abo_combo += y;
          for (char i : p1_rh) {
            for (char j : p2_rh) {
              string rh_combo;
              rh_combo = i; 
              rh_combo += j;
              // printf("combo: %s%s\n", abo_combo.c_str(), rh_combo.c_str());
              S.insert(reverse_combo(abo_combo + rh_combo));
            }
          }
        }
      }
      if (S.size() == 1) {
        vector<string> V(S.begin(), S.end());
        printf("Case %d: %s %s %s\n", tc, p1.c_str(), p2.c_str(), V[0].c_str());
      } else {
        printf("Case %d: %s %s {", tc, p1.c_str(), p2.c_str());
        vector<string> V(S.begin(), S.end());
        sort(V.begin(), V.end());
        reverse(V.begin(), V.end());
        printf("%s", V[0].c_str());
        for (int i=1; i < V.size(); i++)
          printf(", %s", V[i].c_str());
        printf("}\n");
      }
    }

    else if (p2 == "?") {
      set<string> S;
      for (string tmp : { "A+", "A-", "AB+", "AB-", "B+", "B-", "O+", "O-" }) {
        set<string> T;
        vc p1_abo = parse_abo(p1);
        vc p2_abo = parse_abo(tmp);
        vc p1_rh = parse_rh(p1);
        vc p2_rh = parse_rh(tmp);
        for (char x : p1_abo) {
          for (char y : p2_abo) {
            string abo_combo;
            abo_combo = x;
            abo_combo += y;
            for (char i : p1_rh) {
              for (char j : p2_rh) {
                string rh_combo;
                rh_combo = i; 
                rh_combo += j;
                T.insert(reverse_combo(abo_combo + rh_combo));
              }
            }
          }
        }
        if (T.find(c) != T.end()) {
          S.insert(tmp);
        }
      }
      if (S.empty()) {
        printf("Case %d: %s IMPOSSIBLE %s\n", tc, p1.c_str(), c.c_str());
      } else if (S.size() == 1) {
        vector<string> V(S.begin(), S.end());
        printf("Case %d: %s %s %s\n", tc, p1.c_str(), V[0].c_str(), c.c_str());
      } else {
        printf("Case %d: %s {", tc, p1.c_str());
        vector<string> V(S.begin(), S.end());
        sort(V.begin(), V.end());
        reverse(V.begin(), V.end());
        printf("%s", V[0].c_str());
        for (int i=1; i < V.size(); i++)
          printf(", %s", V[i].c_str());
        printf("} %s\n", c.c_str());
      }
    }

    else if (p1 == "?") {
      set<string> S;
      for (string tmp : { "A+", "A-", "AB+", "AB-", "B+", "B-", "O+", "O-" }) {
        set<string> T;
        vc p1_abo = parse_abo(tmp);
        vc p2_abo = parse_abo(p2);
        vc p1_rh = parse_rh(tmp);
        vc p2_rh = parse_rh(p2);
        for (char x : p1_abo) {
          for (char y : p2_abo) {
            string abo_combo;
            abo_combo = x;
            abo_combo += y;
            for (char i : p1_rh) {
              for (char j : p2_rh) {
                string rh_combo;
                rh_combo = i; 
                rh_combo += j;
                T.insert(reverse_combo(abo_combo + rh_combo));
              }
            }
          }
        }
        if (T.find(c) != T.end())
          S.insert(tmp);
      }
      if (S.empty()) {
        printf("Case %d: IMPOSSIBLE %s %s\n", tc, p2.c_str(), c.c_str());
      } else if (S.size() == 1) {
        vector<string> V(S.begin(), S.end());
        printf("Case %d: %s %s %s\n", tc, V[0].c_str(), p2.c_str(), c.c_str());
      } else {
        printf("Case %d: {", tc);
        vector<string> V(S.begin(), S.end());
        sort(V.begin(), V.end());
        reverse(V.begin(), V.end());
        printf("%s", V[0].c_str());
        for (int i=1; i < V.size(); i++)
          printf(", %s", V[i].c_str());
        printf("} %s %s\n", p2.c_str(), c.c_str());
      }
    }
    tc++;
  }
  return 0;
}
