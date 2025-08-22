def rolling_hash(s):
    """
    Compute rolling hash for string s
    """
    MOD = 10**9 + 7
    BASE = 31
    
    hash_value = 0
    power = 1
    
    for char in s:
        hash_value = (hash_value + (ord(char) - ord('a') + 1) * power) % MOD
        power = (power * BASE) % MOD
    
    return hash_value

def polynomial_hash(s):
    """
    Polynomial rolling hash implementation
    """
    MOD = 10**9 + 7
    BASE = 31
    
    hash_value = 0
    base_power = 1
    
    for char in s:
        hash_value = (hash_value + (ord(char) - ord('a') + 1) * base_power) % MOD
        base_power = (base_power * BASE) % MOD
    
    return hash_value

def rabin_karp_search(text, pattern):
    """
    Rabin-Karp string matching algorithm
    """
    MOD = 10**9 + 7
    BASE = 31
    
    n = len(text)
    m = len(pattern)
    
    if m > n:
        return []
    
    # Compute hash of pattern
    pattern_hash = polynomial_hash(pattern)
    
    # Compute hash of first window
    text_hash = 0
    base_power = 1
    
    for i in range(m):
        text_hash = (text_hash + (ord(text[i]) - ord('a') + 1) * base_power) % MOD
        if i < m - 1:
            base_power = (base_power * BASE) % MOD
    
    matches = []
    
    # Check first window
    if text_hash == pattern_hash:
        if text[:m] == pattern:
            matches.append(0)
    
    # Rolling hash for remaining windows
    for i in range(1, n - m + 1):
        # Remove leading character
        text_hash = (text_hash - (ord(text[i-1]) - ord('a') + 1)) % MOD
        text_hash = (text_hash * pow(BASE, MOD-2, MOD)) % MOD
        
        # Add trailing character
        text_hash = (text_hash + (ord(text[i+m-1]) - ord('a') + 1) * base_power) % MOD
        
        # Check for match
        if text_hash == pattern_hash:
            if text[i:i+m] == pattern:
                matches.append(i)
    
    return matches

# Example usage
if __name__ == "__main__":
    text = "abracadabra"
    pattern = "abra"
    
    matches = rabin_karp_search(text, pattern)
    print(f"Pattern '{pattern}' found at positions: {matches}")
