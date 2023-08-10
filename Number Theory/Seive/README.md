# Primes:
- Prime numbers are positive integers divisible only by 1 and itself. In other words, prime numbers can't be divided by other numbers than itself or 1.
- For Example, 2, 3, 5, 7, 11, 13, 17, etc. The above numbers can only be divided evenly by 1 or itself, so they are the prime numbers.
- **Sieve of Eratosthenes** is an efficient algorithm for finding all the prime numbers in a given range.
- The algorithm works iteratively by marking the multiples of each prime as non-primes (composite) because we are sure that if any number is a multiple of some other number,
- Then it can never be prime. For Example, if 2 is a prime number, then all the multiples of 2 (i.e., 4, 6, 8, 10, 12, 14, 16.. and so on) are composite numbers as they are multiple of 2,
- So they can never be prime. We will repeat this process until we are left with no next prime number in the list.
-  Once all the multiples of each discovered prime have been marked as composites, the primes are the remaining unmarked numbers in the list.


# Concept of Sieve Of Eratosthenes:
- Instead of checking every number as prime(brute force approach), we would work on the groups,
- And the main concept behind this algorithm is that a number is said to be prime if none of the smaller prime numbers divides it.
- Since we are iterating over a list of numbers, we already marked all the numbers as non-primes, which are multiple of any other number.
- Hence, if we reach a cell that is not marked, it isn't divisible by any smaller prime number and therefore has to be the prime number.
- At last, we can scan a range of numbers given in the input.
- Let's say the given range is [l..r], then we can iterate from l to r and check the numbers which are not marked as false (as they will be the prime numbers),
- And then, we can include them in our resultant set as primes.

  # Code:
```
#include <bits/stdc++.h>

using namespace std;

void sieve_of_eratosthenes(int n) {
    // Create a boolean array "prime[0..n]" and mark all entries as true, meaning all the numbers are initially considered primes.

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    // Start looking with the smallest prime number, i.e., 2.

    for (int p = 2; p * p <= n; p++) {

        // If it is the next prime, mark all its multiples as false, as they are composite and not prime.
        if (prime[p] == true) {

            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // All the unmarked elements remaining in the list are the primes.

    cout << "The prime numbers under "<<n<<" are:" << endl;

    for (int p = 2; p <= n; p++)
        if (prime[p] == true)
            cout << p << " ";
}

int main() {
    int n; cin>>n;

    sieve_of_eratosthenes(n);
}

  
  ```
