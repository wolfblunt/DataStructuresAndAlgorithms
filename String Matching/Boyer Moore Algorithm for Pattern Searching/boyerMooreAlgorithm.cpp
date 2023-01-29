#include <bits/stdc++.h>

using namespace std;
# define Total_Chars 256

// The preprocessing function
void badCharHeuristic(string str, int size, int bad_characters[Total_Chars]) {
  int i;
  // Initialize with -1
  for (i = 0; i < Total_Chars; i++)
    bad_characters[i] = -1;

  // Fill the actual value of last occurrence
  // of a character
  for (i = 0; i < size; i++) {
    bad_characters[(int) str[i]] = i;
  }
}

// Boyer Moore algorithm using bad character Heuristic
void boyermoore(string T, string P) {
  int m = P.size();
  int n = T.size();

  int bad_character[Total_Chars];

  /* Preprocessing function to  fill the bad character array */
  badCharHeuristic(P, m, bad_character);

  int idx = 0; /* idx defines how much pattern is shifted */
  while (idx <= (n - m)) {
    int j = m - 1;

    /* Reducing j of P until we gets a
    mismatch character, at this shift idx */
    while (j >= 0 && P[j] == T[idx + j])
      j--;

    /* In case if we get j=-1 which signify that
    P is present at current shift */
    if (j < 0) {
      cout << "Shift at which pattern occurs = " << idx << "\n";

      /* We will shift P such that the next
        character in T aligns with the last
        occurrence of it in P.
        To cover the case when P occur at end
        of T we need the condition idx+m < n */

      idx += (idx + m < n) ? m - bad_character[T[idx + m]] : 1;
    }
    // other case
    else
      /* In this case also, We will shift P such
        that the next character in T aligns
        with the last occurrence of it in P.
        To unsure that we get positive
        shift we are using max function.
        The negative shift may occur when the
        last occurrence of bad character in P
        is on the right side of the current
        character. */

      idx += max(1, j - bad_character[T[idx + j]]);
  }
}

int main() {
  string text = "AYRRQMGRPCRQ";
  string pattern = "RPCRQ";
  boyermoore(text, pattern);
  return 0;
}