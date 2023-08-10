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

    cout << "The prime numbers under 30 are:" << endl;

    for (int p = 2; p <= n; p++)
        if (prime[p] == true)
            cout << p << " ";
}

int main() {
    int n = 30;

    sieve_of_eratosthenes(n);
}
