# Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

# Example 1:

# Input: words = ["bella","label","roller"]
# Output: ["e","l","l"]
# Example 2:

# Input: words = ["cool","lock","cook"]
# Output: ["c","o"]


class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        # Initialize the counter with the first word
        common_count = Counter(words[0])
        
        # Iterate over the rest of the words and update the counter with the minimum count intersection
        for word in words[1:]:
            common_count &= Counter(word)
        
        # Convert the counter back to a list of characters, considering the count of each character
        result = []
        for char, count in common_count.items():
            result.extend([char] * count)
        
        return result

        
