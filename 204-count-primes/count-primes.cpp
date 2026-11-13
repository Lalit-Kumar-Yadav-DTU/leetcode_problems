class Solution {
// private:
    // bool isPrime(int n) {
    //     if (n <= 1)
    //         return false;

    //     for (int i = 2; i <=sqrt(n); i++) {
    //         if (n % i == 0) {
    //             return false;
    //         }
    //     }

    //     return true; // This should be outside the loop
    // }

public:
    int countPrimes(int n) {
        // int count = 0;

        // for (int i = 2; i < n; i++) {
        //     if (isPrime(i)) {
        //         count++;
        //     }
        // }

        // return count;
        //-------------------------------------------
        // Sieve of Eratosthenes  Prime Count = (n-2) - Composite Count   
        // A composite number is a positive integer greater than 1 that has more than two factors (meaning it can be divided evenly by numbers other than just 1 and itself)  smallest composite is 4.
        // https://chatgpt.com/share/6af7314d-7a30-83e8-b613-619788bef0e3                                                         
        if(n<=2) return 0;  //strictly less than n
        int prime_count = n-2;
        vector<char>isPrime(n, true);    //marked all n-2 numbers as prime
        for(int i=2; i*i<n; i++){
            if(isPrime[i]){    //if i is currently marked as prime
                for(int j=i*i; j<n; j+=i){
                    if(isPrime[j]){    //if j is currently marked as prime
                        isPrime[j] = 0; //mark j as not prime
                        prime_count--; 
                    }
                }
            }
        }
        return prime_count;
    }
};



// Important concept: Why start from i*i?
// You might wonder why we use:
// for(int j = i*i; j < n; j += i)


// Instead of starting from 2*i.

// Because all multiples of i smaller than i*i have already been marked by smaller prime factors.

// For example, when i = 5:
// - 10 = 2 × 5 → already marked when i = 2.
// - 15 = 3 × 5 → already marked when i = 3.
// - 20 = 4 × 5 → already marked when i = 2.
// - 25 = 5 × 5 → needs to be marked now.
// That's why starting from i*i avoids unnecessary iterations.

// Also, your if(v[j]) condition is important: it ensures prime_count decreases only when a number is marked composite for the first time.