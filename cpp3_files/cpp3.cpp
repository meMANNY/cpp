// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// int main()
// {

//     ios::sync_with_stdio(0);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--)
//     {

//         int n;
//         ll k;
//         cin >> n >> k;
//         vector<ll> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }

//         vector<int> b(n), pref(n), suff(n);
//         for (int i = 0; i < n; i++)
//         {
//             b[i] = (a[i] <= k);
//             pref[i] = b[i] + (i > 0 ? pref[i - 1] : 0);
//         }
//         for (int i = n - 1; i >= 0; i--)
//         {
//             suff[i] = b[i] + (i < n - 1 ? suff[i + 1] : 0);
//         }

//         vector<char> g_pref(n, 0), g_suff(n, 0);
//         for (int i = 0; i <= n - 3; i++)
//         {
//             int l = pref[i];
//             int r = (i + 2) / 2;
//             if (l >= r)
//             {
//                 g_pref[i] = 1;
//             }
//         }

//         for (int i = 2; i < n; i++)
//         {
//             int len = n - i;
//             int l = suff[i];
//             int r = (len + 1) / 2;
//             if (l >= r)
//             {
//                 g_suff[i] = 1;
//             }
//         }

//         bool check = false;
//         int idx = -1;
//         for (int i = 0; i <= n - 3; i++)
//         {
//             if (g_pref[i])
//                 idx = i;
//         }
//         int idx2 = n;
//         for (int i = 2; i < n; i++)
//         {
//             if (g_suff[i])
//             {
//                 idx2 = i;
//                 break;
//             }
//         }

//         if (idx != -1 && idx2 < n && idx2 - idx >= 2)
//         {
//             check = true;
//         }

//         if (!check)
//         {
//             for (int i = 0; i <= n - 3; i++)
//             {
//                 if (g_pref[i] && b[i + 1])
//                 {
//                     check = true;
//                     break;
//                 }
//             }
//         }

//         if (!check)
//         {
//             for (int i = 1; i <= n - 2; i++)
//             {
//                 if (g_suff[i + 1] && b[i])
//                 {
//                     check = true;
//                     break;
//                 }
//             }
//         }

//         cout << (check ? "YES" : "NO") << "\n";
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        // turn into 0/1: b[i]=1 iff a[i]<=k
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++)
        {
            b[i] = (a[i] <= k);
        }
        // pref[i]=sum b[1..i]
        vector<int> pref(n + 1);
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + b[i];
        }
        // 1) goodPref[l]=1 iff median(a[1..l])<=k
        //    i.e. pref[l] >= ceil(l/2)
        vector<char> goodPref(n + 1, 0);
        for (int l = 1; l <= n - 2; l++)
        {
            int need = (l + 1) / 2; // ceil(l/2)
            if (pref[l] >= need)
                goodPref[l] = 1;
        }
        // 2) goodSuff[i]=1 iff median(a[i..n])<=k
        //    i.e. (pref[n]-pref[i-1]) >= ceil((n-i+1)/2)
        vector<char> goodSuff(n + 2, 0);
        for (int i = 3; i <= n; i++)
        {
            int len = n - i + 1;
            int have = pref[n] - pref[i - 1];
            int need = (len + 1) / 2;
            if (have >= need)
                goodSuff[i] = 1;
        }

        // 3) Case A: prefix & suffix
        int bestL = -1;
        for (int l = 1; l <= n - 2; l++)
        {
            if (goodPref[l])
                bestL = l;
        }
        int firstR = n + 1;
        for (int i = 3; i <= n; i++)
        {
            if (goodSuff[i])
            {
                firstR = i;
                break;
            }
        }
        bool ok = false;
        if (bestL != -1 && firstR <= n && firstR - bestL >= 2)
        {
            ok = true;
        }
        if (ok)
        {
            cout << "YES\n";
            continue;
        }

        //
        // Now we need to detect “prefix & middle” or “middle & suffix”
        // for **any** middle length.  Instead of brute‐forcing two cuts,
        // we reduce “median([L..R])<=k” to a simple check on one array M:
        //
        //    Define  M[i] = 2*pref[i] - i.
        //
        // Then for a segment [L..R], one shows by a small algebraic
        // manipulation that
        //
        //    median([L..R])<=k
        //  ⇐⇒  M[R] - M[L-1] ≥ ((R-L+1)%2)
        //
        // i.e. either ≥0 if the segment‐length is even, or ≥1 if odd.
        //
        // We precompute two suffix‐max arrays over R for both parities:
        //
        vector<int> M(n + 1);
        for (int i = 1; i <= n; i++)
        {
            M[i] = 2 * pref[i] - i;
        }
        // suffixMaxEven[i] = max M[j] for j>=i and j even
        // suffixMaxOdd [i] = max M[j] for j>=i and j odd
        vector<int> suffixMaxEven(n + 2, INT_MIN), suffixMaxOdd(n + 2, INT_MIN);
        for (int i = n; i >= 1; i--)
        {
            suffixMaxEven[i] = suffixMaxEven[i + 1];
            suffixMaxOdd[i] = suffixMaxOdd[i + 1];
            if ((i & 1) == 0)
                suffixMaxEven[i] = max(suffixMaxEven[i], M[i]);
            else
                suffixMaxOdd[i] = max(suffixMaxOdd[i], M[i]);
        }
        //
        // Case B: prefix & middle
        //   We need some l<r<n with goodPref[l]=1 **and** median([l+1..r])<=k.
        //   Fix l; mid‐start = L=l+1, so L mod2 = (l+1)mod2.  Let base = M[L-1].
        //   We want some R>=L, R<=n-1, so that:
        //
        //      M[R] >= base + ((R-L+1)%2).
        //
        // But (R-L+1)%2 depends on R%2 vs L%2.  One checks both parities
        // via our two suffix‐max arrays:
        //
        for (int l = 1; l <= n - 2 && !ok; l++)
        {
            if (!goodPref[l])
                continue;
            int L = l + 1;
            int base = M[L - 1];
            // If L is odd, then (R-L+1)%2 = R%2
            //   ⇒ Need M[R] >= base + (R%2)
            //     ⇒ Either (R even and M[R]>=base+0) or (R odd and M[R]>=base+1)
            // else L even, (R-L+1)%2 = 1-(R%2).
            if (L & 1)
            {
                // odd L
                if (suffixMaxEven[L] >= base + 0)
                    ok = true;
                if (suffixMaxOdd[L] >= base + 1)
                    ok = true;
            }
            else
            {
                // even L
                if (suffixMaxEven[L] >= base + 1)
                    ok = true;
                if (suffixMaxOdd[L] >= base + 0)
                    ok = true;
            }
        }
        if (ok)
        {
            cout << "YES\n";
            continue;
        }

        // Case C: middle & suffix
        //   Now fix r in [2..n-1].  Mid ends at R=r, suffix starts at S=r+1.
        //   S suffix‐good is goodSuff[S]==1.  And we need median([l..r])<=k
        //   for some l<=r-1.  That is M[r] - M[l-1] ≥ ((r-l+1)%2) for some l.
        //   Equivalently: M[l-1] <= M[r] - ((r-l+1)%2).  1≤l≤r-1 means 0≤l-1≤r-2.
        //   Let B = M[r] - ((r-l+1)%2).  We need min_{x in [0..r-2]} M[x] ≤ B.
        //   We precompute prefix‐mins of M, then check in O(1).
        //
        vector<int> prefixMin(n + 1);
        prefixMin[0] = 0; // M[0]=0 by def
        for (int i = 1; i <= n; i++)
        {
            prefixMin[i] = min(prefixMin[i - 1], M[i]);
        }
        for (int r = 2; r <= n - 1 && !ok; r++)
        {
            if (!goodSuff[r + 1])
                continue;
            int Mr = M[r];
            // We need some x in [0..r-2] so that Mr - M[x] ≥ ((r-(x+1)+1)%2)
            // i.e. Mr - M[x] ≥ ((r-x)%2).  Equivalently M[x] ≤ Mr - ((r-x)%2).
            // But x from 0..r-2 implies (r-x)%2 =  (r%2==0? x%2:1-x%2).
            // We can just check both parities:
            int best = INT_MIN;
            if (r & 1)
            {
                // r odd ⇒ (r-x)%2 = 1 - (x%2)
                //   if x even ⇒ (r-x)%2=1, need M[x] ≤ Mr-1
                //   if x odd  ⇒ (r-x)%2=0, need M[x] ≤ Mr
                // so we need min over even‐x of M[x] ≤ Mr-1  OR
                //              min over odd‑x  of M[x] ≤ Mr
                // We don’t have them separately, but we can note min over
                // all x is ≤ either bound, so just check both:
                if (prefixMin[r - 2] <= Mr)
                    ok = true;
                if (prefixMin[r - 2] <= Mr - 1)
                    ok = true;
            }
            else
            {
                // r even ⇒ (r-x)%2 = x%2
                //   if x even⇒(r-x)%2=0⇒need M[x] ≤ Mr
                //   if x odd ⇒(r-x)%2=1⇒need M[x] ≤ Mr-1
                if (prefixMin[r - 2] <= Mr)
                    ok = true;
                if (prefixMin[r - 2] <= Mr - 1)
                    ok = true;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
