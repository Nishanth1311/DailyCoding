class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen = dict()
        current_str_len = 0
        longest_substring_len = 0

        for index, value in enumerate(s):
            # If the character is not seen before
            # it can not be part of our longest substring
            # so increast the current string length
            if value not in last_seen:
                current_str_len += 1

            # If the character is seen previously    
            else:
                # If the character is last seen in a position
                # that is not part of our current string, it can be ignored
                # increment the current string length in this case
                if index - current_str_len > last_seen[value]:
                    current_str_len += 1
                # If the character is part of current string
                # Add the new character and reduce the length of the current string
                else:
                    current_str_len = index - last_seen[value]
                    
            last_seen[value] = index 
            
            if current_str_len > longest_substring_len:
                longest_substring_len = current_str_len
                
            # print('index:', index)
            # print('current len:', current_str_len)
            # print('longest str len:', longest_substring_len)
            
            
        return longest_substring_len
            