void primeFactors(int n) 
{ 
  while (n%2 == 0) 
    { 
        prime[2]++:
        n = n/2; 
    } 
     
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        while (n%i == 0) 
        { 
            prime[i]++:
            n = n/i; 
        } 
    } 
     
    if (n > 2) 
        prime[n]++;
} 